---
title: Link-Library-of-C++
date: 2020-03-30 21:43:06
tags:
categories: C++
description:
password:
---











# 0x00 序



> https://www.runoob.com/w3cnote/cpp-static-library-and-dynamic-library.html
>
> https://zhuanlan.zhihu.com/p/32615811
>
> https://www.cnblogs.com/WindSun/p/11287927.html

在写关于病毒程序之前，忽然想学习一下有关C++库文件的编写

库，是可复用代码的集合

总所周知，库文件分为静态链接库和动态链接库，两者有一定的区别

![](Link-Library-of-C/Compile.png)

静态链接库在编译时，就通过链接成为可执行文件的一部分，简单来说，就是将库函数融入目标程序内，即使目标程序没有和库文件在一起也能运行；而动态链接库是在程序运行时调用的，其库并没有融入目标程序内，运行时可以随意加载和移除，节省内存空间。

动态链接库和静态链接库的**相同点是它们都实现了代码的共享，不同点是静态链接库文件中的代码被包含目标程序中，该lib中不能再包含其他动态链接或者静态链接的库了。而动态链接库可以被调用的目标程序动态地“引用”和“卸载”，一个动态链接库中可以包含其他动态链接库或者静态链接库**。在大型的软件项目中一般要实现很多功能，如果把所有单独的功能写成一个个lib文件的话，程序运行的时候要占用很大的内存空间，导致运行缓慢；但是如果将功能写成dll文件，就可以在用到该功能的时候调用功能对应的dll文件，不用这个功能时将dll文件移除内存，这样可以节省内存空间。



- 在Win下，动态库以`.dll`结尾，静态库以`.lib`结尾。
- 在Linux下，动态库文件以`.so`结尾，静态库以`.a`结尾。
- 在Mac下，动态库以`.dylib`结尾，静态库以`.a`结尾。





## Windows



#### 静态库(.lib)

libTest.h

```c++
#ifndef _TEST_H
#define _TEST_H
int test_add(int x, int y);
#endif
```



libTest.cpp

```c++
#include "libTest.h"
#include <iostream>
//using namespace std;
 
int test_add(int x, int y){
	int sum;
	sum = x + y;
	return sum;
}
```



然后windows下需要配合VS命令行(我没内存卸了XD)，或者vs studio里面可以直接生成

使用静态库也可在里面配置

##### 使用

main.cpp

```cpp
#include "libTest.h"
#include <iostream>
using namespace std;
#pragma comment(lib,"libTest.lib") //加入链接库
 
void main(){
	int sum;
	sum = test_add(1, 2);
	cout << sum << endl;
	system("pause");
}

```



#### 动态库(.dll)



dllGen.h

```c++
#ifndef _MYADD_H
#define _MYADD_H
__declspec(dllexport) int test_add(int x, int y);
#endif
```

注：导出函数的声明方式有两种，一种如上所示，另一种采用模块定义(.def)文件声明，具体上网搜



dllGen.cpp

```c++
#include "dllGen.h"
#include <iostream>
using namespace std;
 
int test_add(int x, int y){
	int sum;
	sum = x + y;
	return sum;
}
```



##### 使用

main.cpp

```c++
#include <iostream>
using namespace std;
#include <windows.h>

//定义一个与myadd函数接受参数类型和返回
//值均相同的函数指针类型
typedef int(*lpAddFun)(int, int);

int main(){
	HINSTANCE hDll;//句柄
	lpAddFun addFun;//函数指针
	hDll = LoadLibrary("dllGenTest.dll");//动态加载DLL模块句柄
	if (hDll == NULL){
		FreeLibrary(hDll);
	}
 
	//addFun = (lpAddFun)GetProcAddress(hDll, "myadd"); //通过函数名获取函数的地址，没有运行
	addFun = (lpAddFun)GetProcAddress(hDll, MAKEINTRESOURCE(1)); //通过函数的序号获取函数的地址，work
	
	if (addFun == NULL){
		FreeLibrary(hDll);
	}
 
	int result;
	result = addFun(22,33);
	cout << result << endl;
	system("pause");
    
	FreeLibrary(hDll);
	return 0;
}

```













## Linux



#### 静态库(.a)



add.h

```c++
#ifndef ADD_H
#define ADD_H
int add(int x,int y); 
#endif
```

add.c

```c++
#include <stdio.h>
#include "add.h"
int add(int x, int y)
{
    return (x + y);
}
```

sub.h

```c++
#ifndef _SUB_H_ 
#define _SUB_H_  
int sub(int x, int y);
#endif
```

sub.c

```c++
#include <stdio.h>
#include "sub.h"
int sub(int x, int y)
{
    return (x - y);
}
```



main.c

```c++
#include <stdio.h>
#include "sub.h"
#include "add.h"
 
int main()
{
    int a, b;
    a = add(1, 2);
    b = sub(10, 5);
    printf("a = % d, b = % d\n", a, b);
    return 0;
}
```

不管是静态函数库还是动态函数库，都是由*.o目标文件生成。

所以先复制代码

```sh
$ gcc -c add.c 
$ gcc -c sub.c
```

生成`add.o`、 `sub.o`

静态函数库由ar命令创建

```sh
$ ar -crv libTest.a add.o sub.o
```

>  **参数：**
>
> **-c** create的意思
>
> **-r** replace的意思，表示当插入的模块名已经在库中存在，则替换同名的模块。如果若干模块中有一个模块在库中不存在，ar显示一个错误消息，并不替换其他同名模块。默认的情况下，新的成员增加在库的结尾处，可以使用其他任选项来改变增加的位置。

到此静态函数库创建完毕。



##### 使用方法

通过

```sh
$ gcc -o main main.cpp -L. -lTest
```

编译main.c就会把静态函数库整合进main。

> **参数：**
>
> -L 指定静态函数库的位置供查找，注意L后面还有'.'，表示静态函数库在本目录下查找。
>
> -l 则指定了静态函数库名，由于静态函数库的命名方式是lib*.a，**其中的lib和.a忽略。**



根据静态函数库的特性，此处删除libaddsub.a后main依然可以运行，因为静态库的内容已经整合进去了。



#### 动态库(.so)

直接用上面代码编译，选用gcc选项即可

```sh
$ gcc -shared -fpic -o libTest.so add.cpp sub.cpp
```

> **参数**
>
> -fpic：产生位置无关代码
>
> -shared：生成共享库



```sh
$ gcc -o out main.cpp -L. -lTest
```

此时还不能立即`./out`，因为在动态函数库使用时，会查找/usr/lib /lib目录下的动态函数库，而此时我们生成的库不在里边。

这个时候有以下几种办法可以让他成功运行：

* 最直接最简单的方法就是把`libaddsub.so`拉到`/usr/lib` 或`/lib`中去。

* 还有一种方法,假设`libTest.so`在`/home/linux/Test`

`export LD_LIBRARY_PATH=/home/linux/Test:$LD_LIBRARY_PATH`

* 另外还可以在`/etc/ld.so.conf`文件里加入我们生成的库的目录，然后`/sbin/ldconfig`。

> `/etc/ld.so.conf`是非常重要的一个目录，里面存放的是链接器和加载器搜索共享库时要检查的目录，默认是从`/usr/lib /lib`中读取的，所以想要顺利运行，我们也可以把我们库的目录加入到这个文件中并执行`/sbin/ldconfig`。



> g++(gcc)编译选项
>
> * -c ： 仅编译源代码但不执行链接，输出结果为对象文件，即`.o`
>
> * -shared ：指定生成动态链接库。
>
> * -static ：指定生成静态链接库。
>
> * -fPIC ：表示编译为位置独立的代码，用于编译共享库。目标文件需要创建成位置无关码，念上就是在可执行程序装载它们的时候，它们可以放在可执行程序的内存里的任何地方。
>
> * -L. ：表示要连接的库所在的目录。
>
> * -l：指定链接时需要的动态库。编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，后面加上.a/.so来确定库的名称。
>
> * -Wall ：生成所有警告信息。
>
> * -ggdb ：此选项将尽可能的生成gdb的可以使用的调试信息。
>
> * -g ：编译器在编译的时候产生调试信息。
>
> * -c ：只激活预处理、编译和汇编,也就是把程序做成目标文件(.o文件)。
>
> * -Wl,options ：把参数(options)传递给链接器ld。如果options中间有逗号,就将options分成多个选项,然后传递给链接程序。
>
> ------
>
> 
>
> * **ldd**命令可以查看一个可执行程序依赖的共享库**
>
> 