---
title: Object-oriented Programming
date: 2019-10-21T20:22:11+08:00
tags: []
categories: []
description:
password:
---













虽然一直再写面向对象编程的语言，但是压根没有对象可以面对，希望写完这篇能有对象可以让我面对！！！





## 简介

 面向对象编程(Object-oriented Programming,缩写：OOP)是软件工程中一种具有对象概念的编程范式(Programming Paradigm)，同时也是一种程序开发的抽象方针，与之对应的编程范式还有：函数式编程(Functional Programming)、过程式编程(Procedural Programming)、响应式编程(Reactive Programming)等。  

面向对象的程序设计（OOP）是面向过程程序设计的继承和发展，它不仅汲取了后者的精华，而且以一种更加接近人类思维的方式来分析和解决问题：程序是对现实世界的抽象和描述，现实世界的基本单元是物体，与之对应的，**程序中的基本单元是对象**。 

  面向对象思想认为：现实世界是由对象组成的，无论大到一个国家还是小到一个原子，都是如此。并且**对象都由两部分组成： 描述对象状态或属性的数据（变量）以及描述对象行为或者功能的方法（函数）**。并且与面向过程不同，**面向对象是将数据和操作数据的函数紧密结合**，共同构成对象来更加精确地描述现实世界，这是**面向过程和面向对象两者最本质的区别。** 



##### 对象与类

在面向对象编程中，最常见的表现就是基于类(Class)来表现的，每一个对象实例都有具体的类，即对象的类型。使用类的面向对象编程也称为基于类的编程(Class-based programming)，如常见的Java，C++；而与之类似的有基于原型的编程(Prototype-based programming)，如JavaScript。

- 类：定义对象的数据格式(属性类型)和可用过程(方法)，同时也可能包含类成员的数据(如，常量)和过程(如，静态方法)，类其实就是对象的类型/原型(prototype)。
- 对象：类的实例，通过类实例化出来的具体实例。



### 面向对象的三大特征

 面向对象的三大特征分别是：封装、继承、多态 。

- 封装(Encapsulation)

通过对象隐藏程序的具体实现细节，将数据与操作包装在一起，对象与对象之间通过消息传递机制实现互相通信（方法调用），具体的表现就是通过提供访问接口实现消息的传入传出。

封装常常会通过控制访问权限来控制对象之间的互访权限，常见的访问权限：公有(`public`)，私有(`private`)，保护(`protected`)。某些语言可能还会提供更加具体的访问控制，如，Java的package。

封装的意义：由于封装隐藏了具体的实现，如果实现的改变或升级对于使用方而言是无感知的，提高程序的可维护性；而且封装鼓励程序员把特定数据与对数据操作的功能打包在一起，有利于应用程序的去耦。

- 继承(Inheritance)

支持类的语言基本都支持继承，继承即类之间可以继承，通过继承得到的类称为子类，被继承的类为父类，子类相对于父类更加具体化。

子类具有自己特有的属性和方法，并且子类使用父类的方法也可以覆盖(重写)父类方法，在某些语言中还支持多继承，但是也带来了覆盖的复杂性。

继承的意义：继承是代码复用的基础机制

- 多态(Polymorphism)

多态发生在运行期间，即子类型多态，指的是子类型是一种多态的形式，不同类型的对象实体有统一接口，相同的消息给予不同的对象会引发不同的动作。

多态的意义：提供了编程的灵活性，简化了类层次结构外部的代码，使编程更加注重关注点分离(Separation of concerns，SoC)





关于面向对象编程的设计模式，可以参考[谈谈面向对象编程]( https://www.jianshu.com/p/3a81c69134c2 )





## Python3面向对象编程



> 参考：
>
>  [一文看懂Python面向对象编程核心思想(Python学习与Django入门必看)](https://blog.csdn.net/weixin_42134789/article/details/80194788) 
>
>  [Python3 面向对象](https://www.runoob.com/python3/python3-class.html )
>
>  [Python面向对象编程](https://www.jianshu.com/p/954e9cc89579 )



```python
#!/usr/bin/python3

class people:
    #默认为公有变量
	name = ""
    age = 0
    #定义私有变量，即在变量前加入 __
    __weight = 0
    num = 0
    
    #类专有方法，可重写
    def __init__(self,n,a,w):
        self.name = n
        self.age = a
        self.__weight = w
        self.num += 1
    #类方法一般第一个参数为self
    def speak(self):
        print('I am %s,and I am %d years old' % (self.name,self.age))
    
    @classmethod
    def tol(cls):
        print("total numble of people is {}".format(self.num))
    #这个为类方法，可直接使用people.tol()
        
#student 继承people类
class student(people):
    grade = ""
    def __init__(self,n,a,w,g):
        people.__init__(self,n,a,w)
        self.grade = g
	#方法重写
    def speak(self):
    	print("I am a %s student.\nMy name is %s" % (self.grade,self.name))
    #类的私有方法
    def __show_detail(self):
    	print(self.name+"\t"+self.age+"\t"+self.__weight+"\n"+self.grade)
    #封装
    def getWeight(self):
        return self.weight
    

    
    
#python有多重继承
class sample(people, student):
    tag = ""
    def __init__(self,n,a,w,g,t):
        people.__init__(self,n,a,w)
        student.__init__(self,g=g)
        tag = t
        
        
        
        
s1 = student("Alice",16,47,"7th grades")

```



python提供类的转有方法，可进行方法重写



```python
__init__ : 构造函数，在生成对象时调用
__del__ : 析构函数，释放对象时使用
__repr__ : 打印，转换
__setitem__ : 按照索引赋值
__getitem__: 按照索引获取值
__len__: 获得长度
__cmp__: 比较运算
__call__: 函数调用
__add__: 加运算
__sub__: 减运算
__mul__: 乘运算
__truediv__: 除运算
__mod__: 求余运算
__pow__: 乘方


反向运算符重载：   
__radd__: 加运算
__rsub__: 减运算
__rmul__: 乘运算
__rdiv__: 除运算
__rmod__: 求余运算
__rpow__: 乘方
    
   
复合重载运算符
__iadd__: 加运算
__isub__: 减运算
__imul__: 乘运算
__idiv__: 除运算
__imod__: 求余运算
__ipow__: 乘方

```





------

#### 注：\__new__()方法

python中定义的类在创建实例对象的时候，会自动执行init()方法，但是在执行init()方法之前，会执行new()方法。

*new*()的作用主要有两个。

1.在内存中为对象分配空间
2.返回对象的引用。（即对象的内存地址）

python解释器在获得引用的时候会将其传递给init()方法中的self。

```python
class A:
    def __new__(cls,*args,**kwargs):
        print('__new__')
        return super().__new__(cls)#这里一定要返回，否则__init__()方法不会被执行
    def __init__(self):#这里的self就是new方法中的return返回值
        print('__init__')

a = A()
```

输出结果

```undefined
__new__
__init__
```

我们一定要在*new*方法中最后调用

```python
return super().__new__(cls)
```

否则init方法不会被调用

```python
class A:
    def __new__(cls,*args,**kwargs):
        print('__new__')
        # return super().__new__(cls)#这里一定要返回，否则__init__()方法不会被执行
    def __init__(self):#这里的self就是new方法中的return返回值
        print('__init__')


a = A()
```

输出

```undefined
__new__
```

像以前一样，我们不写*new*方法试试

```python
class A:
    # def __new__(cls,*args,**kwargs):
    #     print('__new__')
        # return super().__new__(cls)#这里一定要返回，否则__init__()方法不会被执行
    def __init__(self):#这里的self就是new方法中的return返回值
        print('__init__')


a = A()
```

输出

```undefined
__init__
```



------

## 私有属性-封装

在实际开发中，对象 的 某些属性或方法 可能只希望 在对象的内部被使用，而 不希望在外部被访问到

**定义方式**

在 定义属性或方法时，在 属性名或者方法名前 增加 两个下划线__ 实际开发中私有属性也不是一层不变的。所以要给私有属性提供外部能够操作的方法。

7.1) **通过自定义get set方法提供私有属性的访问**

```ruby
class Person:
    def __init__(self, name, age):
        self.name = name
        self.__age = age

    #定义对私有属性的get方法，获取私有属性
    def getAge(self):
        return self.__age

    #定义对私有属性的重新赋值的set方法，重置私有属性
    def setAge(self,age):
        self.__age = age

person1 = Person("tom",19)
person1.setAge(20)
print(person1.name,person1.getAge())  #tom 20
```

7.2) **调用property方法提供私有属性的访问**

```ruby
class Student:
    def __init__(self, name, age):
        self.name = name
        self.__age = age

    #定义对私有属性的get方法，获取私有属性
    def getAge(self):
        return self.__age

    #定义对私有属性的重新赋值的set方法，重置私有属性
    def setAge(self,age):
        self.__age = age

    p = property(getAge,setAge) #注意里面getAge,setAge不能带()

s1 = Student("jack",22)
s1.p = 23 #如果使用=,则会判断为赋值，调用setAge方法。
print(s1.name,s1.p)  #jack 23   ，直接使用s1.p会自动判断会取值，调用getAge
print(s1.name,s1.getAge()) #jack 23,这个时候set,get方法可以单独使用。
```

7.3) **使用property标注提供私有属性的访问**

注意： 一旦给函数加上一个装饰器@property,调用函数的时候不用加括号就可以直接调用函数了 



```ruby
class Teacher:
    def __init__(self, name, age,speak):
        self.name = name
        self.__age = age
        self.__speak = speak


    @property      #注意1.@proterty下面默认跟的是get方法，如果设置成set会报错。
    def age(self):
        return self.__age

    @age.setter    #注意2.这里是使用的上面函数名.setter，不是property.setter.
    def age(self,age):
        if age > 150 and age <=0:  #还可以在setter方法里增加判断条件
            print("年龄输入有误")
        else:
            self.__age = age

    @property
    def for_speak(self):  #注意2.这个同名函数名可以自定义名称，一般都是默认使用属性名。
        return self.__speak

    @for_speak.setter
    def for_speak(self, speak):
        self.__speak = speak

t1 = Teacher("herry",45,"Chinese")
t1.age = 38    #注意4.有了property后，直接使用t1.age,而不是t1.age()方法了。
t1.for_speak = "English"  

print(t1.name,t1.age,t1.for_speak)  #herry 38 English
```

------











## C++面向对象编程





> 引用：
>
> [c++面向对象程序设计总结(类的使用)](https://www.cnblogs.com/wpbing/p/9774818.html)
>
> [C++ 类 & 对象]( https://www.runoob.com/cplusplus/cpp-classes-objects.html )
>
> [C++面向对象基础]( https://blog.csdn.net/u012940886/article/details/80381398 )
>
> 







#### 析构函数

析构函是类的一个成员函数，名字由波浪号接类名构成。它没有返回值，也不接受参数：

```c++
class Foo{ 
public:
      ~Foo();   //析构函数
      //...
  };
```

由于析构函数不接受参数，因此它不能被重载。对于一个给定类，只会由唯一一个析构函数。

在一个构造函数中，成员的初始化时在函数体执行之前完成的，且按照它们在类中出现的顺序进行初始化。在一个析构函数中，首先执行函数体，然后销毁成员。成员按初始化顺序的逆序进行销毁。

无论何时一个对象被销毁，就会自动调用其析构函数：

> ​	1.变量在离开其作用域时被销毁
> ​	2.当一个对象被销毁时，其成员被销毁
> ​	3.容器(无论是标准容器还是数组)被销毁时，其元素被销毁
> ​	4.对于动态分配的对象，当对指向它的指针应用delete运算符时被销毁
> ​	5.对于临时对象，当创建它的完整表达式结束时被销毁











> > >未完待续















