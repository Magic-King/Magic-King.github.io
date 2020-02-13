---
title: CTF-Wargame
date: 2020-02-13 16:01:07
tags: [CTF, wargame]
categories: CTF
description:
password:
---









鉴于最近的状态，看逆向又看不进去，就找了个简单的靶场玩一玩

https://overthewire.org/wargames/



# <center>Wargames</center>





## Suggested order to play the games in

1. Bandit
2. Leviathan or Natas or Krypton
3. Narnia
4. Behemoth
5. Utumno
6. Maze
7. …





## Bandit





> ### From the official tips:
>
> There are several things you can try when you are unsure how to continue:
>
> - First, if you know a command, but don’t know how to use it, try the **manual** ([man page](https://en.wikipedia.org/wiki/Man_page)) by entering “**man **” (without the quotes). e.g. if you know about the “ls” command, type: man ls. The “man” command also has a manual, try it. Press q to quit the man command.
> - Second, if there is no man page, the command might be a **shell built-in**. In that case use the “**help **” command. E.g. help cd
> - Also, your favorite **search-engine** is your friend. Learn how to use it! I recommend [Google](https://www.google.com/).
> - Lastly, if you are still stuck, you can [join us on IRC](https://overthewire.org/information/irc.html)





### Level 0

关于ssh的用法

```shell
ssh bandit0@bandit.labs.overthewire.org -p 2220
```



连上主机后便可以开始游戏

```
--[ Playing the games ]--

  This machine might hold several wargames.
  If you are playing "somegame", then:

    * USERNAMES are somegame0, somegame1, ...
    * Most LEVELS are stored in /somegame/.
    * PASSWORDS for each level are stored in /etc/somegame_pass/.

  Write-access to homedirectories is disabled. It is advised to create a
  working directory with a hard-to-guess name in /tmp/.  You can use the
  command "mktemp -d" in order to generate a random and hard to guess
  directory in /tmp/.  Read-access to both /tmp/ and /proc/ is disabled
  so that users can not snoop on eachother. Files and directories with
  easily guessable or short names will be periodically deleted!

  Please play nice:

    * don't leave orphan processes running
    * don't leave exploit-files laying around
    * don't annoy other players
    * don't post passwords or spoilers
    * again, DONT POST SPOILERS!
      This includes writeups of your solution on your blog or website!

--[ Tips ]--

  This machine has a 64bit processor and many security-features enabled
  by default, although ASLR has been switched off.  The following
  compiler flags might be interesting:

    -m32                    compile for 32bit
    -fno-stack-protector    disable ProPolice
    -Wl,-z,norelro          disable relro

  In addition, the execstack tool can be used to flag the stack as
  executable on ELF binaries.

  Finally, network-access is limited for most levels by a local
  firewall.

--[ Tools ]--

 For your convenience we have installed a few usefull tools which you can find
 in the following locations:

    * pwndbg (https://github.com/pwndbg/pwndbg) in /usr/local/pwndbg/
    * peda (https://github.com/longld/peda.git) in /usr/local/peda/
    * gdbinit (https://github.com/gdbinit/Gdbinit) in /usr/local/gdbinit/
    * pwntools (https://github.com/Gallopsled/pwntools)
    * radare2 (http://www.radare.org/)
    * checksec.sh (http://www.trapkit.de/tools/checksec.html) in /usr/local/bin/checksec.sh

--[ More information ]--

  For more information regarding individual wargames, visit
  http://www.overthewire.org/wargames/

  For support, questions or comments, contact us through IRC on
  irc.overthewire.org #wargames.

  Enjoy your stay!
```



### Level 1

`ls`之后得到flag，即下一关的密码（不知道为啥windows的CMD一直登陆不仅

建议用linux,windows是玄学

```sh
bandit0@bandit:~$ cat readme
boJ9jbbUNNfktd78OOpsqOltutMc3MY1
```



wargame的原理就是上一关的flag是下一关ssh的密码



### Level 2

```sh
bandit1@bandit:~$ ls
-
bandit1@bandit:~$ cd -
-bash: cd: OLDPWD not set
bandit1@bandit:~$ cd \-
-bash: cd: OLDPWD not set
bandit1@bandit:~$ cd /-
-bash: cd: /-: No such file or directory
bandit1@bandit:~$ ls -al
total 24
-rw-r-----  1 bandit2 bandit1   33 Oct 16  2018 -
drwxr-xr-x  2 root    root    4096 Oct 16  2018 .
drwxr-xr-x 41 root    root    4096 Oct 16  2018 ..
-rw-r--r--  1 root    root     220 May 15  2017 .bash_logout
-rw-r--r--  1 root    root    3526 May 15  2017 .bashrc
-rw-r--r--  1 root    root     675 May 15  2017 .profile
bandit1@bandit:~$ cat /-
cat: /-: No such file or directory
bandit1@bandit:~$ cat ./-
CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9

```

刚开始以为`-`是一个目录，便去cd，结果是`oldpwd not set`，百度之后发现是返回上一个目录

`ls`查看了才知道是是一个文件

> bash中，`-`会被解析为stdin，即标准输出流，假如直接`$ cat -`，这条命令会回显输入的任意字符，知道输入`eof`
>
> 摆脱转义的方法就是使用相对路径或者绝对路径



### level 3

```sh
bandit2@bandit:~$ ls
spaces in this filename
bandit2@bandit:~$ ls -al
total 24
drwxr-xr-x  2 root    root    4096 Oct 16  2018 .
drwxr-xr-x 41 root    root    4096 Oct 16  2018 ..
-rw-r--r--  1 root    root     220 May 15  2017 .bash_logout
-rw-r--r--  1 root    root    3526 May 15  2017 .bashrc
-rw-r--r--  1 root    root     675 May 15  2017 .profile
-rw-r-----  1 bandit3 bandit2   33 Oct 16  2018 spaces in this filename
bandit2@bandit:~$ cat spaces\ in\ this\ filename 
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK
bandit2@bandit:~$ cat "spaces in this filename" 
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK
bandit2@bandit:~$ cat 'spaces in this filename'
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK

```

总所周知，linux文件名中假如有空格的话，直接输入肯定是打不开的

我这边直接用tab，补全了所有对空格的转义

当然，用引号包含也行

> https://unix.stackexchange.com/questions/148043/is-space-not-allowed-in-a-filename

一般来说linux和unix上应该避免文件名中包含空格的





### level 4

```sh
bandit3@bandit:~$ ls -al
total 24
drwxr-xr-x  3 root root 4096 Oct 16  2018 .
drwxr-xr-x 41 root root 4096 Oct 16  2018 ..
-rw-r--r--  1 root root  220 May 15  2017 .bash_logout
-rw-r--r--  1 root root 3526 May 15  2017 .bashrc
drwxr-xr-x  2 root root 4096 Oct 16  2018 inhere
-rw-r--r--  1 root root  675 May 15  2017 .profile
bandit3@bandit:~$ 
bandit3@bandit:~$ cd inhere
bandit3@bandit:~/inhere$ ls -al
total 12
drwxr-xr-x 2 root    root    4096 Oct 16  2018 .
drwxr-xr-x 3 root    root    4096 Oct 16  2018 ..
-rw-r----- 1 bandit4 bandit3   33 Oct 16  2018 .hidden
bandit3@bandit:~/inhere$ cat .hidden 
pIwrPrtPN36QITSp3EQaw936yaFoFgAB

```

看来，直接`ls -al `是个好习惯

这题应该考察的是linux 的隐藏文件，linux的隐藏文件都以`.`开头







### level 5

```
bandit4@bandit:~$ ls -al
total 24
drwxr-xr-x  3 root root 4096 Oct 16  2018 .
drwxr-xr-x 41 root root 4096 Oct 16  2018 ..
-rw-r--r--  1 root root  220 May 15  2017 .bash_logout
-rw-r--r--  1 root root 3526 May 15  2017 .bashrc
drwxr-xr-x  2 root root 4096 Oct 16  2018 inhere
-rw-r--r--  1 root root  675 May 15  2017 .profile
bandit4@bandit:~$ cd inhere/
bandit4@bandit:~/inhere$ ls -al
total 48
drwxr-xr-x 2 root    root    4096 Oct 16  2018 .
drwxr-xr-x 3 root    root    4096 Oct 16  2018 ..
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file00
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file01
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file02
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file03
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file04
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file05
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file06
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file07
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file08
-rw-r----- 1 bandit5 bandit4   33 Oct 16  2018 -file09
bandit4@bandit:~/inhere$ cat ./-file00
����������~%	C[�걱>��| �
bandit4@bandit:~/inhere$ cat ./-file01
���U"7�w���H��ê�Q����(���#���
bandit4@bandit:~/inhere$ cat ./-file02
�T�v��(�ִ�����A*�
2J�Ş؇_�y7
bandit4@bandit:~/inhere$ cat ./-file03
��.A��u��#���w$N?c�-��Db3��=��
bandit4@bandit:~/inhere$ cat ./-file05
+��pm���;��:D��^��@�gl�Q�
bandit4@bandit:~/inhere$ cat ./-file04
�=<�W�����ht�Z��!��{�U
                          �
                          bandit4@bandit:~/inhere$ cat ./-file06
��@�%@���ZP*E��1�V���̫*����
bandit4@bandit:~/inhere$ cat ./-file07
koReBOKuIDDepwhWk7jZC0RTdopnAYKh
bandit4@bandit:~/inhere$ 

```

太难了，题目说only human-readable，真的是遍历10个文件

当然直接就找到flag了



### level 6

```sh
bandit5@bandit:~/inhere$ ls
maybehere00  maybehere04  maybehere08  maybehere12  maybehere16
maybehere01  maybehere05  maybehere09  maybehere13  maybehere17
maybehere02  maybehere06  maybehere10  maybehere14  maybehere18
maybehere03  maybehere07  maybehere11  maybehere15  maybehere19
bandit5@bandit:~/inhere$ du -a -b | grep 1033
1033	./maybehere07/.file2
bandit5@bandit:~/inhere$ cat ./maybehere07/.file2
DXjZPULLxYr17uwoI01bNLQbtFemEgo7
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        bandit5@bandit:~/inhere$
```

给出三个条件：可读的，大小为1033bytes，不可执行的

明显的，只有大小最好搜索，使用命令`du -a -b`显示出所有文件，以bytes为单位的大小，然后使用管道过滤搜索就行了





### level 7

> https://www.runoob.com/linux/linux-comm-find.html
>
> https://www.cnblogs.com/RXDXB/p/11696751.html

找海量文件终于要用到了find命令

```sh
bandit6@bandit:/home$ find / -user 'bandit7' -group 'bandit6' -size 33c
find: ‘/run/lvm’: Permission denied
find: ‘/run/screen/S-bandit27’: Permission denied
find: ‘/run/screen/S-bandit25’: Permission denied
find: ‘/run/screen/S-bandit2’: Permission denied
find: ‘/run/screen/S-bandit16’: Permission denied
find: ‘/run/screen/S-bandit0’: Permission denied
find: ‘/run/screen/S-bandit20’: Permission denied
find: ‘/run/screen/S-bandit30’: Permission denied
find: ‘/run/screen/S-bandit14’: Permission denied
find: ‘/run/screen/S-bandit33’: Permission denied
find: ‘/run/screen/S-bandit13’: Permission denied
find: ‘/run/screen/S-bandit31’: Permission denied
find: ‘/run/screen/S-bandit8’: Permission denied
find: ‘/run/screen/S-bandit5’: Permission denied
find: ‘/run/screen/S-bandit4’: Permission denied
find: ‘/run/screen/S-bandit29’: Permission denied
find: ‘/run/screen/S-bandit28’: Permission denied
find: ‘/run/screen/S-bandit21’: Permission denied
find: ‘/run/screen/S-bandit26’: Permission denied
find: ‘/run/screen/S-bandit24’: Permission denied
find: ‘/run/screen/S-bandit22’: Permission denied
find: ‘/run/screen/S-bandit1’: Permission denied
find: ‘/run/screen/S-bandit19’: Permission denied
find: ‘/run/screen/S-bandit23’: Permission denied
find: ‘/run/shm’: Permission denied
find: ‘/run/lock/temp/bandit31-git’: Permission denied
find: ‘/run/lock/temp/bandit30-git’: Permission denied
find: ‘/run/lock/temp/bandit29-git’: Permission denied
find: ‘/run/lock/temp/bandit28-git’: Permission denied
find: ‘/run/lock/temp/bandit27-git’: Permission denied
find: ‘/run/lock/temp/bandit5/inhere’: Permission denied
find: ‘/run/lock/lvm’: Permission denied
find: ‘/var/spool/bandit24’: Permission denied
find: ‘/var/spool/rsyslog’: Permission denied
find: ‘/var/spool/cron/crontabs’: Permission denied
find: ‘/var/log’: Permission denied
find: ‘/var/tmp’: Permission denied
find: ‘/var/cache/ldconfig’: Permission denied
find: ‘/var/cache/apt/archives/partial’: Permission denied
/var/lib/dpkg/info/bandit7.password
find: ‘/var/lib/apt/lists/partial’: Permission denied
find: ‘/var/lib/polkit-1’: Permission denied
find: ‘/cgroup2/csessions’: Permission denied
find: ‘/home/bandit28-git’: Permission denied
find: ‘/home/bandit30-git’: Permission denied
find: ‘/home/bandit31-git’: Permission denied
find: ‘/home/bandit5/inhere’: Permission denied
find: ‘/home/bandit27-git’: Permission denied
find: ‘/home/bandit29-git’: Permission denied
find: ‘/tmp’: Permission denied
find: ‘/lost+found’: Permission denied
find: ‘/root’: Permission denied
find: ‘/etc/ssl/private’: Permission denied
find: ‘/etc/lvm/backup’: Permission denied
find: ‘/etc/lvm/archive’: Permission denied
find: ‘/etc/polkit-1/localauthority’: Permission denied
find: ‘/sys/fs/pstore’: Permission denied
find: ‘/proc/tty/driver’: Permission denied
find: ‘/proc/29536/task/29536/fd/6’: No such file or directory
find: ‘/proc/29536/task/29536/fdinfo/6’: No such file or directory
find: ‘/proc/29536/fd/5’: No such file or directory
find: ‘/proc/29536/fdinfo/5’: No such file or directory
find: ‘/boot/lost+found’: Permission denied
bandit6@bandit:/home$ cat /var/lib/dpkg/info/bandit7.password
HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs

```

毕竟是别人的服务器嘛，找出其中可以访问的就是目标文件了







### level 8

> strings：用于打印文件中可打印的字符
>
> 



```sh
bandit7@bandit:~$ ls
data.txt
bandit7@bandit:~$ less data.txt 
bandit7@bandit:~$ strings data.txt |grep millionth
millionth	cvX2JJa4CFALtqS87jk27qwqGhBM9plV
bandit7@bandit:~$ 

```

一看这题目就感觉很大，用less看下格式，然后直接用grep去查找就行了

cat命令在这也是可以和strings互换的





### level 9

### level 10

### level 11

### level 12

### level 13

### level 14

### level 15

### level 16

### level 17

### level 18

### level 19

### level 20

### level 21

### level 22

### level 23

### level 24

### level 25

### level 26

### level 27

### level 28

### level 29

### level 30

### level 31

### level 32

### level 33

### level 34









