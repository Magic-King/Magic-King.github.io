---
title: Makefile
date: 2019-06-06 09:11:19
tags: [c++,make]
categories: C++
description:
password:
---





# <center>Make</center>



>本文参考：
>
>[GNU+make中文手册]("/Makefile/《GNU+make中文手册-v3.80》.pdf")
>
>[GNU+make原版官方手册](/Makefile/make)
>
>[make wiki](<https://zh.wikipedia.org/wiki/Make>)
>
>[Makefile由浅入深](<https://zhuanlan.zhihu.com/p/47390641>)
>
>[跟我一起写Makefile](<https://seisman.github.io/how-to-write-makefile/index.html>)
>
>
>
>



### 序



​		最初了解到Makefile，还是从很久很久以前说起。当时在老师底下做项目，要配置一个nginx服务器，当初给出教程是直接`make&&make install`就完事了，打完代码一行行执行下来看起来非常有成就感233333

​		但是之后在做计算机系统的实验时，才发现Makefile是如此的有用万能，无论是windows还是linux(ubuntu 16.04)下，只需要一个make就能解决编译链接安装问题，make完就能立即使用，实属好用。在之后的操作系统实验中，真正接触到了Makefile这东西，基本每个实验都要写Makefile，因此对Makefile的格式有了一个大概印象，但不过想深入了解一波，便去找了许多资料看。







## 概述

在软件开发中，**make**是一个工具程序（Utility software），经由读取叫做“makefile”的文件，自动化建构软件。它是一种转化文件形式的工具，转换的目标称为“target”；与此同时，它也检查文件的依赖关系，如果需要的话，它会调用一些外部软件来完成任务。它的依赖关系检查系统非常简单，主要根据依赖文件的修改时间进行判断。大多数情况下，它被用来编译源代码，生成结果代码，然后把结果代码连接起来生成**可执行文件**或者**库文件**。它使用叫做“makefile”的文件来确定一个target文件的依赖关系，然后把生成这个target的相关命令传给shell去执行。

许多现代软件的开发中（如[Microsoft Visual Studio](https://zh.wikipedia.org/wiki/Microsoft_Visual_Studio)（他其实有提供一个vs 2017 交叉工具命令提示符，可以进行make，但不过一般在IDE中直接编译生成独有的工程配置文件）），集成开发环境已经取代make，但是在Unix环境中，仍然有许多任务程师采用make来协助软件开发。





## Makefile介绍

make命令执行时，需要一个makefile文件，以告诉make命令需要怎么样的去编译和链接程序。

首先，我们用一个示例来说明makefile的书写规则，以便给大家一个感性认识。这个示例来源于gnu 的make使用手册，在这个示例中，我们的工程有8个c文件，和3个头文件，我们要写一个makefile来告 诉make命令如何编译和链接这几个文件。我们的规则是：

1. 如果这个工程没有编译过，那么我们的所有c文件都要编译并被链接。
2. 如果这个工程的某几个c文件被修改，那么我们只编译被修改的c文件，并链接目标程序。
3. 如果这个工程的头文件被改变了，那么我们需要编译引用了这几个头文件的c文件，并链接目标程序。

只要我们的makefile写得够好，所有的这一切，我们只用一个make命令就可以完成，make命令会自动智能 地根据当前的文件修改的情况来确定哪些文件需要重编译，从而自动编译所需要的文件和链接目标程序。 





### Makefile规则

```makefile
#Makefile中，用#表示注释
target ...:	prerequisites	...
	command 1
	#注意命令前要用Tab
	command 2
	...
	...
#可以使用“\”表示续行，但是“\”之后不能有空格
```



- target

  可以是一个object file（目标文件），也可以是一个执行文件，还可以是一个标签（label）。对 于标签这种特性，在后续的“伪目标”章节中会有叙述。

- prerequisites

  生成该target所依赖的文件和/或target

- command

  该target要执行的命令（任意的shell命令）

这是一个文件的依赖关系，也就是说，**target这一个或多个的目标文件依赖于prerequisites中的文件**， 其生成规则定义在command中。说白一点就是说:

**prerequisites中如果有一个以上的文件比target文件要新的话，command所定义的命令就会被执行。**

这就是Makefile中最核心的规则。





#### 实例

采用GNU make 手册中的例子

```makefile
edit : main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o
    cc -o edit main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o

main.o : main.c defs.h
    cc -c main.c
kbd.o : kbd.c defs.h command.h
    cc -c kbd.c
command.o : command.c defs.h command.h
    cc -c command.c
display.o : display.c defs.h buffer.h
    cc -c display.c
insert.o : insert.c defs.h buffer.h
    cc -c insert.c
search.o : search.c defs.h buffer.h
    cc -c search.c
files.o : files.c defs.h buffer.h command.h
    cc -c files.c
utils.o : utils.c defs.h
    cc -c utils.c
clean :
    rm edit main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o
```



该工程有3个头文件和8个c文件

其中反斜杠(“\”)是换行符，注意换行符之后不能用空格。换行符又利用Makefile的阅读。

把Makefile放在处于工程下的，然后在该目录下输入`make`命令，就可以生成可执行文件了。如果要删除执行文件和所有的中间目标文件，那么只需要执行`make clean`就可以了。

在这个makefile中，目标文件（target）包含：执行文件edit和中间目标文件（ `*.o` ），依赖文 件（prerequisites）就是冒号后面的那些 `.c` 文件和 `.h` 文件。每一个 `.o` 文件都有 一组依赖文件，而这些 `.o` 文件又是执行文件 `edit` 的依赖文件。依赖关系的实质就是说明了目 标文件是由哪些文件生成的，换言之，目标文件是哪些文件更新的。

这里要说明一点的是， `clean` 不是一个文件，它只不过是一个动作名字，有点像c语言中的label一 样，其冒号后什么也没有，那么，make就不会自动去找它的依赖性，也就不会自动执行其后所定义的命令。 要执行其后的命令，就要在make命令后明显得指出这个label的名字。这样的方法非常有用，我们可以在一 个makefile中定义不用的编译或是和编译无关的命令，比如程序的打包，程序的备份，等等。



### make的执行过程如下：

1. 依次读取变量“MAKEFILES”定义的makefile文件列表
2. 读取工作目录下的makefile文件（GNU make的顺序：缺省的是根据命名的查找顺序“GNUmakefile”，“makefile”，“Makefile”，首先找到那个就读取那个（假如是MAKEFILE，需要用`make -f`））
3. 依次读取工作目录makefile文件中使用指示符“include”包含的文件
4. 查找重建所有已读取的makefile文件的规则（如果存在一个目标是当前读取的某一个makefile文件，则执行此规则重建此makefile文件，完成以后从第一步开始重新执行）
5. 初始化变量值并展开那些需要立即展开的变量和函数并根据预设条件确定执行分支
6. 根据“终极目标”以及其他目标的依赖关系建立依赖关系链表
7. 执行除“终极目标”以外的所有的目标的规则（规则中如果依赖文件中任一个文件的时间戳比目标文件新，则使用规则所定义的命令重建目标文件）
8. 执行“终极目标”所在的规则



一上面那个工程为示例：

```
在默认的方式下，也就是我们只输入 make 命令。那么，

1.make会在当前目录下找名字叫“Makefile”或“makefile”的文件。

2.如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到“edit”这个 文件，并把这个文件作为最终的目标文件。

3.如果edit文件不存在，或是edit所依赖的后面的 .o 文件的文件修改时间要比 edit 这个 文件新，那么，他就会执行后面所定义的命令来生成 edit 这个文件。

4.如果 edit 所依赖的 .o 文件也不存在，那么make会在当前文件中找目标为 .o 文件 的依赖性，如果找到则再根据那一个规则生成 .o 文件。（这有点像一个堆栈的过程）

5.当然，你的C文件和H文件是存在的啦，于是make会生成 .o 文件，然后再用 .o 文件生 成make的终极任务，也就是执行文件 edit 了。
```



这就是整个make的依赖性，make会一层又一层地去找文件的依赖关系，直到最终编译出第一个目标文件。在 找寻的过程中，如果出现错误，比如最后被依赖的文件找不到，那么make就会直接退出，并报错，而对于所定义的命令的错误，或是编译不成功，make根本不理。make只管文件的依赖性。

像 `clean` 这种，没有被第一个目标文件直接或间接关联，那么它后面所定义的命 令将不会被自动执行，不过，我们可以显示要make执行。即命令—— `make clean` ，以此来清除所有 的目标文件，以便重编译。

如果这个工程已被编译过了，当我们修改了其中一个源文件，比如 `file.c` ， 那么根据我们的依赖性，我们的目标 `file.o` 会被重编译（也就是在这个依性关系后面所定义的命令）， 于是 `file.o` 的文件也是最新的啦，于是 `file.o` 的文件修改时间要比 `edit` 要新，所 以 `edit` 也会被重新链接了（详见 `edit` 目标文件后定义的命令）。比如我们改变了 `command.h` ，那么， `kdb.o` 、 `command.o` 和 `files.o` 都 会被重编译，并且， `edit` 会被重链接。



### Makefile中使用变量



总所周知，变量是个好东西0.0

在Makefile中使用变量有利于我们对其有更好的维护性。

跟通常编程一样，变量名最好简(jian)洁(dan)易(cu)懂(bao)，有利于人们明白其代表的含义。

在上面例子中，edit后面的一串便可以进行替代了。

```makefile
edit : main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o
    cc -o edit main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o
```



当我们需要添加文件时，需要修改多个地方，使用变量能很好地为我们节省时间。

只需在前面声明变量就好，比如`objects`，`objs`，`obj`等等，只要能很好明白其代表的含义就行

```makefile
objs = main.o kbd.o command.o display.o \
     insert.o search.o files.o utils.o
     
edit : $(objs)
    cc -o edit $(objs)
main.o : main.c defs.h
    cc -c main.c
kbd.o : kbd.c defs.h command.h
    cc -c kbd.c
command.o : command.c defs.h command.h
    cc -c command.c
display.o : display.c defs.h buffer.h
    cc -c display.c
insert.o : insert.c defs.h buffer.h
    cc -c insert.c
search.o : search.c defs.h buffer.h
    cc -c search.c
files.o : files.c defs.h buffer.h command.h
    cc -c files.c
utils.o : utils.c defs.h
    cc -c utils.c
clean :
    rm edit $(objs)
```



比如这样，当我们需要添加新的 `.o` 文件的时候，只需要修改`objs =	...   `就行了



### Makefile的自动推导



GNU的make可以自动推到文件及文件依赖关系后面的命令，于是我们就没必要去在每一个 `.o` 文件后都写上类似的命令，因为，我们的make会自动识别，并自己推导命令。

只要make看到一个 `.o` 文件，它就会自动的把 `.c` 文件加在依赖关系中，如果make找到一个`whatever.o` ，那么 `whatever.c` 就会是 `whatever.o` 的依赖文件。并且 `cc -c whatever.c` 也会被推导出来，于是，我们的makefile再也不用写得这么复杂。我们的 新makefile又出炉了。



```makefile
objects = main.o kbd.o command.o display.o \
    insert.o search.o files.o utils.o

edit : $(objects)
    cc -o edit $(objects)

main.o : defs.h
kbd.o : defs.h command.h
command.o : defs.h command.h
display.o : defs.h buffer.h
insert.o : defs.h buffer.h
search.o : defs.h buffer.h
files.o : defs.h buffer.h command.h
utils.o : defs.h

.PHONY : clean
clean :
    rm edit $(objects)
```

这种方法，也就是make的“隐晦规则”。

`.PHONY` 表示 `clean` 是个伪目标 文件。



#### 另类风格的Makefile



既然我们的make可以自动推导命令，那么我看到那堆 `.o` 和 `.h` 的依赖就有点不爽，那么多的 重复的 `.h` ，能不能把其收拢起来，好吧，没有问题，这个对于make来说很容易，谁叫它提供了自动 推导命令和文件的功能呢？来看看最新风格的makefile吧。

```makefile
objects = main.o kbd.o command.o display.o \
    insert.o search.o files.o utils.o

edit : $(objects)
    cc -o edit $(objects)

$(objects) : defs.h
kbd.o command.o files.o : command.h
display.o insert.o search.o files.o : buffer.h

.PHONY : clean
clean :
    rm edit $(objects)
```



### 清空目标文件的规则



每个Makefile中都应该写一个清空目标文件（ `.o` 和执行文件）的规则，这不仅便于重编译，也很 利于保持文件的清洁。

```makefile
clean:
    rm edit $(objects)
```

更为稳健的做法是：

```makefile
.PHONY : clean
clean :
    -rm edit $(objects)
```

前面说过， `.PHONY` 表示 `clean` 是一个“伪目标”。而在 `rm` 命令前面加了一个小减号的 意思就是，也许某些文件出现问题，但不要管，继续做后面的事。当然， `clean` 的规则不要放在文件 的开头，不然，这就会变成make的默认目标，相信谁也不愿意这样。不成文的规矩是——“clean从来都是放 在文件的最后”。





### Makefile里有什么？

Makefile里主要包含了五个东西：显式规则、隐晦规则、变量定义、文件指示和注释。

1. 显式规则。显式规则说明了如何生成一个或多个目标文件。这是由Makefile的书写者明显指出要生成的 文件、文件的依赖文件和生成的命令。

2. 隐晦规则。由于我们的make有自动推导的功能，所以隐晦的规则可以让我们比较简略地书写 Makefile，这是由make所支持的。

3. 变量的定义。在Makefile中我们要定义一系列的变量，变量一般都是字符串，这个有点像你C语言中的 宏，当Makefile被执行时，其中的变量都会被扩展到相应的引用位置上。

4. 文件指示。其包括了三个部分，一个是在一个Makefile中引用另一个Makefile，就像C语言中 的include一样；另一个是指根据某些情况指定Makefile中的有效部分，就像C语言中的预编译#if一 样；还有就是定义一个多行的命令。有关这一部分的内容，我会在后续的部分中讲述。

5. 注释。Makefile中只有行注释，和UNIX的Shell脚本一样，其注释是用 `#` 字符，这个就 像C/C++中的 `//` 一样。如果你要在你的Makefile中使用 `#` 字符，可以用反斜杠进行转义，如： `\#` 。

   

   还有的就是在Makefile中的命令，必须要以 `Tab` 键开始。



### Makefile的文件名



因为make程序已被用户多次重/改写，其中包括几次用相同的文件格式和算法原理重新编写，并且依照不同需要添加了一些不常见的改良。

现在的版本，大致是 **GNU make**，**BSD make**，**Microsoft nmake**。

默认的情况下，gnu的make命令会在当前目录下按顺序找寻文件名为“GNUmakefile”、 “makefile”、“Makefile”的文件，找到了解释这个文件。在这三个文件名中，最好使用“Makefile” 这个文件名，因为，这个文件名第一个字符为大写，这样有一种显目的感觉。最好不要用“GNUmakefile”， 这个文件是GNU的make识别的。有另外一些make只对全小写的“makefile”文件名敏感，但是基本上来说， 大多数的make都支持“makefile”和“Makefile”这两种默认文件名。

当然，你可以使用别的文件名来书写Makefile，比如：“Make.Linux”，“Make.Solaris” ，“Make.AIX”等，如果要指定特定的Makefile，你可以使用make的 `-f` 和 `--file` 参数， 如： `make -f Make.Linux` 或 `make --file Make.AIX` 。



### 引用其他的Makefile

在Makefile使用 `include` 关键字可以把别的Makefile包含进来，这很像C语言的 `#include` ，被包含的文件会原模原样的放在当前文件的包含位置。 `include` 的语法是：

```makefile
include <filename>
```

`filename` 可以是当前操作系统Shell的文件模式（可以包含路径和通配符）。

在 `include` 前面可以有一些空字符，但是绝不能是 `Tab` 键开始。 `include` 和 `<filename>` 可以用一个或多个空格隔开。举个例子，你有这样几个Makefile： `a.mk` 、 `b.mk` 、 `c.mk` ，还有一个文件叫 `foo.make` ，以及一个变量 `$(bar)` ，其包含 了 `e.mk` 和 `f.mk` ，那么，下面的语句：

```makefile
bar	=	e.mk	f.mk
include foo.make *.mk $(bar)
```

等价于：

```makefile
include foo.make a.mk b.mk c.mk e.mk f.mk
```

make命令开始时，会找寻 `include` 所指出的其它Makefile，并把其内容安置在当前的位置。就好 像C/C++的 `#include` 指令一样。如果文件都没有指定绝对路径或是相对路径的话，make会在当前目 录下首先寻找，如果当前目录下没有找到，那么，make还会在下面的几个目录下找：

1. 如果make执行时，有 `-I` 或 `--include-dir` 参数，那么make就会在这个参数所指定的目 录下去寻找。
2. 如果目录 `<prefix>/include` （一般是： `/usr/local/bin` 或 `/usr/include` ）存在的话，make也会去找。

如果有文件没有找到的话，make会生成一条警告信息，但不会马上出现致命错误。它会继续载入其它的 文件，一旦完成makefile的读取，make会再重试这些没有找到，或是不能读取的文件，如果还是 不行，make才会出现一条致命信息。如果你想让make不理那些无法读取的文件，而继续执行，你可以 在include前加一个减号“-”。如：

```
-include <filename>
```

其表示，无论include过程中出现什么错误，都不要报错继续执行。和其它版本make兼容的相关命令 是sinclude，其作用和这一个是一样的。



### 环境变量MAKEFILES

如果你的当前环境中定义了环境变量 `MAKEFILES` ，那么，make会把这个变量中的值做一个类似于`include` 的动作。这个变量中的值是其它的Makefile，用空格分隔。只是，它和 `include` 不 同的是，从这个环境变量中引入的Makefile的“目标”不会起作用，如果环境变量中定义的文件发现 错误，make也会不理。

但是在这里我还是建议不要使用这个环境变量，因为只要这个变量一被定义，那么当你使用make时， 所有的Makefile都会受到它的影响，这绝不是你想看到的。在这里提这个事，只是为了告诉大家，也许 有时候你的Makefile出现了怪事，那么你可以看看当前环境中有没有定义这个变量。



### make的工作流程

GNU的make工作时的执行步骤如下：（想来其它的make也是类似）

1. 读入所有的Makefile。
2. 读入被include的其它Makefile。
3. 初始化文件中的变量。
4. 推导隐晦规则，并分析所有规则。
5. 为所有的目标文件创建依赖关系链。
6. 根据依赖关系，决定哪些目标要重新生成。
7. 执行生成命令。

1-5步为第一个阶段，6-7为第二个阶段。第一个阶段中，如果定义的变量被使用了，那么，make会把其展 开在使用的位置。但make并不会完全马上展开，make使用的是拖延战术，如果变量出现在依赖关系的规则 中，那么仅当这条依赖被决定要使用了，变量才会在其内部展开。

当然，这个工作方式你不一定要清楚，但是知道这个方式你也会对make更为熟悉。有了这个基础，后续部分 也就容易看懂了。









## 书写规则





