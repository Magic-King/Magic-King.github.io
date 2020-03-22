---
title: Meltdown And Hardware Security
date: 2020-03-21 15:57:45
tags: [CVE, hardware]
categories: [Hardware, Security, CPU]
description:
password:
---













## 0x00 序



由于新型冠状病毒，美股多次熔断，我们的安全课也提到了熔断一词：Meltdown，将其与硬件安全联系在了一起

Meltdown，源自于2018年1月3日的两组CPU芯片漏洞之一

> 2018年1月3日，Google Project Zero（GPZ）团队安全研究员Jann Horn在其团队博客中爆出CPU芯片的两组漏洞，分别是Meltdown与Spectre。

**Meltdown对应CVE-2017-5754（乱序执行缓存污染），Spectre对应CVE-2017-5753（边界检查绕过）与CVE-2017-5715（分支目标注入）。看CVE编号就能知道，这两组漏洞早在2017年6月就已经由GPZ团队向英特尔提交，而在差不多时间由Lipp等人发布的论文Meltdown与Spectre Attacks也详细描述了这一攻击，从文中的声明来看，Lipp等人与GPZ团队似乎是独立发现了这两组漏洞。**

Meltdown漏洞影响几乎所有的Intel CPU和部分ARM CPU，而Spectre则影响所有的Intel CPU和AMD CPU，以及主流的ARM CPU。从个人电脑、服务器、云计算机服务器到移动端的智能手机，都受到这两组硬件漏洞的影响。

总所周知，软件更换肯定比硬件更换容易，软件某个版本有了bug或漏洞，我们大可换其版本，重装就完事了，或者不用他且罢，但是对于硬件级的漏洞，我们也只能从软件层面修复打补丁，或者也就只能等着修复了漏洞的新版CPU发布了，不过换CPU也是一件麻烦事。



> 参考：
>
> [Meltdown and Spectre](https://meltdownattack.com/)
>
> [Github - IAIK / meltdown](https://github.com/IAIK/meltdown)
>
> [Github - paboldin / meltdown-exploit](https://github.com/paboldin/meltdown-exploit)
>
> [Github - speed47 / spectre-meltdown-checker](https://github.com/speed47/spectre-meltdown-checker)
>
> [Meltdown.pdf——漏洞发现者的论文](Meltdown-And-Hardware-Security/meltdown.pdf)
>
> [Meltdown.pdf——论文翻译](https://blog.csdn.net/jus3ve/article/details/79202105)
>
> 
>
> [一步一步理解CPU芯片漏洞：Meltdown与Spectre](https://www.freebuf.com/articles/system/159811.html)：其中分析的exp是这个[Github - paboldin / meltdown-exploit](https://github.com/paboldin/meltdown-exploit)
>
> [Meltdown漏洞利用解读（Part 1）：基础篇](https://www.anquanke.com/post/id/148119)
>
> [首发：Meltdown漏洞分析与实践](https://mp.weixin.qq.com/s/zlspXeDGlAEzVsq2h6gg8w)
>
> 
>
> 修复：
>
> [史上最大CPU漏洞Meltdown & Spectre 影响与修复指南](https://www.freebuf.com/articles/system/159577.html)
>
> 







## 0x01 漏洞原理











我现在只是懂了他为什么这么做，但是我还想懂得他为什么会想到这么做（要去思考1.他做了什么2.他为什么这么做3.他为什么这样想4.忘了哪看到的逻辑层次(绝对不是百度搜出来的那个)

//TODO

[libkdump](https://github.com/IAIK/meltdown/tree/master/libkdump)这是作者开源出来的exp库，我们可以通过阅读(//TODO：等我对操作系统有着更深层次的理解时，来分析代码)并编译它，或者直接利用他编译后的库来使用







## 0x0 漏洞危害



Meltdown与Spectre本质上都是基于缓存侧信道的攻击。

**Meltdown与Spectre主要用于信息泄露**，并不能对目标内存地址进行任意修改。攻击者必须要有执行权限才能进行攻击，对于一般用户只要不被执行恶意代码（比如访问恶意网站），就不会被Meltdown与Spectre攻击。但是在云端，攻击者可以租赁虚拟机来执行攻击者想要执行的任意代码，从而获取宿主物理机以及其它租户的信息，这对云服务商的冲击还是非常大的。



> 文中的思考问题：
>
> ### 值得进一步思考的问题
>
> > 1. 该利用代码一次只能探测一个字节的数据，如果在内核数据还没读取完整之前处理器已经处理异常了该怎么办？
> >
> > 2. 探测数组target_array是否可以不用设置成256\*4KB，设置成512\*2KB，1024\*1KB效果会如何？
> >
> > 3. 探测数组target_array是个大数组，占用多个内存页面，是否容易被检测到？
> >    个人认为：应该是不容易被检测到的，如果数据都在里面的话，多次flush的时间应该会保持不变，但是应该可以把现在内存中的所有信息dump出来
> >
> > 

