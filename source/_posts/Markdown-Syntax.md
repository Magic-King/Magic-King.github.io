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



------



## 流程图



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



