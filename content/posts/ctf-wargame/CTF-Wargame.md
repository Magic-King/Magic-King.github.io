---

title: CTF-Wargame
date: 2020-02-13T16:01:07+08:00
tags: [ctf, wargame]
categories: [ctf]
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
����������~%	C[�걱>��| �
bandit4@bandit:~/inhere$ cat ./-file01
���U"7�w���H��ê�Q����(���#���
bandit4@bandit:~/inhere$ cat ./-file02
�T�v��(�ִ�����A*�
2J�Ş؇_�y7
bandit4@bandit:~/inhere$ cat ./-file03
��.A��u��#���w$N?c�-��Db3��=��
bandit4@bandit:~/inhere$ cat ./-file05
+��pm���;��:D��^��@�gl�Q�
bandit4@bandit:~/inhere$ cat ./-file04
�=<�W�����ht�Z��!��{�U
                          �
                          bandit4@bandit:~/inhere$ cat ./-file06
��@�%@���ZP*E��1�V���̫*����
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

> uniq 命令用于检查及删除文本文件中重复出现的行列，一般与 sort 命令结合使用
> uniq 可检查文本文件中重复出现的行列
>
> https://www.runoob.com/linux/linux-comm-uniq.html
>
> sort命令用于将文本文件内容加以排序
> sort可针对文本文件的内容，以行为单位来排序
>
> https://www.runoob.com/linux/linux-comm-sort.html

```sh
bandit8@bandit:~$ cat data.txt | sort | uniq -c
     10 07iR6PwHwihvQ3av1fqoRjICCulpoyms
     10 0ob6rCn4D4jQ6KCiaT5hmOdWFrm2quR1
     10 1drBmDT7PYS7hVgoTWkJSjUZUK7ZAIAa
     10 1JnkIYLDOdn5M7TGabYxOWkn7HazMjYW
     10 1wBrW0VGjKeYiXltbEWrUipwSHQfTu44
     10 2Dxbtw8cnKyHwvt0lfFNYOGc4cE59uua
     10 2TRkCQhbMjcM0hwL31NnJQ0DVagWN3Ca
     10 4c7EsUtqLnLR9hiepV5EQVhdMgyi8onL
     10 4cQDXE4IPH8fCBUBZaTPgnY2gwnPnlj6
     10 6495bfC0lI1Qkw5kzZHnbVWooaOZHLvj
     10 6rEzM4Qro8dH0e3uemAyYseTiNiNAYap
     10 78rgduVcLZjLzZmooObdaN541MKV6IfQ
     10 8qkrbCAUG9I28M49j9flUro5fWxenFzF
     10 aIl4xN5maZVCQITz0xH0KNXIlLc0MhNf
     10 aPsCQmSWVYGQQHUD6k1fHC2kqSyMlxwV
     10 awglWaTRSAWBcol8hSMTJP4FYhIGJHVO
     10 bCJdTkork5IRbZaaPZK0WVPgYIIO4mHF
     10 BPl0XNou7xAZAI5fdzWzSmPkW1PnvTE1
     10 bvIaDTzHBOGSO7CfpH9vUrJRRlwYTUA7
     10 CS8HVrDmKGLG53qziqQCLWNRlUP1FHsV
     10 CwwHDVp0pO6zmFp87L9AtFzqU5aB5j9w
     10 CyziIvGRdotoy9yA00RAnvvkvrYdKCPp
     10 DRqDxJYAv7IUfAMmrXtXEiz63TUjqeDn
     10 DXI6y5CNPU06rVpkoZgnZJBWfkdW131j
     10 enNw6tuj8mSxxS7f2Yd05puXVeuCZ39G
     10 ewllxPExW9eaHxAH8WZkW9lDuK5cZcUy
     10 eyKcuNPKnjt25kaOZxkMYQ9xqp45aIk9
     10 fIBXc239DbhORY4t9xjgi7fSm4thHsIb
     10 fiK30QpqzoULACXZwkBEKJZvpPQx9Uqm
     10 FlHOKVUDNLx6Ga7CxC4ISRYNflN1GAnF
     10 G4BHP66B4l3XkvB05CMgzrEKyjHhuCwz
     10 gCx35PlKn08nrFFrAgHYLrUVWWZjLdqM
     10 GEzwi36aKB8PLlCPH2wzl9gHzVm97IYu
     10 glONDdR72FJL3Gc03nVNO4PKNzXFGH1A
     10 gqGBgY1IdFDGG2XzB2o1VNGY4j6OL76V
     10 h7jtcUsBhrryyLhtt1mT6Jdmp0l6ozBs
     10 HKryX0XX2HT4WBT0OUzRz5Ac5B2rvIHU
     10 iM3PaCO3VAxAdbdVsdGtEwuwrFQPYJV7
     10 irGm6F73sbUrFhHukhp6JXgMQyLxJTz1
     10 jtNdk5KDgrMkxgbZSJOvjOcM58svrzDY
     10 jVscZ5eK5DWN7IvDSehXmyplCXRSbHJS
     10 KerqNiDbY0zV2VxnOCmWX5XWxumldlAe
     10 kha3sCpHsydUNrxLLXV3cFqWyucGjdxr
     10 kt1VUEZpimCS4BaoAvhN3rgHOmhqaMIR
     10 KUzqHCrxHSpgfkF5ZAzUfjlBaXW3zIaZ
     10 L0nxAwlfV9V3J5onKIT8KYQ9InTcQ7yE
     10 lnB8MWOYjETxoC8bQYrMFnxxQXAWHjP4
     10 lZ9DhnzeHgIuLqYPmNzONpMCkuBYoeJI
     10 M8JMUd7MSd4mOwZj1843ejBH5RXJOloa
     10 mdug9JbW836YVZh3ALULBAxODlinqonJ
     10 MIpMch66sYTmmqepKYczlRA9aJrnkt68
     10 MpAqsgjJIVLT1MxSZcRoOOzl6g1db98Q
     10 MQrydyojsVIYJSY8y1nCMjZGxnL1My7F
     10 MsxcvOe3PGrt78wpZG2bBNF5wfXpZhET
     10 n5fEmvCXKbJErzIDt3MLTmZZVMRNynrR
     10 NL91hwGrqW5lVgoicb592Sd0djnHnbjZ
     10 Nnih4Q0jf3xEOTcmM3yw2HkOm3VPox0w
     10 NT4p09XwRb0k0wG9yIuvfs3MblMGpMc1
     10 nU5zbsdUfmzv7cjNwkV9Hgb65OVe5EDt
     10 nyvBweoC3kzt5QRTjbDfrWO7jhwOGN4g
     10 OcVxHzDW027KWNFS03G31KQEb5TgN1WV
     10 peXkYozDKE2u2BEOed5vvkY0nyjkGawn
     10 PXHEt0PztCiArDZ7UCBmqKdBCiXNQWBN
     10 QmFayGbrzFoiQ5Z2PGmnD2N6Pf77cxl9
     10 QNTac9UtCmQ5VGAnzj10Z9BwV4TuaVvu
     10 qsbKthWb80f3vQKBP7O12SjfFo1V5VkL
     10 quhCb8ZIUJXXM2SbY1ER1D5GaDlQjdDa
     10 QYeOFhgJCJEfKM1ZpT0K322R6SuKdCFT
     10 r0VIMA1yzv838m7UfvutUhCf0zaY3Rqw
     10 rfUNSGOvmQXz0m7PtFoEoPg1BpTbll7X
     10 rJMbGeeDTMsj1RA4YibIQr0o9azHgP0I
     10 rQAYnkKAXIViP4ROmehnDMIAXLpOOLEp
     10 sBB2H7HateUFxr2oxrqUVoumFM60f1lj
     10 SjFHXKRcIc7jlAYGknVMnGXSFd6xRmnF
     10 tDZbF2SuhsvfaA3eTnwfcjQa1pZoPJeX
     10 tiyVGzZcRwUPVAiqkroFMUbMI9ut9hcT
     10 tLKyRATtoCuxMR4zZg1Dnlnr3je3bSHe
     10 tmzBM5rcV9y7AM1xDHudL2yX9oefGieT
     10 tWwjd16fG17vGdjutfOygVTjEGxlijOS
     10 uBRx9inQTeaDZAuzEb2MadWXmkH8uW4O
      1 UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR
     10 vBo3qbjNEF2d3meGEkRfc3mKpjtiDz1i
     10 VElUBEIhJ4yBgOBSN05WgtV2rF6kkGdz
     10 vl9liaz8TKv1enUi0S2REhn01hKjjFIK
     10 vVwG2mb8rU8eCuIlBhCJrZJ4GWR35nWY
     10 W0vbGkT5mfRVWHAXCcMekevbenMJHFhN
     10 W6pn7siBPh5G6ndjv1xx26iHxke8PviX
     10 WaKxNQhiI9dXwvzB1PMpbQRy4CutGrWt
     10 WbfstqfIvgiEuCVVuxwLgLyzUMtho2jP
     10 WBjoFnis277W9vWB8M67h3z1glOYG2Fy
     10 wSpAMdiBSeywE4d1DQZoSp5o8ZVOCqGP
     10 wWfTfhYKmBkmyGH9D6Qjb6x7bMt5narC
     10 x0bga8Oxz5lgM8k52HrYy4ez7XJI0lM0
     10 XURYdoIx95clq6s90MORDydQ187DxQhS
     10 xWmqkcrZ7TmjE7LKjqHVXSLw9fqsjYXp
     10 XWy99VXVCnwdr780PK86hP6rBMkV5E3n
     10 y9sn56N0ZhyxaySYRs518D4vqkMShHwb
     10 YiQvaaidmD39i0ryGZz97Upc5NjgPklY
     10 YR0sflfJZ34iuY3wM3DNNO19dBYnJDmt
     10 yXGLvp7UaeiDKxLGXQYlWuRWdIgeCaT0
     10 YzZX7E35vOa6IQ9SRUGdlEpyaiyjvWXE
bandit8@bandit:~$ cat data.txt | sort | uniq -u
UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR

```

这里的知识是linux的文本处理

用`uniq -c `统计每个字符串出现的次数，`-u`即可显示只出现一次的字符串 







### level 10

找出以`=`开头的字符出，可读的

第一反应想到的是正则表达式和strings命令，尝试了一下，直接成功

```sh
bandit9@bandit:~$ strings data.txt |grep "=.*"
2========== the
========== password
>t=	yP
rV~dHm=
========== isa
=FQ?P\U
=	F[
pb=x
J;m=
=)$=
========== truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk
iv8!=
bandit9@bandit:~$ 
bandit9@bandit:~$ strings data.txt |grep "="
2========== the
========== password
>t=	yP
rV~dHm=
========== isa
=FQ?P\U
=	F[
pb=x
J;m=
=)$=
========== truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk
iv8!=


```

后面看别人直接grep也能成功，可真是出人意料

这边的知识点应该是grep是支持正则表达式的字符串的









### level 11

```sh
bandit10@bandit:~$ strings data.txt | less
bandit10@bandit:~$ strings data.txt 
VGhlIHBhc3N3b3JkIGlzIElGdWt3S0dzRlc4TU9xM0lSRnFyeEUxaHhUTkViVVBSCg==
bandit10@bandit:~$ cat data.txt 
VGhlIHBhc3N3b3JkIGlzIElGdWt3S0dzRlc4TU9xM0lSRnFyeEUxaHhUTkViVVBSCg==
bandit10@bandit:~$ strings data.txt | base64 -d
The password is IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR
bandit10@bandit:~$ 
```

直接less读取怕文件太大，结果就只有一行明显的base64加密

百度了linux中base64命令的用法，毕竟题意就是让用linux命令进行操作的

base64用法如下

```sh
$ echo "Hello World" | base64
SGVsbG8gV29ybGQK
$ echo "SGVsbG8gV29ybGQK" | base64 -d 
```

加`-d`选项为解密





### level 12

看题目是rot13加密，如何用linux指令实现呢

这里用到了`tr`命令

> tr 命令用于转换或删除文件中的字符
>
> tr 指令从标准输入设备读取数据，经过字符串转译后，将结果输出到标准输出设备
>
> https://www.runoob.com/linux/linux-comm-tr.html
>
> https://www.xp.cn/php/2675.html

```sh
bandit11@bandit:~$ cat data.txt 
Gur cnffjbeq vf 5Gr8L4qetPEsPk8htqjhRK8XSP6x2RHh
bandit11@bandit:~$ cat data.txt | tr 'N-Z A-M n-z a-m' 'A-M N-Z a-m n-z'
The password is 5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu
bandit11@bandit:~$
```





### level 13

据说这是xxd导出的十六进制文件

我们去搜xxd命令，恢复成二级制用`xxd -r filename`

```sh
bandit12@bandit:~$ mkdir /tmp/magicking
bandit12@bandit:~$ cp data.txt /tmp/magicking/data.txt
bandit12@bandit:~$ cd /tmp/magicking
bandit12@bandit:/tmp/magicking$ ls
data.txt
bandit12@bandit:/tmp/magicking$ cat data.txt
00000000: 1f8b 0808 d7d2 c55b 0203 6461 7461 322e  .......[..data2.
00000010: 6269 6e00 013c 02c3 fd42 5a68 3931 4159  bin..<...BZh91AY
00000020: 2653 591d aae5 9800 001b ffff de7f 7fff  &SY.............
00000030: bfb7 dfcf 9fff febf f5ad efbf bbdf 7fdb  ................
00000040: f2fd ffdf effa 7fff fbd7 bdff b001 398c  ..............9.
00000050: 1006 8000 0000 0d06 9900 0000 6834 000d  ............h4..
00000060: 01a1 a000 007a 8000 0d00 0006 9a00 d034  .....z.........4
00000070: 0d1a 3234 68d1 e536 a6d4 4000 341a 6200  ..24h..6..@.4.b.
00000080: 0069 a000 0000 0000 d003 d200 681a 0d00  .i..........h...
00000090: 0001 b51a 1a0c 201e a000 6d46 8068 069a  ...... ...mF.h..
000000a0: 6834 340c a7a8 3406 4000 0680 0001 ea06  h44...4.@.......
000000b0: 8190 03f5 4032 1a00 0343 4068 0000 0686  ....@2...C@h....
000000c0: 8000 0320 00d0 0d00 0610 0014 1844 0308  ... .........D..
000000d0: 04e1 c542 9ab8 2c30 f1be 0b93 763b fb13  ...B..,0....v;..
000000e0: 50c4 c101 e008 3b7a 92a7 9eba 8a73 8d21  P.....;z.....s.!
000000f0: 9219 9c17 052b fb66 a2c2 fccc 9719 b330  .....+.f.......0
00000100: 6068 8c65 e504 5ec0 ae02 fa6d 16bc 904b  `h.e..^....m...K
00000110: ba6c f692 356e c02b 0374 c394 6859 f5bb  .l..5n.+.t..hY..
00000120: 0f9f 528e 4272 22bb 103c 2848 d8aa 2409  ..R.Br"..<(H..$.
00000130: 24d0 d4c8 4b42 7388 ce25 6c1a 7ec1 5f17  $...KBs..%l.~._.
00000140: cc18 ddbf edc1 e3a4 67f1 7a4d 8277 c823  ........g.zM.w.#
00000150: 0450 2232 40e0 07f1 ca16 c6d6 ef0d ecc9  .P"2@...........
00000160: 8bc0 5e2d 4b12 8586 088e 8ca0 e67d a55c  ..^-K........}.\
00000170: 2ca0 18c7 bfb7 7d45 9346 ea5f 2172 01e4  ,.....}E.F._!r..
00000180: 5598 673f 45af 69b7 a739 7814 8706 04ed  U.g?E.i..9x.....
00000190: 5442 1240 0796 6cc8 b2f6 1ef9 8d13 421d  TB.@..l.......B.
000001a0: 461f 2e68 4d91 5343 34b5 56e7 46d0 0a0a  F..hM.SC4.V.F...
000001b0: 72b7 d873 71d9 6f09 c326 402d dbc0 7cef  r..sq.o..&@-..|.
000001c0: 53b1 df60 9ec7 f318 00df 3907 2e85 d85b  S..`......9....[
000001d0: 6a1a e105 0207 c580 e31d 82d5 8646 183c  j............F.<
000001e0: 6a04 4911 101a 5427 087c 1f94 47a2 270d  j.I...T'.|..G.'.
000001f0: ad12 fc5c 9ad2 5714 514f 34ba 701d fb69  ...\..W.QO4.p..i
00000200: 8eed 0183 e2a1 53ea 2300 26bb bd2f 13df  ......S.#.&../..
00000210: b703 08a3 2309 e43c 44bf 75d4 905e 5f96  ....#..<D.u..^_.
00000220: 481b 362e e82d 9093 7741 740c e65b c7f1  H.6..-..wAt..[..
00000230: 5550 f247 9043 5097 d626 3a16 da32 c213  UP.G.CP..&:..2..
00000240: 2acd 298a 5c8a f0c1 b99f e2ee 48a7 0a12  *.).\.......H...
00000250: 03b5 5cb3 0037 cece 773c 0200 00         ..\..7..w<...

bandit12@bandit:/tmp/magicking$ xxd -r data.txt

bandit12@bandit:/tmp/magicking$ xxd -r data.txt > data
bandit12@bandit:/tmp/magicking$ file data
data: gzip compressed data, was "data2.bin", last modified: Tue Oct 16 12:00:23 2018, max compression, from Unix
bandit12@bandit:/tmp/magicking$ mv data data.gz
bandit12@bandit:/tmp/magicking$ gz -d data.gz 
-bash: gz: command not found
bandit12@bandit:/tmp/magicking$ gnuzip -d data.gz 
-bash: gnuzip: command not found
bandit12@bandit:/tmp/magicking$ gzip -d data.gz 
bandit12@bandit:/tmp/magicking$ ls
data  data.txt

bandit12@bandit:/tmp/magicking$ file data
data: bzip2 compressed data, block size = 900k
bandit12@bandit:/tmp/magicking$ mv data data.bz2
bandit12@bandit:/tmp/magicking$ bz2 -d data.bz2 
-bash: bz2: command not found
bandit12@bandit:/tmp/magicking$ bzip2 -d data.bz2 
bandit12@bandit:/tmp/magicking$ ls
data  data.txt
bandit12@bandit:/tmp/magicking$ file data
data: gzip compressed data, was "data4.bin", last modified: Tue Oct 16 12:00:23 2018, max compression, from Unix
bandit12@bandit:/tmp/magicking$ gzip -d data
gzip: data: unknown suffix -- ignored
bandit12@bandit:/tmp/magicking$ mv data data.gz
bandit12@bandit:/tmp/magicking$ gzip -d data.gz 
bandit12@bandit:/tmp/magicking$ file data
data: POSIX tar archive (GNU)
bandit12@bandit:/tmp/magicking$ mv data data.tar
bandit12@bandit:/tmp/magicking$ tar -x data.tar
tar: Refusing to read archive contents from terminal (missing -f option?)
tar: Error is not recoverable: exiting now
bandit12@bandit:/tmp/magicking$ tar -xvf data.tar
data5.bin
bandit12@bandit:/tmp/magicking$ ls
data5.bin  data.tar  data.txt
bandit12@bandit:/tmp/magicking$ file data5.bin
data5.bin: POSIX tar archive (GNU)
bandit12@bandit:/tmp/magicking$ mv data5.bin data5.bin.tar
bandit12@bandit:/tmp/magicking$ tar -xvf data5.bin.tar 
data6.bin
bandit12@bandit:/tmp/magicking$ file data6.bin
data6.bin: bzip2 compressed data, block size = 900k
bandit12@bandit:/tmp/magicking$ mv data6.bin data6.bin.bz2
bandit12@bandit:/tmp/magicking$ bzip2 -d data6.bin.bz2 
bandit12@bandit:/tmp/magicking$ ls
data5.bin.tar  data6.bin  data.tar  data.txt
bandit12@bandit:/tmp/magicking$ ls -l
total 48
-rw-r--r-- 1 bandit12 root 10240 Oct 16  2018 data5.bin.tar
-rw-r--r-- 1 bandit12 root 10240 Oct 16  2018 data6.bin
-rw-r--r-- 1 bandit12 root 20480 Feb 14 10:42 data.tar
-rw-r----- 1 bandit12 root  2581 Feb 14 10:37 data.txt
bandit12@bandit:/tmp/magicking$ file data6.bin
data6.bin: POSIX tar archive (GNU)
bandit12@bandit:/tmp/magicking$ mv data6.bin data6.bin.tar
bandit12@bandit:/tmp/magicking$ tar -xvf data6.bin.tar 
data8.bin
bandit12@bandit:/tmp/magicking$ file data8.bin 
data8.bin: gzip compressed data, was "data9.bin", last modified: Tue Oct 16 12:00:23 2018, max compression, from Unix
bandit12@bandit:/tmp/magicking$ mv data8.bin data8.bin.gz
bandit12@bandit:/tmp/magicking$ gzip -d data8.bin.gz 
bandit12@bandit:/tmp/magicking$ ls
data5.bin.tar  data6.bin.tar  data8.bin  data.tar  data.txt
bandit12@bandit:/tmp/magicking$ file data8.bin 
data8.bin: ASCII text
bandit12@bandit:/tmp/magicking$ cat data8.bin 
The password is 8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL
bandit12@bandit:/tmp/magicking$ 
```



逐渐熟练的解压缩操作，简直了这压缩层数，丧心病狂







### level 14

根据题目所描述，`/etc/bandit_pass/bandit14 and can only be read by user bandit14`

我们肯定无法访问

但是，ls之后，发现有一个私钥，而且题目表示可以不用密码

那么这文件就是ssh bandit14的私钥

直接连接，ojbk

```sh
bandit13@bandit:~$ ls
sshkey.private
bandit13@bandit:~$ cat /etc/bandit_pass/bandit14
cat: /etc/bandit_pass/bandit14: Permission denied
bandit13@bandit:~$ ssh
usage: ssh [-1246AaCfGgKkMNnqsTtVvXxYy] [-b bind_address] [-c cipher_spec]
           [-D [bind_address:]port] [-E log_file] [-e escape_char]
           [-F configfile] [-I pkcs11] [-i identity_file]
           [-J [user@]host[:port]] [-L address] [-l login_name] [-m mac_spec]
           [-O ctl_cmd] [-o option] [-p port] [-Q query_option] [-R address]
           [-S ctl_path] [-W host:port] [-w local_tun[:remote_tun]]
           [user@]hostname [command]
bandit13@bandit:~$ ssh -i sshkey.private bandit14@localhost
Could not create directory '/home/bandit13/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit13/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

......

bandit14@bandit:~$ cat /etc/bandit_pass/bandit14
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e

```







### level 15



```sh
bandit14@bandit:~$ cat /etc/bandit_pass/bandit14
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
bandit14@bandit:~$ 
bandit14@bandit:~$ telnet localhost 30000
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.

Wrong! Please enter the correct current password
Connection closed by foreign host.
bandit14@bandit:~$ telnet localhost 30000
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
Correct!
BfMYroe26WYalil77FoDi9qh59eK5xNr

Connection closed by foreign host.
bandit14@bandit:~$ 

```







### level 16

发送需要ssl加密

搜索得知SSL可用于加密任何基于TCP/IP的应用

再搜索openssl的用法即可解出

```sh
bandit15@bandit:~$ openssl s_client -connect localhost:30001 -ign_eof
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1
---
Certificate chain
 0 s:/CN=localhost
   i:/CN=localhost
---
Server certificate
-----BEGIN CERTIFICATE-----
MIICBjCCAW+gAwIBAgIEYo1NxTANBgkqhkiG9w0BAQUFADAUMRIwEAYDVQQDDAls
b2NhbGhvc3QwHhcNMjAwMTA1MTQzNTU4WhcNMjEwMTA0MTQzNTU4WjAUMRIwEAYD
VQQDDAlsb2NhbGhvc3QwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAKF4u2eu
a8VipZPviX0hfNiCnaD2ojAffdBhKTy1bmZSNRuHPBDnU7z8rblNSknSjCITda1C
GEAI8ZktRbtLpBTbYeTgqPN/EiN5UIRMKbU6P2O93zNFPBsmyfQLrgt+DSLnsxlB
i/yYyT7WLdtNVBpgwRwkqi9K7dk9vf9waswLAgMBAAGjZTBjMBQGA1UdEQQNMAuC
CWxvY2FsaG9zdDBLBglghkgBhvhCAQ0EPhY8QXV0b21hdGljYWxseSBnZW5lcmF0
ZWQgYnkgTmNhdC4gU2VlIGh0dHBzOi8vbm1hcC5vcmcvbmNhdC8uMA0GCSqGSIb3
DQEBBQUAA4GBAJECW6IB3Ria4xG002BqD3zEbtmrDlK6nmJq+uQ4eJ6cT18o9REb
npy/lFzlv2LfcrYAnuAp6Fh89MKaYjNzJURjRQ9RkmcYgQJa1n+OBkATb7V+84/a
k9PDRkscxdNFMGBSvzFD33XZ5lbaGdrwCPyoxenoYghV/753wffN7J6H
-----END CERTIFICATE-----
subject=/CN=localhost
issuer=/CN=localhost
---
No client certificate CA names sent
Peer signing digest: SHA512
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 1019 bytes and written 269 bytes
Verification error: self signed certificate
---
New, TLSv1.2, Cipher is ECDHE-RSA-AES256-GCM-SHA384
Server public key is 1024 bit
Secure Renegotiation IS supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : ECDHE-RSA-AES256-GCM-SHA384
    Session-ID: 7EEA483CA2D18FE7CB98BB6A1CC800C7BE4444E492EBFD398DDA8EABD18712C2
    Session-ID-ctx: 
    Master-Key: D0D0B7463ABC8AD513D016BEBF3932F325BE53DBBA712624C9E820AB95735BF63FA59EAECFF34AE5523F2E05BC8BE5F2
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - 56 e9 4e 87 6a 28 48 d0-13 42 5f b9 61 b0 dd d0   V.N.j(H..B_.a...
    0010 - d6 bb 15 df 9d 3a 2c 9f-2d 88 a4 e2 b8 ec 36 de   .....:,.-.....6.
    0020 - 6c ba 2d ac d0 d4 0b 12-d1 76 ac cd 8f 8d 4d b9   l.-......v....M.
    0030 - e4 8d 7f 9e 0b f5 2a 67-42 6c 52 08 94 27 09 75   ......*gBlR..'.u
    0040 - 67 e5 8a 66 24 50 4f db-a7 9d 01 0d 81 ba b3 12   g..f$PO.........
    0050 - c5 2e 8d ee ef 0a 2d 6d-a0 89 72 36 18 30 b2 24   ......-m..r6.0.$
    0060 - fa 82 0a b5 9d da d2 55-70 a7 fd 6d 3f 96 9e 85   .......Up..m?...
    0070 - 8f e8 f8 8d 0e 29 0f 84-12 97 9c 31 7d 79 ef 75   .....).....1}y.u
    0080 - f5 f9 f6 cc 74 29 58 a0-a9 48 f5 17 c4 1d 73 ba   ....t)X..H....s.
    0090 - f1 30 ce 52 12 b6 e2 c2-75 f9 94 b9 04 2a a9 d8   .0.R....u....*..

    Start Time: 1581676007
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
BfMYroe26WYalil77FoDi9qh59eK5xNr
Correct!
cluFn7wTiGryunymYOu4RcffSxQluehd

closed
bandit15@bandit:~$ 

```







### level 17

这道题要我们在给定范围内找出正确的端口，`nc`，`nmap`都可以用

```sh
bandit16@bandit:~$ nc -zv localhost 31000-32000
localhost [127.0.0.1] 31790 (?) open
localhost [127.0.0.1] 31518 (?) open

bandit16@bandit:~$ nmap localhost -p31000-32000 -v

Starting Nmap 7.40 ( https://nmap.org ) at 2020-02-14 11:38 CET
Initiating Ping Scan at 11:38
Scanning localhost (127.0.0.1) [2 ports]
Completed Ping Scan at 11:38, 0.00s elapsed (1 total hosts)
Initiating Connect Scan at 11:38
Scanning localhost (127.0.0.1) [1001 ports]
Discovered open port 31518/tcp on 127.0.0.1
Discovered open port 31790/tcp on 127.0.0.1
Completed Connect Scan at 11:38, 0.04s elapsed (1001 total ports)
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00026s latency).
Not shown: 999 closed ports
PORT      STATE SERVICE
31518/tcp open  unknown
31790/tcp open  unknown

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 0.09 seconds
bandit16@bandit:~$
bandit16@bandit:~$
bandit16@bandit:~$ nmap localhost -p31000-32000 

Starting Nmap 7.40 ( https://nmap.org ) at 2020-02-14 11:38 CET
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00024s latency).
Not shown: 999 closed ports
PORT      STATE SERVICE
31518/tcp open  unknown
31790/tcp open  unknown

Nmap done: 1 IP address (1 host up) scanned in 0.10 seconds

bandit16@bandit:~$ 
bandit16@bandit:~$
bandit16@bandit:~$ openssl s_client -connect localhost:31790 -ign_eof
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1
---
Certificate chain
 0 s:/CN=localhost
   i:/CN=localhost
---
Server certificate
-----BEGIN CERTIFICATE-----
MIICBjCCAW+gAwIBAgIEGPttrzANBgkqhkiG9w0BAQUFADAUMRIwEAYDVQQDDAls
b2NhbGhvc3QwHhcNMjAwMjA5MjA0NzE5WhcNMjEwMjA4MjA0NzE5WjAUMRIwEAYD
VQQDDAlsb2NhbGhvc3QwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAPiElqK1
D097ZCNDgKFxqX1ZUUpFfuoiDSP2dw5KrIruaTQMmfqCxo6dSHvkj1sF//YRI28k
BGyu9pE3zLO45uk4PrjoORYLoQjTCb61oVZLECCOIG21WQUbrhjW4zlZGmtWrqw6
zGLk7dZ8MeYHVSvK0n3Ar45hVedpsLC618ZTAgMBAAGjZTBjMBQGA1UdEQQNMAuC
CWxvY2FsaG9zdDBLBglghkgBhvhCAQ0EPhY8QXV0b21hdGljYWxseSBnZW5lcmF0
ZWQgYnkgTmNhdC4gU2VlIGh0dHBzOi8vbm1hcC5vcmcvbmNhdC8uMA0GCSqGSIb3
DQEBBQUAA4GBADJEAM0VceCYaqhfzpzkzf6dhCIWbb/8P+51Wxw24sn9iLHxdqYe
1WNfxtQb8IYb3q/6JJDJ3d6plNKmFMkFBe5AiN05PCDeMymkTv8vlKj18UNR/4GL
AH1aFGcEYVXkwX0Kl844muUrK7S0AbOvcHmzzA++qTmfB1UK264G0iAH
-----END CERTIFICATE-----
subject=/CN=localhost
issuer=/CN=localhost
---
No client certificate CA names sent
Peer signing digest: SHA512
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 1019 bytes and written 269 bytes
Verification error: self signed certificate
---
New, TLSv1.2, Cipher is ECDHE-RSA-AES256-GCM-SHA384
Server public key is 1024 bit
Secure Renegotiation IS supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : ECDHE-RSA-AES256-GCM-SHA384
    Session-ID: EE1156EF7A043D8173A15CB87FC41D8BB3F61517B8414D62065541FD97928592
    Session-ID-ctx: 
    Master-Key: 2E3037DCB9B4278B13DF68BE8111918D2D978F1B5F190052A0435E6BDD2ACE5751723FB13856C5E98F01240F88914768
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - 9f 82 12 97 ac 31 10 5b-65 4b 5d fb 71 e9 e8 02   .....1.[eK].q...
    0010 - cc 56 9a 1f 91 2b c2 22-7e 93 d9 42 cd 60 56 ab   .V...+."~..B.`V.
    0020 - 89 76 d6 95 7a b7 7e c7-6f d3 a2 95 a5 ee f2 b4   .v..z.~.o.......
    0030 - 4d 48 68 f1 bf 23 df 87-de dd 64 a5 24 1e 1c e7   MHh..#....d.$...
    0040 - 0b c3 f4 b2 c4 72 b9 61-26 3c 17 dd 78 61 68 dd   .....r.a&<..xah.
    0050 - b8 59 36 15 76 19 6f 19-19 14 73 df 2d 8b 66 71   .Y6.v.o...s.-.fq
    0060 - f2 83 0b 22 52 07 69 ba-83 15 0a cc 94 fe f9 07   ..."R.i.........
    0070 - 01 72 d2 18 de 60 42 c1-f5 8d 19 88 4b c9 74 bf   .r...`B.....K.t.
    0080 - ad f5 bf 2b 53 3b 42 ab-89 eb 0c 52 82 de 55 b3   ...+S;B....R..U.
    0090 - e0 8d 53 85 17 d3 3a 8a-1e 80 71 09 54 5d 3c f8   ..S...:...q.T]<.

    Start Time: 1581676499
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
cluFn7wTiGryunymYOu4RcffSxQluehd
Correct!
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAvmOkuifmMg6HL2YPIOjon6iWfbp7c3jx34YkYWqUH57SUdyJ
imZzeyGC0gtZPGujUSxiJSWI/oTqexh+cAMTSMlOJf7+BrJObArnxd9Y7YT2bRPQ
Ja6Lzb558YW3FZl87ORiO+rW4LCDCNd2lUvLE/GL2GWyuKN0K5iCd5TbtJzEkQTu
DSt2mcNn4rhAL+JFr56o4T6z8WWAW18BR6yGrMq7Q/kALHYW3OekePQAzL0VUYbW
JGTi65CxbCnzc/w4+mqQyvmzpWtMAzJTzAzQxNbkR2MBGySxDLrjg0LWN6sK7wNX
x0YVztz/zbIkPjfkU1jHS+9EbVNj+D1XFOJuaQIDAQABAoIBABagpxpM1aoLWfvD
KHcj10nqcoBc4oE11aFYQwik7xfW+24pRNuDE6SFthOar69jp5RlLwD1NhPx3iBl
J9nOM8OJ0VToum43UOS8YxF8WwhXriYGnc1sskbwpXOUDc9uX4+UESzH22P29ovd
d8WErY0gPxun8pbJLmxkAtWNhpMvfe0050vk9TL5wqbu9AlbssgTcCXkMQnPw9nC
YNN6DDP2lbcBrvgT9YCNL6C+ZKufD52yOQ9qOkwFTEQpjtF4uNtJom+asvlpmS8A
vLY9r60wYSvmZhNqBUrj7lyCtXMIu1kkd4w7F77k+DjHoAXyxcUp1DGL51sOmama
+TOWWgECgYEA8JtPxP0GRJ+IQkX262jM3dEIkza8ky5moIwUqYdsx0NxHgRRhORT
8c8hAuRBb2G82so8vUHk/fur85OEfc9TncnCY2crpoqsghifKLxrLgtT+qDpfZnx
SatLdt8GfQ85yA7hnWWJ2MxF3NaeSDm75Lsm+tBbAiyc9P2jGRNtMSkCgYEAypHd
HCctNi/FwjulhttFx/rHYKhLidZDFYeiE/v45bN4yFm8x7R/b0iE7KaszX+Exdvt
SghaTdcG0Knyw1bpJVyusavPzpaJMjdJ6tcFhVAbAjm7enCIvGCSx+X3l5SiWg0A
R57hJglezIiVjv3aGwHwvlZvtszK6zV6oXFAu0ECgYAbjo46T4hyP5tJi93V5HDi
Ttiek7xRVxUl+iU7rWkGAXFpMLFteQEsRr7PJ/lemmEY5eTDAFMLy9FL2m9oQWCg
R8VdwSk8r9FGLS+9aKcV5PI/WEKlwgXinB3OhYimtiG2Cg5JCqIZFHxD6MjEGOiu
L8ktHMPvodBwNsSBULpG0QKBgBAplTfC1HOnWiMGOU3KPwYWt0O6CdTkmJOmL8Ni
blh9elyZ9FsGxsgtRBXRsqXuz7wtsQAgLHxbdLq/ZJQ7YfzOKU4ZxEnabvXnvWkU
YOdjHdSOoKvDQNWu6ucyLRAWFuISeXw9a/9p7ftpxm0TSgyvmfLF2MIAEwyzRqaM
77pBAoGAMmjmIJdjp+Ez8duyn3ieo36yrttF5NSsJLAbxFpdlc1gvtGCWW+9Cq0b
dxviW8+TFVEBl1O4f7HVm6EpTscdDxU+bCXWkfjuRb7Dy9GOtt9JPsX8MBTakzh3
vBgsyi/sN3RqRBcGU40fOoZyfAMT8s1m/uYv52O6IgeuZ/ujbjY=
-----END RSA PRIVATE KEY-----

closed



bandit16@bandit:~$ openssl s_client -connect localhost:31518 -ign_eof
CONNECTED(00000003)
depth=0 CN = localhost
verify error:num=18:self signed certificate
verify return:1
depth=0 CN = localhost
verify return:1
---
Certificate chain
 0 s:/CN=localhost
   i:/CN=localhost
---
Server certificate
-----BEGIN CERTIFICATE-----
MIICBjCCAW+gAwIBAgIES250rzANBgkqhkiG9w0BAQUFADAUMRIwEAYDVQQDDAls
b2NhbGhvc3QwHhcNMjAwMjA5MjA0NzIwWhcNMjEwMjA4MjA0NzIwWjAUMRIwEAYD
VQQDDAlsb2NhbGhvc3QwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBANWyxh7K
T86zWM4NFe95x2KNEBUDz2XlGvU7KxUM9z1OfakmLDYCiujYdR6gI4ZBtyhEql5P
taCiNWO+ZDJCKWhjH/TyIywxjW9/PBHRC8UEzhsxc0wMHbLrlYFwzxT2KjhI3EVY
5VIWkzKrgHuON6PuBbmN0g0z5NN/xYch4kPpAgMBAAGjZTBjMBQGA1UdEQQNMAuC
CWxvY2FsaG9zdDBLBglghkgBhvhCAQ0EPhY8QXV0b21hdGljYWxseSBnZW5lcmF0
ZWQgYnkgTmNhdC4gU2VlIGh0dHBzOi8vbm1hcC5vcmcvbmNhdC8uMA0GCSqGSIb3
DQEBBQUAA4GBAFX4+KlTXWb4R/pUVt7i4FWvp3CuqgLUtgU3vRZqJ3wShIyDbsFK
a4S9uSuWcLLvyq0aa4kLhmoepyNlI3BGUSZZbRXwo/1e5IpCX3RdHhlIc3/Sd7ln
usTkejgEftWMmmBc03RY07EMxbNeXE8zzh2NP+5kVfwWG6GoGuQMXhy8
-----END CERTIFICATE-----
subject=/CN=localhost
issuer=/CN=localhost
---
No client certificate CA names sent
Peer signing digest: SHA512
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 1019 bytes and written 269 bytes
Verification error: self signed certificate
---
New, TLSv1.2, Cipher is ECDHE-RSA-AES256-GCM-SHA384
Server public key is 1024 bit
Secure Renegotiation IS supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : ECDHE-RSA-AES256-GCM-SHA384
    Session-ID: 8F0B20A8164B9ED461FBD0721FA2A8AA489C77A00124ACE93381D0512F7A2740
    Session-ID-ctx: 
    Master-Key: F880B59CBA1854941DFA1C725F833F75B1177248D9651876542343A15AF9E24A45078F96FD305D27CFBE70486DF2EAA3
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - 26 1a 05 91 72 ce a3 a6-e5 fa 17 b1 24 c4 2b 6f   &...r.......$.+o
    0010 - 1d a9 b9 da 93 9a 35 e5-f1 7e fc 83 02 92 06 6a   ......5..~.....j
    0020 - d3 db 90 bb ec c3 bb c3-fe 8f a3 af 08 39 47 35   .............9G5
    0030 - 61 90 8c 2b 82 e3 28 b3-16 e9 f9 6a 4c c1 59 2d   a..+..(....jL.Y-
    0040 - c3 50 40 7a ca b9 c0 54-c8 d9 0b 9b f0 2c 7b fa   .P@z...T.....,{.
    0050 - c7 a4 9a bf c7 f6 e6 0e-bf 07 dc 50 a3 bf 23 48   ...........P..#H
    0060 - e9 0f f3 fb b9 b4 39 1d-c0 0d 71 e2 80 05 fe e7   ......9...q.....
    0070 - ed 38 48 55 d7 f0 b7 97-f1 a1 c2 06 1b 47 7d 51   .8HU.........G}Q
    0080 - 1e cc 4d e8 0e 76 73 0a-20 24 37 6f 20 c7 ca e7   ..M..vs. $7o ...
    0090 - 5b bc 44 09 ad d6 8d 5c-e3 96 86 fd 7d d8 41 75   [.D....\....}.Au

    Start Time: 1581676568
    Timeout   : 7200 (sec)
    Verify return code: 18 (self signed certificate)
    Extended master secret: yes
---
cluFn7wTiGryunymYOu4RcffSxQluehd
cluFn7wTiGryunymYOu4RcffSxQluehd

^C
bandit16@bandit:~$ 

```

nmap扫端口是真的快









### level 18



```sh
bl@bl-virtual-machine:~/wargame$ echo '-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAvmOkuifmMg6HL2YPIOjon6iWfbp7c3jx34YkYWqUH57SUdyJ
imZzeyGC0gtZPGujUSxiJSWI/oTqexh+cAMTSMlOJf7+BrJObArnxd9Y7YT2bRPQ
Ja6Lzb558YW3FZl87ORiO+rW4LCDCNd2lUvLE/GL2GWyuKN0K5iCd5TbtJzEkQTu
DSt2mcNn4rhAL+JFr56o4T6z8WWAW18BR6yGrMq7Q/kALHYW3OekePQAzL0VUYbW
JGTi65CxbCnzc/w4+mqQyvmzpWtMAzJTzAzQxNbkR2MBGySxDLrjg0LWN6sK7wNX
x0YVztz/zbIkPjfkU1jHS+9EbVNj+D1XFOJuaQIDAQABAoIBABagpxpM1aoLWfvD
KHcj10nqcoBc4oE11aFYQwik7xfW+24pRNuDE6SFthOar69jp5RlLwD1NhPx3iBl
J9nOM8OJ0VToum43UOS8YxF8WwhXriYGnc1sskbwpXOUDc9uX4+UESzH22P29ovd
d8WErY0gPxun8pbJLmxkAtWNhpMvfe0050vk9TL5wqbu9AlbssgTcCXkMQnPw9nC
YNN6DDP2lbcBrvgT9YCNL6C+ZKufD52yOQ9qOkwFTEQpjtF4uNtJom+asvlpmS8A
vLY9r60wYSvmZhNqBUrj7lyCtXMIu1kkd4w7F77k+DjHoAXyxcUp1DGL51sOmama
+TOWWgECgYEA8JtPxP0GRJ+IQkX262jM3dEIkza8ky5moIwUqYdsx0NxHgRRhORT
8c8hAuRBb2G82so8vUHk/fur85OEfc9TncnCY2crpoqsghifKLxrLgtT+qDpfZnx
SatLdt8GfQ85yA7hnWWJ2MxF3NaeSDm75Lsm+tBbAiyc9P2jGRNtMSkCgYEAypHd
HCctNi/FwjulhttFx/rHYKhLidZDFYeiE/v45bN4yFm8x7R/b0iE7KaszX+Exdvt
SghaTdcG0Knyw1bpJVyusavPzpaJMjdJ6tcFhVAbAjm7enCIvGCSx+X3l5SiWg0A
R57hJglezIiVjv3aGwHwvlZvtszK6zV6oXFAu0ECgYAbjo46T4hyP5tJi93V5HDi
Ttiek7xRVxUl+iU7rWkGAXFpMLFteQEsRr7PJ/lemmEY5eTDAFMLy9FL2m9oQWCg
R8VdwSk8r9FGLS+9aKcV5PI/WEKlwgXinB3OhYimtiG2Cg5JCqIZFHxD6MjEGOiu
L8ktHMPvodBwNsSBULpG0QKBgBAplTfC1HOnWiMGOU3KPwYWt0O6CdTkmJOmL8Ni
blh9elyZ9FsGxsgtRBXRsqXuz7wtsQAgLHxbdLq/ZJQ7YfzOKU4ZxEnabvXnvWkU
YOdjHdSOoKvDQNWu6ucyLRAWFuISeXw9a/9p7ftpxm0TSgyvmfLF2MIAEwyzRqaM
77pBAoGAMmjmIJdjp+Ez8duyn3ieo36yrttF5NSsJLAbxFpdlc1gvtGCWW+9Cq0b
dxviW8+TFVEBl1O4f7HVm6EpTscdDxU+bCXWkfjuRb7Dy9GOtt9JPsX8MBTakzh3
vBgsyi/sN3RqRBcGU40fOoZyfAMT8s1m/uYv52O6IgeuZ/ujbjY=
-----END RSA PRIVATE KEY-----' > b16.rsa

bl@bl-virtual-machine:~/wargame$ ssh bandit17@bandit.labs.overthewire.org -p 2220 -i b16.rsa 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@         WARNING: UNPROTECTED PRIVATE KEY FILE!          @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Permissions 0644 for 'b16.rsa' are too open.
It is required that your private key files are NOT accessible by others.
This private key will be ignored.
Load key "b16.rsa": bad permissions
bandit17@bandit.labs.overthewire.org's password: 

bl@bl-virtual-machine:~/wargame$ chmod 600 b16.rsa 
bl@bl-virtual-machine:~/wargame$ ssh bandit17@bandit.labs.overthewire.org -p 2220 -i b16.rsa 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames


bandit17@bandit:~$ cat /etc/bandit_pass/bandit17
xLYVMN9WE5zQ5vHacb0sZEVqbrp7nBTn

```

之前没注意，ssh私钥需要600权限，登进去之后就顺手看了下密码



```sh

bandit17@bandit:~$ ls
passwords.new  passwords.old
bandit17@bandit:~$ strings passwords.old
4d22drdsITVoHcfd8bAHeeKrdL3mMHpU
QeGg8ya1PGU13yp57EWuUaxErl8VWjlM
CUGTwQyhKs4fEQLH0UdD7ywCrYBDceZ7
2hUdQXUPpBJKzkslSHCOiC3ytdJ1cuqI
WxgyH7990nLi81smXOeDGnKTpZTlAU3f
g4diRjbnq4PhyC1rfuCaFXZmBLgHPmo6
MBf7rFYTik6DurpaVdC5mXngsTiXWwhv
3zt8L6QnDKXLGWhRvQBUczrk6O5KLl7i
bm9g6Ypy9zVLojtpPaKBKViAKnL19QEY
N2rkdeuoi1RBXCiCDQWlk4BU76M3wJFv
PR0AOkN4NodK61ewgBHS56sEDr3LAobb
CaVTEQzrWPuDvBm9D4CGL8BSC4arizFq
FgheNL06s1UCW8UiuFUWSmtGedi2TxIH
Lvh1gpC39tdJMAJH0atjJLF4yRlCoSH4
OpTHYem6UHMY2zLgwm2sI4e1faHw0M1b
Z84471LxMWArPnxJGsMmvvl2qCcBXZ7M
CExYI7LMdZLSj9AiFp8rutQY6uIcqdfx
lC1IFZxlnj05ZuWKY5Ytad9bTZ0eMgYC
4OfOZR4CMqlUFgxw8nZbKtW3eJcZPrqn
bbctuDOWMvYUCWAiY7APEUnYPUo0zYiT
sCepFVPJBglEuU8uY0LllG1oIJ2HOvrH
o9sp7odH3blIlshg2aCrWPdzuDq5lxx5
97Vd3224QGOfsPGwjURphDfn7ISeXd3S
Tz97n5taD1ZskKSlC1WHDU1CZZ5I3PnM
NDkYNzqHAZnjn7GoKk6kUjmBwLbZ5IjT
pd1THzlzKbAnR9uPnI75EpXdZVUFyVD9
GGwbSfJpRjzYvNHb1n2riVU3VnxCSe9I
qLufXtxv2XKcjrWDqIojlINiJhU9LYCp
kpxAYarBToFo4Vsr1jDBQREvRtbUA9i2
s8ZEkk0YuNoA9YnyUvVwFy29cMIP4psJ
m0q33SCpHDBfTL2yRb8Db2lb6qIX8hjf
xhHqvStzyrj0k1eLNbiQHmadzlY80iZg
FExGbU63PyeJsfxtoIaVjiFKXAhEon0C
04y09Cd0CvZBSnrC1BjauTj70D3P84Gw
Kr58zsSpmfKy4ILtUqbo2hqooPHnI13L
ruisEF4OA3MyOdLEFwVdW84ZwJXRioRT
kN2hWkHUehtqqWpnZW1CulYiOv8RJwPl
V045YMJnMGdta9yQD8ALdny0hholXmdw
gZ5U640FLMMChheWKHNdaQ1lKzLuqjxZ
Al0xVJb5bEzhnFG8nPFe6IJa2FjXVSzo
CT2ZJy6MoLkTqdHuhL5zUIsW41WCntAA
hlbSBPAWJmL6WFDb06gpTx1pPButblOA
46lUvvv0JJzyY0IOhWgGp5IjfsllmvaC
FcSd4Me936rwbk2pAU9ylx9NXTrzdCaX
vfU4mCzATtqUMNLg3a7mPs3OY6Dr4jaZ
mOWgkKPfjXibrdfgG57CWMcbeqBRg4IU
VudOaCtkUbhOdF7dE7KACOqH0R9weDhQ
vzwsuF0cp5IrmEmGb7qNr4VUlsLi463t
ymAqpKh2CPdC7iqFk4KcKdlXeKZqSrhW
ta02hN70k7BoxfiVn7viAFoWKaGDOKnC
bPLvqxn5BDtg4wy8c2uO0x7y3yi3RPMU
VUcDEAfnRTt8nTlAd55q94L6rr0jfCCU
QAIDBC5fx4bBOsyOd8NYItiPWGMaGXY9
X1NUQJrIsrNfaGHMUolOcepDiNss842e
DAL411ARIMja2B3VibQxzNn8iqxCvtPB
Gq0BvsinoaBAuqwLJwtWCSe1wMdiSBSZ
RVO0eC5aK1WRlpKqPAglNSOPwc1OvUp8
XCBD77G8bknfL90F44o0Nbe1jqCBvxqh
qOZOpK7UHdGgsZeQirx8wr9omjopkzuP
nQ1IO5OUcJ4P8ZSrLYNQLFnWS32AMUcE
oUpDAclcfOrSI10qeUCHqxvSxR0aXyrN
uzPVdEpMDIvTBj3eB4mgmhEeCg1WEFqL
WThihtgEnlmNQ6SAqROgERjyxNfgJZk5
l9sPHyleBjYNlZxQbHiCKNoeEfL7W3RA
qfcmi6vHWL5CS7nqkHTcSdeRIoxDEGjU
cI4zMnmzAP4Ei6FvZQ4vgvUhrhKYajGH
MlKrQsbeU3cvq0GNIvwSMipBFUCHRLb4
yqPoTs4J1oNw6KqREjqQk1fXNxAtQzNN
6HgQNDvsu4VC7KBhIpQRCIRhLo4izRjG
nPhoiXgdg3T385gjubCcKtnEa2kSQYiF
BBWqlFI2IycHpCSESbmi8bgQ3XaRVkH9
zC5qgaooKVu5QNTtqEXcgPpmX2IXZcd5
BP8DJZaleBMYuyMzG96xJ6RDk6QUvLoi
NsYnz4oTlDRKsDyWWVvseAeLnrVz80ul
2MVRp5Pej7Ngv3QlcfY9MhFrpm1EER3U
niQz99Dp18DDLdpkqxatJEorlEuxbffD
0LZ5juRJ7Kpn9Y1d2tnXjZY5Qe5YsoSn
DFkA6xfENw4qcgbyJOR1Lq4wHzoEzXf1
DuyGtXuifUSHgURCvn8wW8ZVGkMFEwCG
lsp7PdEBOlGtgQaiZA1BMdxpHPA0YPCt
fZPxMUd4y9F8Ty8W36yMVQRVxJ7M1n4B
rNnhvIf0O32W7YkNFetirVBSHpxx8PVa
IAvk989y4J29tuDjZlSUAcQJ0GKlSLA7
6h32PPx4KHY0pxOVSViJDOzjaidS79i5
3bCdLIIpnsFeobeQnORAVeM7dwvlRhYc
VlaVTJjuHSNlmnukU27pLKfjQDcpFm0R
jVxCHhuF6NHsDa6UdNHgBdNIDH7SZzCE
tY71skfE2Y1Tez1451HdcwjueU9wWO9S
JUplInoYI9VmMuoTU64WX9fQgljz0SRr
YCScjMB7OB5QL8ZiPgyd7wRqlsqhjjGu
3fBUnc3gvyg7iyW1V4D0quYJPM3iNNy4
mrbw5khrpkAXdNfkTs6Eqzj8Am07I4CK
crz9kBtBVlvTVZnvJ3AqfeFYuw89koZh
uD036o50sDvVj9JU0ZMi76np4kE2SLw6
6QX3T8Ul4qgruVmX0Vx8h7H8GkTyAoZ1
EbdKERioX8ShHYhFCIFVIyvP13kL75jA
QyRSUG1osue0Rrc114FF98YH7HjJWPgJ
jMxInIjNK0ChvSQX10862VqCwIQsek95
2pqtLZiT8CzsalDfnn68FjdhbtgqEK1C
80JH1LNM5JFed5XQBVYeiKU5qNNqDjLS
bandit17@bandit:~$ strings passwords.new
4d22drdsITVoHcfd8bAHeeKrdL3mMHpU
QeGg8ya1PGU13yp57EWuUaxErl8VWjlM
CUGTwQyhKs4fEQLH0UdD7ywCrYBDceZ7
2hUdQXUPpBJKzkslSHCOiC3ytdJ1cuqI
WxgyH7990nLi81smXOeDGnKTpZTlAU3f
g4diRjbnq4PhyC1rfuCaFXZmBLgHPmo6
MBf7rFYTik6DurpaVdC5mXngsTiXWwhv
3zt8L6QnDKXLGWhRvQBUczrk6O5KLl7i
bm9g6Ypy9zVLojtpPaKBKViAKnL19QEY
N2rkdeuoi1RBXCiCDQWlk4BU76M3wJFv
PR0AOkN4NodK61ewgBHS56sEDr3LAobb
CaVTEQzrWPuDvBm9D4CGL8BSC4arizFq
FgheNL06s1UCW8UiuFUWSmtGedi2TxIH
Lvh1gpC39tdJMAJH0atjJLF4yRlCoSH4
OpTHYem6UHMY2zLgwm2sI4e1faHw0M1b
Z84471LxMWArPnxJGsMmvvl2qCcBXZ7M
CExYI7LMdZLSj9AiFp8rutQY6uIcqdfx
lC1IFZxlnj05ZuWKY5Ytad9bTZ0eMgYC
4OfOZR4CMqlUFgxw8nZbKtW3eJcZPrqn
bbctuDOWMvYUCWAiY7APEUnYPUo0zYiT
sCepFVPJBglEuU8uY0LllG1oIJ2HOvrH
o9sp7odH3blIlshg2aCrWPdzuDq5lxx5
97Vd3224QGOfsPGwjURphDfn7ISeXd3S
Tz97n5taD1ZskKSlC1WHDU1CZZ5I3PnM
NDkYNzqHAZnjn7GoKk6kUjmBwLbZ5IjT
pd1THzlzKbAnR9uPnI75EpXdZVUFyVD9
GGwbSfJpRjzYvNHb1n2riVU3VnxCSe9I
qLufXtxv2XKcjrWDqIojlINiJhU9LYCp
kpxAYarBToFo4Vsr1jDBQREvRtbUA9i2
s8ZEkk0YuNoA9YnyUvVwFy29cMIP4psJ
m0q33SCpHDBfTL2yRb8Db2lb6qIX8hjf
xhHqvStzyrj0k1eLNbiQHmadzlY80iZg
FExGbU63PyeJsfxtoIaVjiFKXAhEon0C
04y09Cd0CvZBSnrC1BjauTj70D3P84Gw
Kr58zsSpmfKy4ILtUqbo2hqooPHnI13L
ruisEF4OA3MyOdLEFwVdW84ZwJXRioRT
kN2hWkHUehtqqWpnZW1CulYiOv8RJwPl
V045YMJnMGdta9yQD8ALdny0hholXmdw
gZ5U640FLMMChheWKHNdaQ1lKzLuqjxZ
Al0xVJb5bEzhnFG8nPFe6IJa2FjXVSzo
CT2ZJy6MoLkTqdHuhL5zUIsW41WCntAA
kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd
46lUvvv0JJzyY0IOhWgGp5IjfsllmvaC
FcSd4Me936rwbk2pAU9ylx9NXTrzdCaX
vfU4mCzATtqUMNLg3a7mPs3OY6Dr4jaZ
mOWgkKPfjXibrdfgG57CWMcbeqBRg4IU
VudOaCtkUbhOdF7dE7KACOqH0R9weDhQ
vzwsuF0cp5IrmEmGb7qNr4VUlsLi463t
ymAqpKh2CPdC7iqFk4KcKdlXeKZqSrhW
ta02hN70k7BoxfiVn7viAFoWKaGDOKnC
bPLvqxn5BDtg4wy8c2uO0x7y3yi3RPMU
VUcDEAfnRTt8nTlAd55q94L6rr0jfCCU
QAIDBC5fx4bBOsyOd8NYItiPWGMaGXY9
X1NUQJrIsrNfaGHMUolOcepDiNss842e
DAL411ARIMja2B3VibQxzNn8iqxCvtPB
Gq0BvsinoaBAuqwLJwtWCSe1wMdiSBSZ
RVO0eC5aK1WRlpKqPAglNSOPwc1OvUp8
XCBD77G8bknfL90F44o0Nbe1jqCBvxqh
qOZOpK7UHdGgsZeQirx8wr9omjopkzuP
nQ1IO5OUcJ4P8ZSrLYNQLFnWS32AMUcE
oUpDAclcfOrSI10qeUCHqxvSxR0aXyrN
uzPVdEpMDIvTBj3eB4mgmhEeCg1WEFqL
WThihtgEnlmNQ6SAqROgERjyxNfgJZk5
l9sPHyleBjYNlZxQbHiCKNoeEfL7W3RA
qfcmi6vHWL5CS7nqkHTcSdeRIoxDEGjU
cI4zMnmzAP4Ei6FvZQ4vgvUhrhKYajGH
MlKrQsbeU3cvq0GNIvwSMipBFUCHRLb4
yqPoTs4J1oNw6KqREjqQk1fXNxAtQzNN
6HgQNDvsu4VC7KBhIpQRCIRhLo4izRjG
nPhoiXgdg3T385gjubCcKtnEa2kSQYiF
BBWqlFI2IycHpCSESbmi8bgQ3XaRVkH9
zC5qgaooKVu5QNTtqEXcgPpmX2IXZcd5
BP8DJZaleBMYuyMzG96xJ6RDk6QUvLoi
NsYnz4oTlDRKsDyWWVvseAeLnrVz80ul
2MVRp5Pej7Ngv3QlcfY9MhFrpm1EER3U
niQz99Dp18DDLdpkqxatJEorlEuxbffD
0LZ5juRJ7Kpn9Y1d2tnXjZY5Qe5YsoSn
DFkA6xfENw4qcgbyJOR1Lq4wHzoEzXf1
DuyGtXuifUSHgURCvn8wW8ZVGkMFEwCG
lsp7PdEBOlGtgQaiZA1BMdxpHPA0YPCt
fZPxMUd4y9F8Ty8W36yMVQRVxJ7M1n4B
rNnhvIf0O32W7YkNFetirVBSHpxx8PVa
IAvk989y4J29tuDjZlSUAcQJ0GKlSLA7
6h32PPx4KHY0pxOVSViJDOzjaidS79i5
3bCdLIIpnsFeobeQnORAVeM7dwvlRhYc
VlaVTJjuHSNlmnukU27pLKfjQDcpFm0R
jVxCHhuF6NHsDa6UdNHgBdNIDH7SZzCE
tY71skfE2Y1Tez1451HdcwjueU9wWO9S
JUplInoYI9VmMuoTU64WX9fQgljz0SRr
YCScjMB7OB5QL8ZiPgyd7wRqlsqhjjGu
3fBUnc3gvyg7iyW1V4D0quYJPM3iNNy4
mrbw5khrpkAXdNfkTs6Eqzj8Am07I4CK
crz9kBtBVlvTVZnvJ3AqfeFYuw89koZh
uD036o50sDvVj9JU0ZMi76np4kE2SLw6
6QX3T8Ul4qgruVmX0Vx8h7H8GkTyAoZ1
EbdKERioX8ShHYhFCIFVIyvP13kL75jA
QyRSUG1osue0Rrc114FF98YH7HjJWPgJ
jMxInIjNK0ChvSQX10862VqCwIQsek95
2pqtLZiT8CzsalDfnn68FjdhbtgqEK1C
80JH1LNM5JFed5XQBVYeiKU5qNNqDjLS
bandit17@bandit:~$ diff passwords.old passwords.new 
42c42
< hlbSBPAWJmL6WFDb06gpTx1pPButblOA
---
> kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd
bandit17@bandit:~$ 

```

这么长肯定不可能用肉眼去代替机器做的事嘛

所以就用到了`diff`命令

<为第一个文件，> 为第二个文件，因此flag为`kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd`



### level 19

```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit18@bandit.labs.overthewire.org -p 2220
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit18@bandit.labs.overthewire.org's password: 
#kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!


  Enjoy your stay!

Byebye !
Connection to bandit.labs.overthewire.org closed.
bl@bl-virtual-machine:~/wargame$ 

```



由上一关提示已经知道了，我们会看到byebye，直接看题目

`.bashrc`会禁止所有通过ssh登陆的

> 仅作了解，错误方向
>
> https://blog.csdn.net/luoluonuoyasuolong/article/details/88806211

一种方法是利用命令拼接，将命令作为参数传过去，在执行shell之前运行

```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit18@bandit.labs.overthewire.org -p 2220 'cat ./readme'
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit18@bandit.labs.overthewire.org's password: 
IueksS7Ubh8G3DCwVzrTd8rAVOwq3M5x

```

第二种方式利用scp命令绕过

```sh
bl@bl-virtual-machine:~/wargame$ scp -P 2220  bandit18@bandit.labs.overthewire.org:./readme  ./readme
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit18@bandit.labs.overthewire.org's password: 
readme                                        100%   33     0.0KB/s   00:00    
bl@bl-virtual-machine:~/wargame$ cat ./readme 
IueksS7Ubh8G3DCwVzrTd8rAVOwq3M5x
bl@bl-virtual-machine:~/wargame$ 
```



顺便爬下了他的`.bashrc`文件，这道题的万恶之源

```bash
# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
#[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    #alias grep='grep --color=auto'
    #alias fgrep='fgrep --color=auto'
    #alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
#alias ll='ls -l'
#alias la='ls -A'
#alias l='ls -CF'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi
echo 'Byebye !'
exit 0

```







### level 20



> 关于setuid：https://blog.csdn.net/oo__yan/article/details/7076889
>
> 



```sh
bandit19@bandit:~$ ls
bandit20-do
bandit19@bandit:~$ ./bandit20-do 
Run a command as another user.
  Example: ./bandit20-do id
bandit19@bandit:~$ strings bandit20-do 
/lib/ld-linux.so.2
libc.so.6
_IO_stdin_used
exit
execv
printf
__libc_start_main
__gmon_start__
GLIBC_2.0
PTRh0
QVhk
UWVS
t$,U
[^_]
Run a command as another user.
  Example: %s id
/usr/bin/env
;*2$"
GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
crtstuff.c
__JCR_LIST__
deregister_tm_clones
__do_global_dtors_aux
completed.6587
__do_global_dtors_aux_fini_array_entry
frame_dummy
__frame_dummy_init_array_entry
bandit20.c
__FRAME_END__
__JCR_END__
__init_array_end
_DYNAMIC
__init_array_start
__GNU_EH_FRAME_HDR
_GLOBAL_OFFSET_TABLE_
__libc_csu_fini
__x86.get_pc_thunk.bx
printf@@GLIBC_2.0
_edata
__data_start
__gmon_start__
exit@@GLIBC_2.0
__dso_handle
_IO_stdin_used
__libc_start_main@@GLIBC_2.0
execv@@GLIBC_2.0
__libc_csu_init
_fp_hw
__bss_start
main
__TMC_END__
.symtab
.strtab
.shstrtab
.interp
.note.ABI-tag
.note.gnu.build-id
.gnu.hash
.dynsym
.dynstr
.gnu.version
.gnu.version_r
.rel.dyn
.rel.plt
.init
.plt.got
.text
.fini
.rodata
.eh_frame_hdr
.eh_frame
.init_array
.fini_array
.jcr
.dynamic
.got.plt
.data
.bss
.comment
bandit19@bandit:~$ ./bandit20-do 
Run a command as another user.
  Example: ./bandit20-do id
bandit19@bandit:~$ ./bandit20-do  id
uid=11019(bandit19) gid=11019(bandit19) euid=11020(bandit20) groups=11019(bandit19)
bandit19@bandit:~$ ls -al
total 28
drwxr-xr-x  2 root     root     4096 Oct 16  2018 .
drwxr-xr-x 41 root     root     4096 Oct 16  2018 ..
-rwsr-x---  1 bandit20 bandit19 7296 Oct 16  2018 bandit20-do
-rw-r--r--  1 root     root      220 May 15  2017 .bash_logout
-rw-r--r--  1 root     root     3526 May 15  2017 .bashrc
-rw-r--r--  1 root     root      675 May 15  2017 .profile
bandit19@bandit:~$ ./bandit20-do whoami
bandit20
bandit19@bandit:~$ ./bandit20-do cat /etc/bandit_pass/bandit20
GbKksEFF4yrVs6il55v6gwY5aVje5f0j
bandit19@bandit:~$ 

```



这一关涉及到的是linux权限的相关知识。/etc/bandit_pass/bandit20的所有者为bandit20，而其权限设置使得只有自身和bandit20这个group的成员能够读取。

setuid这个文件的拥有者为bandit20，而bandit19，也就是当前登录用户有执行的权限。而该文件有s权限，即setuid权限。能够在程序中调用setuid()系统调用，将自身的suid改成与euid相同，也就是在运行中作为bandit20执行命令。

对于手头的这个文件，只要将欲执行的命令作为参数传入即可。

这样的文件如果能够通过一定方式执行命令甚至于获得shell，是渗透人员理想的提权途径。





### level 21

题目的意思是有一个setuid的执行文件，他会和localhost的给定端口建立连接，然后他会从连接中读取一行信息，将其和前一关的flag对比，正确就会返回flag



```sh
bandit20@bandit:~$ ls -al
total 32
drwxr-xr-x  2 root     root      4096 Oct 16  2018 .
drwxr-xr-x 41 root     root      4096 Oct 16  2018 ..
-rw-r--r--  1 root     root       220 May 15  2017 .bash_logout
-rw-r--r--  1 root     root      3526 May 15  2017 .bashrc
-rw-r--r--  1 root     root       675 May 15  2017 .profile
-rwsr-x---  1 bandit21 bandit20 12088 Oct 16  2018 suconnect
bandit20@bandit:~$ ./suconnect 
Usage: ./suconnect <portnumber>
This program will connect to the given port on localhost using TCP. If it receives the correct password from the other side, the next password is transmitted back.
bandit20@bandit:~$ nc -lp 2333 < /etc/bandit_pass/bandit20
gE269g2h3mw3pwgrj0Ha9Uoqen1c9DGr
bandit20@bandit:~$ 
```

利用nc监听端口即可做到

```sh
bandit20@bandit:~$ 
bandit20@bandit:~$ ls
suconnect
bandit20@bandit:~$ ./suconnect 2333
Read: GbKksEFF4yrVs6il55v6gwY5aVje5f0j
Password matches, sending next password
bandit20@bandit:~$ 
```







### level 22



这关原以为是让了解crontab的用法，没想到看执行文件干了什么就得到了flag

```sh
bandit21@bandit:~$ cat /etc/bandit_pass/bandit21
gE269g2h3mw3pwgrj0Ha9Uoqen1c9DGr
bandit21@bandit:~$ ls /etc/cron.d/
atop  cronjob_bandit22  cronjob_bandit23  cronjob_bandit24
bandit21@bandit:~$ cat /etc/cron.d/atop
PATH=/bin:/usr/bin:/sbin:/usr/sbin

# daily restart of atop at midnight
0 0 * * * root if [ -d "/run/systemd/system" ]; then systemctl restart atop; else /usr/share/atop/atop.daily \& ; fi
bandit21@bandit:~$ cat /etc/cron.d/cronjob_bandit22
@reboot bandit22 /usr/bin/cronjob_bandit22.sh &> /dev/null
* * * * * bandit22 /usr/bin/cronjob_bandit22.sh &> /dev/null
bandit21@bandit:~$ cat /usr/bin/cronjob_bandit22.sh 
#!/bin/bash
chmod 644 /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
cat /etc/bandit_pass/bandit22 > /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
bandit21@bandit:~$ cat /usr/bin/cronjob_bandit23.sh 
cat: /usr/bin/cronjob_bandit23.sh: Permission denied
bandit21@bandit:~$ crontab -l
crontabs/bandit21/: fopen: Permission denied
bandit21@bandit:~$ cat /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
Yk7owGAcWjwMVRwrTesJEwB7WVOiILLI

```





### level 23

> https://www.linuxidc.com/Linux/2019-03/157335.htm
>
> 其他的：
>
> https://blog.csdn.net/long2746004900/article/details/53367353
>
> https://blog.csdn.net/zhongqi2513/article/details/78613768



这关的核心还是阅读shell文件

题目也十分温馨的提醒了，若是不懂可以运行运行debug



```sh
bandit22@bandit:~$ ls /etc/cron.d
atop  cronjob_bandit22  cronjob_bandit23  cronjob_bandit24
bandit22@bandit:~$ cat /etc/cron.d/cronjob_bandit23
@reboot bandit23 /usr/bin/cronjob_bandit23.sh  &> /dev/null
* * * * * bandit23 /usr/bin/cronjob_bandit23.sh  &> /dev/null
bandit22@bandit:~$ cat /usr/bin/cron
cronjob_bandit22.sh  cronjob_bandit24.sh  
cronjob_bandit23.sh  crontab              
bandit22@bandit:~$ cat /usr/bin/cronjob_bandit23.sh
#!/bin/bash

myname=$(whoami)
mytarget=$(echo I am user $myname | md5sum | cut -d ' ' -f 1)

echo "Copying passwordfile /etc/bandit_pass/$myname to /tmp/$mytarget"

cat /etc/bandit_pass/$myname > /tmp/$mytarget
bandit22@bandit:~$ echo I am user $myname | md5sum | cut -d ' ' -f 1
7db97df393f40ad1691b6e1fb03d53eb
bandit22@bandit:~$ cat /tmp/7db97df393f40ad1691b6e1fb03d53eb
Yk7owGAcWjwMVRwrTesJEwB7WVOiILLI
bandit22@bandit:~$ whoami
bandit22
bandit22@bandit:~$ /usr/bin/cronjob_bandit23.sh  &> /dev/null
bandit22@bandit:~$ /usr/bin/cronjob_bandit23.sh 
Copying passwordfile /etc/bandit_pass/bandit22 to /tmp/8169b67bd894ddbb4412f91573b38db3
bandit22@bandit:~$ ls -al /usr/bin/cronjob_bandit23.sh
-rwxr-x--- 1 bandit23 bandit22 211 Oct 16  2018 /usr/bin/cronjob_bandit23.sh
bandit22@bandit:~$ echo I am user bandit23 | md5sum | cut -d ' ' -f 1
8ca319486bfbbc3663ea0fbe81326349
bandit22@bandit:~$ cat /tmp/8ca319486bfbbc3663ea0fbe81326349
jc1udXuA1tiHqjIsL8yaapX5XIAI6i0n
bandit22@bandit:~$ 


```

但是这里有个坑，忽然发现得到的flag和上次一样，注意到该sh是bandit23所执行的，属于bandit22组，所以用户名应该是bandit23

最后查询的flag进入下一关



### level 24

老套路，打开sh阅读源码

这是一个能运行并删除某个文件夹里所有脚本文件的脚本（这里用到timeout去执行任何文件

所以我们需要自己写一个脚本去获取密码

```sh
bandit23@bandit:~$ cat /etc/cron.d/cronjob_bandit24 
@reboot bandit24 /usr/bin/cronjob_bandit24.sh &> /dev/null
* * * * * bandit24 /usr/bin/cronjob_bandit24.sh &> /dev/null
bandit23@bandit:~$ cat /usr/bin/cronjob_bandit24.sh
#!/bin/bash

myname=$(whoami)

cd /var/spool/$myname
echo "Executing and deleting all scripts in /var/spool/$myname:"
for i in * .*;
do
    if [ "$i" != "." -a "$i" != ".." ];
    then
	echo "Handling $i"
	timeout -s 9 60 ./$i
	rm -f ./$i
    fi
done


bandit23@bandit:~$ ls -al /usr/bin/cronjob_bandit24.sh
-rwxr-x--- 1 bandit24 bandit23 253 Oct 16  2018 /usr/bin/cronjob_bandit24.sh
bandit23@bandit:~$ ls /var/spool/bandit24
ls: cannot open directory '/var/spool/bandit24': Permission denied
bandit23@bandit:~$ ls /var/spool/
bandit24  cron  mail  rsyslog
bandit23@bandit:~$ ls /var/spool/ -al
total 1348
drwxr-xr-x  5 root root        4096 Oct 16  2018 .
drwxr-xr-x 11 root root        4096 Oct 16  2018 ..
drwxrwx-wx 37 root bandit24 1359872 Feb 16 10:41 bandit24
drwxr-xr-x  3 root root        4096 Oct 16  2018 cron
lrwxrwxrwx  1 root root           7 Oct 16  2018 mail -> ../mail
drwx------  2 root root        4096 Jan 14  2018 rsyslog
bandit23@bandit:~$ ls
bandit23@bandit:~$ touch fuck.sh
touch: cannot touch 'fuck.sh': Permission denied
bandit23@bandit:~$ touch /tmp/bandit23/fuck.sh
bandit23@bandit:~$ ls -al  /tmp/bandit23/
total 305956
drwxrwxrwx 7 bandit23 root          4096 Feb 16 10:56 .
drwxrws-wt 1 root     root     313204736 Feb 16 10:57 ..
-rw-r--r-- 1 bandit23 bandit23         0 Feb 16 10:56 fuck.sh
-rw-r--r-- 1 bandit24 bandit24         1 Feb 14 16:05 out
-rw-r--r-- 1 bandit24 bandit24         0 Feb 14 16:49 output
-rw-r--r-- 1 bandit24 bandit24        66 Feb 14 20:48 pass
drwxr-xr-x 3 bandit27 bandit27      4096 Feb  7 13:12 repo
drwxr-xr-x 3 bandit28 bandit28      4096 Feb  7 13:21 repo28
drwxr-xr-x 4 bandit29 bandit29      4096 Feb  7 13:28 repo29
drwxr-xr-x 3 bandit30 bandit30      4096 Feb  7 13:29 repo30
drwxr-xr-x 3 bandit31 bandit31      4096 Feb  7 13:55 repo31
-rwxrwxrwx 1 bandit23 bandit23        99 Feb 15 17:49 shell.sh
bandit23@bandit:~$ vim /tmp/bandit23/fuck.sh
bandit23@bandit:/tmp/bandit23$ cat fuck.sh
#!/bin/bash

cat /etc/bandit_pass/bandit24 >> /tmp/bandit23/bandit23_pass

bandit23@bandit:~$ chmod +x /tmp/bandit23/fuck.sh
bandit23@bandit:~$ 
bandit23@bandit:~$ cd /tmp/bandit23
bandit23@bandit:/tmp/bandit23$ ls
fuck.sh  out  output  pass  repo  repo28  repo29  repo30  repo31  shell.sh
bandit23@bandit:/tmp/bandit23$ cp fuck.sh /var/spool/bandit24/fuck.sh
bandit23@bandit:/tmp/bandit23$ ls
fuck.sh  out  output  pass  repo  repo28  repo29  repo30  repo31  shell.sh
bandit23@bandit:/tmp/bandit23$ ls
fuck.sh  out  output  pass  repo  repo28  repo29  repo30  repo31  shell.sh
bandit23@bandit:/tmp/bandit23$ ls
fuck.sh  out  output  pass  repo  repo28  repo29  repo30  repo31  shell.sh
bandit23@bandit:/tmp/bandit23$ ls
bandit23_pass  out     pass  repo28  repo30  shell.sh
fuck.sh        output  repo  repo29  repo31
bandit23@bandit:/tmp/bandit23$ cat bandit23_pass
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
bandit23@bandit:/tmp/bandit23$ 

```







### level 25



```sh
bandit24@bandit:~$ telnet localhost 30002
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 1
Timeout. Exiting.
Connection closed by foreign host.
bandit24@bandit:/tmp/bandit24$ nc localhost 30002
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 5201
Wrong! Please enter the correct pincode. Try again.
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 1213
Wrong! Please enter the correct pincode. Try again.
^C
bandit24@bandit:~$ cd /tmp/bandit24
bandit24@bandit:/tmp/bandit24$ ls
bandit24.sh   counters.txt  pass          pin_mod.py  pktempdir  tcol
bandit25.sh   getpass.sh    pass24.sh     pin.py      qsd.txt    test.txt
bash_file.sh  mine.sh       password.txt  pins        script.sh  wesh.sh
bandit24@bandit:/tmp/bandit24$ UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
-bash: UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ: command not found
bandit24@bandit:/tmp/bandit24$ nc localhost 30002 UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
 
Fail! You did not supply enough data. Try again.

UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 1

^C
bandit24@bandit:/tmp/bandit24$ ls
bandit24.sh   fuck24.sh   pass24.sh     pins       tcol
bandit25.sh   getpass.sh  password.txt  pktempdir  test.txt
bash_file.sh  mine.sh     pin_mod.py    qsd.txt    wesh.sh
counters.txt  pass        pin.py        script.sh
bandit24@bandit:/tmp/bandit24$ python
Python 2.7.13 (default, Sep 26 2018, 18:42:22) 
[GCC 6.3.0 20170516] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> exit()
bandit24@bandit:/tmp/bandit24$ touch fuck24.py
bandit24@bandit:/tmp/bandit24$ vim fuck24.py
bandit24@bandit:/tmp/bandit24$ touch pass24
bandit24@bandit:/tmp/bandit24$ cat fuck24.py
# !/usr/bin/env python

f = open('pass24','w')
passwd = 'UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ'
for i in range(10000):
    flag = passwd + ' ' + str(i).zfill(4) + '\n'
    f.write(flag)

f.close()

bandit24@bandit:/tmp/bandit24$ python fuck24.py
bandit24@bandit:/tmp/bandit24$ less pass24
bandit24@bandit:/tmp/bandit24$ nc localhost 30002 < pass24 > ans.txt
bandit24@bandit:/tmp/bandit24$ sort ans.txt | uniq -u

Correct!
Exiting.
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
The password of user bandit25 is uNG9O58gUE7snukf3bvZ0rxhtnjzSGzG
bandit24@bandit:/tmp/bandit24$ 

```



简单来说，有一个程序在监听30002端口，接收`$bandit24_pass pin`，需要我们爆破pin

这边利用python生成`pass24`字典

```python
# !/usr/bin/env python

f = open('pass24','w')
passwd = 'UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ'
for i in range(10000):
    flag = passwd + ' ' + str(i).zfill(4) + '\n'
    f.write(flag)

f.close()
```

然后通过`nc localhost 30002 < pass24 > ans.txt`命令将其传给守护程序，返回结果存入ans.txt

然后再ans.txt中找出不一样的即可

//TODO：后续想用单纯的shell脚本跑一波





### level26



```sh
bandit25@bandit:~$ ls
bandit26.sshkey
bandit25@bandit:~$ ssh bandit26@localhost -i bandit26.sshkey 
Could not create directory '/home/bandit25/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit25/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!

If you find any problems, please report them to Steven or morla on
irc.overthewire.org.

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

  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /  
 | |__   __ _ _ __   __| |_| |_   ) / /_  
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \ 
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/ 
Connection to localhost closed.
bandit25@bandit:~$ 
bandit25@bandit:~$ cat /etc/passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
_apt:x:100:65534::/nonexistent:/bin/false
messagebus:x:101:104::/var/run/dbus:/bin/false
sshd:x:102:65534::/run/sshd:/usr/sbin/nologin
identd:x:103:65534::/var/run/identd:/bin/false
ntp:x:104:107::/home/ntp:/bin/false
bandit0:x:11000:11000:bandit level 0:/home/bandit0:/bin/bash
bandit1:x:11001:11001:bandit level 1:/home/bandit1:/bin/bash
bandit10:x:11010:11010:bandit level 10:/home/bandit10:/bin/bash
bandit11:x:11011:11011:bandit level 11:/home/bandit11:/bin/bash
bandit12:x:11012:11012:bandit level 12:/home/bandit12:/bin/bash
bandit13:x:11013:11013:bandit level 13:/home/bandit13:/bin/bash
bandit14:x:11014:11014:bandit level 14:/home/bandit14:/bin/bash
bandit15:x:11015:11015:bandit level 15:/home/bandit15:/bin/bash
bandit16:x:11016:11016:bandit level 16:/home/bandit16:/bin/bash
bandit17:x:11017:11017:bandit level 17:/home/bandit17:/bin/bash
bandit18:x:11018:11018:bandit level 18:/home/bandit18:/bin/bash
bandit19:x:11019:11019:bandit level 19:/home/bandit19:/bin/bash
bandit2:x:11002:11002:bandit level 2:/home/bandit2:/bin/bash
bandit20:x:11020:11020:bandit level 20:/home/bandit20:/bin/bash
bandit21:x:11021:11021:bandit level 21:/home/bandit21:/bin/bash
bandit22:x:11022:11022:bandit level 22:/home/bandit22:/bin/bash
bandit23:x:11023:11023:bandit level 23:/home/bandit23:/bin/bash
bandit24:x:11024:11024:bandit level 24:/home/bandit24:/bin/bash
bandit25:x:11025:11025:bandit level 25:/home/bandit25:/bin/bash
bandit26:x:11026:11026:bandit level 26:/home/bandit26:/usr/bin/showtext
bandit27:x:11027:11027:bandit level 27:/home/bandit27:/bin/bash
bandit28:x:11028:11028:bandit level 28:/home/bandit28:/bin/bash
bandit29:x:11029:11029:bandit level 29:/home/bandit29:/bin/bash
bandit3:x:11003:11003:bandit level 3:/home/bandit3:/bin/bash
bandit30:x:11030:11030:bandit level 30:/home/bandit30:/bin/bash
bandit31:x:11031:11031:bandit level 31:/home/bandit31:/bin/bash
bandit32:x:11032:11032:bandit level 32:/home/bandit32:/home/bandit32/uppershell
bandit33:x:11033:11033:bandit level 33:/home/bandit33:/bin/bash
bandit4:x:11004:11004:bandit level 4:/home/bandit4:/bin/bash
bandit5:x:11005:11005:bandit level 5:/home/bandit5:/bin/bash
bandit6:x:11006:11006:bandit level 6:/home/bandit6:/bin/bash
bandit7:x:11007:11007:bandit level 7:/home/bandit7:/bin/bash
bandit8:x:11008:11008:bandit level 8:/home/bandit8:/bin/bash
bandit9:x:11009:11009:bandit level 9:/home/bandit9:/bin/bash
bandit27-git:x:11527:11527::/home/bandit27-git:/usr/bin/git-shell
bandit28-git:x:11528:11528::/home/bandit28-git:/usr/bin/git-shell
bandit29-git:x:11529:11529::/home/bandit29-git:/usr/bin/git-shell
bandit30-git:x:11530:11530::/home/bandit30-git:/usr/bin/git-shell
bandit31-git:x:11531:11531::/home/bandit31-git:/usr/bin/git-shell


```



`ls`有一个ssh私钥连上去之后，连接被关闭了

根据题目提示我们去看`/etc/passwd`

> https://blog.csdn.net/yexiangCSDN/article/details/89963698
>
> https://blog.csdn.net/zyy1659949090/article/details/88176215
>
> /etc/passwd这文件里存放里用户相关信息，包括指定登录shell
>
> 大概格式为：
> **用户名:口令:用户标识号uid:组标识号gid:注释性描述:主目录:指定登录shell**
>
> 



看到26关这一行是一个showtext

```
bandit26:x:11026:11026:bandit level 26:/home/bandit26:/usr/bin/showtext
```

cat查看发现是设置中断类型为linux

```sh
bandit25@bandit:~$ cat /usr/bin/showtext
#!/bin/sh

export TERM=linux

more ~/text.txt
exit 0
bandit25@bandit:~$ 
```

> tips：
>
> more，less，vim的退出来的那个都是可以执行命令的
>
> 

因为这里是more，所以我们把终端缩小

然后我就卡住了，因为执行的命令都没有回显

最后看别人的攻略，发现是在more的模式下按`v`，进入vim模式

在vim模式下，用`:e /etc/bandit_pass/bandit26`导入密码文件，得到如下一行

```
5czgV9L3Xx8JPOyRbXh6lQbmIOWvPT6Z
```



长见识了长见识了

这简直就是个骚操作





// 在ans.txt中





### 

### level 27



```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit26@bandit.labs.overthewire.org -p 2220 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit26@bandit.labs.overthewire.org's password: 
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!

If you find any problems, please report them to Steven or morla on
irc.overthewire.org.

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

  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /  
 | |__   __ _ _ __   __| |_| |_   ) / /_  
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \ 
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/ 
Connection to bandit.labs.overthewire.org closed.
```

用上一关的flag进入这一关，发现连接又被断开了

推测方法跟上一关一样，进入more模式，利用vim模式执行命令

但是这次并不能用`:e`来读取文件，一i那位权限不够，`!command`也无法执行

后来查资料发现vim还可以通过设置shell的目录来执行shell的方式

```sh
# vim模式下
:set shell=/bin/sh
:sh
```



这样就得到了一个shell，ls发现有一个`./bandit27-do`程序，推测和以前一样，是要给setuid的程序，尝试一下果然没错，直接用此读取密码



```sh

bl@bl-virtual-machine:~/wargame$ ssh bandit26@bandit.labs.overthewire.org -p 2220 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit26@bandit.labs.overthewire.org's password: 
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!

If you find any problems, please report them to Steven or morla on
irc.overthewire.org.

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

  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /  
!vim
  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /  
!v
  _                     _ _ _   ___   __
 | |                   | (_) | |__ \ / /
:!ls
  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /
 | |__   __ _ _ __   __| |_| |_   ) / /_
:!ls
  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /
:sh
$ ls
bandit27-do  text.txt
$ cat text.txt
  _                     _ _ _   ___   __  
 | |                   | (_) | |__ \ / /  
 | |__   __ _ _ __   __| |_| |_   ) / /_  
 | '_ \ / _` | '_ \ / _` | | __| / / '_ \ 
 | |_) | (_| | | | | (_| | | |_ / /| (_) |
 |_.__/ \__,_|_| |_|\__,_|_|\__|____\___/ 
$ ./bandit27-do
Run a command as another user.
  Example: ./bandit27-do id
$ ./bandit27-do id
uid=11026(bandit26) gid=11026(bandit26) euid=11027(bandit27) groups=11026(bandit26)
$ ./bandit27-do cat /etc/bandit_pass/bandit27
3ba3118a22e93127a4ed485be72ef5ea

```







### level 28



```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit27@bandit.labs.overthewire.org -p 2220 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit27@bandit.labs.overthewire.org's password: 
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!

If you find any problems, please report them to Steven or morla on
irc.overthewire.org.

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

bandit27@bandit:~$ git clone ssh://bandit27-git@localhost/home/bandit27-git/repofatal: could not create work tree dir 'repo': Permission denied
bandit27@bandit:~$ git clone ssh://bandit27-git@localhost:2220/home/bandit27-git/repo
fatal: could not create work tree dir 'repo': Permission denied
bandit27@bandit:~$ cd /tmp
bandit27@bandit:/tmp$ mkdir b27r
bandit27@bandit:/tmp$ cd b27r
bandit27@bandit:/tmp/b27r$ git clone ssh://bandit27-git@localhost:2220/home/bandit27-git/repo
Cloning into 'repo'...
ssh: connect to host localhost port 2220: Connection refused
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
bandit27@bandit:/tmp/b27r$ git clone ssh://bandit27-git@localhost/home/bandit27-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit27/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit27/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit27-git@localhost's password: 
remote: Counting objects: 3, done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (3/3), done.
bandit27@bandit:/tmp/b27r$ ls
repo
bandit27@bandit:/tmp/b27r$ cd repo
bandit27@bandit:/tmp/b27r/repo$ ls
README
bandit27@bandit:/tmp/b27r/repo$ 
bandit27@bandit:/tmp/b27r/repo$ cat README
The password to the next level is: 0ef186ac70e04ea33b4c1853d2526fa2
bandit27@bandit:/tmp/b27r/repo$ 
```



由题目知道git的密码和本关flag一样

很简单的一个git的用法，git支持ssh协议这在之前就已经知道了

所以直接进入bandit27去clone仓库

结果没有权限，以为是端口错了，结果是忘了我们对bandit27的home目录没有读写权限

老办法，去tmp创一个新目录，然后clone，果然成功，flag在repo里的README里









### level 29

无意的发现

```sh
bandit12@bandit:~$ ls
data.txt
bandit12@bandit:~$ ls /tmp/fuck
repo
bandit12@bandit:~$ ls /tmp/fuck/repo
README.md
bandit12@bandit:~$ ls /tmp/fuck/repo/README.md 
/tmp/fuck/repo/README.md
bandit12@bandit:~$ cat /tmp/fuck/repo/README.md 
# Bandit Notes
Some notes for level29 of bandit.

## credentials

- username: bandit29
- password: bbc96594b4e001778eee9975372716b2

```

原来是碰巧有人在`/tmp/fuck`创建了这个git仓库，同道中人啊



```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit28@bandit.labs.overthewire.org -p 2220 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit28@bandit.labs.overthewire.org's password: 
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!


  Enjoy your stay!

bandit28@bandit:~$ ls
bandit28@bandit:~$ mkdir /tmp/b28r
bandit28@bandit:~$ cd /tmp/b28r
bandit28@bandit:/tmp/b28r$ ls
bandit28@bandit:/tmp/b28r$ git clone ssh://bandit28-git@localhost/home/bandit28-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit28/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit28/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit28-git@localhost's password: 
remote: Counting objects: 9, done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 9 (delta 2), reused 0 (delta 0)
Receiving objects: 100% (9/9), done.
Resolving deltas: 100% (2/2), done.
bandit28@bandit:/tmp/b28r$ ls
repo
bandit28@bandit:/tmp/b28r$ cd repo
bandit28@bandit:/tmp/b28r/repo$ ls
README.md
bandit28@bandit:/tmp/b28r/repo$ cat README.md 
# Bandit Notes
Some notes for level29 of bandit.

## credentials

- username: bandit29
- password: xxxxxxxxxx

bandit28@bandit:/tmp/b28r/repo$ ls -al
total 16
drwxr-sr-x 3 bandit28 root 4096 Feb 26 04:12 .
drwxr-sr-x 3 bandit28 root 4096 Feb 26 04:12 ..
drwxr-sr-x 8 bandit28 root 4096 Feb 26 04:12 .git
-rw-r--r-- 1 bandit28 root  111 Feb 26 04:12 README.md
bandit28@bandit:/tmp/b28r/repo$ ls .git
branches  description  hooks  info  objects      refs
config    HEAD         index  logs  packed-refs
bandit28@bandit:/tmp/b28r/repo$ ls .git/branches/
bandit28@bandit:/tmp/b28r/repo$ cat .git/HEAD
ref: refs/heads/master
bandit28@bandit:/tmp/b28r/repo$ git log
commit 073c27c130e6ee407e12faad1dd3848a110c4f95
Author: Morla Porla <morla@overthewire.org>
Date:   Tue Oct 16 14:00:39 2018 +0200

    fix info leak

commit 186a1038cc54d1358d42d468cdc8e3cc28a93fcb
Author: Morla Porla <morla@overthewire.org>
Date:   Tue Oct 16 14:00:39 2018 +0200

    add missing data

commit b67405defc6ef44210c53345fc953e6a21338cc7
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:39 2018 +0200

    initial commit of README.md
bandit28@bandit:/tmp/b28r/repo$ git revert 186a1038cc54d1358d42d468cdc8e3cc28a93fcb
error: could not revert 186a103... add missing data
hint: after resolving the conflicts, mark the corrected paths
hint: with 'git add <paths>' or 'git rm <paths>'
hint: and commit the result with 'git commit'
bandit28@bandit:/tmp/b28r/repo$ git reset --hard  186a1038cc54d1358d42d468cdc8e3cc28a93fcb
HEAD is now at 186a103 add missing data
bandit28@bandit:/tmp/b28r/repo$ ls
README.md
bandit28@bandit:/tmp/b28r/repo$ cat README.md 
# Bandit Notes
Some notes for level29 of bandit.

## credentials

- username: bandit29
- password: bbc96594b4e001778eee9975372716b2

bandit28@bandit:/tmp/b28r/repo$ git reset --hard b67405defc6ef44210c53345fc953e6a21338cc7
HEAD is now at b67405d initial commit of README.md
bandit28@bandit:/tmp/b28r/repo$ cat README.md 
# Bandit Notes
Some notes for level29 of bandit.

## credentials

- username: bandit29
- password: <TBD>

bandit28@bandit:/tmp/b28r/repo$ 

```



老办法，直接tmp目录创建新目录，然后clone

发现README里明显有一个假flag`xxxxxx`，其他也没啥东西可推测的，题目也就只有一个git的提示，我们便想到git的分支和回滚，查看`branch`发现没有其他分支，`git log`发现有以前的提交，利用命令`git reset --hard <commit_id>`回滚到对应版本，然后`cat README.md`得到flag：`bbc96594b4e001778eee9975372716b2`

> 还可以用`git show `查看版本差别



### level 30



```sh
  Enjoy your stay!

bandit29@bandit:~$ mkdir /tmp/b29r
bandit29@bandit:~$ cd /tmp/b29r
bandit29@bandit:/tmp/b29r$ git clone ssh://bandit29-git@localhost/home/bandit29-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit29/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit29/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit29-git@localhost's password: 
remote: Counting objects: 16, done.
remote: Compressing objects: 100% (11/11), done.
remote: Total 16 (delta 2), reused 0 (delta 0)
Receiving objects: 100% (16/16), done.
Resolving deltas: 100% (2/2), done.
bandit29@bandit:/tmp/b29r$ ls
repo
bandit29@bandit:/tmp/b29r$ cd repo
bandit29@bandit:/tmp/b29r/repo$ ls
README.md
bandit29@bandit:/tmp/b29r/repo$ cat README.md 
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: <no passwords in production!>

bandit29@bandit:/tmp/b29r/repo$ git log
commit 84abedc104bbc0c65cb9eb74eb1d3057753e70f8
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:41 2018 +0200

    fix username

commit 9b19e7d8c1aadf4edcc5b15ba8107329ad6c5650
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:41 2018 +0200

    initial commit of README.md
bandit29@bandit:/tmp/b29r/repo$ ls .git/branches/
bandit29@bandit:/tmp/b29r/repo$ ls .git
branches  description  hooks  info  objects      refs
config    HEAD         index  logs  packed-refs
bandit29@bandit:/tmp/b29r/repo$ cat .git/config 
[core]
	repositoryformatversion = 0
	filemode = true
	bare = false
	logallrefupdates = true
[remote "origin"]
	url = ssh://bandit29-git@localhost/home/bandit29-git/repo
	fetch = +refs/heads/*:refs/remotes/origin/*
[branch "master"]
	remote = origin
	merge = refs/heads/master
bandit29@bandit:/tmp/b29r/repo$ git reset --hard 84abedc104bbc0c65cb9eb74eb1d3057753e70f8
HEAD is now at 84abedc fix username
bandit29@bandit:/tmp/b29r/repo$ ls
README.md
bandit29@bandit:/tmp/b29r/repo$ cat README.md 
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: <no passwords in production!>

bandit29@bandit:/tmp/b29r/repo$ 
bandit29@bandit:/tmp/b29r/repo$ cat .git/HEAD 
ref: refs/heads/master
bandit29@bandit:/tmp/b29r/repo$ git branch
* master
bandit29@bandit:/tmp/b29r/repo$ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/dev
  remotes/origin/master
  remotes/origin/sploits-dev
bandit29@bandit:/tmp/b29r/repo$ git checkout origin/dev
Note: checking out 'origin/dev'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b <new-branch-name>

HEAD is now at 33ce2e9... add data needed for development
bandit29@bandit:/tmp/b29r/repo$ ls
code  README.md
bandit29@bandit:/tmp/b29r/repo$ cat README.md 
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: 5b90576bedb2cc04c86a9e924ce42faf

bandit29@bandit:/tmp/b29r/repo$ ls code
gif2ascii.py
bandit29@bandit:/tmp/b29r/repo$ cat code/gif2ascii.py 

bandit29@bandit:/tmp/b29r/repo$ 

```

`git log`发现就只有两次提交，`cat README`发现说密码不在production

> https://www.cnblogs.com/jiangzhaowei/p/7879916.html

这里果然出现了中英的差别，百度才得知production就是我们通常所说的master分支，上文中可以看到git开发中常见的几个分支`dev`，`master`，`release`等

直接`git branch -a `查看所有分支，切换到`dev`分支，便得到了flag：`5b90576bedb2cc04c86a9e924ce42faf`





### level 31



```sh
bandit30@bandit:~$ mkdir /tmp/b30r
bandit30@bandit:~$ cd /tmp/b30r
bandit30@bandit:/tmp/b30r$ ls
bandit30@bandit:/tmp/b30r$ git clone ssh://bandit30-git@localhost/home/bandit30-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit30/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit30/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit30-git@localhost's password: 
remote: Counting objects: 4, done.
remote: Total 4 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (4/4), done.
bandit30@bandit:/tmp/b30r$ cd repo
bandit30@bandit:/tmp/b30r/repo$ ls
README.md
bandit30@bandit:/tmp/b30r/repo$ cat README.md 
just an epmty file... muahaha
bandit30@bandit:/tmp/b30r/repo$ git log
commit 3aa4c239f729b07deb99a52f125893e162daac9e
Author: Ben Dover <noone@overthewire.org>
Date:   Tue Oct 16 14:00:44 2018 +0200

    initial commit of README.md
bandit30@bandit:/tmp/b30r/repo$ cat .git/config 
[core]
	repositoryformatversion = 0
	filemode = true
	bare = false
	logallrefupdates = true
[remote "origin"]
	url = ssh://bandit30-git@localhost/home/bandit30-git/repo
	fetch = +refs/heads/*:refs/remotes/origin/*
[branch "master"]
	remote = origin
	merge = refs/heads/master
bandit30@bandit:/tmp/b30r/repo$ git branch  -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/master
bandit30@bandit:/tmp/b30r/repo$ ls .git
branches  description  hooks  info  objects      refs
config    HEAD         index  logs  packed-refs
bandit30@bandit:/tmp/b30r/repo$ cat .git/description 
Unnamed repository; edit this file 'description' to name the repository.
bandit30@bandit:/tmp/b30r/repo$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
nothing to commit, working tree clean
bandit30@bandit:/tmp/b30r/repo$ git diff --cache
error: invalid option: --cache
bandit30@bandit:/tmp/b30r/repo$ git diff --cached
bandit30@bandit:/tmp/b30r/repo$ git diff
bandit30@bandit:/tmp/b30r/repo$ git diff HEAD
bandit30@bandit:/tmp/b30r/repo$ git show-ref
3aa4c239f729b07deb99a52f125893e162daac9e refs/heads/master
3aa4c239f729b07deb99a52f125893e162daac9e refs/remotes/origin/HEAD
3aa4c239f729b07deb99a52f125893e162daac9e refs/remotes/origin/master
f17132340e8ee6c159e0a4a6bc6f80e1da3b1aea refs/tags/secret
bandit30@bandit:/tmp/b30r/repo$ git show f17132340e8ee6c159e0a4a6bc6f80e1da3b1aea47e603bb428404d265f59c42920d81e5
bandit30@bandit:/tmp/b30r/repo$ 

```



> https://cloud.tencent.com/developer/section/1138782
>
> https://www.softwhy.com/article-8540-1.html
>
> `git show-ref`：查看本地引用

得到了奇奇怪怪的新知识了







### level 32



```sh
bandit31@bandit:~$ mkdir /tmp/b31r
bandit31@bandit:~$ cd /tmp/b31r
bandit31@bandit:/tmp/b31r$ git clone ssh://bandit31-git@localhosthome/bandit31-git/repo
Cloning into 'repo'...
ssh: Could not resolve hostname localhosthome: No address associated with hostname
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
bandit31@bandit:/tmp/b31r$ ls
bandit31@bandit:/tmp/b31r$ git clone ssh://bandit31-git@localhost/home/bandit31-git/repo
Cloning into 'repo'...
Could not create directory '/home/bandit31/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit31/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit31-git@localhost's password: 
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 4 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (4/4), done.
bandit31@bandit:/tmp/b31r$ cd repo
bandit31@bandit:/tmp/b31r/repo$ ls
README.md
bandit31@bandit:/tmp/b31r/repo$ cat README.md 
This time your task is to push a file to the remote repository.

Details:
    File name: key.txt
    Content: 'May I come in?'
    Branch: master

bandit31@bandit:/tmp/b31r/repo$ touch key.txt
bandit31@bandit:/tmp/b31r/repo$ echo 'May I come in?' >> key.txt 
bandit31@bandit:/tmp/b31r/repo$ cat key.txt 
May I come in?
bandit31@bandit:/tmp/b31r/repo$ git add key.txt 
The following paths are ignored by one of your .gitignore files:
key.txt
Use -f if you really want to add them.
bandit31@bandit:/tmp/b31r/repo$ git add -f key.txt 
bandit31@bandit:/tmp/b31r/repo$ ls -al
total 24
drwxr-sr-x 3 bandit31 root 4096 Feb 26 04:47 .
drwxr-sr-x 3 bandit31 root 4096 Feb 26 04:46 ..
drwxr-sr-x 8 bandit31 root 4096 Feb 26 04:48 .git
-rw-r--r-- 1 bandit31 root    6 Feb 26 04:46 .gitignore
-rw-r--r-- 1 bandit31 root   15 Feb 26 04:47 key.txt
-rw-r--r-- 1 bandit31 root  147 Feb 26 04:46 README.md
bandit31@bandit:/tmp/b31r/repo$ cat .gitignore 
*.txt
bandit31@bandit:/tmp/b31r/repo$ git commit -m "Hello"
[master de012c9] Hello
 1 file changed, 1 insertion(+)
 create mode 100644 key.txt
bandit31@bandit:/tmp/b31r/repo$ git push
Could not create directory '/home/bandit31/.ssh'.
The authenticity of host 'localhost (127.0.0.1)' can't be established.
ECDSA key fingerprint is SHA256:98UL0ZWr85496EtCRkKlo20X3OPnyPSB5tB5RPbhczc.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/bandit31/.ssh/known_hosts).
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit31-git@localhost's password: 
Counting objects: 3, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 319 bytes | 0 bytes/s, done.
Total 3 (delta 0), reused 0 (delta 0)
remote: ### Attempting to validate files... ####
remote: 
remote: .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
remote: 
remote: Well done! Here is the password for the next level:
remote: 56a9bf19c63d650ce78e6ec0354ee45e
remote: 
remote: .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
remote: 
To ssh://localhost/home/bandit31-git/repo
 ! [remote rejected] master -> master (pre-receive hook declined)
error: failed to push some refs to 'ssh://bandit31-git@localhost/home/bandit31-git/repo'
bandit31@bandit:/tmp/b31r/repo$ 

```



这一关目的通过README可看到，是需要push到远程仓库，这对我们再熟悉不过了

不过，这有个坑就是`.gitignore`，里面忽略了`*.txt`

用`git add -f`或删掉`.gitignore`都行，然后push上去，这操作太骚了，改写了git push失败的返回结果，在结果里给出了flag





### level 33



```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit32@bandit.labs.overthewire.org -p 2220This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit32@bandit.labs.overthewire.org's password: 
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!

If you find any problems, please report them to Steven or morla on
irc.overthewire.org.

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

WELCOME TO THE UPPERCASE SHELL
>> #!/bin/sh
>> bash
sh: 1: BASH: not found
>> man
sh: 1: MAN: not found
>> sh
sh: 1: SH: not found
>> $0
$ ls
uppershell
$ id
uid=11033(bandit33) gid=11032(bandit32) groups=11032(bandit32)
$ pwd
/home/bandit32
$ cat /etc/bandit_pass/bandit32
cat: /etc/bandit_pass/bandit32: Permission denied
$ cat /etc/bandit_pass/bandit33
c9c3199ddf4121b10cf581a98d51caee
$ 

```

这关是真的骚，Linux中大小写严格区分，导致我们的命令都执行不了

后来看题解得知`$0`可以直接进入`sh`，然后就可以了woc

还有一个题解是利用ssh协议，传一个bash脚本(如下)，放在tmp文件夹下，用大写文件名`./TEST`逃逸，然后执行bash，不过还是没有上面这个办法简单暴力

```
#!/bin/bash
bash
```





### level 34

```sh
bl@bl-virtual-machine:~/wargame$ ssh bandit33@bandit.labs.overthewire.org -p 2220 
This is a OverTheWire game server. More information on http://www.overthewire.org/wargames

bandit33@bandit.labs.overthewire.org's password: 
Linux bandit 4.18.12 x86_64 GNU/Linux
               
      ,----..            ,----,          .---. 
     /   /   \         ,/   .`|         /. ./|
    /   .     :      ,`   .'  :     .--'.  ' ;
   .   /   ;.  \   ;    ;     /    /__./ \ : |
  .   ;   /  ` ; .'___,/    ,' .--'.  '   \' .
  ;   |  ; \ ; | |    :     | /___/ \ |    ' ' 
  |   :  | ; | ' ;    |.';  ; ;   \  \;      : 
  .   |  ' ' ' : `----'  |  |  \   ;  `      |
  '   ;  \; /  |     '   :  ;   .   \    .\  ; 
   \   \  ',  /      |   |  '    \   \   ' \ |
    ;   :    /       '   :  |     :   '  |--"  
     \   \ .'        ;   |.'       \   \ ;     
  www. `---` ver     '---' he       '---" ire.org     
               
              
Welcome to OverTheWire!

If you find any problems, please report them to Steven or morla on
irc.overthewire.org.

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

bandit33@bandit:~$ ls
README.txt
bandit33@bandit:~$ cat README.txt 
Congratulations on solving the last level of this game!

At this moment, there are no more levels to play in this game. However, we are constantly working
on new levels and will most likely expand this game with more levels soon.
Keep an eye out for an announcement on our usual communication channels!
In the meantime, you could play some of our other wargames.

If you have an idea for an awesome new level, please let us know!
bandit33@bandit:~$ 

```

只有一个`README.txt`，恭喜完结撒花

截图纪念一下

![](bandit_end.png)











> 以下是后面找到的一些题解
>
> https://blog.csdn.net/winkar/article/details/38408873?locationNum=5&fps=1
>
> https://www.freebuf.com/column/181443.html
>
> https://www.jianshu.com/p/bf8cc6b0efd1







------





## Krypton



> SSH Information
> Host: krypton.labs.overthewire.org
> Port: 2222



### level 0



```
Welcome to Krypton! The first level is easy. The following string encodes the password using Base64:

S1JZUFRPTklTR1JFQVQ=
Use this password to log in to krypton.labs.overthewire.org with username krypton1 using SSH on port 2222. You can find the files for other levels in /krypton/
```



啊这熟悉的开头，简单的base64编码

```
KRYPTONISGREAT
```

解码得到如上flag

```sh
$ ssh krypton1@krypton.labs.overthewire.org -p 2222
The authenticity of host '[krypton.labs.overthewire.org]:2222 ([176.9.9.172]:2222)' can't be established.
ECDSA key fingerprint is SHA256:SCySwNrZFEHArEX1cAlnnaJ5gz2O8VEigY9X80nFWUU.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added '[krypton.labs.overthewire.org]:2222,[176.9.9.172]:2222' (ECDSA) to the list of known hosts.
 _                     _
| | ___ __ _   _ _ __ | |_ ___  _ __
| |/ / '__| | | | '_ \| __/ _ \| '_ \
|   <| |  | |_| | |_) | || (_) | | | |
|_|\_\_|   \__, | .__/ \__\___/|_| |_|
           |___/|_|
a http://www.overthewire.org wargame.

krypton1@krypton.labs.overthewire.org's password:
Permission denied, please try again.
krypton1@krypton.labs.overthewire.org's password:
Permission denied, please try again.
krypton1@krypton.labs.overthewire.org's password:
Welcome to Ubuntu 14.04 LTS (GNU/Linux 4.4.0-92-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

krypton1@krypton:~$
```





成功连上level1



### level 1



```sh
krypton1@krypton:~$ ls -al
total 24
drwxr-xr-x  3 krypton1 krypton1 4096 Feb 27 11:03 .
drwxr-xr-x 10 root     root     4096 Feb 27 11:03 ..
-rw-r--r--  1 krypton1 krypton1  220 Apr  9  2014 .bash_logout
-rw-r--r--  1 krypton1 krypton1 3637 Apr  9  2014 .bashrc
drwx------  2 krypton1 krypton1 4096 Feb 27 11:03 .cache
-rw-r--r--  1 krypton1 krypton1  675 Apr  9  2014 .profile
krypton1@krypton:~$ cd /krypton/
krypton1@krypton:/krypton$ ls
krypton1  krypton2  krypton3  krypton4  krypton5  krypton6
krypton1@krypton:/krypton$ ls krypton1
README  krypton2
krypton1@krypton:/krypton$ cat krypton1/README
Welcome to Krypton!

This game is intended to give hands on experience with cryptography
and cryptanalysis.  The levels progress from classic ciphers, to modern,
easy to harder.

Although there are excellent public tools, like cryptool,to perform
the simple analysis, we strongly encourage you to try and do these
without them for now.  We will use them in later excercises.

** Please try these levels without cryptool first **


The first level is easy.  The password for level 2 is in the file
'krypton2'.  It is 'encrypted' using a simple rotation called ROT13.
It is also in non-standard ciphertext format.  When using alpha characters for
cipher text it is normal to group the letters into 5 letter clusters,
regardless of word boundaries.  This helps obfuscate any patterns.

This file has kept the plain text word boundaries and carried them to
the cipher text.

Enjoy!
krypton1@krypton:/krypton$ cat krypton1/krypton2
YRIRY GJB CNFFJBEQ EBGGRA
krypton1@krypton:/krypton$
```



通过README可知，简单的ROT13加密

```
LEVEL TWO PASSWORD ROTTEN
```



进入下一关



### level 2



```sh
krypton2@krypton:~$ ls
krypton2@krypton:~$ cd /krypton/
krypton2@krypton:/krypton$ cd krypton2
krypton2@krypton:/krypton/krypton2$ ls
README  encrypt  keyfile.dat  krypton3
krypton2@krypton:/krypton/krypton2$ cat README
Krypton 2

ROT13 is a simple substitution cipher.

Substitution ciphers are a simple replacement algorithm.  In this example
of a substitution cipher, we will explore a 'monoalphebetic' cipher.
Monoalphebetic means, literally, "one alphabet" and you will see why.

This level contains an old form of cipher called a 'Caesar Cipher'.
A Caesar cipher shifts the alphabet by a set number.  For example:

plain:  a b c d e f g h i j k ...
cipher: G H I J K L M N O P Q ...

In this example, the letter 'a' in plaintext is replaced by a 'G' in the
ciphertext so, for example, the plaintext 'bad' becomes 'HGJ' in ciphertext.

The password for level 3 is in the file krypton3.  It is in 5 letter
group ciphertext.  It is encrypted with a Caesar Cipher.  Without any
further information, this cipher text may be difficult to break.  You do
not have direct access to the key, however you do have access to a program
that will encrypt anything you wish to give it using the key.
If you think logically, this is completely easy.

One shot can solve it!

Have fun.

Additional Information:

The `encrypt` binary will look for the keyfile in your current working
directory. Therefore, it might be best to create a working direcory in /tmp
and in there a link to the keyfile. As the `encrypt` binary runs setuid
`krypton3`, you also need to give `krypton3` access to your working directory.

Here is an example:

krypton2@melinda:~$ mktemp -d
/tmp/tmp.Wf2OnCpCDQ
krypton2@melinda:~$ cd /tmp/tmp.Wf2OnCpCDQ
krypton2@melinda:/tmp/tmp.Wf2OnCpCDQ$ ln -s /krypton/krypton2/keyfile.dat
krypton2@melinda:/tmp/tmp.Wf2OnCpCDQ$ ls
keyfile.dat
krypton2@melinda:/tmp/tmp.Wf2OnCpCDQ$ chmod 777 .
krypton2@melinda:/tmp/tmp.Wf2OnCpCDQ$ /krypton/krypton2/encrypt /etc/issue
krypton2@melinda:/tmp/tmp.Wf2OnCpCDQ$ ls
ciphertext  keyfile.dat

krypton2@krypton:/krypton/krypton2$
krypton2@krypton:/krypton/krypton2$ mktemp -d
/tmp/tmp.fz9I1hQd5d
krypton2@krypton:/krypton/krypton2$ cd /tmp/tmp.fz9I1hQd5d
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ln -s /krypton/krypton2/keyfile.dat 
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls
keyfile.dat
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ chmod 777 .
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ /krypton/krypton2/encrypt /etc/issue  
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls
ciphertext  keyfile.dat
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ cat ciphertext 
GNGZFGXFEZX
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ cat keyfile.dat 
cat: keyfile.dat: Permission denied
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls -al
total 12
drwxrwxrwx 2 krypton2 krypton2 4096 Feb 27 11:19 .
drwxrwx-wt 3 root     root     4096 Feb 27 11:20 ..
-rw-rw-r-- 1 krypton3 krypton2   11 Feb 27 11:19 ciphertext
lrwxrwxrwx 1 krypton2 krypton2   29 Feb 27 11:18 keyfile.dat -> /krypton/krypton2/keyfile.dat
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ 
```



将密文`GNGZFGXFEZX`进行凯撒位移

```
HOHAGHYGFAY
IPIBHIZHGBZ
JQJCIJAIHCA
KRKDJKBJIDB
LSLEKLCKJEC
MTMFLMDLKFD
NUNGMNEMLGE
OVOHNOFNMHF
PWPIOPGONIG
QXQJPQHPOJH
RYRKQRIQPKI
SZSLRSJRQLJ
TATMSTKSRMK
UBUNTULTSNL
VCVOUVMUTOM
WDWPVWNVUPN
XEXQWXOWVQO
YFYRXYPXWRP
ZGZSYZQYXSQ
AHATZARZYTR
BIBUABSAZUS
CJCVBCTBAVT
DKDWCDUCBWU
ELEXDEVDCXV
FMFYEFWEDYW
GNGZFGXFEZX
```



发现果然好像没有可读的，再看看README原来这是个示例（我好蠢

```sh
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ cat /etc/issue
Ubuntu 14.04.5 LTS \n \l

krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls  /krypton/krypton2/krypton3 
/krypton/krypton2/krypton3
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls  /krypton/krypton2/ -al
total 32
drwxr-xr-x 2 root     root     4096 Nov  4 05:21 .
drwxr-xr-x 8 root     root     4096 Nov  4 05:21 ..
-rw-r----- 1 krypton2 krypton2 1815 Nov  4 05:21 README
-rwsr-x--- 1 krypton3 krypton2 8970 Nov  4 05:21 encrypt
-rw-r----- 1 krypton3 krypton3   27 Nov  4 05:21 keyfile.dat
-rw-r----- 1 krypton2 krypton2   13 Nov  4 05:21 krypton3
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls
ciphertext  keyfile.dat
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ rm -f ciphertext 
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ /krypton/krypton2/encrypt /krypton/krypton2/krypton3 
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ ls
ciphertext  keyfile.dat
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ cat ciphertext 
AYCQYPGQCYQW
krypton2@krypton:/tmp/tmp.fz9I1hQd5d$ 
```

重新用krypton3被加载，解密，得到`CAESARISEASY`

```
BZDRZQHRDZRX
CAESARISEASY
DBFTBSJTFBTZ
ECGUCTKUGCUA
FDHVDULVHDVB
GEIWEVMWIEWC
HFJXFWNXJFXD
IGKYGXOYKGYE
JHLZHYPZLHZF
KIMAIZQAMIAG
LJNBJARBNJBH
MKOCKBSCOKCI
NLPDLCTDPLDJ
OMQEMDUEQMEK
PNRFNEVFRNFL
QOSGOFWGSOGM
RPTHPGXHTPHN
SQUIQHYIUQIO
TRVJRIZJVRJP
USWKSJAKWSKQ
VTXLTKBLXTLR
WUYMULCMYUMS
XVZNVMDNZVNT
YWAOWNEOAWOU
ZXBPXOFPBXPV
AYCQYPGQCYQW
```





得到flag进入下一关



### level 3



```sh
krypton3@krypton:~$ ls
krypton3@krypton:~$ cd /krypton/krypton3
krypton3@krypton:/krypton/krypton3$ ls
HINT1  HINT2  README  found1  found2  found3  krypton4
krypton3@krypton:/krypton/krypton3$ cat README 
Well done.  You've moved past an easy substitution cipher.

Hopefully you just encrypted the alphabet a plaintext 
to fully expose the key in one swoop.

The main weakness of a simple substitution cipher is 
repeated use of a simple key.  In the previous exercise
you were able to introduce arbitrary plaintext to expose
the key.  In this example, the cipher mechanism is not 
available to you, the attacker.

However, you have been lucky.  You have intercepted more
than one message.  The password to the next level is found
in the file 'krypton4'.  You have also found 3 other files.
(found1, found2, found3)

You know the following important details:

- The message plaintexts are in English (*** very important)
- They were produced from the same key (*** even better!)


Enjoy.


krypton3@krypton:/krypton/krypton3$ cat found1
CGZNL YJBEN QYDLQ ZQSUQ NZCYD SNQVU BFGBK GQUQZ QSUQN UZCYD SNJDS UDCXJ ZCYDS NZQSU QNUZB WSBNZ QSUQN UDCXJ CUBGS BXJDS UCTYV SUJQG WTBUJ KCWSV LFGBK GSGZN LYJCB GJSZD GCHMS UCJCU QJLYS BXUMA UJCJM JCBGZ CYDSN CGKDC ZDSQZ DVSJJ SNCGJ DSYVQ CGJSO JCUNS YVQZS WALQV SJJSN UBTSX COSWG MTASN BXYBU CJCBG UWBKG JDSQV YDQAS JXBNS OQTYV SKCJD QUDCX JBXQK BMVWA SNSYV QZSWA LWAKB MVWAS ZBTSS QGWUB BGJDS TSJDB WCUGQ TSWQX JSNRM VCMUZ QSUQN KDBMU SWCJJ BZBTT MGCZQ JSKCJ DDCUE SGSNQ VUJDS SGZNL YJCBG UJSYY SNXBN TSWAL QZQSU QNZCY DSNCU BXJSG CGZBN YBNQJ SWQUY QNJBX TBNSZ BTYVS OUZDS TSUUM ZDQUJ DSICE SGNSZ CYDSN QGWUJ CVVDQ UTBWS NGQYY VCZQJ CBGCG JDSNB JULUJ STQUK CJDQV VUCGE VSQVY DQASJ UMAUJ CJMJC BGZCY DSNUJ DSZQS UQNZC YDSNC USQUC VLANB FSGQG WCGYN QZJCZ SBXXS NUSUU SGJCQ VVLGB ZBTTM GCZQJ CBGUS ZMNCJ LUDQF SUYSQ NSYNB WMZSW TBUJB XDCUF GBKGK BNFAS JKSSG QGWDC USQNV LYVQL UKSNS TQCGV LZBTS WCSUQ GWDCU JBNCS UESGN SUDSN QCUSW JBJDS YSQFB XUBYD CUJCZ QJCBG QGWQN JCUJN LALJD SSGWB XJDSU COJSS GJDZS GJMNL GSOJD SKNBJ STQCG VLJNQ ESWCS UMGJC VQABM JCGZV MWCGE DQTVS JFCGE VSQNQ GWTQZ ASJDZ BGUCW SNSWU BTSBX JDSXC GSUJS OQTYV SUCGJ DSSGE VCUDV QGEMQ ESCGD CUVQU JYDQU SDSKN BJSJN QECZB TSWCS UQVUB FGBKG QUNBT QGZSU QGWZB VVQAB NQJSW KCJDB JDSNY VQLKN CEDJU TQGLB XDCUY VQLUK SNSYM AVCUD SWCGS WCJCB GUBXI QNLCG EHMQV CJLQG WQZZM NQZLW MNCGE DCUVC XSJCT SQGWC GJKBB XDCUX BNTSN JDSQJ NCZQV ZBVVS QEMSU YMAVC UDSWJ DSXCN UJXBV CBQZB VVSZJ SWSWC JCBGB XDCUW NQTQJ CZKBN FUJDQ JCGZV MWSWQ VVAMJ JKBBX JDSYV QLUGB KNSZB EGCUS WQUUD QFSUY SQNSU krypton3@krypton:/krypton/krypton3$ cat found2
QVJDB MEDGB QJJSG WQGZS NSZBN WUXBN JDSYS NCBWU MNICI STBUJ ACBEN QYDSN UQENS SJDQJ UDQFS UYSQN SKQUS WMZQJ SWQJJ DSFCG EUGSK UZDBB VCGUJ NQJXB NWQXN SSUZD BBVZD QNJSN SWCGQ ABMJQ HMQNJ SNBXQ TCVSX NBTDC UDBTS ENQTT QNUZD BBVUI QNCSW CGHMQ VCJLW MNCGE JDSSV CPQAS JDQGS NQAMJ JDSZM NNCZM VMTKQ UWCZJ QJSWA LVQKJ DNBME DBMJS GEVQG WQGWJ DSUZD BBVKB MVWDQ ISYNB ICWSW QGCGJ SGUCI SSWMZ QJCBG CGVQJ CGENQ TTQNQ GWJDS ZVQUU CZUQJ JDSQE SBXUD QFSUY SQNST QNNCS WJDSL SQNBV WQGGS DQJDQ KQLJD SZBGU CUJBN LZBMN JBXJD SWCBZ SUSBX KBNZS UJSNC UUMSW QTQNN CQESV CZSGZ SBGGB ISTAS NJKBB XDQJD QKQLU GSCED ABMNU YBUJS WABGW UJDSG SOJWQ LQUUM NSJLJ DQJJD SNSKS NSGBC TYSWC TSGJU JBJDS TQNNC QESJD SZBMY VSTQL DQISQ NNQGE SWJDS ZSNST BGLCG UBTSD QUJSU CGZSJ DSKBN ZSUJS NZDQG ZSVVB NQVVB KSWJD STQNN CQESA QGGUJ BASNS QWBGZ SCGUJ SQWBX JDSMU MQVJD NSSJC TSUQG GSUYN SEGQG ZLZBM VWDQI SASSG JDSNS QUBGX BNJDC UUCOT BGJDU QXJSN JDSTQ NNCQE SUDSE QISAC NJDJB QWQME DJSNU MUQGG QKDBK QUAQY JCUSW BGTQL JKCGU UBGDQ TGSJQ GWWQM EDJSN RMWCJ DXBVV BKSWQ VTBUJ JKBLS QNUVQ JSNQG WKSNS AQYJC USWBG XSANM QNLDQ TGSJW CSWBX MGFGB KGZQM USUQJ JDSQE SBXQG WKQUA MNCSW BGQME MUJQX JSNJD SACNJ DBXJD SJKCG UJDSN SQNSX SKDCU JBNCZ QVJNQ ZSUBX UDQFS UYSQN SMGJC VDSCU TSGJC BGSWQ UYQNJ BXJDS VBGWB GJDSQ JNSUZ SGSCG ASZQM USBXJ DCUEQ YUZDB VQNUN SXSNJ BJDSL SQNUA SJKSS GQGWQ UUDQF SUYSQ NSUVB UJLSQ NUACB ENQYD SNUQJ JSTYJ CGEJB QZZBM GJXBN JDCUY SNCBW DQISN SYBNJ SWTQG LQYBZ NLYDQ VUJBN CSUGC ZDBVQ UNBKS UDQFS UYSQN SUXCN UJACB ENQYD SNNSZ BMGJS WQUJN QJXBN WVSES GWJDQ JUDQF SUYSQ NSXVS WJDSJ BKGXB NVBGW BGJBS UZQYS YNBUS ZMJCB GXBNW SSNYB QZDCG EQGBJ DSNSC EDJSS GJDZS GJMNL UJBNL DQUUD QFSUY SQNSU JQNJC GEDCU JDSQJ NCZQV ZQNSS NTCGW CGEJD SDBNU SUBXJ DSQJN SYQJN BGUCG VBGWB GRBDG QMANS LNSYB NJSWJ DQJUD QFSUY SQNSD QWASS GQZBM GJNLU ZDBBV TQUJS NUBTS JKSGJ CSJDZ SGJMN LUZDB VQNUD QISUM EESUJ SWJDQ JUDQF SUYSQ NSTQL DQISA SSGST YVBLS WQUQU ZDBBV TQUJS NALQV SOQGW SNDBE DJBGB XVQGZ QUDCN SQZQJ DBVCZ VQGWB KGSNK DBGQT SWQZS NJQCG KCVVC QTUDQ FSUDQ XJSCG DCUKC VVGBS ICWSG ZSUMA UJQGJ CQJSU UMZDU JBNCS UBJDS NJDQG DSQNU QLZBV VSZJS WQXJS NDCUW SQJD
krypton3@krypton:/krypton/krypton3$ cat found3 
DSNSM YBGVS ENQGW QNBUS KCJDQ ENQIS QGWUJ QJSVL QCNQG WANBM EDJTS JDSAS SJVSX NBTQE VQUUZ QUSCG KDCZD CJKQU SGZVB USWCJ KQUQA SQMJC XMVUZ QNQAQ SMUQG WQJJD QJJCT SMGFG BKGJB GQJMN QVCUJ UBXZB MNUSQ ENSQJ YNCPS CGQUZ CSGJC XCZYB CGJBX ICSKJ DSNSK SNSJK BNBMG WAVQZ FUYBJ UGSQN BGSSO JNSTC JLBXJ DSAQZ FQGWQ VBGEB GSGSQ NJDSB JDSNJ DSUZQ VSUKS NSSOZ SSWCG EVLDQ NWQGW EVBUU LKCJD QVVJD SQYYS QNQGZ SBXAM NGCUD SWEBV WJDSK SCEDJ BXJDS CGUSZ JKQUI SNLNS TQNFQ AVSQG WJQFC GEQVV JDCGE UCGJB ZBGUC WSNQJ CBGCZ BMVWD QNWVL AVQTS RMYCJ SNXBN DCUBY CGCBG NSUYS ZJCGE CJ
krypton3@krypton:/krypton/krypton3$ cat HINT1
Some letters are more prevalent in English than others.
krypton3@krypton:/krypton/krypton3$ cat HINT2
"Frequency Analysis" is your friend.
krypton3@krypton:/krypton/krypton3$ 
krypton3@krypton:/krypton/krypton3$
```



> https://www.jianshu.com/p/a131136c0dbf



```
# 25char
257: (space)
155: S
107: C
106: Q
102: J
100: U
87: B
81: G
74: N
69: D
57: Z
56: V
47: W
42: Y
32: T
29: X
29: M
27: L
25: K
20: A
17: E
11: F
7: O
2: I
2: H
1: R

```



```
# 26char
354: (space)
243: S
186: Q
158: J
135: N
130: U
129: B
119: D
111: G
86: C
66: W
59: Z
53: V
45: M
37: T
34: E
33: Y
33: X
30: K
27: L
26: A
14: I
12: F
3: O
2: R
2: H
1: P
```





```
# 25char
93: (space)
58: S
48: Q
41: J
35: G
34: C
31: N
30: B
27: U
22: D
21: V
16: Z
16: W
13: E
12: M
12: K
9: Y
9: X
9: A
6: T
6: L
5: F
3: I
2: O
1: R
1: P

```



假如把所有综合一起统计

```
703: (space)
456: S:e
340: Q:t
301: J:a
257: U:o
246: B:i
240: N:n
227: G:s
227: C:h
210: D:r
132: Z:d
130: V:l
129: W:c
86: M:u
84: Y:m
75: T:w
71: X:f
67: K:g
64: E:y
60: L:p
55: A:b
28: F:v
19: I:k
12: O:j
4: R:x
4: H:q
2: P:z

```

把上述词频带入解开，貌似也不是密码啊

```sh
krypton3@krypton:/krypton/krypton3$ cat krypton4 
KSVVW BGSJD SVSIS VXBMN YQUUK BNWCU ANMJS 
gellc isear eleke lfiun mtoog incho bnuae
```



>  http://www.richkni.co.uk/php/crypta/freq.php
>
>  http://www.simonsingh.net/The_Black_Chamber/hintsandtips.html

我疯了，做法没问题，但据说只能一个个试，直接找到了题解

```
secret:  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
text:    B O I H G K N Q V T W Y U R X Z A J E M S L D F P C 
```

用命令替换得到密码

```sh
$ cat krypton4 | tr '[A-Z]' '[BOIHGKNQVTWYURXZAJEMSLDFPC]'
```

```sh
krypton3@krypton:/krypton/krypton3$  cat krypton4 | tr '[A-Z]' '[BOIHGKNQVTWYURXZAJEMSLDFPC]'
WELLD ONETH ELEVE LFOUR PASSW ORDIS BRUTE 
krypton3@krypton:/krypton/krypton3$ 
```



