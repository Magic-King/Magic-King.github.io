---
title: ShadowSocks-SourceCode-Learning
date: 2020-01-30 21:39:16
tags: [ShadowSocks, Network]
categories: Network
description:
password:
---











# 关于ShadowSocks的学习



对待科学上网的工具，既然开源的话，就要有科学的精神对其进行学习。



其GitHub官方网址：https://github.com/shadowsocks

本文学习的源码来自：https://github.com/shadowsocks/shadowsocks

版本是2.9.1的python版本



> 参考：
>
> [shadowsocks 源码分析：整体结构](https://bitmingw.com/2017/03/25/shadowsocks-code-analysis-overview/)
>
> [你也能写个 Shadowsocks](https://segmentfault.com/a/1190000011862912)
>
> [shadowsocks源码分析：ssserver](https://huiliu.github.io/2016/03/19/shadowsocks.html)
>
> [shadowsocks 源码阅读](https://0x01.io/2016/02/28/shadowsocks-源码阅读/)
>
> [Shadowsocks 源码分析——协议与结构](https://loggerhead.me/posts/shadowsocks-yuan-ma-fen-xi-xie-yi-yu-jie-gou.html)
>
> [shadowsocks客户端源码分析]([https://blog.gfkui.com/2018/04/29/shadowsocks%E5%AE%A2%E6%88%B7%E7%AB%AF%E6%BA%90%E7%A0%81%E5%88%86%E6%9E%90/index.html](https://blog.gfkui.com/2018/04/29/shadowsocks客户端源码分析/index.html))
>
> 





## 关于SOCKS协议



ShadowSocks的数据传输时建立在SOCK5协议之上，SOCKS5 是 TCP/IP 层面的网络代理协议。

ss-server 端解密出来的数据就是采用 SOCKS5 协议封装的，通过 SOCKS5 协议 ss-server 端能读出本机软件想访问的服务的真正地址以及要传输的原数据



> 关于Socks5学习：
>
> [socks5 协议简介](http://zhihan.me/network/2017/09/24/socks5-protocol/)
>
> [HTTP协议和SOCKS5协议](https://www.cnblogs.com/yinzhengjie/p/7357860.html)
>
> [socks-wiki](https://zh.wikipedia.org/wiki/SOCKS)
>
> 



socks是一种网络传输协议，主要用于客户端与外网服务器之间通讯的中间传递。根据OSI七层模型来划分，SOCKS属于会话层协议，位于表示层与传输层之间。

socks5协议将socks4协议扩展：

* 对UDP连接的支持
* 多种用户身份验证方式和通信加密方式
* 将寻址方式扩展为包含域名和v6 IP地址（即IPv6）



socks协议的设计初衷是在保证网络隔离的情况下，提高部分人员的网络访问权限。但是他却被发现了新的用途：突破网络通信限制，这和该协议的设计初衷正好相反。





#### Socks5协议流程

![](ShadowSocks-SourceCode-Learning/1.png)



建立TCP连接后，客户端需要先发送请求来协商版本及认证方式，详细可见[rfc1928](https://www.ietf.org/rfc/rfc1928.txt)







## Shadowsocks原理



![](ShadowSocks-SourceCode-Learning/2.png)



- **PC**是需要利用shadowsocks代理的应用；
- **SS Local**：为shadowsocks客户端，通常运行在PC/手机上（也可以运行在任务PC可 以到达的位置），用于与shadowsocks服务端建立连接。
- **GFW**：你懂的
- **ss server**：shadowsocks服务端，与ss local通讯，完成ss local请 求的访问，并将返回数据加密返回给ss local





混淆时实在ClientHello阶段，即第1阶段时进行混淆，加入jiade目标网址







## shadowsocks源码分析



shadowsocks文件树形结构图如下

```

├── .gitignore
├── .travis.yml
├── CHANGES
├── CONTRIBUTING.md
├── debian
│   ├── changelog
│   ├── compat
│   ├── config.json
│   ├── control
│   ├── copyright
│   ├── docs
│   ├── init.d
│   ├── install
│   ├── rules
│   ├── shadowsocks.default
│   ├── shadowsocks.manpages
│   ├── source
│   │   └── format
│   ├── sslocal.1
│   └── ssserver.1
├── Dockerfile
├── LICENSE
├── MANIFEST.in
├── README.md
├── README.rst
├── setup.py
├── shadowsocks
│   ├── asyncdns.py
│   ├── common.py
│   ├── crypto
│   │   ├── __init__.py
│   │   ├── openssl.py
│   │   ├── rc4_md5.py
│   │   ├── sodium.py
│   │   ├── table.py
│   │   └── util.py
│   ├── daemon.py
│   ├── encrypt.py
│   ├── eventloop.py
│   ├── __init__.py
│   ├── local.py
│   ├── lru_cache.py
│   ├── manager.py
│   ├── server.py
│   ├── shell.py
│   ├── tcprelay.py
│   └── udprelay.py
├── tests
├─tests
│  ├──  aes-cfb1.json
│  ├──  aes-cfb8.json
│  ├──  aes-ctr.json
│  ├──  aes.json
│  ├──  assert.sh
│  ├──  chacha20-ietf.json
│  ├──  chacha20.json
│  ├──  client-multi-server-ip.json
│  ├──  coverage_server.py
│  ├──  fastopen.json
│  ├──  gen_multiple_passwd.py
│  ├──  graceful.json
│  ├──  graceful_cli.py
│  ├──  graceful_server.py
│  ├──  ipv6-client-side.json
│  ├──  ipv6.json
│  ├──  jenkins.sh
│  ├──  nose_plugin.py
│  ├──  rc4-md5-ota.json
│  ├──  rc4-md5.json
│  ├──  salsa20-ctr.json
│  ├──  salsa20.json
│  ├──  server-dnsserver.json
│  ├──  server-multi-passwd-client-side.json
│  ├──  server-multi-passwd-empty.json
│  ├──  server-multi-passwd-performance.json
│  ├──  server-multi-passwd-table.json
│  ├──  server-multi-passwd.json
│  ├──  server-multi-ports.json
│  ├──  setup_tc.sh
│  ├──  table.json
│  ├──  test.py
│  ├──  test_command.sh
│  ├──  test_daemon.sh
│  ├──  test_graceful_restart.sh
│  ├──  test_large_file.sh
│  ├──  test_udp_src.py
│  ├──  test_udp_src.sh
│  ├──  workers.json
│  │
│  ├─libsodium
│  │    └── install.sh
│  │
│  └─socksify
│       ├── install.sh
│       └── socks.conf
|
└── utils
    ├── autoban.py
    ├── fail2ban
    │   └── shadowsocks.conf
    └── README.md
```



有过python工程经验（类似于Flask）很明显得知，工程核心代码位于`shadowsocks`里，其他提供了打包测试功能。





对于核心代码：

```
├── shadowsocks
│   ├── asyncdns.py
│   ├── common.py
│   ├── crypto
│   │   ├── __init__.py
│   │   ├── openssl.py
│   │   ├── rc4_md5.py
│   │   ├── sodium.py
│   │   ├── table.py
│   │   └── util.py
│   ├── daemon.py
│   ├── encrypt.py
│   ├── eventloop.py
│   ├── __init__.py
│   ├── local.py
│   ├── lru_cache.py
│   ├── manager.py
│   ├── server.py
│   ├── shell.py
│   ├── tcprelay.py
│   └── udprelay.py
```



- **tcprelay.py**提供了类TCPRelay, TCPRelayHandler来处理TCP代理连接
- **udprelay.py**提供了类UDPRelay，UDPRelayHandler来处理UDP代理连接
- **eventloop.py**提供了类EventLoop对`epoll`, `kqueue`, `select`方法的包装，提供统一的IO复用接口
- **encrypt.py**提供加密解密相关接口
  - 具体的加密实现在crypto文件夹中实现
- **daemon.py**：用于实现守护进程；
- **shell.py**：读取命令行参数，检查配置
- **common.py**包含一些通用接口
- **lru_cache.py**：实现了LRU缓存
- **server.py**是服务端入口ssserver；
- **local.py**是客户端入口sslocal；











