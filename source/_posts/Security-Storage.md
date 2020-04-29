---
title: Security Storage
date: 2020-04-27 21:36:22
tags:
categories:
description: About Linux security storage
password:
---









# About encrypting Linux file



## 0x00 序

在上次做完vhdx实验后，老师又让我们做了一次有关linux的文件加密的相关实验

但是在做实验时，都是直接照敲命令运行，到最后看到lost+found就算成功了，但是作为一个学习者我们不能酱紫

我们这次来看看这些命令到底是做什么的



## 0x01 losetup/cryptoloop 方法



创建命令如下：

```sh
$ dd if=/dev/zero of=bigf1 bs=1024000 count=0 seek=77
$ modprobe cryptoloop des aes
$ losetup -e aes /dev/loop1 bigf1
$ # fdisk /dev/loop1
$ mkfs /dev/loop1
$ mkdir d1
$ mount /dev/loop1  d1
$ cd d1
$ ls

```



* `dd` ：`dd`命令用于创建一个大文件，用来当作虚拟磁盘，相当于windows的vhdx文件

  * > [Linux dd命令](https://www.runoob.com/linux/linux-comm-dd.html)

  * 第一条命令，`if`规定输入文件名，即标准输入； `of`规定输出文件名，即标准输出；`bs`用于设置读入&输出的块大小，单位为 byte 字节；`count` 规定拷贝block个块 ；`seek` 规定从输出文件开头跳过blocks个块后在开始复制，对应的跳过输入文件的前n个块的选项为`skip`。

  * `/dev/zero` ：属于linux中的特殊设备，零设备，可以无限的提供空字符(0x00,ASCII码为NUL)，常用来生成一个特定大小的文件

  * 所以这条命令意于创建一个大小为1G的全为0的大文件



类似的创建大文件命令有： `fallocate` 、 `truncate` 

`fallocate`：功能是为文件预分配物理空间，而不是生成一个空洞文件，fallocate分配的空间在磁盘的扇区上是连续的，它减少后续写入和读取文件时的磁盘寻道开销；并且是迅速直接占用空间，而不是想空洞文件那样“假装”占有那么多空间，这样就可以保证随着磁盘空间的使用，而不会出现该段磁盘空间不足。由于`fallocate`并不是标准的`posix`接口，并不是所有的文件系统都是支持的，目前主流的`ext4`和`xfs`都是可以的。

`truncate`是将文件的末尾位置“扩展到”一个固定位置而生成的一个空洞文件，也即是稀疏文件。该文件并不占用实际磁盘空间，只是逻辑上看起来那么大而已。



* `modprobe` ：这个命令在之前学习内核编程时有接触过，用来自动加载模块及其依赖，相当于`apt install` 自动装包，这个就是自动加载模块进内核
  * 这边用于加载后面所用的加密模块



* `losetup` 命令：关键之处来了，该命令用于设置循环设备。循环设备可把文件虚拟成区块设备，籍以模拟整个文件系统，让用户得以将其视为硬盘驱动器，光驱或软驱等设备，并挂入当作目录来使用。

  * ```sh
    $ losetup [-d][-e <加密方式>][-o <平移数目>][循环设备代号][文件]
    ```

  * [Linux losetup命令](https://www.runoob.com/linux/linux-comm-losetup.html)

  * 这边是将`big1`大文件虚拟成块设备`/dev/loop1`，然后以aes的方法加密

  * `/dev/loop` ：`loop`设备是一种伪设备，是使用文件来模拟块设备的一种技术，文件模拟成块设备后, 就像一个磁盘或光盘一样使用。在使用之前，一个 loop 设备必须要和一个文件进行连接。这种结合方式给用户提供了一个替代块特殊文件的接口。因此，如果这个文件包含有一个完整的文件系统，那么这个文件就可以像一个磁盘设备一样被 mount 起来。之所以叫loop设备（回环），其实是从文件系统这一层来考虑的，因为这种被 mount 起来的镜像文件它本身也包含有文件系统，通过loop设备把它mount起来，它就像是文件系统之上再绕了一圈的文件系统，所以称为 loop。

    * [wiki - Loop设备](https://zh.wikipedia.org/wiki/Loop%E8%AE%BE%E5%A4%87)
    * 卸载一个loop设备：`losetup -d /dev/loop1`
    * `losetup -a`查看所有的loop设备，如果命令没有输出就说明所有的loop设备都没有被占用
    *  创建loop设备的命令`mknod -m 0660 /dev/loopX b 7 X`：假如loop设备全满，可以通过这个建一个新的，又或者手贱删了(比如我)，用这个也能创建回来



* `mkfs`命令用于在特定的分区上建立 linux 文件系统
  * [Linux mkfs命令](https://www.runoob.com/linux/linux-comm-mkfs.html)
  * 既然我们都把大文将big1当一个虚拟磁盘一样和loop设备关联在一起，那么现在就是来制作虚拟磁盘的时候，这个命令在big1上建立linux文件系统



* `mkdir d1;mount /dev/loop1 d1;cd d1` ： 这几个命令一起讲了，就是创建个文件夹d1，可以供刚才的虚拟磁盘挂载，类似于插入u盘然后挂载到本地一样

  * [Linux mount命令](https://www.runoob.com/linux/linux-comm-mount.html)

    

卸载虚拟磁盘，这个也是非常简单，按着上面的步骤逆着回去就行了

```sh
$ umount /dev/loop1
$ losetup -d /dev/loop1
$ rmmod cryptoloop des aes
$ # rm -rf big1 d1
$ 
```









## 0x02 luks:cryptsetup/dm-crypt方法



创建的命令如下

```sh
$ apt install cryptsetup-bin
$ modprobe aes  # or des，twofish etc
$ modprobe dm-crypt
$ lsmod | grep -E "aes|dm"
$ ls /dev/mapper/control
$ dmsetup targets  # 查看targets信息
$ dd if=/dev/zero of=bf1 bs=1024000 count=500 conv=fdatasync 
$ losetup /dev/loop1 bf1
$ cryptsetup -c aes create efs1 /dev/loop1
$ dmsetup ls
$ ls /dev/mapper/efs1
$ mkfs /dev/mapper/efs1
$ mkdir efs1
$ mount /dev/mapper/efs1 ./efs1
$ cd ./efs1
$ dd if=/dev/zero of=t1 bs=1024000 count=100 conv=fdatasync 
$ 
$ cd ..
$ hexdump -C -x ./efs1 # 看到乱码

```



首先来了解一下 `cryptsetup-bin`  ，这个包提供了一个接口，该接口使用Linux内核设备映射器对象 `dm-crypt` 去加密块设备，支持Linux统一密钥设置（LUKS）的功能。

> [dm-crypt: a device-mapper crypto target](https://www.saout.de/misc/dm-crypt/)
>
> [DMCrypt ](https://gitlab.com/cryptsetup/cryptsetup/-/wikis/DMCrypt) ： wiki
>
> [GitLab - Cryptsetup](https://gitlab.com/cryptsetup/cryptsetup) ：项目官网
>
> [Linux块设备加密之dm-crypt分析](https://blog.csdn.net/sonicling/article/details/6275898) ：一些源码分析
>
> [dm-crypt——多功能 Linux 磁盘加密工具](https://blog.csdn.net/zhongbeida_xue/article/details/78550712) ：使用方法介绍
>
> [使用cryptsetup创建加密磁盘](http://blog.lujun9972.win/blog/2018/04/12/%E4%BD%BF%E7%94%A8cryptsetup%E5%88%9B%E5%BB%BA%E5%8A%A0%E5%AF%86%E7%A3%81%E7%9B%98/index.html)

`dm-crypt` ：自从Linux Kernel 2.6 的早期版本，被整合到内核中

支持以下集中加密格式

* LUKS：`dm-crypt` 最常用的一个模式
* Plain：原始的dm-crypt格式
* Loop-AES ：比较陈旧的Linux磁盘加密工具
* TCRYPT：TrueCrypt的缩写，这个老师上课介绍过，也是一个加密工具

> 1. 可以通过 `uname -a`：可以查看内核版本
>
> 2. 然后从[这里（Linux 官网）](http://cdn.kernel.org/pub/linux/kernel/)下载对应版本的linux源码
>
> 3. 在`kernel_path/drivers/md/dm-crypt.c`拿出源码
>
> 4. 然后参考这个目录下的Makefile，当然也可以通用的用内核编译的Makefile，比如[我的博客](https://magic-king.net/2020/02/20/Linux-Kernel-Coding-Introdution/#more)里的这里面的Makefile，稍加修改就可以编译得到`.ko`的内核模块执行文件
>
>    
>
>    P.S. 也可以去编译整个内核源码，然后在对应文件夹找到对应的`.ko`文件，进行内核模块加载
>
> 



* `/dev/mapper/control` 
  * [Linux 内核中的 Device Mapper 机制](http://www.embeddedlinux.org.cn/emb-linux/kernel-driver/201710/28-7692.html)
  * [Linux系统/dev/mapper目录浅谈](https://blog.csdn.net/believe36/article/details/44133889)
  * [Linux 内核中的 Device Mapper 机制](https://www.ibm.com/developerworks/cn/linux/l-devmapper/index.html) ：IBM的内核机制讲解



* `dmsetup` 命令：该命令用于查看Device Mapper相关的设备概述，若无指定设备名称，则输出所有的Device Mapper设备信息

  * > [ DMSETUP 命令](http://linux.51yip.com/search/dmsetup)



这一些列命令的操作大多和第一种方法相似，只是换了一种工具罢了



卸载的命令如下

```sh
$ cd ..
$ umount /dev/mapper/efs1
$ cryptsetup remove efs1
$ dmsetup ls  # now nothing left
$ losetup -d /dev/loop1
$ rmmod dm-crypt

```

























