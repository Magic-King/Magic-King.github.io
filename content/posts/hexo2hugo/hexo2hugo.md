---
title: "Hexo2hugo"
date: 2021-02-17T12:09:34+08:00
draft: false
tags: []
categories: []
description:
---





男人都是见色忘义的大猪蹄子，一看见好看的人就没了。

原本心想着hexo博客就这样将就用着吧，之前听同学说hugo挺好的也没在意，没想到遇见了更好看的hugo主题[MemE](https://github.com/reuixiy/hugo-theme-meme) ，这简洁的博客加上这渐变色，直接让我想用hugo了。

而且这次换电脑让我重新生成博客也遇到了许多bug，只能将hexo维护在旧版本也不太方便，于是说做就做，来一次大迁移。



> Refer:
>
> https://jdhao.github.io/2018/10/10/hexo_to_hugo/



## 迁移



我这为了方便就先用`scoop search hugo`，发现`scoop`的仓库里有hugo，那么就不用像hexo那样用npm去安装了，十分方便。

直接`scoop install hugo-extended` 完事。



### 建立博客



hugo建立新的站点：`hugo new site "folder_name"`

```powershell
PS D:\0project> hugo new site "hugo"
Congratulations! Your new Hugo site is created in D:\0project\hugo.

Just a few more steps and you're ready to go:

1. Download a theme into the same-named folder.
   Choose a theme from https://themes.gohugo.io/ or
   create your own with the "hugo new theme <THEMENAME>" command.
2. Perhaps you want to add some content. You can add single files
   with "hugo new <SECTIONNAME>\<FILENAME>.<FORMAT>".
3. Start the built-in live server via "hugo server".

Visit https://gohugo.io/ for quickstart guide and full documentation.
PS D:\0project> cd hugo
PS D:\0project\hugo> ls

    目录: D:\0project\hugo


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----          2021/2/9     14:56                archetypes
d-----          2021/2/9     14:56                content
d-----          2021/2/9     14:56                data
d-----          2021/2/9     14:56                layouts
d-----          2021/2/9     14:56                static
d-----          2021/2/9     14:56                themes
-a----          2021/2/9     14:56             82 config.toml
```

上面文件中，hugo与hexo的对应关系如下

|  hugo目录   |     hexo目录     | 作用                                                         |
| :---------: | :--------------: | :----------------------------------------------------------- |
|   content   |      source      | 存储博文的md文件，hexo中的_post,_draft,各自定义的页面目录其实对应到hugo中的话，都是在content下的 |
| config.toml | **_config.yaml** | 用于配置站点中各项参数                                       |
|   themes    |      themes      | 存放主题                                                     |
|   static    |      source      | hugo中的static目录中存放一些常规静态文件，可以是博客中引用的图片、文件也可以是自添加的任意文件，最终渲染都会放到站点的根目录 |
|   public    |      public      | 存放渲染后的站点静态文件                                     |
|   layout    |        无        | 存放自定义的样式布局文件，优先级高于主题中的同名文件，方便修改主题样式 |



#### 安装主题

安装主题的流程跟hexo没啥区别，甚至觉得比hexo要更简单，具体其他主题可以去官网主题库找。

> 官网主题库：[Hugo Themes](https://themes.gohugo.io/)

我这里安装的主题是[MemE](https://github.com/reuixiy/hugo-theme-meme)，直接如下

```powershell
PS D:\0project\hugo> git init
PS D:\0project\hugo> git submodule add --depth 1 https://github.com/reuixiy/hugo-theme-meme.git themes/meme
PS D:\0project\hugo> rm config.toml && cp themes/meme/config-examples/zh-cn/config.toml config.toml
```

然后复制配置文件，在里面修改相关选项



将hexo中的`./hexo/source/_post` 移动至 `./hugo/content/posts`

注意博客迁移时，要对文件头做一定的修改

* 
* 加入`typora-root-url: ..\..\static\res` ，因为他不像hexo支持posts下同名文件夹的资源引用，要将所有文件放入static才能用，因此需要添加一行，让typora能够正确显示图片





将所有文件移进同名文件夹中

```python
import os
import sys
import shutil

# move files to the folder which have the same name.


if __name__=='__main__':
	try:
		path = sys.argv[1]
	except  Exception:
		print("Usage: python op.py /to/your/path")
		exit(0)
	fileList = os.listdir(path)
	folders = []
	files = []
	for item in fileList:
		item = os.path.join(path, item)
		if os.path.isdir(item):
			folders.append(item)
		elif os.path.isfile(item):
			files.append(os.path.basename(item))

	# print(folders)
	# assert(0)

	# move to folder
	for item in files:
		folderName = item.split('.')[0]
		folderPath = os.path.join(path, folderName)
		# print(folderPath in folders)
		# assert(0)
		if folderPath not in folders:
			os.mkdir(folderPath)
		shutil.copyfile(os.path.join(path, item), os.path.join(folderPath, item))

	print("End.......")

```



然后，将当前仓库添加为远程分支

```sh
$ git add .
$ git commit -m "new blog"
$ git branch hugo
$ git checkout hugo
$ 
$ git remote add origin git@github.com:username/username.github.io.git
$ git push -u origin hugo
```

然后在github界面，将`Settings->Options->GitHub Pages` 改成Github action所生成的分支（gh-pages）

> Refer: https://github.com/reuixiy/io-oi.me/issues/90
>
> https://io-oi.me/tech/custom-domains-on-github-pages/

记得在`~/blog/static/CNAME`（Hugo），添加chame，chame里为自定义域名

然后就成功部署了



------



* #### rss Error

  > http://blog.jiayuanzhang.com/post/add-full-content-rss/

> ### This page contains the following errors:
>
> error on line 6111 at column 9: PCDATA invalid Char value 19
>
> ### Below is a rendering of the page up to the first error.

原因是博客中的markdown 有不可见字符如（^E，^H等等），导致生成rss错误

我也不知道为啥hexo就能正常生成，将不可见字符删除后，rss生成成功

