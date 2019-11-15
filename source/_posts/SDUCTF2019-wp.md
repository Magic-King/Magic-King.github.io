---
title: SDUCTF2019-wp
date: 2019-11-15 13:39:00
tags: [ctf]
categories: ctf
description:
password:
---





# <center>SDUCTF2019-WriteUp</center>



刚入门了ctf2周，便有新生赛玩，真好。



PS.刚准备写wp又放出来一题QAQ

！！！写wp一半又放出题目



# Web



### 0x01 最简答的Web题



>  题目描述：flag就在html里面，右键点击查看源代码即可查看 



直接F12查看源码，找到flag

![](SDUCTF2019-wp\web1.jpg)



### 0x02 按钮点击

> 题目描述： 想方设法点击按钮 

进入页面一个灰色的按钮，F12查看源码

![](SDUCTF2019-wp\web2-1.jpg)

删除button标签里的disabled即可点击按钮

```html
<input style="width: 150px; height: 60px; font-size: 30px;" type="button" onclick="c()" value="flag" disabled="">
```

![](SDUCTF2019-wp\web2-3.jpg)

后面好奇，发现flag就在click2.js里，被base64加密过

![](SDUCTF2019-wp\web2-2.jpg)





### 0x03 量子波动速读

> 题目描述： 你会量子波动速读吗？ 

进入页面就一个按钮，点击查看，发现一闪而过的fakeflag

```html
<button onclick="window.location.href = 'flag_is_here.html'">
    点击查看flag
</button>
```

源码如上，输入`url/flag_is_here.html`发现就是刚才一闪而过的页面

利用burpsuite抓包即可，因为所有请求被burpsuite拦截，所以可以看到`/flag_is_here.html`但是页面上给的是fake ctf，明显不是flag，查看源码得到flag，我是直接用repeater发一个包获得Response。

![](SDUCTF2019-wp\web3.jpg)



### 0x04 芝麻开门

> 题目描述： 简单的提交，芝麻开门 

<img src="SDUCTF2019-wp\web4.jpg" style="zoom:50%;" />

直接复制题目的zhimakaimen进去，返回的是口令错误

![](SDUCTF2019-wp\web4-1.jpg)

查看burpsuite拦截的包，好像是因为他的输入框有长度限制，所以少了一个字母

![](SDUCTF2019-wp\web4-2.jpg)

利用burpsuite的repeater重新发一个完整的包，得到flag





### 0x05 Funny Button

> 题目描述： 有趣的按钮，你能点到吗？ 

即示例的题目，删除html的css或js都可以，甚至可以用tab键选中button按钮，点击去就是flag



### 0x06 曲奇

> 题目描述： 你喜欢吃曲奇饼干吗？ 

曲奇==cookies，直接查看网站cookies即可

![](SDUCTF2019-wp\web6.jpg)

flag即在内容里，注意flag要进行url解码





### 0x07 GET

> 题目描述： 你就是个没有感情的浏览器 

![](SDUCTF2019-wp\web7.jpg)

![](SDUCTF2019-wp\web7-2.jpg)

我是一个莫得感情的get机器



### 0x08 未来浏览器

> 题目描述：  小王正在追剧《亲爱的，热爱的》，电脑屏幕。。。。（谁帮我编个） 当他再次醒来。。。。。。。 

![](SDUCTF2019-wp\web8.jpg)

有题目已知，用burpsuite改http头属性`User-Agent`即可

```http
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/6666.6.6666.66 Safari/537.36
```

改后发包得到flag



### 0x09 POST

> 题目描述：  你就是一个没有感情的浏览器 

![](SDUCTF2019-wp\web9.jpg)

<img src="SDUCTF2019-wp\web9-2.jpg" style="zoom:50%;" />



我只是一个莫得感情的post机器

利用firefox插件HackBar发送post请求，或者用burpsuite也行




### 0x0a vim好用啊

> 题目描述：  小明同学用vim编辑主页的时候，实验室断电了！ 

![](SDUCTF2019-wp\web10.jpg)

由题目得知用vim时断电，用过vim的人都知道，当vim非正常退出时会创建一个保护的缓存文件，现在word也一样。

直接百度搜vim异常退出的备份文件，因为上次做过类似的，试试`index.php.bak`和`index.php~`没用，就百度了一下，得知备份文件格式为`.index.php.swp`，访问`url/.index.php.swp`下载文件得到`.index.php.swp`

![](SDUCTF2019-wp\web10-2.jpg)

得知flag在`url/vimvimvimvim.php`里，果然vim是最好的编辑器（狗头保命





### 0x0b 一句话木马

> 题目描述： 听说过**一句话木马**吗？
> 					听说过**中国菜刀**吗？
> 					听说过**中国蚁剑**吗？
> 					快去了解一下吧！！



![](SDUCTF2019-wp\web11.jpg)

看刀`<!--php eval(@$_POST["cmd"]);-->`就可知是一句话木马，对这个稍微了解一下，去github获取中国蚁剑即可

不过有一个坑，就是他默认访问是`index.php`，但是通过中国蚁剑连不上，回头看页面，发现在题目中有一个`shell.php`，于是尝试`url/shell.php`加上密码`cmd`，成功连上得到flag

![](SDUCTF2019-wp\web11-2.jpg)





### 0x0c 达拉崩吧	

> 题目描述：  达拉崩吧打怪小游戏 

![](SDUCTF2019-wp\web12.jpg)



进入页面是个小游戏，发现是hackergame2019原题嘤嘤嘤

### 原题wp： [https://github.com/ustclug/hackergame2019-writeups/blob/master/official/%E8%BE%BE%E6%8B%89%E5%B4%A9%E5%90%A7%E5%A4%A7%E5%86%92%E9%99%A9/README.md](https://github.com/ustclug/hackergame2019-writeups/blob/master/official/达拉崩吧大冒险/README.md) 

不过在买菜这里，有一个大整数溢出，后续会搞懂这个原理

![](SDUCTF2019-wp\web12-2.jpg)



<img src="SDUCTF2019-wp\web12-3.jpg" style="zoom:50%;" />



然后得到flag

![](SDUCTF2019-wp\web12-4.jpg)





# Misc



### 0x01 Gif

> 题目描述： Gif你眼神够快吗？ 



用StegSolve.jar 打开目标gif，即可逐帧查看，一共六帧，4帧都是flag需要自己拼接。

拼接完得到flag`SDUCTF{Gif_is_very_interesting}`





### 0x02 PDF

> 题目描述： pdf里面藏了啥？ 

跟攻防世界的一题misc一样，随便找个网站将pdf转doc，然后把图片拖开flag就藏在下面。

或者用一些pdf编辑器也做的到。

![](SDUCTF2019-wp\misc2.jpg)





### 0x03 今晚月色美吗

> 题目描述： 小王同学在路上走路，突然发现小朱同学发了一条朋友圈，配图是美美的月亮。于是小王同学心血来潮，掏出手机也拍了一张照片。你觉得月亮有什么奇怪的地方吗？ 

用StegSolve查看，原以为是加密，，没想到是藏在不同色差层。

![](SDUCTF2019-wp\misc3.jpg)





### 0x04 聋子听声音

> 题目描述：



我这边用的是Audacity，据说AU也可以查看，根据题目描述，音频应该不是隐写，而是藏在频谱图里

查看频谱图就可得flag

![](SDUCTF2019-wp\misc4.jpg)





# PWN



### 0x01 Simple nc

> 题目描述： 你会使用nc命令吗?
> 					可能是全球最简单的pwn题目 



![](SDUCTF2019-wp\pwn1.jpg)

虽然pwn还没入门，不过这确实是最简单得pwn。

熟悉nc即netcat命令即可，`netcat ctf.sec.sdunet.cn 38849`直接连上通过`ls,cat`命令读取flag



# Crypto



### 0x01 Base

> 题目描述：[https://baike.baidu.com/item/贝斯/]
>
> [奇怪的链接](https://www.google.com/search?q=ZmxhZ3tiYXNlNjRfaXNfbm90X2FuX2VuY3J5cHRpb25fbWV0aG9kfQ)

题目直接给了两个链接，不过第二个如下

```
ZmxhZ3tiYXNlNjRfaXNfbm90X2FuX2VuY3J5cHRpb25fbWV0aG9kfQ
```

直接扔base64去解码，得到flag：`flag{base64_is_not_an_encryption_method}`



### 0x02 诡异的数字

> 题目描述：摩同学做ctf到深夜，点开这道题却发现网安实验室里的灯突然有规律的时暗时亮，十分诡异。难道这代表着什么？
> 他用颤抖的双手记下了下面这段文字。你能发现其中的奥秘吗？
> 11 111 010 000 0 11111 00 000 11111
> 00 10 1 0 010 0 000 1 00 10 110
>
> flag格式为sductf{xxxxxxxxxx}

既然是摩同学，那么直接放莫斯解码即可，字符串利用python脚本的`str.replae()`方法替换成`.-`即可，即1对应`-`，2对应`.`，解得flag。



### 0x03 九宫格

> 题目描述：无论是搜狗输入法还是百度输入法还是QQ输入法还是讯飞输入法还是谷歌输入法还是..........都有9宫格，所以这个题目炒鸡简单
>
> 7426366432983
> 解出来的明文赋值给x
>
> flag为 flag{ md5(x+md5(x,16), 32) }
> (结果没有空格，x+ 表示的是x与另一个字符串进行拼接）



一串数字通过经典的九宫格打出来是`山东大学`四个字

然后通过python的`hashlib.md5()`就可以算出flag

md5的16位百度得知是截取32位md5中间的16位

```python
import hashlib
s = "山东大学"
mobj = hashlib.md5(s.encode('utf-8')).hexdigest()[8:24]
ans = hashlib.md5(str(s+mobj).encode('utf-8')).hexdigest()
```

```python
>>> import hashlib
>>> s = "山东大学"
>>> mobj = hashlib.md5(s.encode('utf-8')).hexdigest()[8:24]
>>> mobj
'f09383b061bb3c9f'
>>> ans = hashlib.md5(str(s+mobj).encode('utf-8')).hexdigest()
>>> ans
'ecf506190946c4e8d06d53e14191329e'
```



# Mobile



### 0x01 apk1

>  题目描述：用着安卓手机，你懂apk吗？ 

通过工具`d2j-dex2jar`和`jd-gui`两者逆向apk得到flag

![](SDUCTF2019-wp\mobile-apk1.jpg)

### 0x02 apk2

> 题目描述： 你真的懂apk吗？ 

通过工具`d2j-dex2jar`和`jd-gui`两者逆向apk得到flag

![](SDUCTF2019-wp\mobile-apk2.jpg)



然后看代码可知是对字符串进行一个排序，将字符串里的第i位放到s2[i]位，得到结果

直接写一个python脚本得到flag



# Reverse



### 0x01 Java jar

> 题目描述： 都是java程序员，互相偷个代码谁不会呀！ 

![](SDUCTF2019-wp\re1-java.jpg)

下载附件得到jar包，直接解压得到文件，打开`main.class`，看到flag明文就在main.class里



0x02

> 题目描述： C#简直跟java一样，会java就自然上手c#了。 

下载附件得到sductf.exe，拖入辣个女人ida进行逆向，直接得到flag

![](SDUCTF2019-wp\re2-sductf.jpg)







0x03 Rust

> 题目描述： 你听说过Rust语言吗？
> 					据说它非常安全。 



没接触过rust语言，不过据说逆向不知道程序逆向结构时，最好自己写个程序HelloWorld进行逆向一波看结构，但是我偷懒了。

直接百度搜索：rust逆向

 https://www.anquanke.com/post/id/169970 

 https://blog.csdn.net/qq_33438733/article/details/81138573 

看完链接之后打开ida，还需要64bit的辣个女人。

乱逛发现有一个字符串，但是解码出来是一个奇怪的东西，继续找主函数main

![](SDUCTF2019-wp\re3-rust-2.jpg)



主函数入口

![](SDUCTF2019-wp\re3-rust-3.jpg)



点进第一个函数查看流程



![](SDUCTF2019-wp\re3-rust-4.jpg)



既然是逆向，那就从尾部往后面看，果然看到一个判断和一个类似flag的字符串`c2R1Y3Rme0lfbDB2ZV9ydXN0X2hoaGh9`，base64解码得到flag：`sductf{I_l0ve_rust_hhhh}`



![](SDUCTF2019-wp\re3-rust-5.jpg)









































