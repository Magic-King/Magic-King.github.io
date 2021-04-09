---
title: "Mit6.828"
date: 2021-04-04T10:35:58+08:00
draft: false
tags: []
categories: [os]
description:
---





## 0x00 序



小菜鸡一直想复习一下操作系统，总感觉当初跟着老师学操作系统的时候，仿佛想小学跟着老师背语文一样，枯燥而又难理解。在学完大多课程之后，才发现操作系统是如此的重要，也正好在网上看到了MIT 6.828这门操作系统神课，就想着跟着这门课，加深我对操作系统的理解，以便对计算机的整体架构有着进一步的认识。



> Reference：
>
> [Mit 6.828: Operating System Engineering](https://pdos.csail.mit.edu/6.828/2018/index.html) ：课程官网
>
> [Mit 6.828 Schedule](https://pdos.csail.mit.edu/6.828/2018/schedule.html) ：官方课程安排，据说跟着走就行了
>
> [Mit 6.828 Reference](https://pdos.csail.mit.edu/6.828/2018/reference.html) ： 课程需要的一些资料文档之类的
>
> Github上两个大佬的总结
>
> [SmallPond/MIT6.828_OS - Github](https://github.com/SmallPond/MIT6.828_OS) ：原博客（[MIT6.828-神级OS课程-要是早遇到，我还会是这种 five 系列](https://zhuanlan.zhihu.com/p/74028717)）
>
> [woai3c/MIT6.828 -Github](https://github.com/woai3c/MIT6.828) ：原博客（[强烈推荐的两个神级教学项目: nand2tetris 与 MIT6.828](https://segmentfault.com/a/1190000022185065)）
>
> [MIT 6.828：实现操作系统 ](https://github.com/Anarion-zuo/AnBlogs/tree/master/6.828)





## 0x01 Overview



#### 6.828: Learning by doing

Mit 6.828主要会学习操作系统的基本设计和实现方法，其主题包括：虚拟内存、线程、上下文切换、内核、中断、系统调用、进程间通信、并发、软硬件交互。

实验所用的xv6：X86 version 6，1970年的Unix的版本6的重新实现

实验目标：各个lab相互构建、结合，形成一个原始的操作系统，可以在操作系统上通过自己实现的shell运行简单的命令。

我们所构建的操作系统JOS，具有类似unix的功能，但是是以外核的方式实现的（即unix函数大多在用户层实现，而非内核层）。

JOS操作系统的主要部分有：boot引导、内存管理、用户环境、抢先式多任务、文件系统、spawn库函数、shell、网络驱动

> 1. Booting
> 2. Memory management
> 3. User environments
> 4. Preemptive multitasking
> 5. File system, spawn, and shell
> 6. Network driver







## 0x02 Lab 1: Booting a PC



>  https://pdos.csail.mit.edu/6.828/2018/labs/lab1/



lab1有三个部分

* part1：熟悉x86汇编、qemu x86模拟器、PC boot引导过程
* part2：阅读我们6.828课程的内核引导部分(`lab/boot`目录下)
* part3：研究我们最初的JOS内核模板(`lab/kernal`目录下)



#### 软件准备

一个是得有`git`这个工具，第二个便要求是有x86架构的机器( `$ uname -a` 中能看到 `i386 GNU/Linux` 或者 `i686 GNU/Linux` 或者 `x86_64 GNU/Linux`.)

```shell
$ git clone https://pdos.csail.mit.edu/6.828/2018/jos.git lab
```

然后，做完实验使用`git commit -am "message"`提交，`git diff`查看提交的记录变化



试了试，用windows的qemu+clion还是没法直接跑，还是老老实实地搞个ubuntu16.04 32bit来完成课程把

在下面这个tools里有介绍课程的工具链应该如何构建安装

我在ubuntu16.04 32bit环境下，是可以直接安装实验环境的，不用像给的参考一样，一个个下源码包构建安装。不过还是拉取了MIT官方的git仓库来安装qemu

```shell
$ git clone https://github.com/mit-pdos/6.828-qemu.git qemu
$ cd qemu
$ ./configure --disable-kvm --disable-werror --target-list="i386-softmmu x86_64-softmmu"
$ make
$ sudo make install
```





> https://pdos.csail.mit.edu/6.828/2018/tools.html
>
> 中文参考以下
>
> https://www.cnblogs.com/gatsby123/p/9746193.html



至于工具怎么用，可以看官方的这篇文章：[6.828 lab tools guide](https://pdos.csail.mit.edu/6.828/2018/labguide.html)

> 简略摘要：
>
> **JOS MakeFile** ：提供了各种方式运行JOS系统，用这些方式运行的qemu，可以被gdb所连接调试。一旦qemu开始运行，就可以在`./lib`目录下运行`gdb`命令，用他所提供的`./gdbinit`可以将gdb直接指向qemu，加载内核符号，切换32bit或16bit模式。退出gdb会关闭qemu。
>
> * `make qemu` ：编译所有内容，并在新建窗口使用VGA控制台和终端的串行控制台启动qemu。退出可以关闭VGA窗口或`ctrl+C` 
> * `make qemu-nox` ：和`make qemu`相似，但只运行串行终端，这个在需要ssh连接时十分有用，因为VGA窗口会占用大量带宽
> * `make qemu-gdb` ：和`make qemu`相似，在机器的第一条指令停止，并等待gdb连接，而不是被动地在任何时候接受gdb连接
> * `make qemu-nox-gdb` ：`qemu-nox` 和`qemu-gdb`的结合
> * `make run-name` ：运行用户程序，比如`make run-hello` 会运行`./user/hello.c` (lib3+)
> * `make run-name-nox`, `run-name-gdb`, `run-name-gdb-nox ` ：`run-name`的扩展应用，含义与上面的方式一样
>
> makefile的一些选项
>
> * `make V=1 ...`  ：详细模式，打印出每条被执行的指令，包括指令参数
> * `make V=1 grade` ：在任何失败测试后停止，并将QEMU输出放在 `jos.out`中
> * `make QEMUEXTRA='args' ...` ：给qemu的特殊参数
>
> 
>
> JOS  `./obj/`目录
>
> * `obj/boot/boot.asm`, `obj/kern/kernel.asm`, `obj/user/hello.asm`, etc.
>   bootloader, kernel, and user programs的汇编代码
> * `obj/kern/kernel.sym`, `obj/user/hello.sym`, etc.
>   用户和内核的符号表
> * `obj/boot/boot.out`, `obj/kern/kernel`, `obj/user/hello`, etc
>   链接至内核和用户程序的elf程序镜像，包括gdb所使用的符号信息
>
> 
>
> GDB : [GDB manual](http://sourceware.org/gdb/current/onlinedocs/gdb/)
>
> * `ctrl+c` ：中断机器，并将当前指令在gdb中断
> * `c` or `continue` ： 继续执行指令，直至下个断点或`ctrl+c`
> * `si` or `stepi `：执行一条机器指令
> * `b function` or `b file:line` ：在给定函数或行数下断点
> * `b *addr`  ： 在EIP地址下断点
> * `set print pretty`：让数组和结构体输出更好看
> * `info registers `：打印通用寄存器的值，eip、eflags
> * `x/Nx addr` ：展示一个从addr开始的N字的十六进制转储
> * `x/Ni addr` 展示从addr开始的N条汇编指令，使用eip作为addr将在当前指令指针处显示指令
> * `symbol-file file` ：切换到file的符号文件
> * `thread n` ：让gdb聚焦于一个线程，这个命令将监控切换到线程n
> * `info threads` ： 打印出所有线程，包括他们的状态
>
> 
>
> QEMU
>
> * `xp/Nx paddr` ：展示从paddr开始的物理地址的N字十六进制转储
>
> * `info register` ： 展示机器的内部寄存器状态。这包括段选择器，本地，全局和中断描述符表以及任务寄存器的机器的**隐藏**段状态，此隐藏状态是在加载段选择器时虚拟CPU从GDT / LDT读取的信息
>   如下，这是JOS内核在lab1运行时的各状态
>
>   ```
>   CS =0008 10000000 ffffffff 10cf9a00 DPL=0 CS32 [-R-]
>   ```
>
>   `CS =0008` ：代码选择器的可见部分，我们正在使用段0x8，意味着我们正在引用全局描述符表（`0x8 & 4 = 0`），而我们当前的CPL(特权级别)为`0x8&3 = 0`
>
>   `10000000` ： 这个段基址，线性地址(Linear address)  = 逻辑地址(logical address) +  0x10000000
>
>   `ffffffff` ：段地址的限制，超过`0xffffffff`地址的地址会造成段错误
>
>   `10cf9a00` ： 这个段的原始标志，在接下来的新段中qemu会帮助我们解码这个东西
>
>   `DPL=0` ： 段的特权级别，当代码有着0级别的特权时才能加载这个段
>
>   `CS32` ：这是32bit模式下的段
>
>   `[-R-]` ：段是只读的
>
> * `info mem` ：展示虚拟内存的映射表和访问权限
>
> * `info pg` ：打印出当前页表结构
>
> * `make QEMUEXTRA='-d int' ...` ： 打印出所有中断和当时的寄存器转储到文件`qemu.log`
>
> 
>
> 

