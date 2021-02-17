---
title: Regular Expression
date: 2019-09-22T14:00:51+08:00
tags: [regex, python]
categories: [tech]
description:
password: 
---









## 正则表达式的规则





常用元字符

| 代码 | 说明                       |
| :--- | :------------------------- |
| .    | 匹配除换行符以外的任意字符 |
| \w   | 匹配字母或数字或下划线     |
| \s   | 匹配任意的空白符           |
| \d   | 匹配数字                   |
| \b   | 匹配单词的开始或结束       |
| ^    | 匹配字符串的开始           |
| $    | 匹配字符串的结束           |

常用限定符

| 代码/语法 | 说明             |
| :-------- | :--------------- |
| *         | 重复零次或更多次 |
| +         | 重复一次或更多次 |
| ?         | 重复零次或一次   |
| {n}       | 重复n次          |
| {n,}      | 重复n次或更多次  |
| {n,m}     | 重复n到m次       |

常用反义词

| 代码/语法 | 说明                                       |
| :-------- | :----------------------------------------- |
| \W        | 匹配任意不是字母，数字，下划线，汉字的字符 |
| \S        | 匹配任意不是空白符的字符                   |
| \D        | 匹配任意非数字的字符                       |
| \B        | 匹配不是单词开头或结束的位置               |
| [^x]      | 匹配除了x以外的任意字符                    |
| [^aeiou]  | 匹配除了aeiou这几个字母以外的任意字符      |

**预定义字符集表**

| \d   | \d匹配任何十进制数，它相当于类[0-9]，\d+如果需要匹配一位或者多位数的数字时用 |
| ---- | ------------------------------------------------------------ |
| \D   | \D匹配任何非数字字符，它相当于类[^0-9]                       |
| \s   | \s匹配任何空白字符，它相当于类[\t\n\r\f\v]                   |
| \S   | \S匹配任何非空白字符，它相当于类[^\t\n\r\f\v]                |
| \w   | \w匹配包括下划线在内任何字母数字字符，它相当于类  `{a-z,A-Z,0-9,_}` |
| \W   | \W匹配非任何字母数字字符包括下划线在内，它相当于类 `{ ^a-z,A-Z,0-9,_}` |
| \A   | 仅匹配字符串开头,同^                                         |
| \Z   | 仅匹配字符串结尾，同$                                        |
| \b   | b匹配一个单词边界，也就是指单词和空格间的位置                |
| \B   | [^\b]                                                        |

 





## 常用正则表达式



> 引用：[史上最全常用正则表达式大全](http://www.cnblogs.com/zxin/archive/2013/01/26/2877765.html)

### 一、校验数字的表达式

 

1. 数字：`^[0-9]*$`

2. n位的数字：`^\d{n}$`

3. 至少n位的数字：`^\d{n,}$`

4. m-n位的数字：`^\d{m,n}$`

5. 零和非零开头的数字：`^(0|[1-9][0-9]*)$`

6. 非零开头的最多带两位小数的数字：`^([1-9][0-9]*)+(.[0-9]{1,2})?$`

7. 带1-2位小数的正数或负数：`^(\-)?\d+(\.\d{1,2})?$`

8. 正数、负数、和小数：`^(\-|\+)?\d+(\.\d+)?$`

9. 有两位小数的正实数：`^[0-9]+(.[0-9]{2})?$`

10. 有1~3位小数的正实数：`^[0-9]+(.[0-9]{1,3})?$`

11. 非零的正整数：`^[1-9]\d*$` 或 `^([1-9][0-9]*){1,3}$` 或 `^\+?[1-9][0-9]*$`

12. 非零的负整数：`^\-[1-9][]0-9"*$` 或 `^-[1-9]\d*$`

13. 非负整数：`^\d+$` 或 `^[1-9]\d*|0$`

14. 非正整数：`^-[1-9]\d*|0$` 或 `^((-\d+)|(0+))$`

15. 非负浮点数：`^\d+(\.\d+)?$` 或 `^[1-9]\d*\.\d*|0\.\d*[1-9]\d*|0?\.0+|0$`

16. 非正浮点数：`^((-\d+(\.\d+)?)|(0+(\.0+)?))$` 或                                                                `^(-([1-9]\d*\.\d*|0\.\d*[1-9]\d*))|0?\.0+|0$`

17. 正浮点数：`^[1-9]\d*\.\d*|0\.\d*[1-9]\d*$` 或                                                                        `^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$`

18. 负浮点数：`^-([1-9]\d*\.\d*|0\.\d*[1-9]\d*)$` 或 `^(-(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*)))$`

19. 浮点数：`^(-?\d+)(\.\d+)?$` 或 `^-?([1-9]\d*\.\d*|0\.\d*[1-9]\d*|0?\.0+|0)$`

 

 

### 二、校验字符的表达式

 

1. 汉字：`^[\u4e00-\u9fa5]{0,}$`

2. 英文和数字：`^[A-Za-z0-9]+$ 或 ^[A-Za-z0-9]{4,40}$`

3. 长度为3-20的所有字符：`^.{3,20}$`

4. 由26个英文字母组成的字符串：`^[A-Za-z]+$`

5. 由26个大写英文字母组成的字符串：`^[A-Z]+$`

6. 由26个小写英文字母组成的字符串：`^[a-z]+$`

7. 由数字和26个英文字母组成的字符串：`^[A-Za-z0-9]+$`

8. 由数字、26个英文字母或者下划线组成的字符串：`^\w+$ 或 ^\w{3,20}$`

9. 中文、英文、数字包括下划线：`^[\u4E00-\u9FA5A-Za-z0-9_]+$`

10. 中文、英文、数字但不包括下划线等符号：`^[\u4E00-\u9FA5A-Za-z0-9]+$ `或                                           ` ^[\u4E00-\u9FA5A-Za-z0-9]{2,20}$`

 

11. 可以输入含有^%&',;=?$\"等字符：`[^%&',;=?$\x22]+ 12` 
12. 禁止输入含有~的字符：`[^~\x22]+`

 

 

### 三、特殊需求表达式

 

1. Email地址：`^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$`

2. 域名：`[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(/.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+/.?`

3. InternetURL：`[a-zA-z]+://[^\s]*` 或  `^http://([\w-]+\.)+[\w-]+(/[\w-./?%&=]*)?$`

4. 手机号码：`^(13[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\d{8}$`

5. 电话号码("XXX-XXXXXXX"、"XXXX-XXXXXXXX"、"XXX-XXXXXXX"、"XXX-XXXXXXXX"、"XXXXXXX"和"XXXXXXXX)：`^(\(\d{3,4}-)|\d{3.4}-)?\d{7,8}$`

6. 国内电话号码(0511-4405222、021-87888822)：`\d{3}-\d{8}|\d{4}-\d{7}`

7. 身份证号(15位、18位数字)：`^\d{15}|\d{18}$`

8. 短身份证号码(数字、字母x结尾)：`^([0-9]){7,18}(x|X)?$ `或` ^\d{8,18}|[0-9x]{8,18}|[0-9X]{8,18}?$`

9. 帐号是否合法(字母开头，允许5-16字节，允许字母数字下划线)：`^[a-zA-Z][a-zA-Z0-9_]{4,15}$`

 

10. 密码(以字母开头，长度在6~18之间，只能包含字母、数字和下划线)：`^[a-zA-Z]\w{5,17}$`

11. 强密码(必须包含大小写字母和数字的组合，不能使用特殊字符，长度在8-10之间)：                `^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,10}$`

 

12. 日期格式：`^\d{4}-\d{1,2}-\d{1,2}`

13. 一年的12个月(01～09和1～12)：`^(0?[1-9]|1[0-2])$`

14. 一个月的31天(01～09和1～31)：`^((0?[1-9])|((1|2)[0-9])|30|31)$`

    

15. 钱的输入格式：

 有四种钱的表示形式我们可以接受:"10000.00" 和 "10,000.00", 和没有 "分" 的 "10000" 和 "10,000"：`^[1-9][0-9]*$`

 这表示任意一个不以0开头的数字,但是,这也意味着一个字符"0"不通过,所以我们采用下面的形式：`^(0|[1-9][0-9]*)$`

 一个0或者一个不以0开头的数字.我们还可以允许开头有一个负号：`^(0|-?[1-9][0-9]*)$`

 这表示一个0或者一个可能为负的开头不为0的数字.让用户以0开头好了.把负号的也去掉,因为钱总不能是负的吧.下面我们要加的是说明可能的小数部分：`^[0-9]+(.[0-9]+)?$`

 必须说明的是,小数点后面至少应该有1位数,所以"10."是不通过的,但是 "10" 和 "10.2" 是通过的：`^[0-9]+(.[0-9]{2})?$`

 这样我们规定小数点后面必须有两位,如果你认为太苛刻了,可以这样：`^[0-9]+(.[0-9]{1,2})?$`

 这样就允许用户只写一位小数.下面我们该考虑数字中的逗号了,我们可以这样：                            `^[0-9]{1,3}(,[0-9]{3})*(.[0-9]{1,2})?$`

 到3个数字,后面跟着任意个 逗号+3个数字,逗号成为可选,而不是必须：                                               `^([0-9]+|[0-9]{1,3}(,[0-9]{3})*)(.[0-9]{1,2})?$`

 备注：这就是最终结果了,别忘了"+"可以用"*"替代如果你觉得空字符串也可以接受的话(奇怪,为什么?)最后,别忘了在用函数时去掉去掉那个反斜杠,一般的错误都在这里



16. xml文件：`^([a-zA-Z]+-?)+[a-zA-Z0-9]+\\.[x|X][m|M][l|L]$`

17. 中文字符的正则表达式：`[\u4e00-\u9fa5]`

18. 双字节字符：`[^\x00-\xff]` (包括汉字在内，可以用来计算字符串的长度(一个双字节字符长度计2，ASCII字符计1))
19. 空白行的正则表达式：`\n\s*\r `(可以用来删除空白行)*
20. HTML标记的正则表达式：`<(\S*?)[^>]*>.*?</\1>|<.*? />` (网上流传的版本太糟糕，上面这个也仅仅能部分，对于复杂的嵌套标记依旧无能为力)
21. 首尾空白字符的正则表达式：` ^\s*|\s*$`或 `(^\s*)|(\s*$)` (可以用来删除行首行尾的空白字符(包括空格、制表符、换页符等等)，非常有用的表达式)
22. 腾讯QQ号：`[1-9][0-9]{4,}` (腾讯QQ号从10000开始)
23. 中国邮政编码：`[1-9]\d{5}(?!\d)` (中国邮政编码为6位数字)
24. IP地址：`\d+\.\d+\.\d+\.\d+` (提取IP地址时有用)
25. IP地址：`((?:(?:25[0-5]|2[0-4]\\d|[01]?\\d?\\d)\\.){3}(?:25[0-5]|2[0-4]\\d|[01]?\\d?\\d))`

 











## Python re模块



人生苦短，不如Python。

> 引用：[python基础—re模块—正则表达式](https://blog.csdn.net/jamfiy/article/details/88139202)

python从1.5版本起增加re模块为自带的模块，提供了Perl风格的正则表达式模式



以下是python re库的常用函数



|                 函数                 |                        描述                        |
| :----------------------------------: | :------------------------------------------------: |
|      compile(pattern[, flags])       |       根据包含正则表达式的字符串创建模式对象       |
|   search(pattern, string[, flags])   |                 在字符串中查找模式                 |
|   match(pattern, string[, flags])    |                在字符串开头匹配模式                |
| split(pattern, string[, maxsplit=0]) |                根据模式来分割字符串                |
|       findall(pattern, string)       | 返回一个列表，其中包含字符串中所有与模式匹配的子串 |
|  sub(pat, repl, string[, count=0])   |     将字符串中与模式pat匹配的子串都替换为repl      |
|            escape(string)            |    对字符串中所有的正则表达式特殊字符都进行转义    |



* #### re.compile()

```python
compile 函数用于编译正则表达式，生成一个正则表达式（ Pattern ）对象，供 match() 和 search() 这两个函数使用。

语法格式为：

re.compile(pattern[, flags])

实例

>>>import re

>>> pattern = re.compile(r'\d+') # 用于匹配至少一个数字

>>> m = pattern.match('one12twothree34four') # 查找头部，没有匹配

>>> print(m)

None

>>> m = pattern.match('one12twothree34four', 2, 10) # 从'e'的位置开始匹配，没有匹配

>>> print(m)

None

>>> m = pattern.match('one12twothree34four', 3, 10) # 从'1'的位置开始匹配，正好匹配 >>>

print(m) # 返回一个 Match 对象
<_sre.SRE_Match object at 0x10a42aac0>

>>> m.group(0) # 可省略 0 '12'

>>> m.start(0) # 可省略 0 3

>>> m.end(0) # 可省略 0 5

>>> m.span(0) # 可省略 0 (3, 5)

在上面，当匹配成功时返回一个 Match 对象，其中：

group([group1, …]) 方法用于获得一个或多个分组匹配的字符串，当要获得整个匹配的子串时，可直接使用 group() 或 group(0)；
start([group]) 方法用于获取分组匹配的子串在整个字符串中的起始位置（子串第一个字符的索引），参数默认值为 0；
end([group]) 方法用于获取分组匹配的子串在整个字符串中的结束位置（子串最后一个字符的索引+1），参数默认值为 0；
span([group]) 方法返回 (start(group), end(group))。
再看看一个例子：

实例

>>>import re

>>> pattern = re.compile(r'([a-z]+) ([a-z]+)', re.I) # re.I 表示忽略大小写

>>> m = pattern.match('Hello World Wide Web')

>>> print(m)# 匹配成功，返回一个 Match 对象
<_sre.SRE_Match object at 0x10bea83e8>

>>> m.group(0) # 返回匹配成功的整个子串 'Hello World'

>>> m.span(0) # 返回匹配成功的整个子串的索引 (0, 11)

>>> m.group(1) # 返回第一个分组匹配成功的子串 'Hello'

>>> m.span(1) # 返回第一个分组匹配成功的子串的索引 (0, 5)

>>> m.group(2) # 返回第二个分组匹配成功的子串 'World'

>>> m.span(2) # 返回第二个分组匹配成功的子串 (6, 11)

>>> m.groups() # 等价于 (m.group(1), m.group(2), ...) ('Hello', 'World')

>>> m.group(3) # 不存在第三个分组

Traceback (most recent call last):
File "<stdin>", line 1, in <module>
IndexError: no such group

```



* #### re.search()&re.match()



```python
re.search 扫描整个字符串并返回第一个成功的匹配。

函数语法：

re.search(pattern, string, flags=0)

函数参数说明：

pattern:匹配的正则表达式
string:要匹配的字符串。
flags:标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等。

    
匹配成功re.search方法返回一个匹配的对象，否则返回None。

我们可以使用group(num) 或 groups() 匹配对象函数来获取匹配表达式。

匹配对象方法

group(num=0):匹配的整个表达式的字符串，group() 可以一次输入多个组号，在这种情况下它将返回一个包含那些组所对应值的元组。
groups():返回一个包含所有小组字符串的元组，从 1 到 所含的小组号。

实例

import re

line = "Cats are smarter than dogs";
searchObj = re.search( r'(.*) are (.*?) .*', line, re.M|re.I)

if searchObj:
      print ("searchObj.group() : ", searchObj.group())
      print ("searchObj.group(1) : ", searchObj.group(1))
      print ("searchObj.group(2) : ", searchObj.group(2))
else:
      print( "Nothing found!!")

以上实例执行结果如下：

searchObj.group() : Cats are smarter than dogs
searchObj.group(1) : Cats
searchObj.group(2) : smarter

 
_____________________________________________________________________________


re.match 尝试从字符串的起始位置匹配一个模式，如果不是起始位置匹配成功的话，match()就返回none。

函数语法：

re.match(pattern, string, flags=0)

函数参数说明：（同re.search一样）

匹配成功re.match方法返回一个匹配的对象，否则返回None。

我们可以使用group(num) 或 groups() 匹配对象函数来获取匹配表达式。

匹配对象方法：（同re.search一样）

实例

import re

print(re.match('www', 'www.runoob.com').span()) # 在起始位置匹配
print(re.match('com', 'www.runoob.com')) # 不在起始位置匹配

以上实例运行输出结果为：
(0, 3) 
None

实例

import re

line = "Cats are smarter than dogs"
matchObj = re.match( r'(.*) are (.*?) .*', line, re.M|re.I)

if matchObj:
     print("matchObj.group() : ", matchObj.group())
     print("matchObj.group(1) : ", matchObj.group(1))
     print("matchObj.group(2) : ", matchObj.group(2))
else:
     print("No match!!")

以上实例执行结果如下：

matchObj.group() : Cats are smarter than dogs
matchObj.group(1) : Cats
matchObj.group(2) : smarter

 
____________________________________________________________________________


re.match与re.search的区别:
re.match只匹配字符串的开始，如果字符串开始不符合正则表达式，则匹配失败，函数返回None；而re.search匹配整个字符串，直到找到一个匹配。

实例

import re
line = "Cats are smarter than dogs";
matchObj = re.match( r'dogs', line, re.M|re.I)
if matchObj:
     print("match --> matchObj.group() : ", matchObj.group())
else:
     print ("No match!!")
matchObj = re.search( r'dogs', line, re.M|re.I)
if matchObj:
     print("search --> matchObj.group() : ", matchObj.group())
else:
     print("No match!!")

以上实例运行结果如下：

No match!!
search --> matchObj.group() : dogs

```





* #### re.split()



```python
split 方法按照能够匹配的子串将字符串分割后返回列表，它的使用形式如下：

re.split(pattern, string[, maxsplit=0, flags=0])

参数:
pattern:匹配的正则表达式
string:要匹配的字符串。
maxsplit:分隔次数，maxsplit=1 分隔一次，默认为 0，不限制次数。
flags:标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等。

实例

>>>import re

>>> re.split('\W+', 'runoob, runoob, runoob.')
['runoob', 'runoob', 'runoob', '']

>>> re.split('(\W+)', ' runoob, runoob, runoob.')
['', ' ', 'runoob', ', ', 'runoob', ', ', 'runoob', '.', '']

>>> re.split('\W+', ' runoob, runoob, runoob.', 1)
['', 'runoob, runoob, runoob.']

>>> re.split('a*', 'hello world') # 对于一个找不到匹配的字符串而言，split 不会对其作出分割
['hello world']

```



* #### re.sub()



```python
Python 的 re 模块提供了re.sub用于替换字符串中的匹配项。

语法:
re.sub(pattern, repl, string, count=0, flags=0)

参数：
pattern : 正则中的模式字符串。
repl : 替换的字符串，也可为一个函数。
string : 要被查找替换的原始字符串。
count : 模式匹配后替换的最大次数，默认 0 表示替换所有的匹配。

    
实例:

import re

phone = "2004-959-559 # 这是一个国外电话号码"
num = re.sub(r'#.*$', "", phone)   # 删除字符串中的 Python注释
print ("电话号码是: ", num)
num = re.sub(r'\D', "", phone) # 删除非数字(-)的字符串
print ("电话号码是 : ", num)

以上实例执行结果如下：

电话号码是: 2004-959-559
电话号码是 : 2004959559

 

以下实例中将字符串中的匹配的数字乘以 2：

import re

def double(matched):   # 将匹配的数字乘以 2
    value = int(matched.group('value'))
    return str(value * 2)

s = 'A23G4HFD567'
print(re.sub('(?P<value>\d+)', double, s))

执行输出结果为：
A46G8HFD1134

```





* #### findall()



```python
在字符串中找到正则表达式所匹配的所有子串，并返回一个列表，如果没有找到匹配的，则返回空列表。

注意： match 和 search 是匹配一次,findall 匹配所有。

语法格式为：

findall(string[, pos[, endpos]])

参数：

string: 待匹配的字符串。
pos: 可选参数，指定字符串的起始位置，默认为 0。
endpos: 可选参数，指定字符串的结束位置，默认为字符串的长度。
查找字符串中的所有数字：

实例

import re

pattern = re.compile(r'\d+') # 查找数字
result1 = pattern.findall('runoob 123 google 456')
result2 = pattern.findall('run88oob123google456', 0, 10) #取字符串之中0-10之间的数字出来
print(result1，result2)

输出结果：
['123', '456']，['88', '12']

```





* #### re.finditer()



```python
和 findall 类似，在字符串中找到正则表达式所匹配的所有子串，并把它们作为一个迭代器返回。

re.finditer(pattern, string, flags=0)

参数:

pattern:匹配的正则表达式
string:要匹配的字符串。
flags:标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等。

实例

import re

it = re.finditer(r"\d+","12a32bc43jf3")
for match in it:
    print (match.group() )

输出结果：
12 32 43 3

```





* #### re.escape()



re.escape()的主要作用就是将一个字符串变成可以匹配的正则表达式

```python
re.escape是一个工具函数，用于对字符串中所有可能被视为正则表达式运算符的字符进行转义。使用这个函数的情况有：字符串很长，其中包含大量特殊字符，而你不想输入大量的反斜杠；你从用户那里获取了一个字符串（例如，通过函数input），想将其用于正则表达式中。下面的示例说明了这个函数的工作原理：
>>> re.escape('www.python.org') 
'www\\.python\\.org' 
>>> re.escape('But where is the ambiguity?') 
'But\\ where\\ is\\ the\\ ambiuity\\?' 

```































