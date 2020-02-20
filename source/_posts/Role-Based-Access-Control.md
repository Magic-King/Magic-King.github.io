---
title: Role-Based-Access-Control
date: 2020-02-19 09:59:25
tags: [linux, security]
categories: linux
description:
password:
---







# <center>Role Based Access Control</center>





> 参考：
>
> [Spring Security 实战干货： RBAC权限控制概念的理解](https://zhuanlan.zhihu.com/p/91898362)
>
> [Role-Based-Access-Control__sandhu96.pdf](https://csrc.nist.gov/CSRC/media/Projects/Role-Based-Access-Control/documents/sandhu96.pdf)
>
> [什么是 Azure 资源的基于角色的访问控制 (RBAC)?](https://docs.microsoft.com/zh-cn/azure/role-based-access-control/overview)
>
> [Role Based Access Control](https://csrc.nist.gov/projects/role-based-access-control)
>
> 



------





### RBAC的简介



* RBAC：Role Based Access Control：基于角色的访问控制



RBAC的概念起源于早期的多用户计算机系统，他的兴起是因为人们需要通用的可定制工具

RBAC支持三个著名的安全性原则：最少特权、权限分离、数据抽象



简单来说，就是将用户对应一个身份，而一个身份拥有相应的权限，如下图所示

![](Role-Based-Access-Control/1.jpg)



就如同公司的项目经理，人事经理，上到CEO，CTO等等，每个职位有着相应的权限，而且在每个公司的CTO可以拥有不同的权限，同时CTO也可以由不同人来担任。把这个关系映射到计算机系统来，就是基于角色的访问控制。

相较于直接将权限分配给用户，这种RBAC的机制有着较强的扩展性，也便于权限管理：在权限更改时，无需遍历所有用户，增加了提权的效率，以及降低了漏调权限的概率，这样用户和资源权限解除了耦合性，这就是 **RBAC** 模型的优势所在。







### RBAC的分类



**RBAC模型**可以分为：**RBAC0**，**RBAC1**，**RBAC2**，**RBAC3** 四种。其中**RBAC0为基础**，其他都是因RBAC为基础的变种。















### 概念理解





#### 角色（Role）

角色是一个组织中的一个职务职能或职称

角色的概念与在访问控制中的用户组的概念相近，但是一个角色是把一组用户和一些权限关联在一起，而用户组却只能代表一组的用户

多角色分配：假如有一个用户被分配到了多种角色，那么会怎么样呢？RBAC是一个加法模型，因此，该用户会拥有其所分配到的所有角色所具有的权限。





#### 权限（Permission）

权限具有原子性，不可再分

在RBAC框架里，拒绝访问被建模为一个约束，而不是一个否定的权限。



