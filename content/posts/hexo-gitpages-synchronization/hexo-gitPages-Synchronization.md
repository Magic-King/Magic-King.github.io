---
title: hexo+gitPages Synchronization
date: 2019-05-16T15:30:39+08:00
tags: [hexo]
categories: [tech]
---



# Hexo+gitPages 的博客多端同步管理及迁移



> 本文参考
>
> [如何解决github+Hexo的博客多终端同步问题](<https://blog.csdn.net/Monkey_LZL/article/details/60870891>)
>
> [利用Hexo在多台电脑上提交和更新github pages博客](<https://www.jianshu.com/p/0b1fccce74e0>)
>
> [搭建hexo博客并简单的实现多终端同步](<https://righere.github.io/2016/10/10/install-hexo/>)
>
> [hexo博客同步管理及迁移](<https://www.jianshu.com/p/fceaf373d797>)





主体的思路是将博文内容相关文件放在Github项目中master中，将Hexo配置写博客用的相关文件(包括博客内容主题等等)放在Github项目的hexo分支上，这个是关键，多终端的同步只需要对分支hexo进行操作。

### 同步的首次操作

在创建了博客的目录下操作，push本地文件夹Hexo中的必要文件到yourname.github.io的hexo分支上。

只托管部分用于多终端的同步的文件

**注意**：使用第三方主题时，要删除第三方主题的.git文件夹删除，不然无法push到远程仓库



```shell
git init  //初始化本地仓库
git add source //将必要的文件依次添加，有些文件夹如npm install产生的node_modules由于路径过长不好处理，所以这里没有用`git add .`命令了，而是依次添加必要文件，如下图所示,其实也可以用'git add .'命令，在.gitignore文件中加入不需要同步的文件即可
git commit -m "Blog Source Hexo"
git branch hexo  //新建hexo分支
git checkout hexo  //切换到hexo分支上
git remote add origin git@github.com:yourname/yourname.github.io.git  //将本地与Github项目对接
git push origin hexo  //push到Github项目的hexo分支上
```



多出来的hexo的分支，用于文件同步，原有的master分支用于部署静态博客页面





### 在新终端进行更新博客



先从github中把文件clone到本地，然后安装相应组件。然后通过git的提交同步内容，用hexo的命令部署博客到gitPages里。

```shell
git clone -b hexo git@github.com:yourname/yourname.github.io.git  //将Github中hexo分支clone到本地
cd  yourname.github.io  //切换到刚刚clone的文件夹内
npm install    //注意，这里一定要切换到刚刚clone的文件夹内执行，安装必要的所需组件，不用再init
hexo new post "new blog name"   //新建一个.md文件，并编辑完成自己的博客内容
git add source  //经测试每次只要更新sorcerer中的文件到Github中即可，因为只是新建了一篇新博客，如果更改了主题样式的话还是建议用'git add .'
git commit -m "XX"
git push origin hexo  //更新分支
hexo d -g   //push更新完分支之后将自己写的博客对接到自己搭的博客网站上，同时同步了Github中的master

```



### 已有博客的终端更新博客



进入相应的文件夹，更新博客直行命令即可。



```sh
git pull origin hexo//先pull完成本地和远端的融合
hexo new post "new blog"
git add .
git commit -m "Blog update"
git push origin hexo
hexo d -g
```





