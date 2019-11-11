---
title: XCTF-adworld-crypto-wp
date: 2019-11-10 21:14:36
tags: [ctf, crypto]
categories: ctf
description:
password:
---





# <center>Crypto&WriteUp</center>



crypto永远充满了google和常识（还有工具



# <center>攻防世界&Crypto新手练习区</center>





## 0x01 幂数加密



>   题目描述：你和小鱼终于走到了最后的一个谜题所在的地方，上面写着一段话“亲爱的朋友， 很开心你对网络安全有这么大的兴趣，希望你一直坚持下去，不要放弃 ，学到一些知识， 走进广阔的安全大世界”，你和小鱼接过谜题，开始了耐心细致的解答。flag为cyberpeace{你解答出的八位大写字母} 



下载附件打开查看是txt，里面放一段数字

```
8842101220480224404014224202480122
```

由ctf-wiki的常识可知，这是01248加密，即以0为分割，将其中的数加起来对应字母表的排位。

解得flag

```
01248：
23 5 12 12 4 15 14 5
w  e l  l  d o  n  e
```



## 0x02 base64



> 题目描述：元宵节灯谜是一种古老的传统民间观灯猜谜的习俗。 因为谜语能启迪智慧又饶有兴趣，灯谜增添节日气氛，是一项很有趣的活动。 你也很喜欢这个游戏，这不，今年元宵节，心里有个黑客梦的你，约上你青梅竹马的好伙伴小鱼， 来到了cyberpeace的攻防世界猜谜大会，也想着一展身手。 你们一起来到了小孩子叽叽喳喳吵吵闹闹的地方，你俩抬头一看，上面的大红灯笼上写着一些奇奇怪怪的 字符串，小鱼正纳闷呢，你神秘一笑，我知道这是什么了。 



打开附件是一段英文，有题目得知是base64编码，解码得flag

```
Y3liZXJwZWFjZXtXZWxjb21lX3RvX25ld19Xb3JsZCF9
cyberpeace{Welcome_to_new_World!}
```



## 0x03 Caesar

> 题目描述：你成功的解出了来了灯谜，小鱼一脸的意想不到“没想到你懂得这么多啊！” 你心里面有点小得意，“那可不是，论学习我没你成绩好轮别的我知道的可不比你少，走我们去看看下一个” 你们继续走，看到前面也是热热闹闹的，同样的大红灯笼高高挂起，旁边呢好多人叽叽喳喳说个不停。你一看 大灯笼，上面还是一对字符，你正冥思苦想呢，小鱼神秘一笑，对你说道，我知道这个的答案是什么了


由题目得知是凯撒密码，随便百度一个工具进行暴力破解得知，移位12位

快捷：算出o和c得插值，但是我觉得更慢

``` 
oknqdbqmoq{kag_tmhq_xqmdzqp_omqemd_qzodkbfuaz}
cyberpeace{you_have_learned_caesar_encryption}
```



## 0x04 Morse

>  题目描述：小鱼得意的瞟了你一眼，神神气气的拿走了答对谜语的奖励，你心里暗暗较劲 想着下一个谜题一定要比小鱼更快的解出来。不知不觉你们走到了下一个谜题的地方，这个地方有些奇怪。 上面没什么提示信息，只是刻着一些0和1，感觉有着一些奇怪的规律，你觉得有些熟悉，但是就是想不起来 这些01代表着什么意思。一旁的小鱼看你眉头紧锁的样子，扑哧一笑，对你讲“不好意思我又猜到答案了。”(flag格式为cyberpeace{xxxxxxxxxx},均为小写) 

下载附件，打开文档是一串01串

```
11 111 010 000 0 1010 111 100 0 00 000 000 111 00 10 1 0 010 0 000 1 00 10 110
```

假如按`1:=.&0:=-`翻译则第一个字母可翻译，但是后面有一个字符无法翻译

因此，01调换顺序`1:=-&0:=.`

利用python的str.replace的到`.-`的morsecode，找个在线工具直接翻译得到结果，需要自己加上cyberpeace{}格式：`cyberpeace{morsecodeissointeresting}`

```
morsecodeissointeresting
```

可惜我后来没注意到需要全部小写，浪费了时间。



## 0x05 Railfence

>  题目描述：被小鱼一连将了两军，你心里更加不服气了。两个人一起继续往前走， 一路上杂耍卖艺的很多，但是你俩毫无兴趣，直直的就冲着下一个谜题的地方去了。 到了一看，这个谜面看起来就已经有点像答案了样子了，旁边还画着一张画，是一副农家小院的 图画，上面画着一个农妇在栅栏里面喂5只小鸡，你嘿嘿一笑对着小鱼说这次可是我先找到答案了。 

打开附件是一个文档如下，如题目明显的是栅栏加密。找了个在线工具破解。

```
ccehgyaefnpeoobe{lcirg}epriec_ora_g
```

结果常规栅栏加密没跑出来，在看到题目有一个数字5盲猜这可能是栅栏加密的key，但是常规的是跑不出来flag的，后面看百科知道有个是www型栅栏加密

**PS:WWW型的加密密钥就不只能是字符串长度的因子，小于其长度的任何一个数都可能是其key值，所以第一步也是确定密钥。**

由题目可知key可能是5，一尝试果然正确，得到flag：`cyberpeace{railfence_cipher_gogogo}`

附一个www型栅栏密码的网站： http://www.atoolbox.net/Tool.php?Id=777 

附赠一个栅栏密码的脚本

```python
#!/usr/bin/env python3

#常见的栅栏解密

e = input('清输入要解密的字符串\n')
elen = len(e)  # 计算字符串长度
field = []
for i in range(2, elen):  # 做一个循环，从2开始到数字elen（字符串长度）
    if elen % i == 0:  # 计算那些数字能整除字符串长度
        field.append(i)  # 将能整出的数字加入到field里面

for f in field:
    b = elen // f  # 用字符串实际长度除以上面计算出能整出的数字f
    result = {x: '' for x in range(b)}
    for i in range(elen):  # 字符串有多少位，就循环多少次
        a = i % b
        result.update({a: result[a] + e[i]})  # 字符串截断，并更新数据
    d = ''
    for i in range(b):
        d += result[i]
    print('分为'+str(f)+'栏时，解密结果为：'+d+'\n')  # 输出结果，并开始下一个循环

    
#W型加密

string=input("输入要加密的字符串\n")
length = len(string)

#猜想不会是一栏,和n栏（滑稽）因为这个就是原来字符串（狗头）
#那么，就暴力遍历一波其中的那些⑧

for i in range(2,length):
    result={x:""for x in range(i)}  
    for a in range(length) :
        width=i*2-2
        num=a%width
        if(num<i):
            result.update({num:result[num]+string[a]})           
        else:         
            ll=2*i-2-num
            result.update({ll:result[ll]+string[a]})               
    d=''
    
    for k in range(i):
        d=d+result[k]
    print("分为"+str(i)+"栏,结果是："+d)

```





## 0x06 转轮机加密

>  题目描述：你俩继续往前走，来到了前面的下一个关卡，这个铺面墙上写了好多奇奇怪怪的 英文字母，排列的的整整齐齐，店面前面还有一个大大的类似于土耳其旋转烤肉的架子，上面一圈圈的 也刻着很多英文字母，你是一个小历史迷，对于二战时候的历史刚好特别熟悉，一拍大腿：“嗨呀！我知道 是什么东西了！”。提示：托马斯·杰斐逊 



看题目可知是转轮机算法

附件内容如下：

```
1:   < ZWAXJGDLUBVIQHKYPNTCRMOSFE <
2:   < KPBELNACZDTRXMJQOYHGVSFUWI <
3:   < BDMAIZVRNSJUWFHTEQGYXPLOCK <
4:   < RPLNDVHGFCUKTEBSXQYIZMJWAO <
5:   < IHFRLABEUOTSGJVDKCPMNZQWXY <
6:   < AMKGHIWPNYCJBFZDRUSLOQXVET <
7:   < GWTHSPYBXIZULVKMRAFDCEONJQ <
8:   < NOZUTWDCVRJLXKISEFAPMYGHBQ <
9:   < XPLTDSRFHENYVUBMCQWAOIKZGJ <
10:  < UDNAJFBOWTGVRSCZQKELMXYIHP <
11： < MNBVCXZQWERTPOIUYALSKDJFHG <
12： < LVNCMXZPQOWEIURYTASBKJDFHG <
13： < JZQAWSXCDERFVBGTYHNUMKILOP <

密钥为： 2,3,7,5,13,12,9,1,8,10,4,11,6
密文为：NFQKSEVOQOFNP
```

//TODO：还需要搞清楚转轮机算法的原理，有点混乱现在

官方wp给出以下python自动化脚本



```python
import re
sss='''1: < ZWAXJGDLUBVIQHKYPNTCRMOSFE < 2: < KPBELNACZDTRXMJQOYHGVSFUWI < 3: < BDMAIZVRNSJUWFHTEQGYXPLOCK < 4: < RPLNDVHGFCUKTEBSXQYIZMJWAO < 5: < IHFRLABEUOTSGJVDKCPMNZQWXY < 6: < AMKGHIWPNYCJBFZDRUSLOQXVET < 7: < GWTHSPYBXIZULVKMRAFDCEONJQ < 8: < NOZUTWDCVRJLXKISEFAPMYGHBQ < 9: < XPLTDSRFHENYVUBMCQWAOIKZGJ < 10: < UDNAJFBOWTGVRSCZQKELMXYIHP < 11 < MNBVCXZQWERTPOIUYALSKDJFHG < 12 < LVNCMXZPQOWEIURYTASBKJDFHG < 13 < JZQAWSXCDERFVBGTYHNUMKILOP <
'''
m="NFQKSEVOQOFNP"
content=re.findall(r'< (.*?) <',sss,re.S)
iv=[2,3,7,5,13,12,9,1,8,10,4,11,6]
vvv=[]
ans=""
for i in range(13):
   index=content[iv[i]-1].index(m[i])
   vvv.append(index)
for i in range(0,26):
   flag=""
   for j in range(13):
       flag+=content[iv[j]-1][(vvv[j]+i)%26]
   print(flag)
```









## 0x07 easy RSA



打开附件查看。

```
在一次RSA密钥对生成中，假设p=473398607161，q=4511491，e=17
求解出d
fi=(p-1)(q-1)

--------------------------------------------------------------


e*d=1 mod fi
d=e^(fi(fi)-1)
```



感谢舍友的cpp文件

```cpp
#include<iostream>
#include<cstdio>
#define ll long long
ll  gcd(ll a,ll b,ll&aa,ll&bb){
	ll ab=0,ba=0;aa=1;bb=1;
	while(1){
		if(a==0){aa=ba;return b;}
		ba-=(b/a)*aa;bb-=(b/a)*ab;b%=a;
		if(b==0){bb=ab;return a;}
		aa-=(a/b)*ba;ab-=(a/b)*bb;a%=b;
	}
}
ll mod_inverse(ll a,ll mod){
	ll res,temp;
	ll d=gcd(a,mod,res,temp);
	if(d==1)return res;
	return -1;
}
int main(){
	ll p,q,e,d;
	p = 473398607161;
	q = 4511491;
	e = 17;
	std::cout<<mod_inverse(e,(p-1)*(q-1))<<std::endl;
}

```



根据舍友给的rsa的cpp文件改出的python脚本，不会爆longlong哦（虽然原题也不会爆。

```python

def EX_GCD(a,b,arr): #扩展欧几里得
    if b == 0:
        arr[0] = 1
        arr[1] = 0
        return a
    g = EX_GCD(b, a % b, arr)
    t = arr[0]
    arr[0] = arr[1]
    arr[1] = t - int(a / b) * arr[1]
    return g

	
def ModReverse(a,n): #ax=1(mod n) 求a模n的乘法逆x
    arr = [0,1,]
    gcd = EX_GCD(a,n,arr)
    if gcd == 1:
        return (arr[0] % n + n) % n
    else:
        return -1

'''
while True:
	a,b = eval(input())
	print(ModReverse(a,b))
'''

if __name__=='__main__':
	while True:
		l = input("p,q,e:")
		p,q,e = map(lambda x:int(x),l.split(","))
		fn = (p-1)*(q-1)
		#print(l)
		d = ModReverse(e,fn)
		print("d=%d"%d)

```



PS：看官方wp给出了一个GitHub项目地址：一款可以解rsa的工具 https://github.com/3summer/CTF-RSA-tool 

```python
python solve.py --verbose --private -N 2135733555619387051 -e 17 -p 473398607161 -q 4511491 
```



## 0x08 Normal_RSA



>  题目描述：你和小鱼走啊走走啊走，走到下一个题目一看你又一愣，怎么还是一个数学题啊 小鱼又一笑，hhhh数学在密码学里面很重要的！现在知道吃亏了吧！你哼一声不服气，我知道数学 很重要了！但是工具也很重要的，你看我拿工具把他解出来！你打开电脑折腾了一会还真的把答案 做了出来，小鱼有些吃惊，向你投过来一个赞叹的目光 



果然，解rsa都是需要工具的，看完官方wp后，发现只需要ctf-rsa-tools一行代码就能跑出flag来。

甚至连题目给的样例都是人家example里的（虽然是摘自PCTF。

```python
python solve.py --verbose -k examples/jarvis_oj_mediumRSA/pubkey.pem --decrypt examples/jarvis_oj_mediumRSA/flag.enc
```



不过在看wp时，发现有人给了另一种常规解法

他的解题思路解题思路是：①使用 openssl 解密.pem 中参数 --> ②参数十六进制转换为十进制 --> ③ 利用 factor 对大整数进行分解，得到 p 和 q  --> ④用 rsatool 生成私钥文件: private.pem  --> ⑤用 private.pem 解密 flag.enc 

其中第三步factor用到的网站为：http://www.factordb.com/ 

```sh
#1
$openssl rsa -pubin -text -modulus -in warmup -in pubkey.pem
#2将得到的modulus用python进行转换
$python
>>> 0xC2636AE5C3D8E43FFB97AB09028F1AAC6C0BF6CD3D70EBCA281BFFE97FBE30DD 
87924348264132406875276140514499937145050893665602592992418171647042491658461
>>>
#3 进入网站 http://www.factordb.com/  将大整数分解为p，q
#p= 275127860351348928173285174381581152299 
#q= 319576316814478949870590164193048041239
#4 利用rsatool 生成私钥文件 private.pem
$python rsatool.py -o private.pem -e 65537 -p XXX -q XXX
#5
$openssl rsautl -decrypt -in flag.enc -inkey private.pem
```





## 0x09 不仅仅是Morse

>  题目描述：“这个题目和我们刚刚做的那个好像啊但是为什么按照刚刚的方法做出来答案却不对呢” ，你奇怪的问了问小鱼，“可能是因为还有一些奇怪的加密方式在里面吧，我们在仔细观察观察”。两个人 安安静静的坐下来开始思考，很耐心的把自己可以想到的加密方式一种种的过了一遍，十多分钟后两个人 异口同声的说“我想到了！”。一种食物,格式为cyberpeace{小写的你解出的答案} 



题目附件给了一大串摩斯电码，按常理找一个网站解密了

```
--/.-/-.--/..--.-/-..././..--.-/..../.-/...-/./..--.-/.-/-./---/-/...././.-./..--.-/-.././-.-./---/-.././..../..../..../..../.-/.-/.-/.-/.-/-.../.-/.-/-.../-.../-.../.-/.-/-.../-.../.-/.-/.-/.-/.-/.-/.-/.-/-.../.-/.-/-.../.-/-.../.-/.-/.-/.-/.-/.-/.-/-.../-.../.-/-.../.-/.-/.-/-.../-.../.-/.-/.-/-.../-.../.-/.-/-.../.-/.-/.-/.-/-.../.-/-.../.-/.-/-.../.-/.-/.-/-.../-.../.-/-.../.-/.-/.-/-.../.-/.-/.-/-.../.-/.-/-.../.-/-.../-.../.-/.-/-.../-.../-.../.-/-.../.-/.-/.-/-.../.-/-.../.-/-.../-.../.-/.-/.-/-.../-.../.-/-.../.-/.-/.-/-.../.-/.-/-.../.-/.-/-.../.-/.-/.-/.-/-.../-.../.-/-.../-.../.-/.-/-.../-.../.-/.-/-.../.-/.-/-.../.-/.-/.-/-.../.-/.-/-.../.-/.-/-.../.-/.-/-.../.-/-.../.-/.-/-.../-.../.-/-.../.-/.-/.-/.-/-.../-.../.-/-.../.-/.-/-.../-.../.-
```

摩斯电码解密网站： http://www.zhongguosou.com/zonghe/moErSiCodeConverter.aspx 

解出来如下，明显嵌套了另外一种加密

```
MAY..--.-BE..--.-HAVE..--.-ANOTHER..--.-DECODEHHHHAAAAABAABBBAABBAAAAAAAABAABABAAAAAAABBABAAABBAAABBAABAAAABABAABAAABBABAAABAAABAABABBAABBBABAAABABABBAAABBABAAABAABAABAAAABBABBAABBAABAABAAABAABAABAABABAABBABAAAABBABAABBA

```

因为后面一串AB串，转摩斯翻译不出来，因为不晓得哪里分界，转为二进制也没有思路，百度得知这是培根密码

培根密码解密网站： http://rumkin.com/tools/cipher/baconian.php 

AB串解得`ATTACKANDDEFENCEWORLDISINTERESTING`

记得小写。



## 0x0a 混合编码

>  题目描述：经过了前面那么多题目的历练，耐心细致在解题当中是 必不可少的品质，刚巧你们都有，你和小鱼越来越入迷。那么走向了下一个题目，这个题目好长 好长，你知道你们只要细心细致，答案总会被你们做出来的，你们开始慢慢的尝试，慢慢的猜想 ，功夫不负有心人，在你们耐心的一步步的解答下，答案跃然纸上，你俩默契一笑，相视击掌 走向了下面的挑战。格式为cyberpeace{小写的你解出的答案} 

这题感觉没什么好说的，下载附件发现

```
JiM3NjsmIzEyMjsmIzY5OyYjMTIwOyYjNzk7JiM4MzsmIzU2OyYjMTIwOyYjNzc7JiM2ODsmIzY5OyYjMTE4OyYjNzc7JiM4NDsmIzY1OyYjNTI7JiM3NjsmIzEyMjsmIzEwNzsmIzUzOyYjNzY7JiMxMjI7JiM2OTsmIzEyMDsmIzc3OyYjODM7JiM1NjsmIzEyMDsmIzc3OyYjNjg7JiMxMDc7JiMxMTg7JiM3NzsmIzg0OyYjNjU7JiMxMjA7JiM3NjsmIzEyMjsmIzY5OyYjMTIwOyYjNzg7JiMxMDU7JiM1NjsmIzEyMDsmIzc3OyYjODQ7JiM2OTsmIzExODsmIzc5OyYjODQ7JiM5OTsmIzExODsmIzc3OyYjODQ7JiM2OTsmIzUwOyYjNzY7JiMxMjI7JiM2OTsmIzEyMDsmIzc4OyYjMTA1OyYjNTY7JiM1MzsmIzc4OyYjMTIxOyYjNTY7JiM1MzsmIzc5OyYjODM7JiM1NjsmIzEyMDsmIzc3OyYjNjg7JiM5OTsmIzExODsmIzc5OyYjODQ7JiM5OTsmIzExODsmIzc3OyYjODQ7JiM2OTsmIzExOTsmIzc2OyYjMTIyOyYjNjk7JiMxMTk7JiM3NzsmIzY3OyYjNTY7JiMxMjA7JiM3NzsmIzY4OyYjNjU7JiMxMTg7JiM3NzsmIzg0OyYjNjU7JiMxMjA7JiM3NjsmIzEyMjsmIzY5OyYjMTE5OyYjNzc7JiMxMDU7JiM1NjsmIzEyMDsmIzc3OyYjNjg7JiM2OTsmIzExODsmIzc3OyYjODQ7JiM2OTsmIzExOTsmIzc2OyYjMTIyOyYjMTA3OyYjNTM7JiM3NjsmIzEyMjsmIzY5OyYjMTE5OyYjNzc7JiM4MzsmIzU2OyYjMTIwOyYjNzc7JiM4NDsmIzEwNzsmIzExODsmIzc3OyYjODQ7JiM2OTsmIzEyMDsmIzc2OyYjMTIyOyYjNjk7JiMxMjA7JiM3ODsmIzY3OyYjNTY7JiMxMjA7JiM3NzsmIzY4OyYjMTAzOyYjMTE4OyYjNzc7JiM4NDsmIzY1OyYjMTE5Ow==
```

明显的base64编码，解base64得到如下：

```
&#76;&#122;&#69;&#120;&#79;&#83;&#56;&#120;&#77;&#68;&#69;&#118;&#77;&#84;&#65;&#52;&#76;&#122;&#107;&#53;&#76;&#122;&#69;&#120;&#77;&#83;&#56;&#120;&#77;&#68;&#107;&#118;&#77;&#84;&#65;&#120;&#76;&#122;&#69;&#120;&#78;&#105;&#56;&#120;&#77;&#84;&#69;&#118;&#79;&#84;&#99;&#118;&#77;&#84;&#69;&#50;&#76;&#122;&#69;&#120;&#78;&#105;&#56;&#53;&#78;&#121;&#56;&#53;&#79;&#83;&#56;&#120;&#77;&#68;&#99;&#118;&#79;&#84;&#99;&#118;&#77;&#84;&#69;&#119;&#76;&#122;&#69;&#119;&#77;&#67;&#56;&#120;&#77;&#68;&#65;&#118;&#77;&#84;&#65;&#120;&#76;&#122;&#69;&#119;&#77;&#105;&#56;&#120;&#77;&#68;&#69;&#118;&#77;&#84;&#69;&#119;&#76;&#122;&#107;&#53;&#76;&#122;&#69;&#119;&#77;&#83;&#56;&#120;&#77;&#84;&#107;&#118;&#77;&#84;&#69;&#120;&#76;&#122;&#69;&#120;&#78;&#67;&#56;&#120;&#77;&#68;&#103;&#118;&#77;&#84;&#65;&#119;
```

明显的unicode编码，解码得到如下

```
LzExOS8xMDEvMTA4Lzk5LzExMS8xMDkvMTAxLzExNi8xMTEvOTcvMTE2LzExNi85Ny85OS8xMDcvOTcvMTEwLzEwMC8xMDAvMTAxLzEwMi8xMDEvMTEwLzk5LzEwMS8xMTkvMTExLzExNC8xMDgvMTAw
```

没有明显特征，解一波base64得到如下

```
/119/101/108/99/111/109/101/116/111/97/116/116/97/99/107/97/110/100/100/101/102/101/110/99/101/119/111/114/108/100
```

盲猜Ascii吗

```python
>>> a = '/119/101/108/99/111/109/101/116/111/97/116/116/97/99/107/97/110/100/100/101/102/101/110/99/101/119/111/114/108/100'
>>> l = a.split('/')
>>> s = ''
>>> for i in range(30):#从i+1开始因为/的原因，l[0] = ''
...     s += chr(int(l[i+1]))
>>> s
'welcometoattackanddefenceworld'
```



得到flag：`cyberpeace{welcometoattackanddefenceworld}`



## 0x0b easychallenge

>  题目描述：你们走到了一个冷冷清清的谜题前面，小鱼看着题目给的信息束手无策，丈二和尚摸不着头脑 ，你嘿嘿一笑，拿出来了你随身带着的笔记本电脑，噼里啪啦的敲起来了键盘，清晰的函数逻辑和流程出现在 了电脑屏幕上，你敲敲键盘，更改了几处地方，运行以后答案变出现在了电脑屏幕上。 



下载附件发现是一个pyc文件，明显是一个已经编译的python文件

百度搜反编译pyc，找到一个在线反编译网站 https://tool.lu/pyc/ 



反编译得到源代码：

```python
#!/usr/bin/env python
# encoding: utf-8
# 如果觉得不错，可以推荐给你的朋友！http://tool.lu/pyc
import base64

def encode1(ans):
    s = ''
    for i in ans:
        x = ord(i) ^ 36
        x = x + 25
        s += chr(x)
    
    return s


def encode2(ans):
    s = ''
    for i in ans:
        x = ord(i) + 36
        x = x ^ 36
        s += chr(x)
    
    return s


def encode3(ans):
    return base64.b32encode(ans)

flag = ' '
print 'Please Input your flag:'
flag = raw_input()
final = 'UC7KOWVXWVNKNIC2XCXKHKK2W5NLBKNOUOSK3LNNVWW3E==='
if encode3(encode2(encode1(flag))) == final:
    print 'correct'
else:
    print 'wrong'
```



易知chr和ord为反函数、`x^a^a=x`、`base64.b32decode()`和`base64.b32encode()`互为反函数

因此写一个python脚本即可得出flag



```python
>>> final = 'UC7KOWVXWVNKNIC2XCXKHKK2W5NLBKNOUOSK3LNNVWW3E==='
>>> import base64
>>> a = base64.b32decode(final)#decode3
>>> a
b'\xa0\xbe\xa7Z\xb7\xb5Z\xa6\xa0Z\xb8\xae\xa3\xa9Z\xb7Z\xb0\xa9\xae\xa3\xa4\xad\xad\xad\xad\xad\xb2'
#注意要将a的字节流转换
>>> b = "\xa0\xbe\xa7Z\xb7\xb5Z\xa6\xa0Z\xb8\xae\xa3\xa9Z\xb7Z\xb0\xa9\xae\xa3\xa4\xad\xad\xad\xad\xad\xb2"
>>> s = ''#decode2
>>> for i in b:
...     s += chr((ord(i)^36)-36)
...
>>>
>>> s
'`v_ZomZ^`ZxfciZoZpifc\\eeeeer'
>>> l = ''#decode1
>>> for i in s:
...     l+= chr((ord(i)-25)^36)
...
>>> l
'cyberpeace{interestinghhhhh}'

```



PS：

```shell
#编译python文件为.pyc文件
$python -m compileall main.py

#pyc的反编译
#依赖python的uncompyle
$pip install uncompyle

#查看帮助
$uncompyle6 --help
#将models.pyc反编译成models.py
$uncompyle6 models.pyc > models.py


```

利用uncompyle6反编译的pyc文件和在线编译文件相同，也挺快的

![](XCTF-adworld-crypto-wp\11_1.jpg)





## 0x0c easy_ECC



>  题目描述：转眼两个人又走到了下一个谜题的地方，这又是一种经典的密码学加密方式 而你刚好没有这个的工具，你对小鱼说“小鱼我知道数学真的很重要了，有了工具只是方便我们使用 懂了原理才能做到，小鱼你教我一下这个缇努怎么做吧！”在小鱼的一步步带领下，你终于明白了ECC 的基本原理，成功的解开了这个题目，两个人相视一笑，快步走向了下一个题目所在的位置。flag格式为cyberpeace{x+y的值} 



由题目可知：这是ECC加密

```
已知椭圆曲线加密Ep(a,b)参数为

p = 15424654874903

a = 16546484

b = 4548674875

G(6478678675,5636379357093)

私钥为

k = 546768

求公钥K(x,y)

```



又因为题目说工具，了解其算法后，便找到了一个python的脚本计算公钥

```python
import collections
import random

EllipticCurve = collections.namedtuple('EllipticCurve', 'name p a b g n h')

curve = EllipticCurve(
   'secp256k1',
   # Field characteristic.
   p=int(input('p=')),
   # Curve coefficients.
   a=int(input('a=')),
   b=int(input('b=')),
   # Base point.
   g=(int(input('Gx=')),
      int(input('Gy='))),
   # Subgroup order.
   n=int(input('k=')),
   # Subgroup cofactor.
   h=1,
)


# Modular arithmetic ##########################################################

def inverse_mod(k, p):
   """Returns the inverse of k modulo p.

  This function returns the only integer x such that (x * k) % p == 1.

  k must be non-zero and p must be a prime.
  """
   if k == 0:
       raise ZeroDivisionError('division by zero')

   if k < 0:
       # k ** -1 = p - (-k) ** -1 (mod p)
       return p - inverse_mod(-k, p)

   # Extended Euclidean algorithm.
   s, old_s = 0, 1
   t, old_t = 1, 0
   r, old_r = p, k

   while r != 0:
       quotient = old_r // r
       old_r, r = r, old_r - quotient * r
       old_s, s = s, old_s - quotient * s
       old_t, t = t, old_t - quotient * t

   gcd, x, y = old_r, old_s, old_t

   assert gcd == 1
   assert (k * x) % p == 1

   return x % p


# Functions that work on curve points #########################################

def is_on_curve(point):
   """Returns True if the given point lies on the elliptic curve."""
   if point is None:
       # None represents the point at infinity.
       return True

   x, y = point

   return (y * y - x * x * x - curve.a * x - curve.b) % curve.p == 0


def point_neg(point):
   """Returns -point."""
   assert is_on_curve(point)

   if point is None:
       # -0 = 0
       return None

   x, y = point
   result = (x, -y % curve.p)

   assert is_on_curve(result)

   return result


def point_add(point1, point2):
   """Returns the result of point1 + point2 according to the group law."""
   assert is_on_curve(point1)
   assert is_on_curve(point2)

   if point1 is None:
       # 0 + point2 = point2
       return point2
   if point2 is None:
       # point1 + 0 = point1
       return point1

   x1, y1 = point1
   x2, y2 = point2

   if x1 == x2 and y1 != y2:
       # point1 + (-point1) = 0
       return None

   if x1 == x2:
       # This is the case point1 == point2.
       m = (3 * x1 * x1 + curve.a) * inverse_mod(2 * y1, curve.p)
   else:
       # This is the case point1 != point2.
       m = (y1 - y2) * inverse_mod(x1 - x2, curve.p)

   x3 = m * m - x1 - x2
   y3 = y1 + m * (x3 - x1)
   result = (x3 % curve.p,
             -y3 % curve.p)

   assert is_on_curve(result)

   return result


def scalar_mult(k, point):
   """Returns k * point computed using the double and point_add algorithm."""
   assert is_on_curve(point)



   if k < 0:
       # k * point = -k * (-point)
       return scalar_mult(-k, point_neg(point))

   result = None
   addend = point

   while k:
       if k & 1:
           # Add.
           result = point_add(result, addend)

       # Double.
       addend = point_add(addend, addend)

       k >>= 1

   assert is_on_curve(result)

   return result


# Keypair generation and ECDHE ################################################

def make_keypair():
   """Generates a random private-public key pair."""
   private_key = curve.n
   public_key = scalar_mult(private_key, curve.g)

   return private_key, public_key



private_key, public_key = make_keypair()
print("private key:", hex(private_key))
print("public key: (0x{:x}, 0x{:x})".format(*public_key))
```



```sh
$python ecc_calKey.py
p=15424654874903
a=16546484
b=4548674875
Gx=6478678675
Gy=5636379357093
k=546768
private key: 0x857d0
public key: (0xcb19fe553fa, 0x50545408eb4)

$python
>>> 0x50545408eb4+0xcb19fe553fa
19477226185390
>>>
```













