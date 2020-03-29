---
title: lsp-hijack
date: 2020-03-25 14:17:01
tags:
categories:
description:
password:
---

















## 序



原本只是想白嫖免费的腾讯加速器，用完卸了，没想到还卸载不了。

其中有两个dll删除时总是显示正在运行中，用`tasklist /m xxx.dll`查看运行dll的进程，一一终止，然后把他删了。

然后发现，我网络炸了？？？

ssr也被加速器顺便给炸了，显示绑定了另外一个端口





> 参考：
>
> [分层服务提供程序](https://baike.baidu.com/item/LSP/2970?fromtitle=LSP协议&fromid=807563&fr=aladdin)
>
> [LSP-wiki](https://en.wikipedia.org/wiki/Layered_Service_Provider)
>
> [LSP劫持与网络数据转发代理服务器的心得笔记](https://blog.csdn.net/sspdfn/article/details/86520816)
>
> 







Winsock LSP全称Windows Socket Layered Service Provider(分层服务提供商)，它是Windows底层网络Socker通信需要经过的大门。一些流氓软件可以把自已加进去，就可以截取、访问、修改网络的数据包，可以随意添加广告，还能获取你的浏览习惯.如果加进的是木马，后果可想而知。而且因为LSP工作在底层，所以无论你用什么浏览器，都逃不了经过它。而LSP中的dll文件被删除后，就会出现无法上网的情况。

Winsock LSP 可用于非常广泛的实用用途，包括 Internet [家长控制](https://baike.baidu.com/item/家长控制/1466292) (parental control) 和 Web 内容筛选。在以前版本的 Windows XP 中，删除不正确的（也称为“buggy”）LSP 可能会导致注册表中的 Winsock 目录损坏，潜在的导致所有网络连接的丢失。 LSP就是TCP/IP等协议的接口．LSP用在正途上可以方便程序员们编写监视系统网络通讯情况的Sniffer，可是现在常见的LSP都被用于[浏览器劫持](https://baike.baidu.com/item/浏览器劫持/1798451)。



现在大多加速器，尤其以腾讯系为主的大多应用（腾讯加速器，TGP(现wegame)，都是以lsp劫持到自己的节点进行加速

非正常卸载(比如强行删除加速器文件)通常会带来无法上网的问题。



> 如何编写lsp劫持：
>
> https://blog.csdn.net/Aaron133/article/details/78028942
>
> https://www.cnblogs.com/freesec/p/6541725.html
>
> https://www.cnblogs.com/hjbf/p/10195244.html
>
> https://blog.csdn.net/sspdfn/article/details/86520816
>
> 





windows10 解决办法

```sh
$ netsh winsock reset
```



PS：用ping检查网络状况

```sh
ping 127.0.0.1(判断本地tcp/ip协议是否正常)，
#ping  本地ip (判断网卡是否正常)，
ping  gateway_ip # 网关(判断路由器是否正常)，
ping  14.215.177.39 # 外网ip，百度的ip (判断网络连接是否正常),  
ping  baidu.com # 外网域名(判断DNS是否正常)，
```

