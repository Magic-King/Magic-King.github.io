---
title: Data Backup
date: 2020-05-15 14:09:35
tags:
categories:
description:
password:
---







## 0x00 序



最近硬盘频繁崩溃，让我对我的电脑产生了担忧，于是就准备把上次老师说的备份来实现一下（虽然以前也有备份，但肯定没有现在电脑的资料全面）



主要工具采用的是Rsync（当时了解镜像站时了解到的一个工具，可以实现增量备份）

了解到有一个portableapp可以进行软件备份

> 通过google参考其他人的方案：
>
> 网上大多看到的工具都是：FileSync
>
> FileSync是一个开源文件夹比较和同步工具，支持windows、linux、mac
>
> 官网：https://freefilesync.org/
>
> 





------





> 参考资料：
>
> > 仅供参考的阅读资料(我觉得可能没软用)
> >
> > 存储方案：[适用于个人用户的最佳数据备份方案有哪些？](https://www.zhihu.com/question/23565277)
> >
> > [个人数据备份方案](https://www.cnblogs.com/BillySir/p/6392091.html)
> >
> > 
>
> [当前工作环境下的个人数据备份方案及实践](https://www.oheng.com/%E5%BD%93%E5%89%8D%E5%B7%A5%E4%BD%9C%E7%8E%AF%E5%A2%83%E4%B8%8B%E7%9A%84%E4%B8%AA%E4%BA%BA%E6%95%B0%E6%8D%AE%E5%A4%87%E4%BB%BD%E6%96%B9%E6%A1%88%E5%8F%8A%E5%AE%9E%E8%B7%B5/)
>
> [数据备份与灾难恢复](https://www.jianshu.com/p/2a1c339f113f)：感觉这篇更多的是针对企业的数据备份、容灾
>
> * [全平台的备份指南，让你从此重装不再难](https://sspai.com/post/56272) :极度推荐的备份方法，虽然他的本意是面对系统重装的
>
> [个人数据备份方案设计](https://maxiee.github.io/post/DataBackupmd/)
>
> [简易个人数据备份方案](https://www.yywr.net/96.yy)
>
> [软件使用 篇二：个人数据的备份经验1-通过脚本自动化备份](https://post.smzdm.com/p/507822/)
>
> [免费个人数据备份软件介绍：FreeFileSync、Syncthing](https://cloud.tencent.com/developer/news/180449)
>
> > DISM++：Dism++ 是一款 Windows 系统管理优化工具，它解决了我们安装、维护系统的一大痛点问题——自定义设置和优化。相当于一个 “一站式” 管理优化工具集。
> >
> > [Dism++ ，强大的 Windows 系统优化工具](https://zhuanlan.zhihu.com/p/37664732)
> >
> > [Dism++，也许是最强的实用工具](http://www.chuyu.me/zh-Hans/)：汉化官网，gui版本
> >
> > 之前了解的，不过之后感觉没有什么用了，已经决定使用scoop了
> >
> > 
>
> 

之前还了解过portableApps，不过感觉其界面UI不行，还是主要面向可移动应用，不过可以自己制作相关的portableApp，在其官网上都给出了教程

但是portableApps意味着就无法使用右键菜单了，也没法命令行快速启动，这是挺蛋疼的。不过这是一种可以方便移植到U盘的解决办法







## 0x01 用rsync备份



rsync是可以实现增量备份的工具。配合任务计划，rsync能实现定时或间隔同步，配合inotify或sersync，可以实现触发式的实时同步。

rsync可以实现scp的远程拷贝(`rsync`不支持远程到远程的拷贝，但`scp`支持)、`cp`的本地拷贝、`rm`删除和`ls -l`显示文件列表等功能。但需要注意的是，rsync的最终目的或者说其原始目的是实现两端主机的文件同步，因此实现的scp/cp/rm等功能仅仅只是同步的辅助手段，且rsync实现这些功能的方式和这些命令是不一样的。事实上，rsync有一套自己的算法，其算法原理以及rsync对算法实现的机制可能比想象中要复杂一些。

因此我们来介绍一波rsync



> 参考：
>
> [rsync -samba.org](https://www.samba.org/ftp/rsync/rsync.html)：官网
>
> [the rsync web pages](https://rsync.samba.org/)
>
> [rsync(1) - Linux man page](https://linux.die.net/man/1/rsync)
>
> [第2章 rsync(一)：基本命令和用法](https://www.cnblogs.com/f-ck-need-u/p/7220009.html)：全文系列在：[2.Linux 基本服务](https://www.junmajinlong.com/linux/index/)
>
> [rsync命令](https://man.linuxde.net/rsync)
>
> https://api.vaipixel.fxcdev.com/archives/216.html
>
> 



下面介绍几条常用的命令

```sh
$ rsync [OPTION]... SRC DEST
$ rsync [OPTION]... SRC [USER@]host:DEST
$ rsync [OPTION]... [USER@]HOST:SRC DEST
$ rsync [OPTION]... [USER@]HOST::SRC DEST
$ rsync [OPTION]... SRC [USER@]HOST::DEST
$ rsync [OPTION]... rsync://[USER@]HOST[:PORT]/SRC [DEST]
```



其实这命令跟ssh的转发挺像的，都是固定一个地方到另一个地方

1. 拷贝本地文件。当SRC和DES路径信息都不包含有单个冒号":"分隔符时就启动这种工作模式。如：`rsync -a /data /backup`
2. 使用一个远程shell程序(如[rsh](http://man.linuxde.net/rsh)、[ssh](http://man.linuxde.net/ssh))来实现将本地机器的内容拷贝到远程机器。当DST路径地址包含单个冒号":"分隔符时启动该模式。如：`rsync -avz *.c foo:src`
3. 使用一个远程shell程序(如rsh、ssh)来实现将远程机器的内容拷贝到本地机器。当SRC地址路径包含单个冒号":"分隔符时启动该模式。如：`rsync -avz foo:src/bar /data`
4. 从远程rsync服务器中拷贝文件到本地机。当SRC路径信息包含"::"分隔符时启动该模式。如：`rsync -av root@192.168.78.192::www /databack`
5. 从本地机器拷贝文件到远程rsync服务器中。当DST路径信息包含"::"分隔符时启动该模式。如：`rsync -av /databack root@192.168.78.192::www`
6. 列远程机的文件列表。这类似于rsync传输，不过只要在命令中省略掉本地机信息即可。如：`rsync -v rsync://192.168.78.192/www`



具体选项如下：

```sh
-v, --verbose 详细模式输出。
-q, --quiet 精简输出模式。
-c, --checksum 打开校验开关，强制对文件传输进行校验。
-a, --archive 归档模式，表示以递归方式传输文件，并保持所有文件属性，等于-rlptgoD。
-r, --recursive 对子目录以递归模式处理。
-R, --relative 使用相对路径信息。
-b, --backup 创建备份，也就是对于目的已经存在有同样的文件名时，将老的文件重新命名为~filename。可以使用--suffix选项来指定不同的备份文件前缀。
--backup-dir 将备份文件(如~filename)存放在在目录下。
-suffix=SUFFIX 定义备份文件前缀。
-u, --update 仅仅进行更新，也就是跳过所有已经存在于DST，并且文件时间晚于要备份的文件，不覆盖更新的文件。
-l, --links 保留软链结。
-L, --copy-links 想对待常规文件一样处理软链结。
--copy-unsafe-links 仅仅拷贝指向SRC路径目录树以外的链结。
--safe-links 忽略指向SRC路径目录树以外的链结。
-H, --hard-links 保留硬链结。
-p, --perms 保持文件权限。
-o, --owner 保持文件属主信息。
-g, --group 保持文件属组信息。
-D, --devices 保持设备文件信息。
-t, --times 保持文件时间信息。
-S, --sparse 对稀疏文件进行特殊处理以节省DST的空间。
-n, --dry-run现实哪些文件将被传输。
-w, --whole-file 拷贝文件，不进行增量检测。
-x, --one-file-system 不要跨越文件系统边界。
-B, --block-size=SIZE 检验算法使用的块尺寸，默认是700字节。
-e, --rsh=command 指定使用rsh、ssh方式进行数据同步。
--rsync-path=PATH 指定远程服务器上的rsync命令所在路径信息。
-C, --cvs-exclude 使用和CVS一样的方法自动忽略文件，用来排除那些不希望传输的文件。
--existing 仅仅更新那些已经存在于DST的文件，而不备份那些新创建的文件。
--delete 删除那些DST中SRC没有的文件。
--delete-excluded 同样删除接收端那些被该选项指定排除的文件。
--delete-after 传输结束以后再删除。
--ignore-errors 及时出现IO错误也进行删除。
--max-delete=NUM 最多删除NUM个文件。
--partial 保留那些因故没有完全传输的文件，以是加快随后的再次传输。
--force 强制删除目录，即使不为空。
--numeric-ids 不将数字的用户和组id匹配为用户名和组名。
--timeout=time ip超时时间，单位为秒。
-I, --ignore-times 不跳过那些有同样的时间和长度的文件。
--size-only 当决定是否要备份文件时，仅仅察看文件大小而不考虑文件时间。
--modify-window=NUM 决定文件是否时间相同时使用的时间戳窗口，默认为0。
-T --temp-dir=DIR 在DIR中创建临时文件。
--compare-dest=DIR 同样比较DIR中的文件来决定是否需要备份。
-P 等同于 --partial。
--progress 显示备份过程。
-z, --compress 对备份的文件在传输时进行压缩处理。
--exclude=PATTERN 指定排除不需要传输的文件模式。
--include=PATTERN 指定不排除而需要传输的文件模式。
--exclude-from=FILE 排除FILE中指定模式的文件。
--include-from=FILE 不排除FILE指定模式匹配的文件。
--version 打印版本信息。
--address 绑定到特定的地址。
--config=FILE 指定其他的配置文件，不使用默认的rsyncd.conf文件。
--port=PORT 指定其他的rsync服务端口。
--blocking-io 对远程shell使用阻塞IO。
-stats 给出某些文件的传输状态。
--progress 在传输时现实传输过程。
--log-format=formAT 指定日志文件格式。
--password-file=FILE 从FILE中得到密码。
--bwlimit=KBPS 限制I/O带宽，KBytes per second。
-h, --help 显示帮助信息。
```



比较注意的是这些选项：`-e`、`-v`、`-r`、 `-R` 、`-p`

-aqzrtopg

rsync可以依靠rsync协议或者ssh协议通道来进行备份，本质上是建立起一个通道进行备份





## 0x02 备份指南



* 备份的321原则
  * 3：存储 3 份完整文件，一份原件加上两份拷贝。
  * 2：将文件起码保持在两种不同的介质上。
  * 1：将一份拷贝保存在异地。



然后在做备份时，需要对备份文件的每个目录写个Readme，方便解释如何备份，如何恢复

然后再做个总目录，就完美了



一个备份目录示例如下（摘自参考链接中的少数派，个人正在制作相关的备份目录）：

```
重装指南
├── 目录.md
├── Google Chrome 扩展
│   ├── 如何备份.md
│   ├── Proxy SwitchyOmega.bak
│   └── 扩展列表.md
├── 桌面程序
│   ├── 如何备份.md
│   ├── Bandizip
│   │   └── Bandizip Settings.reg
│   ├── Directory Opus
│   │   └── Opus Config.ocb
│   ├── DnsJumper
│   │   └── DnsJumper.ini
│   ├── Everything
│   │   └── Everything.ini
│   ├── Listary
│   │   └── Preferences.json
│   ├── Snipaste
│   │   └── config.ini
│   └── VSCode
│       ├── 扩展列表.md
│       ├── 键位绑定.json
│       ├── 全局设置.json
│       └── 代码片段
│           ├── c.json
│           ├── ...
│           └── markdown.json
├── Linux 安装指南
│   ├── CentOS.md
│   ├── 软件列表.md
│   └── WSL.md
├── Mac 安装指南
│   ├── 如何备份.md
│   ├── brew bundle.md
│   ├── 应用程序.md
│   └── 手动安装.md
├── 手机应用列表
│   ├── 如何备份.md
│   ├── Android.md
│   └── iPhone.md
├── oh-my-zsh
│   ├── 如何备份.md
│   ├── zshrc-mac.md
│   ├── zshrc-vps.md
│   └── zshrc-wsl.md
└── Windows 安装指南
    ├── 如何备份.md
    ├── 第一次配置.md
    └── 软件列表.md
```































