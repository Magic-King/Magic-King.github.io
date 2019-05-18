---
title: Markdown Syntax
date: 2019-05-14 16:43:54
tags: Markdown
categories: Markdown
---



# <center>Markdown Syntax</center>







> 本文参考
>
> [Markdown基本语法(简书)](<https://www.jianshu.com/p/191d1e21f7ed>)
>
> [Markdown官方文档](www.markdown.cn)
>
> [Markdown语法html支持](<https://www.jianshu.com/p/b03a8d7b1719#fnref1>)
>
> [Markdown部分详细用法](<http://www.pianshen.com/article/2061138675/#_51>)





------



## 标题



Markdown 支持两种标题的语法，类 Setext 和类 atx 形式。

```markdown
Atx形式

# 这是一级标题
## 这是二级标题
### 这是三级标题
#### 这是四级标题
##### 这是五级标题
###### 这是六级标题
```



# 这是一级标题

## 这是二级标题

### 这是三级标题

#### 这是四级标题

##### 这是五级标题

###### 这是六级标题



```html
Setext形式

This is an H1
=============

This is an H2
-------------
```



This is an H1
=============

This is an H2
-------------



## 根据标题生成目录

```markdown
[TOC]  根据标题自动生成目录
```



[TOC]







------



## 字体





```
**这是加粗的文字**
*这是倾斜的文字*`
***这是斜体加粗的文字***
~~这是加删除线的文字~~
```

**加粗测试**

*倾斜测试*

***斜体加粗测试***

~~删除线测试~~



------



## 引用





```
>这是引用的内容
>>这是引用的内容
>>>多重引用
>>>>>>>>>>这是引用的内容
```

> 引用测试一
>
> > 引用测试二
> >
> > > 多重引用
> > >
> > > > > > > > > > > 引用测试







------



## 分割线



```
---
----
***
*****
```

只要三个以上就可以

---

------

***

******





------



## 图片引用





```markdown
![图片alt](图片地址 ''图片title'')

图片alt就是显示在图片下面的文字，相当于对图片内容的解释。
图片title是图片的标题，当鼠标移到图片上时显示的内容。title可加可不加
```



```markdown
![blockchain](https://ss0.bdstatic.com/70cFvHSh_Q1YnxGkpoWK1HF6hhy/it/
u=702257389,1274025419&fm=27&gp=0.jpg "区块链")
```



![blockchain](https://ss0.bdstatic.com/70cFvHSh_Q1YnxGkpoWK1HF6hhy/it/u=702257389,1274025419&fm=27&gp=0.jpg"区块链")





### 插入带有链接的图片

```markdown
[[图片上传失败...(image-f83b77-1542510791300)]](http://www.baidu.com){:target="_blank"}       // 内链式

[[图片上传失败...(image-4dc956-1542510791300)]][5]{:target="_blank"}                      // 引用式
[5]: http://www.baidu.com
```



[[图片上传失败...(image-f83b77-1542510791300)]](htttp://www.baidu.com){:target="_blank"}

内链式



[[图片上传失败...(image-f83b77-1542510791300)]][5]{:target="blank"}

[5]:http://www.baidu.com/



外链式





------



## 超链接引用





```markdown
[超链接名](超链接地址 "超链接title")
title可加可不加
```



```markdown
[简书](http://jianshu.com)
[百度](http://baidu.com)
```

 

[baidu](http://baidu.com)



注：Markdown本身语法不支持链接在新页面中打开，貌似简书做了处理，是可以的。别的平台可能就不行了，如果想要在新页面中打开的话可以用html语言的a标签代替。

```
<a href="超链接地址" target="_blank">超链接名</a>

示例
<a href="https://www.jianshu.com/u/1f5ac0cf6a8b" target="_blank">简书</a>
```

<a href="https://www.jianshu.com/u/1f5ac0cf6a8b" target="_blank">简书</a>



------



## 视频插入

注：Markdown 语法是不支持直接插入视频的
 普遍的做法是 插入HTML的 iframe 框架，通过网站自带的分享功能获取，如果没有可以尝试第二种方法
 第二是伪造播放界面，实质是插入视频图片，然后通过点击跳转到相关页面

**代码1**
 注：多数第三方平台不支持插入`<iframe>`视频

```markdown
<iframe height=498 width=510 src='http://player.youku.com/embed/XMjgzNzM0NTYxNg==' frameborder=0 'allowfullscreen'></iframe>
```



**代码2**

```markdown
[[图片上传失败...(image-49aefe-1542510791300)]](http://v.youku.com/v_show/id_XMjgzNzM0NTYxNg==.html?spm=a2htv.20009910.contentHolderUnit2.A&from=y1.3-tv-grid-1007-9910.86804.1-2#paction){:target="_blank"}
```







------



## 列表




```markdown
无序列表用任一种皆可

- 列表内容
+ 列表内容
* 列表内容

注意：- + * 跟内容之间都要有一个空格
```

- 列表（-）
- 列表（-）

+ 列表（+）


* 列表（*）



```markdown
有序列表内容

1.列表内容
2.列表内容
3.列表内容

注意：序号跟内容之间要有空格
```





1. 第一点
2. 第二点
3. 第三点



```markdown
**上一级和下一级之间敲三个空格即可**

- 一级无序列表内容
  - 二级无序列表内容
  - 二级无序列表内容
  - 二级无序列表内容
- 一级无序列表内容
  1. 二级有序列表内容
  2. 二级有序列表内容
  3. 二级有序列表内容

1. 一级有序列表内容
   - 二级无序列表内容
   - 二级无序列表内容
   - 二级无序列表内容
2. 一级有序列表内容
   1. 二级有序列表内容
   2. 二级有序列表内容
   3. 二级有序列表内容
```







**上一级和下一级之间敲三个空格即可**

- 一级无序列表内容
  - 二级无序列表内容
  - 二级无序列表内容
  - 二级无序列表内容
- 一级无序列表内容
  1. 二级有序列表内容
  2. 二级有序列表内容
  3. 二级有序列表内容

1. 一级有序列表内容
   - 二级无序列表内容
   - 二级无序列表内容
   - 二级无序列表内容
2. 一级有序列表内容
   1. 二级有序列表内容
   2. 二级有序列表内容
   3. 二级有序列表内容





------



## 表格





```
表头|表头|表头
---|:--:|---:
内容|内容|内容
内容|内容|内容

第二行分割表头和内容。
- 有一个就行，为了对齐，多加了几个
文字默认居左
-两边加：表示文字居中
-右边加：表示文字居右
注：原生的语法两边都要用 | 包起来。此处省略
```



```markdown
姓名|技能|排行
--|:--:|--:
刘备|哭|大哥
关羽|打|二哥
张飞|骂|三弟
```



| 姓名 | 技能 | 排行 |
| ---- | :--: | ---: |
| 刘备 |  哭  | 大哥 |
| 关羽 |  打  | 二哥 |
| 张飞 |  骂  | 三弟 |



Typora编辑器中可以直接使用crtl+T，或者在菜单段落中找到表格生成



------



## 代码引用



单行代码

```markdown
  `代码内容`
```

`int main(){return 0;}`



代码块

```markdown
(```)language
  代码...
  代码...
  代码...
(```)
```



> 注：为了防止转译，前后三个反引号处加了小括号，实际是没有的。这里只是用来演示，实际中去掉两边小括号即可。



```c++
#include<iostream>
using namespace std;
int main(){
    cout<< "hello markdown";
    return 0;
}
```



### 格式化代码html版

```markdown
<pre>
## 这是一个不起作用的标题
</pre>

```



<pre>## 这是一个不起作用的标题</pre>





------



## 流程图



注：** `st=>start: 开始` 的`：`后面保持空格**

| 形参    | 实参                          | 含义                          |
| ------- | ----------------------------- | ----------------------------- |
| tag     | st                            | 标签 (可以自定义)             |
| =>      | =>                            | 赋值                          |
| type    | start                         | 类型  (6种类型)               |
| content | 开始                          | 描述内容 (可以自定义)         |
| :>url   | `http://www.baidu.com[blank]` | 链接与跳转方式 **兼容性很差** |

| 6种类型     | 含义   |
| ----------- | ------ |
| start       | 启动   |
| end         | 结束   |
| operation   | 程序   |
| subroutine  | 子程序 |
| condition   | 条件   |
| inputoutput | 输出   |



| 形参          | 实参        | 含义                                                         |
| ------------- | ----------- | ------------------------------------------------------------ |
| ->            | ->          | 连接                                                         |
| condition     | c1          | 条件                                                         |
| (布尔值,方向) | (yes,right) | 如果满足向右连接，4种方向：right ，left，up ，down 默认为：down |

注：operation (程序); subroutine (子程序) ;condition (条件)，都可以在括号里加入连接方向。





~~~markdown
```flow
st=>start: 开始
op=>operation: My Operation
cond=>condition: Yes or No?
e=>end
st->op->cond
cond(yes)->e
cond(no)->op
&```
~~~



```flow
st=>start: 开始
op=>operation: My Operation
cond=>condition: Yes or No?
e=>end
st->op->cond
cond(yes)->e
cond(no)->op
&```
```







## 选项框

```markdown
- [x] 选项一
- [ ] 选项二  
需要注意的是：-、[x]、和选择一之间都要有空格，如果不下x[ ]中也要有空格

```



- [x] 选项一
- [ ] 选项二





------



## 数学公式



支持LaTex的数学公式，参考[<https://www.jianshu.com/p/2bbec51d756f>](<https://www.jianshu.com/p/2bbec51d756f>)

数学公式（MathJax)，参考[<https://www.jianshu.com/p/a0aa94ef8ab2>](<https://www.jianshu.com/p/a0aa94ef8ab2>)



注：1个$左对齐，2个居中

```markdown
$$ x \href{why-equal.html}{=} y^2 + 1 $$
$ x = {-b \pm \sqrt{b^2-4ac} \over 2a}. $
```


$$
x \href{why-equal.html}{=} y^2 +1
$$


使用Typora的时候可以直接使用 $$+回车，或者用crtl+shift+M生成公式块（在段落菜单中的公式块）

参考[<https://blog.csdn.net/mingzhuo_126/article/details/82722455>](<https://blog.csdn.net/mingzhuo_126/article/details/82722455>)



------



## 脚注



```markdown
Markdown[^1]
[^1]: Markdown是一种纯文本标记语言        // 在文章最后面显示脚注
```



Markdown[^1]

[^1]: markdown是一种纯文本标记语言



------

## 锚点

注：只有**标题**支持锚点， 跳转目录方括号后 保持空格

```markdown
[公式标题锚点](#1)

### [需要跳转的目录] {#1}    // 方括号后保持空格
```



[脚注标题锚点](#1)

```markdown
由于{# 是hexo的标注语言
hexo 中 {# 属于保留字段 {# ... #}属于注释字段
把```以外的{#改成{{ '{#' }}即可解决
```









------

## 自动邮箱链接



```markdown
<xxx@outlook.com>
```

<xxx@outlook.com>



------





## 时序图

**代码1**

```
​```sequence
A->>B: 你好
Note left of A: 我在左边     // 注释方向，只有左右，没有上下
Note right of B: 我在右边
B-->A: 很高兴认识你
​```
```

**演示**



![img](https:////upload-images.jianshu.io/upload_images/6912209-784ce9bb7beb6672.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/393/format/webp)



**代码详解**

注：`A->>B: 你好`   后面可以不写文字，但是一定要在最后加上`：`
 Note left of A 代表注释在A的左边

| 符号 | 含义     |
| ---- | -------- |
| `-`  | 实线     |
| `>`  | 实心箭头 |
| `--` | 虚线     |
| `>>` | 空心箭头 |

**代码2**

```
    ```sequence
    起床->吃饭: 稀饭油条
    吃饭->上班: 不要迟到了
    上班->午餐: 吃撑了
    上班->下班:
    Note right of 下班: 下班了
    下班->回家:
    Note right of 回家: 到家了
    回家-->>起床:
    Note left of 起床: 新的一天
```





**演示**

![img](https://upload-images.jianshu.io/upload_images/6912209-f109a13fcf7e2ccb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/577/format/webp)








