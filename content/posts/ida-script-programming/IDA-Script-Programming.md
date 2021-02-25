---
title: IDA-Script
date: 2020-04-19T16:02:33+08:00
tags: [reverse, IDA]
categories: [reverse]
description: About IDA Script
password:
---



# IDA 脚本入门



总所皆知，IDA是一个非常好用的逆向静态分析工具，上节课，老师带我们体验到了ida脚本的魅力，我们这次就来了解一波IDA的脚本



> Reference:
>
> [IDA Pro 脚本系统(idc idaPython)帮助文档索引](https://blog.csdn.net/lacoucou/article/details/79349677)
>
> [2018-07-14 IDA-脚本编写](https://www.jianshu.com/p/366cd488cb24)
>
> idc
>
> [IDA Help: Alphabetical list of IDC functions](https://www.hex-rays.com/products/ida/support/idadoc/162.shtml)
>
> [[翻译][原创]IDC脚本 - IDC脚本语言官方教程](https://bbs.pediy.com/thread-219016.htm)
>
> [IDA-IDC脚本编写语法](https://www.cnblogs.com/gwind/p/8250842.html)
>
> IDA Python
>
> [IDAPython初学者指南](https://gitee.com/it-ebooks/it-ebooks-2018-04to07/raw/master/IDAPython%20%E5%88%9D%E5%AD%A6%E8%80%85%E6%8C%87%E5%8D%97.pdf)：本地版本[here](./IDAPython 初学者指南.pdf)
>
> [IDAPython Docs](https://www.hex-rays.com/products/ida/support/idapython_docs/)：hex-rays官方文档
>
> [IDA-python学习小结](https://cartermgj.github.io/2017/10/10/ida-python/)
>
> [ IDAPYTHON --- IDA 脚本](https://wizardforcel.gitbooks.io/grey-hat-python/content/41.html)
>
> ​		[IDAPython 函数](https://wizardforcel.gitbooks.io/grey-hat-python/content/43.html)
>
> [IDApython插件编写及脚本批量分析教程](https://blog.csdn.net/qq_35056292/article/details/89421793)
>
> 



我解到了IDA脚本主要有IDA python 和 IDC

IDC脚本语言是一种类似C的脚本语言，和C语言有着类似的语言标记。然而，由于IDC是一种脚本语言，就无法包含指针这样的高级特性了，但是所有的变量类型，脚本解释器都是可以支持的。**IDC中的变量是弱类型**的，一个变量可以保存任何类型的数据，因此变量声明的时候是不需要指定变量类型的，比如你可以这样进行变量声明：` auto myvar;`

IDA python 为IDA中集成的python解释器（美中不足的就是目前是python2.7版本），能够调用所有的idc的函数以及所有python脚本，他可以充分利用python的数据处理能力和所有python模块

脚本的用处很多，以现在的我的了解来说，ida脚本最多的用处是用来脱壳和寻找pwn的易被攻击的函数





## 使用



* `shift + F2` 会弹出一个对话框，可以将脚本直接写在里面，点run运行，即`File -> Script Command`
* 菜单栏中 `File -> Script file`载入idc文件，同样，`alt + F7`



输出在下面的Output Window里





## IDC



IDC脚本语言借用了很多C语言的语法，因此我们很快就能上手



* #### IDC变量

`auto`： IDC关键字auto用于引入一个局部变量，如`auto var,addr;`

1. IDC认可使用`/* */`的c语言风格进行多行注释。
2. 也使用`//`的C++风格进行行尾注释
3. 使用`;`作为终止符（和c语言中一样）
4. IDC并不支持c风格数组类型，指针,结构体,联合之类，复杂的数据类型



`extern`：IDA使用`extern`关键字引入全局变量申明



* #### 表达式

IDC**支持c中的所有表达式和逻辑运算符，包括三元运算符（？：）。**

**支持**逗号运算符，但是 **不支持** op=(+=,*=,>>=等)复合赋值运算符。

**不支持**算术移位，如果要移位只能修改最高位和最低位。如下所示：



提供**分片运算**，使用方括号和其实索引（包括）与结束索引（不包括）来指定至少一个索引。这个就像python数组一样，比如`s1 = str[7:9]`、`s2 = str[:6]`、`s3 = str[10:]`





* #### IDC语句



语句以分号结尾，但是不支持复合语句。

引入`try/catch`块和相关的throw语句，相当与C++的异常处理。

使用和C语言一样的花括号和语义。在花括号中可以申明变量，**申明变量**必须位于花括号内的**第一条语句**。

**Message**类似于c语言中的print





* #### IDC函数



- **.idc文件**支持用户定义的函数。
- IDC命令对话框**不支持**用户定义的函数。
- 使用**static**声明用户定义的函数。
- 函数的参数列表以**逗号**隔开。

* 若需要返回值 ，使用**return**
  * 可以将函数的引用作为参数传递给另外一个函数，并将函数引用的作为函数的结果返回。

* main()函数依旧为函数入口







* ### IDC程序

- 当执行大量的IDC语句的时候，需要创建一个独立的IDC程序文件。
- IDC程序文件，**至少定义一个没有参数的main函数**。
- IDC文件必须包含**#include<idc.idc> **这个文件，由此获得宏定义。



拿老师给的示例程序来说

```c
#include <idc.idc>

/*
//part1:helloworld
static main(){
	//Wait();
	Message("Hello world");
	//Exit(0);
	return 0;
}
*/

//part2:see segment

static list_segs()
{	auto ea, i=0;
	ea = FirstSeg();
	while (ea != BADADDR)
	{	Message("\nsegment %d 0x%08X-0x%08X\n", 
 			i, ea, SegEnd(ea));
		list_func_with_ref(ea);
		ea = NextSeg(ea);
		i++;
}	
}

/*
static main()
{		//Wait();
		list_segs();
		//func_list_ref();		
		Message("\n\n bye \n\n");		
		//Exit(0);
}
*/


//part3:see function

static list_func_with_ref(ea)
{
    auto func;
    func = SegStart(ea);
    //Message("first addr is %x\n", func); // note: first address maybe not a func
    while (func != BADADDR && func < SegEnd(ea))
    {
        if (GetFunctionFlags(func) != -1) // if really a func
        {
            auto ref, tip;
            if (func>=SegStart(ea) && func<SegEnd(ea))
                tip = "Internal";
            else
                tip = "External";
            Message("%s Function 0x%08X %s\n", tip, func, GetFunctionName(func));
            for (ref=RfirstB(func); ref != BADADDR; ref=RnextB(func, ref))
            {
                auto caller_name, caller_addr;
                caller_name = GetFunctionName(ref);
                caller_addr = GetFunctionAttr(ref, FUNCATTR_START);
                Message("  called at 0x%08X by 0x%08X(%s)\n", ref, caller_addr, caller_name);
            }
        }
        func=NextFunction(func);
    }
}

static main()
{		
		Message("Hello!");
		//Wait();
		list_segs();
		auto ea;
		//ea = FirstSeg();
		//list_func_with_ref(ea);		
		Message("\n\n bye \n\n");		
		//Exit(0);
}

```



首先在头部引入`#include <idc.idc>`，这个是必须的，包含了idc里面的宏定义

`FirstSeg()`获取第一个Segment段的地址，然后调用`list_ref_function`展示其中的函数，将此过程进行循环每一个segment

`list_ref_function`：通过`GetFunctionFlags`来判断是否是一个地址是否有函数开始标志，来获取函数的地址和名字，并用Message函数打印出来



## IDA Python



IDA Python 由三个分离的模块组成,他们分别是 idc,idautils 和 idaapi。

```
idc:这是兼容idc函数的模块  
idautils:很使用的一个模块，大多数处理都是需要依托于这个模块  
idaapi:允许使用者通过类的形式，访问更多底层的数据  
```

IDA Python 的强大之处在于它能遍历所有的指令,所有的交叉引用地址,还有搜索所有的代码和数据。



#### 一些功能

> 指令处理

1. 获取当前指令地址：ea=here() print “0x%x %s”%(ea,ea)
2. 获取当前的汇编指令：idc.GetDisasm(ea)
3. 获取当前处于的段：idc.SegName()
4. 获取该段程序最低和最高地址：hex(MinEA()) hex(MaxEA())
5. 获取下(上)一条汇编指令地址：ea = here() ; next_instr = idc.NextHead(ea) PrevHead(ea)

> 函数操作

1. 获取程序所有函数的名称：

   ```
   for func in idautils.Functions():
    print hex(func), idc.GetFunctionName(func)
   ```

2. 计算当前函数有多少条指令

   ```
   ea = here()
   len(list(idautils.FuncItems(ea)))
   ```

3. 获取当前IDB中记录的所有有名字函数的地址和名称： idautils.Names() 返回的是一个以元组组成的列表，函数的起始地址指向了其plt表![img](https://raw.githubusercontent.com/carterMgj/blog_img/master/2017-10-10-IDA-python/3.png)

> 指令操作

1. 给定地址，打印指令 idc.GetDisasm(ea)
2. 给定函数中一个地址，得到整个函数的指令列表 idautils.FuncItems(here())
3. 获取函数的一些flag信息： idc.GetFunctionFlags(func)
4. 对一条汇编指令进行拆解： 获取指令的操作：idc.GetMnem(here()) 获取指令的操作数：idc.GetOpType(ea,n) 根据返回的数值，可以判断操作数类型（普通寄存器、常量字符串等）
5. 对汇编指令中用到的操作数，求取其引用的地址，也就是双击该操作数后跳转到的地址 hex(idc.GetOperandValue(here(),1))

> 交叉引用

1. 指令从哪个地方来：idautils.CodeRefsTo(here(),0)
2. 指令下一步去到哪儿：idautils.CodeRefsFrom(here(),0)
3. 数据从哪个地方来：idautils.DataRefsTo(here(),0)
4. 数据下一步去到哪儿：idautils.DataRefsFrom(here(),0)
5. 较为通用的一种获取xref：idautils.XrefsTo(here(),flag) 其中flag=0时，所有的交叉引用都会被显示





