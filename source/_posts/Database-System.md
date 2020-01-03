---
title: Database-System
date: 2020-01-02 11:15:07
tags: [Database, StudyNote]
categories: Database
description:
password:
---





#  数据库系统概念





## 引言



DBMS定义：由一个相互关联的数据集合和一组用以访问这些数据的程序组成，这个数据集合同城称作**数据库(Database)**。

DBMS的目标：方便、高效地存取数据库信息



* 四个基本概念
  * 数据（Data）
  * 数据库（Database）
  * 数据库管理系统（DBMS）
  * 数据库系统（DBS）



### 数据

数据（Data）是数据库中存储的基本对象

**数据的定义**：描述事物的符号记录

**数据的种类**：文字、图形、图像、声音

**数据的特点**：数据与其语义是不可分的

！数据的形式不能完全表达其内容



#### 数据结构

**逻辑结构**：数据之间存在的逻辑关系，如表、树、图、数组等

**物理结构**：数据在计算机内的存储方式，如顺序方式、链接方式



### 数据库

数据库（Database，简称DB）是**长期**储存在计算机内、**有组织的**、**可共享**的**大量**数据集合

#### 数据库的特征

* 数据按一定的数据模型组织、描述和储存
* 可为各种用户共享
* 冗余度较小
* 数据独立性较高
* 易扩展



### 数据库管理系统

数据库管理系统（Database Management System，简称DBMS）由一个相互关联的数据的集合和一组用以访问这些数据的程序组成，是位于用户与操作系统之间的一层数据管理软件。

**用途**：科学地组织和存储数据、高效地获取和维护数据



* **数据定义功能**：提供数据定义语言（DDL），定义数据库中的数据对象
* **数据操作功能**：提供数据操纵语言（DML），操纵数据实现对数据库的基本操作（增删改查）
* **数据库的运行管理**：保证数据的安全性、完整性，保证多用户对数据的并发使用，发生故障后的系统恢复
* **数据库的建立和维护功能**：数据库数据批量装载，数据库转储，介质故障恢复，数据库的重组织，性能监视





### 数据库系统

数据库系统（Database System，简称DBS）是指在计算机系统中引入数据库后的系统，在不引起混淆的情况下常常把数据库系统简称为数据库

**数据库系统的组成**：由数据库、数据库管理系统、应用系统（及其开发工具）、数据库管理员（和用户）构成

如下图所示

![](Database-System\1.jpg)



下图为各系统间的关系

![](Database-System\2.jpg)



### 数据管理技术

数据管理：对数据进行分类、组织、编码、存储、检索和维护，是数据处理的中心问题

数据管理的发展动力：应用需求的推动；计算机硬件的发展；计算机软件的发展。

发展阶段：①人工管理阶段（50年代中期以前）②文件系统阶段（50年代后期~60年代中期）③数据库系统阶段（60年代后期开始）



> 早期，数据库应用程序直接建立在文件系统之上，文件系统的弊端如下：
>
> * 数据的冗余和不一致性：多种文件格式，相同的信息在几个文件重复存储
> * 数据访问困难：对于每一个新任务，需要写一个程序
> * 数据孤立：数据分散在不同格式的多个文件中
> * 完整性问题：一致性约束“淹没”在程序代码中，增加新约束或修改现有约束很困难
> * 更新的原子性问题：难以保持原子性，执行部分更新，是的数据处于不一致状态
> * 多用户的并发访问异常：系统的总体性能和相应速度要求：并发访问数据，没有控制的并发访问导致不一致性
> * 安全性问题：控制用户只存取部分数据难以实现
>
> 



数据库的观点：数据不是依赖于处理过程的附属品，而是现实世界中独立存在的对象

数据统一按表结构存放

<center>数据库VS文件系统</center>  
![](Database-System\3.jpg)



### 实例与模式

Instance and Schemas

型(Schema)与值(Instance)的区别：

* 型是对数据的结构和属性的说明——模式
* 值是型的一个具体赋值——实例
* 型是相对稳定的，值是随时间不断变化的



```c++
class person{
	public:	string name;
			string address;
};
person Tom;
//person是型,Tom是变量,Tom在某时刻的值是实例
```



#### 模式：数据库的总体设计

* 通过高级程序设计语言进行类比
* **物理模式**：在物理层描述的数据库设计
* **逻辑模式（子模式）**：在逻辑层描述的数据库设计

#### 实例：在特定时刻存储在数据库中的信息集合

* 类似于一个变量的值

#### 物理数据的独立性：物理模式的改变而不会影响逻辑模式

* 应用依赖于逻辑模式
* 在一般情况下，应明确定义不同层次之间和组件之间的接口，这样某些部分的改变不会对其他部分造成较大影响

#### 逻辑数据的独立性

* 当模式改变时，修改外模式（模式映像），使外模式保持不变，从而应用程序可以保持不变，称为数据的逻辑独立性



### 数据视图



**物理层**：描述数据存储

**逻辑层**：描述存储在数据库中的数据，以及数据间的关系

**视图层**：最高层次的抽象，只描述整个数据库的某部分数据。视图层提供了防止用户访问数据库的某些部分的安全性机制

![](Database-System\4.jpg)

如图，下图的COBOL和PL/I是由由逻辑层创建的两个视图，而最下面那个即是物理层所存放的数据

![](Database-System\5.jpg)





### 数据模型

**数据库结构的基础是数据模型**

数据模型描述的内容：数据、数据关系、数据语义、数据约束

常用数据模型：关系模型、实体-联系数据模型（ER模型，主要用于数据库设计）、基于对象的数据模型（oo数据模型，面向对象和对象关系）、半结构化数据模型（XML，可扩展标记语言）、其他模型（如网状模型、层次模型）等





### 数据库语言



* DML（Data Manipulaton Language）：操纵按照某种适当的数据模型组织起来的数据的语言
  - 查询
  - 更新（增、删、改）

DML分类：①过程化：用户指定需要什么数据以及如何获得这些数据；②声明式（非过程化）：用户指定需要什么数据，而不指明如何获得这些数据

SQL是应用最广泛的DML



* DDL（Data Definition Language）：用于定义数据库模式以及其他特征的语言
  * 数据库模式
  * 完整性约束：
    * 主键（ID，用来确定唯一的instructor）
    * 参照完整性（SQL中的参照约束）
  * 断言
  * 授权

DDL编译器产生一系列存储在**数据字典**中的表，数据字典包含元数据（元数据是关于数据的数据）



### 关系数据库

SQL：是一门广泛使用的非过程化语言

```sql
# 例
# SQL-DML
select instructor.ID, department.building
from instructor, department
where instructor.dept_name = department.dept_name and
		department.dept_nmae = 'Physics';

# SQL-DDL
create table deptment(
	dept_name char(20),
    building char(20),
    budget numberic(12,2)
);

```



来自应用程序的数据库访问：DML由宿主语言执行



### 数据库设计

数据库设计的主要内容是数据库模式的设计

数据库设计过程：

* 获取用户需求
* 概念设计
* 逻辑设计
* 物理设计



现实世界是实体及其实体之间关系的集合

实体：现实世界中区别于其他对象的事情或物体，实体被一组属性所描述

关系：几个实体之间的关联

可以用实体关系图（entity-relationship diagram，E-R图）来表示

![](Database-System\6.jpg)



规范化：数据库设计的另外一种方法，目标是生成一个关系模式集合，是我们的存储信息是没有不必要的冗余，同时又能方便地检索数据

规范化最常用的方法就是使用函数依赖

规范化也提供了判定一个关系模式优劣的标准



### 数据存储和查询

存储管理器是一个程序模块，提供了数据库中存储的低层数据与应用程序以及向系统提交的查询之间的接口

* 存储管理器的任务
  * 与文件管理器交互
  * 对数据的有效的存储、查询、更新
* 存储管理器部件
  * 权限及完整性管理器
  * 事务管理器
  * 文件管理器
  * 缓冲区管理器



#### 查询管理器

查询管理器的组件包括

* DDL解释器：他解释DDL语句，并将这些定义记录在数据字典中
* DML编译器：将查询语言中的DML语句翻译成为一个执行方案
* 查询执行引擎：执行由DML编译器产生的低级指令



![](Database-System\7.jpg)



* 查询处理器的工作过程
  * 解析和转换
  * 优化
  * 计算



过程如下图

![](Database-System\8.jpg)

两方面来评估一个给定查询：①正则表达式②每个操作有不同的实现算法

需要估计操作的开销：关键取决于数据库需要维护的关系的统计信息；需要顾及中间结果的统计数据，从而计算复杂的表达式成本



### 事务管理

**事务**是由一系列操作序列构成的程序执行单元，是一个不可分割的工作单位

**事务管理组件**保证了当系统出现了故障（例如电源故障、操作系统崩溃）或事务失败时，数据库仍然保持一致性（正确性）

**并发控制管理器**控制了并发事务间的相互影响，保证数据库的一致性



### 数据库系统内部结构



![](Database-System\9.jpg)





#### 数据库体系结构

数据库系统的体系结构很大程度上取决于数据库系统所运行的计算机系统

* 集中式
* 客户/服务器式
  * 远程数据库用户工作用的客户机（Clinet）
  * 运行数据库系统的服务器（Server）
* 并行（多处理器）
  * 并行系统通过并行地使用多个处理器和磁盘来提高处理速度和I/O速度
* 分布式
  * 在分布式数据库系统中，数据库存储于几台计算机中，分布式系统中的计算机之间通过网络相互通信，他们不共享主存储器或磁盘



### 数据挖掘

数据挖掘式应用一系列技术从大型数据库或数据仓库中提取人马感兴趣的信息和知识，这些知识或信息式隐含的，实现未知而潜在有用的，提取的知识表示为概念、规则、规律、模式等形式

数据挖掘式一类深层次的数据分析



### 数据库管理员

对数据库系统进行集中控制的人称作数据库管理员（Database Administrator）

* DBA的作用
  * 模式定义
  * 存储结构及存取方法定义
  * 模式及物理组织的修改
  * 数据访问授权
  * 日常维护





## 关系模型



关系理论是建立在集合代数理论基础上的，有坚实的数学基础





#### 关系数据结构

* **单一的数据结构——关系**：现实世界中的实体及实体间的各种联系均用关系来表示

* **数据的逻辑结构——二维表**：从用户角度，关系模型中的数据的逻辑结构是一张二维表





#### 属性的类型

* 每个属性的可能的取值范围（集合）叫属性的**域**

* 属性的值（通常）要求为**原子的**，也就是说，不可再分的
  * 属性的原子性问题要根据应用的需求确定
* null（空值）：是一个特殊的值，表示值未知或不存在
  * 空值给数据库访问和更新带来了很多困难



### 关系的基本概念



#### 关系

笛卡尔积D<sub>1</sub> × D<sub>2</sub> × ... × D<sub>n</sub> 的子集叫做在域D<sub>1</sub>，D<sub>2</sub> ，...，D<sub>n</sub> 上的关系，用R(D<sub>1</sub>，D<sub>2</sub> ，...，D<sub>n</sub> )表示

R是关系的名字，n是关系的度或目

关系是笛卡尔积中有意义的子集

关系也可以表示为二维表



#### 关系模型和实例

```
A1,A2,...,An 是属性
R = (A1,A2,...,An) 是一个关系模式
例:
instructor = (ID,name,dept_name,salary)

形式上，给定集合D1,D2,...,Dn,一个关系r是D1×D2×...×Dn 的一个子集,因此,一个关系是一组n元组(a1,a2,...,an)的集合，其中ai ∈ Di

```

关系的当前值（关系实例）可以用一个表指定

元素t是关系r中的一个元组，表中一行代表一个元组

* 数据库由多个关系组成



### 码

* **码的作用**：我们必须有一种能够区分给定关系中不同元组的方法。我们一般用元组中的属性表明，即一个元组的属性值必须是能够唯一区分元组的，一个关系中没有两个元组在所有属性上的取值都相同

* **超码**：超码是一个或者多个属性的集合，这些属性的组合可以使我们在一个关系中唯一地标识一个元组（例如，{ID}和{ID，name}都是instructor的超码）

* **候选码**：最小的超码称为候选码，即超码的任意真子集都不能成为超码（例如，{ID}是Instructor的一个候选码）

* **主码**：从一个关系的多个候选码中选定一个作为主码（习惯上把主码属性放在其他属性前面，并且加下划线）

* **外码**：一个关系模式r1可能在他的属性中包含另一个关系r2的主码，这个属性称作r1上参照r2的外码（r1和r2可以是同一个关系）
  * 关系r1称作外码依赖的参照关系
  * 关系r2称作外码的被参照关系



### 关系查询语言

查询语言是用户用来从数据库中请求获取信息的语言

* 广泛应用的查询语言：SQL
* “纯”查询语言
  * 关系代数（过程化）
  * 元组关系演算（非过程化）
  * 域关系演算（非过程化）





### 关系操作



* 基本操作
  * 一元运算
    * 选择、投影、更名
  * 多元运算
    * 笛卡尔积、并、集合差
* 其他运算
  * 集合交、θ连接，自然连接、除、赋值





自然连接：设r和s是关系模式R和S的实例，R和S关系实例的自然连接是关系模式R∪S的实例，遵守以下规则：①对于每一对元组 t<sub>r</sub> 和 t<sub>s</sub> ，其中 t<sub>r</sub>  来自r，t<sub>s</sub> 来自s；②如果 t<sub>r</sub> 和 t<sub>s</sub> 在属性组R∩S上的每个属性值都一样，添加一个元组t到结果集，其中 t由t<sub>r</sub> 在r上相同的值，t有 t<sub>s</sub> 在s上相同的值



笛卡尔积运算从两个关系中合并元组，但不同于连接运算的是，其结果包含来自两个关系元组的所有对，无论它们的属性是否匹配





```
# 选择元组
Relation r:
	A	B	C	D
	α	α	1	7
	α	β	5	7
	β	β	12	3
	β	β	23	10

select tuples with A=B and D>5
σ A=B and D>5 (r)

ans:
	A	B	C	D
	α	α	1	7
	β	β	23	10
	
	
------------------------------

# 选择列(属性)

Relation r:
	A	B	C
	α	10	1
	α	20	1
	β	30	1
	β	40	2


select A and C

Projection
Π A,C (r)

ans:
	A	C
	α	1
	β	1
	β	2


------------------------------

# 连接两个关系
# 笛卡尔积

Relation r,s:
	r
		A	B
		α	1
		β	2
	s
		C	D	E
		α	10	a
		β	10	a
		β	20	b
		γ	10	b

r × s:
	
	A	B	C	D	E
	α	1	α	10	a
	α	1	β	10	a
	α	1	β	20	b
	α	1	γ	10	b
	β	2	α	10	a
	β	2	β	10	a
	β	2	β	20	b
	β	2	γ	10	b


------------------------------

# 并运算

Relation r,s:
	r
		A	B
		α	1
		α	2
		β	1
	
	s
		A	B
		α	2
		β	3
		
r ∪ s:
		A	B
		α	1
		α	2
		β	1
		β	3
		

------------------------------

# 差运算

Relation r,s:
	r
		A	B
		α	1
		α	2
		β	1
	
	s
		A	B
		α	2
		β	3
		
		
r - s: 

		A	B
		α	1
		β	1
		
------------------------------

# 交运算

Relation r,s:
	r
		A	B
		α	1
		α	2
		β	1
	
	s	
		A	B
		α	2
		β	3

r ∩ s:
		A	B
		α	2
		
------------------------------

# 自然连接

Relation r,s
	r
		A	B	C	D
		α	1	α	a
		β	2	γ	a
		γ	4	β	b
		α	1	γ	a
		δ	2	β	b
	
	s
		B	D	E
		1	a	α
		3	a	β
		1	a	γ
		2	b	δ
		3	b	ε
		

Natural Join
r ⋈	s:
		A	B	C	D	E
		α	1	α	a	α
		α	1	α	a	γ
		α	1	γ	a	α
		α	1	γ	a	γ
		δ	2	β	b	δ


------------------------------

# 连接两个关系
# 笛卡尔积

------------------------------

```







## SQL



SQL：Structured Query Language 

商用系统一般支持sql-92的大部分特性，并支持后续的扩充标准中部分的扩充特性，以及系统特殊的自有特性

体系结构：user==(==>view==>table)==>base table==> stored file



| SQL功能  | 操作符                 |
| -------- | ---------------------- |
| 数据查询 | Select                 |
| 数据定义 | Create、Alter、Drop    |
| 数据操纵 | Insert、Update、Delete |
| 数据控制 | Grant、Revoke          |

 



### 数据定义

**SQL的数据定义语言（DDL）**能够定义每个关系的信息，包括①每个关系的模式；②每个属性的值域；③完整性约束；④将来的信息，如每个关系的索引集合，每个关系的安全性和权限信息，磁盘上每个关系的物理存储结构



####  **SQL的基本类型**

 * char(n)：固定长度的字符串，用户指定长度n
 * varchar(n)：可变长度的字符串，用户指定最大长度n
 * int：整数类型（和机器相关的整数类型的有限子集）
 * smallint：小整数类型（和机器相关的整数类型的子集）
 * numeric(p,d)：定点数，精度由用户指定，这个数有p位数字，其中d位数字在小数点右边
 * real，double，precision：浮点数与双精度浮点数，精度与机器相关
 * float(n)：浮点数，精度由用户指定，精度至少为n位

 



#### 创建表结构



使用`create table `命令创建一个SQL关系表：

```sql
create table r( A1 D1,
				A2 D2,
				...,
				An Dn)

# r是关系名
# 每个Ai是关系模式r的一个属性名
# Di是属性Ai的域的类型

#例
create table instructor(ID	char(5),
                        name	varchar(20)	not null,
                        dept_name	varchar(20),
                        salary	numeric(8,2) )
    
insert into instructor  
   values (‘10211’, ’Smith’, ’Biology’, 66000);

```



##### `Create table`中的完整性约束

* `not null` 
* `primary key(A1,A2,...,An)`
* `foreign key(Am,...,An) references r`

注：被声明为主码的属性自动被确保为`not null` 

例：

```mysql
create table instructor(
						ID	char(5),
						name	varchar(20)	not null,
						dept_name	varchar(20),
						salary	numeric(8.2),
						primary key(ID),
						foreign key(dept_name) references department)

create table takes(
					ID	varchar(5),
					course_id	varchar(8),
					sec_id	varchar(8),
					semester	varchar(6),
					year	numeric(4,0),
					grade	varchar(2),
					primary key (ID,course_id,sec_id,semester,year),
					foreign key (ID) references	student,
					)

```

主码的声明和属性的声明可以放在一起，例如`course_id	 varchar(8)  primary key,`



#### 删除和更改表结构



```mysql
# 删除表和他的内容
drop table student

# 删除表中的内容,但是保留表
delete from student


# 更改表结构
alter table

# 属性A是关系r将要增加的属性,D是A的域
# 对于关系r中的所有元组,在新增加的属性上的取值都为null
alter table r add A D

# A是关系r的一个属性名
# 许多数据库不支持删除属性的操作
alter table r drop A

# 修改表中属性A的数据类型,将A的域改为D
# 可能破坏原有的数据
alter table r modify A D



```



#### 索引

建立索引是加快查询速度的有效手段

建立索引：由DBA或表的属主（建立表的人）根据需要建立索引；或者有些DBMS自动建立特定列上（Primary key，unique）的索引

维护索引：DBMS自动完成

使用索引：DBMS自动选择是否使用索引以及使用哪些索引

定义的格式

```mysql
create	[unique | distinct]	[cluster]	index	index_name	
		on table_name	(col_name	[asc | desc]	[,col_name asc|desc,...])
# unique(distinct):	唯一性索引，不允许表中不同的行在索引列上取相同的值.若已有相同值存在,则系统给出相关信息,不建此索引.系统并拒绝违背唯一性的插入、更新
# cluster: 聚集索引,表中元组按索引项的值排序并物理地聚集在一起.一个基本表上只能建一个聚集索引
# asc|desc: 索引表中索引值的排序次序,缺省为asc

drop index index_name
# 删除索引

```



##### 索引的有关说明

* 可以动态地定义索引，即可以随时建立和删除索引

* 不允许用户在数据操作中引用索引。索引如何使用完全由系统决定，这支持了数据的物理独立性

* 应该在使用频率高的、经常用于连接的列上建索引

* 一个表上可建多个索引。索引可以提高查询效率，但索引过多耗费空间，且降低了插入、删除、更新的效率







### SQL查询的基本结构



**SQL的数据操纵语言（DML）**提供了从数据库中查询信息，以及在数据库中插入元组、删除元组、修改元组的能力



* SQL中的标识符大小写不敏感





#### Select

`select`子句用于列出查询结果中所需要的属性，与关系代数中的投影运算相对应

SQL允许在关系和查询结果中保留重复的元组

强制去重，需要在`select`之后使用关键字`distinct`

`*`一般代表所有属性，是一个通配符

`Select`子句可包含`+`、`-`、`*`、`/`运算符的算数表达式,运算对象可以是常量或者元组的属性

```mysql
# 典型的查询语句
# Ai表示一个属性,ri表示一个关系,P是一个谓词(即可以是一个条件判断)
select	A1,A2,...,An
from	r1,r2,...,rn
where	P

# 去重
select distinct dept_name
	from	instructor
	
# 关键词all显式指明不去重复
select all dept_name 
	from instructor
	
# *代表所有属性
select *
	from instructor
	
# Select子句可包含+、-、*、/运算符的算数表达式,运算对象可以是常量或者元组的属性
select	ID,name,salary/12
	from instructor


```



#### where

`where`子句指定查询结果必须满足的条件，与关系代数中的选择谓词相对应

比较结果可以使用逻辑连词`and`，`or`，`not`连接

比较结果可以用于算术表达式

> 语法成分：
>
> * 逻辑运算符：and，or，not
> * 比较运算符：<，<=，>，>=，=，<>
> * between条件：判断表达式的值是否在某范围内，例如 `age between 18 and 20 `==`age∈[18,20]`，`not between ... and ... `
>
> 



```mysql
# 找出所有在Computer Science系并且工资超过80000美元的教师的姓名
select	name
from	instructor
where dept_name = 'Computer Science' and salary > 80000


```



#### from

`from`子句列出了查询中的包含关系，与关系代数中的笛卡尔积运算相对应

笛卡尔积不是经常被直接使用，他在使用时经常与`where`子句（关系代数的选择操作）一起使用



```mysql
# 求笛卡尔积instructor × teacher
# 产生所有的instructor-teacher对,包含两个关系的所有属性
select	* 
from	instructor, teacher


```





#### 连接



```mysql
# 例
# 对于大学所有讲授课程的教师,找出他们的姓名以及所讲授的课程的标识
select	name,course_id
from instructor,teacher
where instructor.ID = teacher.ID

```



##### 连接查询及执行过程

同时涉及多个表的查询称为连接查询

用来连接两个表的条件称为连接条件或连接谓词

一般格式：`[<table_name1>.]<col_name1><比较运算符>[<table_name2>.]<col_name2>`

`[<table_name1>.]<col_name1> between [<table_name2>.]<col_name2> AND [<table_name3>.]<col_name3>`



连接字段：连接谓词中的列名称为连接字段。连接条件中的各连接字段类型必须是可比的，但不必是相同的

> * 嵌套循环法（Nested-Loop）
>
>   * 首先在表1中找到第一个元组，然后从头开始扫描表2，逐一查找满足连接件的元组，找到后就将表1中的第一个元组与该元组拼接起来，形成结果表中一个元组。
>   * 表2全部查找完后，再找表1中第二个元组，然后再从头开始扫描表2，逐一查找满足连接条件的元组，找到后就将表1中的第二个元组与该元组拼接起来，形成结果表中一个元组
>   * 重复上述操作，直到表1中的全部元组都处理完毕
>
>   
>
>   ------
>
>   
>
>  * 排序合并法（Sort-Merge）
>
>     * 首先按照连接属性对表1和表2排序
>     * 对表1的第一个元组，从头开始扫描表2，顺序查找满足连接条件的元组，找到后就将表1中的第一个元组与该元组拼接起来，形成结果表中一个元组。当遇到表2中第一条大于表1连接字段值的元组时，对表2的查询不再继续
>     * 找到表1的第二条元组，然后从刚才的中断点处继续顺序扫描表2，查找满足连接条件的元组，找到后就将表1中的第一个元组与该元组拼接起来，形成结果表中一个元组。直接遇到表2中大于表1连接字段值的元组时，对表2的查询不再继续
>     * 重复上述操作，直到表1或表2中的全部元组都处理完毕为止
>
>    
>
> ------
>
>    
>
> * 索引连接法（Index-Join）
>
>   * 对表2按连接字段建立索引
>   * 对表1中的每个元组，依次根据其连接字段值查询表2的索引，从中找到满足条件的元组，找到后就将表1中的第一个元组与该元组拼接起来，形成结果表中一个元组
>
>   
>



#### 自然连接

自然连接只考虑两个关系模式中都出现的属性上取值相同的元组对，并且相同属性的列只保留一个副本

```mysql
select	*
from	instructor	natural join	teacher

select	name,course_id
from	instructor, teacher
where	instructor.iD = teacher.ID
||
select	name,course_id
from instructor natural join	teacher
```



自然连接中的危险：有些属性可能具有相同的名称，但是他们的实际意义是不同的，在这种情况下，他们可能被错误的认为是相同属性

```mysql
# 例
# 错误的写法(使course.dept_name = instructor.dept_name)
select name, title
from instructor natural join teaches natural join course;

# 正确的写法
select name, title
from instructor natural join teaches, coursewhere teaches.course_id = course.course_id;

# 另一个正确的写法
select name, title
from (instructor natural join teaches) join course using(course_id);

```





#### 更名运算

SQL允许使用as子句对关系和属性进行更名

```mysql
old_name as new_name
```

* **在Oracle中，关键词`as`必须被省略**

```mysql
#例
select	ID,name,salary/12 as monthly_salary
from 	instructor

# 找出满足工资至少比Computer Science系某一个教师的工资要高的教师姓名
select	distinct	T.name
from instructor	as T,instructor	as S
where	T.salary > S.salary	and	S.dept_name = 'Computer Science'
```



#### 字符串运算

SQL中通过字符串匹配运算来支持在字符串上的比较，使用`like`操作符来实现模式匹配，使用两个特殊字符（通配符）描述模式

* 百分号（`%`）：`%`字符匹配任何子串
* 下划线（`_`）：`_`字符匹配任何字符
* `Like`的单向性：
  * `'济南市山大路' like '济南市%' = true `
  * `'济南市%' like '济南市山大路' = false`



```mysql
# 例
# 找出名字中包含dar的教师名字
select	name
from	instructor
where	name like '%dar%'

# 匹配字符串“100 %”
str like '100 \%' escape '\'
```



##### Escape

`Escape`定义转义字符，以去掉特殊字符的特定含义，使其被作为普通字符对待，如用`escape '\'`，定义`\`作为转义字符，则可用`\%`去匹配`%`，用`\_`取匹配`_`

```mysql
'ab\%cd%' escape '\'	= 'ab%cd'
'ab\\cd%' escape '\'	= 'ab\cd'
```



**VALUE是大小写敏感的**

> * 模式匹配的例子：
>   * ‘Intro%’ 匹配任何以“Intro”打头的字符串
>   * ‘%Comp%’ 匹配任何包含“Comp” 子串的字符串
>   * ‘_ _ _’匹配只含三个字符的字符串
>   * ‘_ _ _ %’匹配至少含三个字符的字符串
>
> 
>
> * SQL 支持一系列的串运算，包括
>   * 串联 （使用“||”）
>   * 大小写转换
>   * 计算串长度, 抽取子串, 等等 
>
> 



#### 排列元组的显示次序



```mysql
# 例
# 按字母顺序排列出所有教师的名字
select	distinct	name
from	instructor
order by name

# 我们可以用desc指定降序,用asc指定升序,默认情况下是升序排列
order by name desc

# 可以在多个属性上进行排序
order by dept_name,name

```



只是显示次序排序，只能是sql的最后一个子句，只能出现目标列内的字段

当排序列含空值时，ASC排序列为空值的元组最后显示，DESC排序列为空值的元组最先显示



#### where子句谓词

```mysql
# 元组比较
select	name,course_id
from	instructor, teacher
where	(instructor.ID, dept_name) = (teacher.ID, 'Biology')

# 表示方法: (v1,v2,...,vn)
# 元组比较: 按照字典顺序进行比较
# 例如 (a1,a2)<=(b1,b2) === (a1<b1)or ((a1=b1) and (a2<=b2))

```



#### 重复

* 对于存在重复元组的关系，SQL 可以决定在结果中显示该元组的几个副本 

* 一些关系代数运算的**多重集**版本——给定多重集关系*r*1 和*r*2 ：
    1. σ<sub>θ</sub> (r1)：如果关系*r*1的元组*t*1有c1个副本，并且*t*1满足选择条件σ<sub>θ</sub>  ，则在 σ<sub>θ</sub> 里有*c*1个*t*1的副本
    2. Π<sub>A</sub> (r)：对于关系*r*1的每个元组*t*1的每个副本，在Π<sub>A</sub> (r1)里都有一个副本Π<sub>A</sub> (t1) ，Π<sub>A</sub> (t1)是r1中相应副本t1的投影
    3. r1  x r2：如果关系*r*1的元组*t*1有*c*1个副本，关系*r*2的元组*t*2有*c*2个副本，则关系*r*1 x *r*2的元组t1，t2有*c*1 x *c*2个副本



#### 集合运算

集合运算`union`，`intersect`和`except`，每个运算都自动去重

union：并集；intersect：交集；except：差集；

如果要保留重复，则要使用对应的多重集版本`union all`，`intersect all`，`except all`

> 如果一个元组在r中出现m次，在s中出现n次，那么：
>
> * `r union all s`：m+n次
> * `r intersect all s`：min(m,n)次
> * `r except all s`：max(0,m-n)次



```mysql
# 例
# 找出在2009年秋季开课，或者在2010年春季开课，或两个学期都开课的所有课程
(select course_id 
 from section 
 where sem = ‘Fall’ and year = 2009)
union(select course_id 
      from section 
      where sem = ‘Spring’ and year = 2010)


# 找出在2009年秋季和2010年春季都开课的所有课程
(select course_id 
 from section 
 where sem = ‘Fall’ and year = 2009)
intersect(select course_id 
          from section 
          where sem = ‘Spring’ and year = 2010)


# 找出在2009年秋季学期开课但不在2010年春季学期开课的所有课程
(select course_id 
 from section 
 where sem = ‘Fall’ and year = 2009)
except/minus(select course_id 
             from section 
             where sem = ‘Spring’ and year = 2010)



```



#### 空值

元组的一些属性可以为空值，用`null`表示

null代表一个不知道或不存在的值

包含null的任何算术表达式的计算结果是null，比如`5+null = null`

谓词：`is null`可以用来检测空值，但是不能写 `var = null

带有`null`的任何比较运算返回 `unknown`，比如`5<null := unknown`，`null<>null := unknown`，`null = null  := unknown`

三值逻辑使用真值`unknown`

* or：`(unknown or true) = true`，`(unknown or false) = unknown`，`(unknown or unknown) = unknown`
* and：`(unknown and true) = unknown`，`(unknown and false) = falses`，`(unknown or unknown) = unknown`
* not：`not unknown = unknown` 
* 若谓词P的值为unknown，则`P is unknown = true`

where子句中谓词对一个元组计算出的值如果为`unknown`，则结果当false处理





#### 聚集函数

聚集函数以一个值的集合（集或多重集）为输入，返回单个值

> * avg：平均值
> * min：最小值
> * max：最大值
> * sum：总和
> * count：计数
>
> 



聚集函数的性质同关系代数：①聚集函数作用域集合（多重集）返回单值；②聚集函数作用默认作用于多重集；③强制作用于集合，使用distinct。

（无分组）仅用聚集函数的SQL：SQL返回关系，返回的关系有且只有一行；Select子句中出现聚集函数，不能同时出现非聚集的属性

```mysql
# 例
# 找出Computer Science系教师的平均工资
select avg(salary)
from instructor
where dept_name = 'Computer Science'

# 找出在2012年春季学期讲授的课程的教师总数
select count(distinct ID)
from teacher
where semester = 'Spring' and year = 2010

# 找出course关系中的元组数
select count(*)
from course
```



##### `group by`子句

在关系子集上运用聚集函数，得到一个新的关系

`group by`子句的作用对象是查询的中间结果表

分组方法：按指定一列或多列值分组，值相等为一组

使用`Group by `子句后，`Select`子句的列名列表中只能出现分组属性和聚集函数，不能出现非聚集的非分组属性

分组聚集计算时，SQL返回关系，每组对应一行，无组时返回空关系

`having`是对分组聚集结果进行选择，不满足条件的舍弃



```mysql
# 例
# 计算每个系的教师的平均工资,dept——name为系名
select dept_name, avg(salary)
from instructor
group by dept_name;
```

















### 附加的基本运算

### 集合运算

### 空值

### 聚集函数

### 嵌套子查询

### 数据库的修改







































































