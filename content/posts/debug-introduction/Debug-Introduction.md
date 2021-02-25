---
title: Debug-Introduction
date: 2020-01-25T16:05:34+08:00
tags: [debug, reverse]
categories: [reverse]
description:
password:
---



# Debug 入门



在以前打ACM的时候，debug全靠`printf`和大脑跑程序，但是现在做逆向的时候发现了debug的新知识。





## 单步调试



现在基本主流的IDE都提供了debug模式，其中`step into`，`step over`，`step out`是三个主流的函数，也是ollydbg动态调试中最重要的武器。

其中概念如下：

* step into：Step to the next line excuted（F7）
  单步执行，遇到子函数就进入并且继续单步执行（简而言之，进入子函数）；

* step over：Step to the next line in this file（F8）
  在单步执行时，在函数内遇到子函数时不会进入子函数内单步执行，而是将子函数整个执行完再停止，也就是把子函数整个作为一步。有一点,经过我们简单的调试,在不存在子函数的情况下是和step into效果一样的（简而言之，越过子函数，但子函数会执行）。

* step out：Step to the first line executed after returning from this method
  当单步执行到子函数内时，用step out就可以执行完子函数余下部分，并返回到上一层函数。
  

简单来说，`step into`就是逐行运行，当碰到函数时，会进入函数内部进行执行；而`step over`是直接执行到断点处，即不会每行都停下来；`step out `是在执行到子函数的任意部分时，使用该函数会直接执行到该函数的返回语句，但是如果子函数剩下部分仍有断点，则执行到断点部分停下。

在看《有趣的二进制》时，发现了一个简洁的解释：

* Step into：跳入：调用函数时进入函数内部
* Step over：跳出，调用函数时不进入函数内部，**将函数作为一条指令来执行**

（可以直接在pycharm进行实验，实验代码如下）

```python
#!/usr/bin/env python
# -*- coding:utf-8 -*-


def add(a, b):
    c = a + b
    return c


def divide(a, b):
    c = a / b
    return c


def debug_test():
    x = 8
    y = 2
    sum = add(x, y)
    d = divide(x, y)
    print(sum, d)
    return 0


if __name__ == '__main__':
    ans = debug_test()
    print(ans)
```



### Ollydbg

在OD中：

* Step into：F7：执行一句OP code，若遇到CALL，进入函数代码内部
* Step over：F8：执行一句OP code，若遇到CALL，仅执行函数自身，不跟随进入



visual studio的调试：https://blog.csdn.net/boylinux/article/details/7659759

在visual studio里，F11为step into，F10为Step over



## 汇编语言：跳转指令



> 参考：https://blog.csdn.net/weibo1230123/article/details/84236308



ARM的跳转指令如下

* 无条件跳转: JMP;
* 根据 CX、ECX 寄存器的值跳转: `JCXZ`(CX 为 0 则跳转)、`JECXZ`(ECX 为 0 则跳转);
* 根据 EFLAGS 寄存器的标志位跳转



根据标志位跳转的指令如下：

```assembly

JE   ;等于则跳转
JNE  ;不等于则跳转
 
JZ   ;为 0 则跳转
JNZ  ;不为 0 则跳转
 
JS   ;为负则跳转
JNS  ;不为负则跳转
 
JC   ;进位则跳转
JNC  ;不进位则跳转
 
JO   ;溢出则跳转
JNO  ;不溢出则跳转
 
JA   ;无符号大于则跳转
JNA  ;无符号不大于则跳转
JAE  ;无符号大于等于则跳转
JNAE ;无符号不大于等于则跳转
 
JG   ;有符号大于则跳转
JNG  ;有符号不大于则跳转
JGE  ;有符号大于等于则跳转
JNGE ;有符号不大于等于则跳转
 
JB   ;无符号小于则跳转
JNB  ;无符号不小于则跳转
JBE  ;无符号小于等于则跳转
JNBE ;无符号不小于等于则跳转
 
JL   ;有符号小于则跳转
JNL  ;有符号不小于则跳转
JLE  ;有符号小于等于则跳转
JNLE ;有符号不小于等于则跳转
 
JP   ;奇偶位置位则跳转
JNP  ;奇偶位清除则跳转
JPE  ;奇偶位相等则跳转
JPO  ;奇偶位不等则跳转
```









