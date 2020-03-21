---
title: hexo+gitpages
date: 2019-05-14 16:41:30
tags: hexo
categories: hexo
---



# hexo+gitPages搭建个人博客



> 本文参考
>
> **hexo 博客搭建**
>
> [hexo官方文档](<https://hexo.io/zh-cn/docs/>)
>
> [【持续更新】最全Hexo博客搭建+主题优化+插件配置+常用操作+错误分析](<https://juejin.im/post/5bebfe51e51d45332a456de0>)
>
> [手把手教你搭建自己的个人博客（图文教程）](<https://blog.csdn.net/gsl9d1p04f6x2ts3c9/article/details/81024330>)
>
> [搭建篇 --使用Github+hexo搭建个人博客教程—总结自己爬过的坑]([https://www.chakid.com/2017/07/05/%E4%B8%80%E3%80%81%E6%90%AD%E5%BB%BA%E7%AF%87-%E4%BD%BF%E7%94%A8Github-hexo%E6%90%AD%E5%BB%BA%E4%B8%AA%E4%BA%BA%E5%8D%9A%E5%AE%A2%E6%95%99%E7%A8%8B%E2%80%94%E6%80%BB%E7%BB%93%E8%87%AA%E5%B7%B1%E7%88%AC%E8%BF%87%E7%9A%84%E5%9D%91/](https://www.chakid.com/2017/07/05/一、搭建篇-使用Github-hexo搭建个人博客教程—总结自己爬过的坑/))
>
> [GitHub+Hexo 搭建个人网站详细教程](<https://zhuanlan.zhihu.com/p/26625249?utm_source=weibo&utm_medium=social>)
>
> [史上最详细的Hexo博客搭建图文教程](<https://xuanwo.io/2015/03/26/hexo-intor/>)
>
> 
>
> **hexo优化**
>
> [hexo博客改装和一些细节优化](https://www.chakid.com/2018/05/26/hexo%E5%8D%9A%E5%AE%A2%E6%94%B9%E8%A3%85%E5%92%8C%E4%B8%80%E4%BA%9B%E7%BB%86%E8%8A%82%E4%BC%98%E5%8C%96/)
>
> https://www.chakid.com/2018/05/26/hexo博客改装和一些细节优化
>
> [Hexo NexT 博客后台管理指南](<https://www.cnblogs.com/xingyunblog/p/8681205.html>)
>
> [Hexo主题更改以及小功能的添加](<https://blog.csdn.net/qq_36177977/article/details/83826453>)
>
> 
>
> **hexo-NexT主题配置**
>
> [NexT官方展示](<https://theme-next.org/archives/>)
>
> [NexT官方中文文档ReadME](<https://github.com/theme-next/hexo-theme-next/blob/master/docs/zh-CN/README.md>)
>
> [NexT源码](<https://github.com/theme-next/hexo-theme-next>)
>
> [NexT文档](<http://theme-next.iissnan.com/getting-started.html>)
>
> [Hexo的Next主题详细配置](<https://www.jianshu.com/p/3a05351a37dc>)
>
> [hexo的next主题个性化教程:打造炫酷网站](https://www.cnblogs.com/php-linux/p/8416122.html)
>
> [hexo的next主题个性化教程：打造炫酷网站](<https://blog.csdn.net/qq_33699981/article/details/72716951>)
>
> [【持续更新】hexo next主题优化手册](https://inspurer.github.io/2018/11/11/hexo-next主题优化/)
>
> [可参考博客嘤](<https://inspurer.github.io/archives/>)
>
> https://guanqr.com/tech/website/hexo-theme-next-customization/
>
> https://biqianhan-zidi.github.io/
>
> 
>
> **yilia主题**
>
> [yilia主题源码（GitHub）](<https://github.com/litten/hexo-theme-yilia>)
>
> [yilia主题展示](<http://litten.me/>)
>
> 
>
> hexo+gitpage优化：
>
> https://blog.lgf.im/2020/03/speedup-github-page/#
>
> 







## hexo博客搭建



### 安装前提

安装 Hexo 相当简单。然而在安装前，您必须检查电脑中是否已安装下列应用程序：

- [Node.js](http://nodejs.org/) (Should be at least nodejs 6.9)
- [Git](http://git-scm.com/)

如果您的电脑中已经安装上述必备程序，那么恭喜您！接下来只需要使用 npm 即可完成 Hexo 的安装。

```
$ npm install -g hexo-cli
```

如果您的电脑中尚未安装所需要的程序，请根据以下安装指示完成安装。

如果您的电脑中尚未安装所需要的程序，请根据以下安装指示完成安装。

> Mac 用户
>
> 您在编译时可能会遇到问题，请先到 App Store 安装 Xcode，Xcode 完成后，启动并进入 **Preferences -> Download -> Command Line Tools -> Install** 安装命令行工具。

### 安装 Git

- Windows：下载并安装 [git](https://git-scm.com/download/win).
- Mac：使用 [Homebrew](http://mxcl.github.com/homebrew/), [MacPorts](http://www.macports.org/) ：`brew install git`;或下载 [安装程序](http://sourceforge.net/projects/git-osx-installer/) 安装。
- Linux (Ubuntu, Debian)：`sudo apt-get install git-core`
- 

- Linux (Fedora, Red Hat, CentOS)：`sudo yum install git-core`

> Windows 用户
>
> 由于众所周知的原因，从上面的链接下载git for windows最好挂上一个代理，否则下载速度十分缓慢。也可以参考[这个页面](https://github.com/waylau/git-for-win)，收录了存储于百度云的下载地址。

### 安装 Node.js

安装 Node.js 的最佳方式是使用 [nvm](https://github.com/creationix/nvm)。

cURL:

```
$ curl https://raw.github.com/creationix/nvm/v0.33.11/install.sh | sh
```

Wget:

```
$ wget -qO- https://raw.github.com/creationix/nvm/v0.33.11/install.sh | sh
```

安装完成后，重启终端并执行下列命令即可安装 Node.js。

```
$ nvm install stable
```

或者您也可以下载 [安装程序](http://nodejs.org/) 来安装。

> Windows 用户
>
> 对于windows用户来说，建议使用安装程序进行安装。安装时，请勾选**Add to PATH**选项。
> 另外，您也可以使用**Git Bash**，这是git for windows自带的一组程序，提供了Linux风格的shell，在该环境下，您可以直接用上面提到的命令来安装Node.js。打开它的方法很简单，在任意位置单击右键，选择“Git Bash Here”即可。由于Hexo的很多操作都涉及到命令行，您可以考虑始终使用**Git Bash**来进行操作。



### 安装 Hexo

所有必备的应用程序安装完成后，即可使用 npm 安装 Hexo。

```
$ npm install -g hexo-cli
```

在安装的时候我用的是`npm install hexo --save`





## 关于npm命令

### 回顾 npm install 命令

最近在写Node程序的时候，突然对 npm install 的-save和-save-dev 这两个参数的使用比较混乱。其实博主在这之前对这两个参数的理解也是模糊的，各种查资料和实践后对它们之间的异同点略有理解。遂写下这篇文章避免自己忘记，同时也给node猿友一点指引。

我们在使用 npm install 安装模块的模块的时候 ，一般会使用下面这几种命令形式：

```shell
npm install moduleName # 安装模块到项目目录下`
npm install -g moduleName # -g 的意思是将模块安装到全局，具体安装到磁盘哪个位置，要看 npm config prefix 的位置。
npm install -save moduleName # -save 的意思是将模块安装到项目目录下，并在package文件的dependencies节点写入依赖。
npm install -save-dev moduleName # -save-dev 的意思是将模块安装到项目目录下，并在package文件的devDependencies节点写入依赖。
```

那么问题来了，在项目中我们应该使用四个命令中的哪个呢？这个就要视情况而定了。下面对这四个命令进行对比，看完后你就不再这么问了。

### npm install moduleName 命令

1. 安装模块到项目node_modules目录下。
2. 不会将模块依赖写入devDependencies或dependencies 节点。
3. 运行 npm install 初始化项目时不会下载模块。

### npm install -g moduleName 命令

1. 安装模块到全局，不会在项目node_modules目录中保存模块包。
2. 不会将模块依赖写入devDependencies或dependencies 节点。
3. 运行 npm install 初始化项目时不会下载模块。

### npm install -save moduleName 命令

1. 安装模块到项目node_modules目录下。
2. 会将模块依赖写入dependencies 节点。
3. 运行 npm install 初始化项目时，会将模块下载到项目目录下。
4. 运行npm install --production或者注明NODE_ENV变量值为production时，**会**自动下载模块到node_modules目录中。

### npm install -save-dev moduleName 命令

1. 安装模块到项目node_modules目录下。
2. 会将模块依赖写入devDependencies 节点。
3. 运行 npm install 初始化项目时，会将模块下载到项目目录下。
4. 运行npm install --production或者注明NODE_ENV变量值为production时，**不会**自动下载模块到node_modules目录中。





## 建站

安装 Hexo 完成后，请执行下列命令，Hexo 将会在指定文件夹中新建所需要的文件。

&lt;folder&gt; 为hexo安装目录

```
$ hexo init <folder>
$ cd <folder>
$ npm install
```

新建完成后，指定文件夹的目录如下：

```
.
├── _config.yml
├── package.json
├── scaffolds
├── source
|   ├── _drafts
|   └── _posts
└── themes
```

### _config.yml

网站的 [配置](https://hexo.io/zh-cn/docs/configuration) 信息，您可以在此配置大部分的参数。

### package.json

应用程序的信息。[EJS](https://ejs.co/), [Stylus](http://learnboost.github.io/stylus/) 和 [Markdown](http://daringfireball.net/projects/markdown/) renderer 已默认安装，您可以自由移除。

```
package.json{
  "name": "hexo-site",
  "version": "0.0.0",
  "private": true,
  "hexo": {
    "version": ""
  },
  "dependencies": {
    "hexo": "^3.8.0",
    "hexo-generator-archive": "^0.1.5",
    "hexo-generator-category": "^0.1.3",
    "hexo-generator-index": "^0.2.1",
    "hexo-generator-tag": "^0.2.0",
    "hexo-renderer-ejs": "^0.3.1",
    "hexo-renderer-stylus": "^0.3.3",
    "hexo-renderer-marked": "^0.3.2",
    "hexo-server": "^0.3.3"
  }
}
```

### scaffolds

[模版](https://hexo.io/zh-cn/docs/writing) 文件夹。当您新建文章时，Hexo 会根据 scaffold 来建立文件。

Hexo的模板是指在新建的markdown文件中默认填充的内容。例如，如果您修改scaffold/post.md中的Front-matter内容，那么每次新建一篇文章时都会包含这个修改。

### source

资源文件夹是存放用户资源的地方。除 `_posts` 文件夹之外，开头命名为 `_` (下划线)的文件 / 文件夹和隐藏的文件将会被忽略。Markdown 和 HTML 文件会被解析并放到 `public` 文件夹，而其他文件会被拷贝过去。

### themes

[主题](https://hexo.io/zh-cn/docs/themes) 文件夹。Hexo 会根据主题来生成静态页面。





## 配置

您可以在 `_config.yml` 中修改大部分的配置。

<iframe src="https://www.youtube.com/embed/A0Enyn70jKU" frameborder="0" allowfullscreen="" style="box-sizing: inherit; margin: 1em 0px; padding: 0px; border: 0px; outline: 0px; font-weight: inherit; font-style: inherit; font-family: inherit; font-size: 15px; vertical-align: baseline;"></iframe>
### 网站

| 参数          | 描述                                                         |
| :------------ | :----------------------------------------------------------- |
| `title`       | 网站标题                                                     |
| `subtitle`    | 网站副标题                                                   |
| `description` | 网站描述                                                     |
| `author`      | 您的名字                                                     |
| `language`    | 网站使用的语言                                               |
| `timezone`    | 网站时区。Hexo 默认使用您电脑的时区。[时区列表](https://en.wikipedia.org/wiki/List_of_tz_database_time_zones)。比如说：`America/New_York`, `Japan`, 和 `UTC` 。 |

其中，`description`主要用于SEO，告诉搜索引擎一个关于您站点的简单描述，通常建议在其中包含您网站的关键词。`author`参数用于主题显示文章的作者。

### 网址

| 参数                 | 描述                                                         | 默认值                      |
| :------------------- | :----------------------------------------------------------- | :-------------------------- |
| `url`                | 网址                                                         |                             |
| `root`               | 网站根目录                                                   |                             |
| `permalink`          | 文章的 [永久链接](https://hexo.io/zh-cn/docs/permalinks) 格式 | `:year/:month/:day/:title/` |
| `permalink_defaults` | 永久链接中各部分的默认值                                     |                             |

> 网站存放在子目录
>
> 如果您的网站存放在子目录中，例如 `http://yoursite.com/blog`，则请将您的 `url`设为 `http://yoursite.com/blog` 并把 `root` 设为 `/blog/`。

### 目录

| 参数           | 描述                                                         | 默认值           |
| :------------- | :----------------------------------------------------------- | :--------------- |
| `source_dir`   | 资源文件夹，这个文件夹用来存放内容。                         | `source`         |
| `public_dir`   | 公共文件夹，这个文件夹用于存放生成的站点文件。               | `public`         |
| `tag_dir`      | 标签文件夹                                                   | `tags`           |
| `archive_dir`  | 归档文件夹                                                   | `archives`       |
| `category_dir` | 分类文件夹                                                   | `categories`     |
| `code_dir`     | Include code 文件夹                                          | `downloads/code` |
| `i18n_dir`     | 国际化（i18n）文件夹                                         | `:lang`          |
| `skip_render`  | 跳过指定文件的渲染，您可使用 [glob 表达式](https://github.com/isaacs/node-glob)来匹配路径。 |                  |

> 提示
>
> 如果您刚刚开始接触Hexo，通常没有必要修改这一部分的值。

### 文章

| 参数                | 描述                                                         | 默认值    |
| :------------------ | :----------------------------------------------------------- | :-------- |
| `new_post_name`     | 新文章的文件名称                                             | :title.md |
| `default_layout`    | 预设布局                                                     | post      |
| `auto_spacing`      | 在中文和英文之间加入空格                                     | false     |
| `titlecase`         | 把标题转换为 title case                                      | false     |
| `external_link`     | 在新标签中打开链接                                           | true      |
| `filename_case`     | 把文件名称转换为 (1) 小写或 (2) 大写                         | 0         |
| `render_drafts`     | 显示草稿                                                     | false     |
| `post_asset_folder` | 启动 [Asset 文件夹](https://hexo.io/zh-cn/docs/asset-folders) | false     |
| `relative_link`     | 把链接改为与根目录的相对位址                                 | false     |
| `future`            | 显示未来的文章                                               | true      |
| `highlight`         | 代码块的设置                                                 |           |

> 相对地址
>
> 默认情况下，Hexo生成的超链接都是绝对地址。例如，如果您的网站域名为`example.com`,您有一篇文章名为`hello`，那么绝对链接可能像这样：`http://example.com/hello.html`，它是**绝对**于域名的。相对链接像这样：`/hello.html`，也就是说，无论用什么域名访问该站点，都没有关系，这在进行反向代理时可能用到。通常情况下，建议使用绝对地址。

### 分类 & 标签

| 参数               | 描述     | 默认值          |
| :----------------- | :------- | :-------------- |
| `default_category` | 默认分类 | `uncategorized` |
| `category_map`     | 分类别名 |                 |
| `tag_map`          | 标签别名 |                 |

### 日期 / 时间格式

Hexo 使用 [Moment.js](http://momentjs.com/) 来解析和显示时间。

| 参数          | 描述     | 默认值       |
| :------------ | :------- | :----------- |
| `date_format` | 日期格式 | `YYYY-MM-DD` |
| `time_format` | 时间格式 | `H:mm:ss`    |

### 分页

| 参数             | 描述                                | 默认值 |
| :--------------- | :---------------------------------- | :----- |
| `per_page`       | 每页显示的文章量 (0 = 关闭分页功能) | `10`   |
| `pagination_dir` | 分页目录                            | `page` |

### 扩展

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| `theme`  | 当前主题名称。值为`false`时禁用主题 |
| `deploy` | 部署部分的设置                      |





## 部署

当执行完`npm install`之后即可通过`hexo s`或者`hexo serve`通过本地访问hexo博客。

此时博客已搭建在本地了。



##### 方案一：GithubPages

1. 创建[Github](https://link.juejin.im?target=https%3A%2F%2Fgithub.com)账号

2. 创建仓库， 仓库名为：<Github账号名称>.github.io

3. 将本地Hexo博客推送到GithubPages

   3.1. 安装`hexo-deployer-git`插件。在命令行（即Git Bash）运行以下命令即可：

   ```
   $ npm install hexo-deployer-git --save
   
   ```

   3.2. 添加SSH key。

   - 创建一个 SSH key 。在命令行（即Git Bash）输入以下命令， 回车三下即可：

     ```
     $ ssh-keygen -t rsa -C "邮箱地址"
     
     ```

   - 添加到 github。 复制密钥文件内容（路径形如`C:\Users\Administrator\.ssh\id_rsa.pub`），粘贴到[New SSH Key](https://link.juejin.im?target=https%3A%2F%2Fgithub.com%2Fsettings%2Fkeys)即可。

   - 测试是否添加成功。在命令行（即Git Bash）依次输入以下命令，返回“You've successfully authenticated”即成功：

     ```
     $ ssh -T git@github.com
     $ yes
     ```

   3.3. 修改`_config.yml`（在站点目录下）。文件末尾修改为：

   ```
   # Deployment
   ## Docs: https://hexo.io/docs/deployment.html
   deploy:
     type: git
     repo: git@github.com:<Github账号名称>/<Github账号名称>.github.io.git
     branch: master
   
   ```

   注意：上面仓库地址写ssh地址，不写http地址。

   3.4. 推送到GithubPages。在命令行（即Git Bash）依次输入以下命令， 返回`INFO Deploy done: git`即成功推送：

   ```
   $ hexo g
   $ hexo d
   
   ```

4. 等待1分钟左右，浏览器访问网址： `https://<Github账号名称>.github.io`

至此，您的Hexo博客已经搭建在GithubPages, 域名为`https://<Github账号名称>.github.io`。

##### 方案二：GithubPages + 域名

在方案一的基础上，添加自定义域名（您购买的域名）。

1. 域名解析。

   类型选择为 CNAME；

   主机记录即域名前缀，填写为www；

   记录值填写为自定义域名；

   解析线路，TTL 默认即可。

2. 仓库设置。

   2.1. 打开博客仓库设置：`https://github.com/<Github账号名称>/<Github账号名称>.github.io/settings`

   2.2. 在Custom domain下，填写自定义域名，点击`save`。

   2.3. 在站点目录的`source`文件夹下，创建并打开`CNAME.txt`，写入你的域名（如`www.simon96.online`），保存，并重命名为`CNAME`。

3. 等待10分钟左右。

   浏览器访问自定义域名。

   至此，您的Hexo博客已经解析到自定义域名，`https://<Github账号名称>.github.io`依然可用。

   （可在github仓库中设置跳转至个人域名）

###### **绑定域名**

虽然在Internet上可以访问我们的网站，但是网址是GitHub提供的:[http://xxxx.github.io](https://link.zhihu.com/?target=http%3A//xxxx.github.io) (知乎排版可能会出现"http://"字样) 而我们想使用我们自己的个性化域名，这就需要绑定我们自己的域名。这里演示的是在阿里云万网的域名绑定，在国内主流的域名代理厂商也就阿里云和腾讯云。登录到阿里云，进入管理控制台的域名列表，找到你的个性化域名，进入解析



![img](https://pic3.zhimg.com/80/v2-47323ad4490e206aef93a3d68f0670b6_hd.jpg)

然后添加解析



![img](https://pic3.zhimg.com/80/v2-40222b3a295bb692aac22829a8ec3be2_hd.jpg)





包括添加三条解析记录，192.30.252.153是GitHub的地址，你也可以ping你的 [http://xxxx.github.io](https://link.zhihu.com/?target=http%3A//xxxx.github.io) 的ip地址，填入进去。第三个记录类型是CNAME，CNAME的记录值是：你的用户名.[http://github.io](https://link.zhihu.com/?target=http%3A//github.io) 这里千万别弄错了。第二步，登录GitHub，进入之前创建的仓库，点击settings，设置Custom domain，输入你的域名



![img](https://pic4.zhimg.com/80/v2-85ba6dda906f22dea4c03df2b47d994b_hd.jpg)

点击save保存。第三步，进入本地博客文件夹 ，进入blog/source目录下，创建一个记事本文件，输入你的域名，对，只要写进你自己的域名即可。如果带有www，那么以后访问的时候必须带有www完整的域名才可以访问，但如果不带有www，以后访问的时候带不带www都可以访问。所以建议，不要带有www。这里我还是写了www(不建议带有www):

![img](https://pic1.zhimg.com/80/v2-79abfff91af3f520e24cb91acf6aa994_hd.jpg)

保存，命名为CNAME ，注意保存成**所有文件**而不是**txt文件**。

完成这三步，进入blog目录中，按住shift键右击打开命令行，依次输入：

```bash
hexo clean
hexo g
hexo d
```

这时候打开浏览器在地址栏输入你的个性化域名将会直接进入你自己搭建的网站。



##### 方案三：GithubPages + CodingPages + 域名

GithubPages 在国内较慢，百度不收录，而CodingPages 在国外较快。所以在方案二的基础上，添加CodingPages 。

1. 创建[Coding](https://link.juejin.im?target=https%3A%2F%2Fcoding.net%2F)账号

2. 创建仓库， 仓库名为：<Coding账号名称>

3. 进入项目里『代码』页面，点击『一键开启静态 Pages』，稍等片刻CodingPages即可部署成功。

4. 将本地Hexo博客推送到CodingPages

   4.1. 鉴于创建GithubPages 时，已经生成过公钥。可直接复制密钥文件内容（路径形如`C:\Users\Administrator\.ssh\id_rsa.pub`）， 粘贴到[新增公钥](https://link.juejin.im?target=https%3A%2F%2Fdev.tencent.com%2Fuser%2Faccount%2Fsetting%2Fkeys)。

   4.2. 测试是否添加成功。在命令行（即Git Bash）依次输入以下命令，返回“You've successfully authenticated”即成功：

   ```
   $ ssh -T git@git.coding.net
   $ yes
   
   ```

   4.3. 修改`_config.yml`（在存放Hexo初始化文件的路径下）。文件末尾修改为：

   ```
   # Deployment
   ## Docs: https://hexo.io/docs/deployment.html
   deploy:
   - type: git
     repo: git@github.com:<Github账号名称>/<Github账号名称>.github.io.git
     branch: master
   - type: git
     repo: git@git.dev.tencent.com:<Coding账号名称>/<Coding账号名称>.git
     branch: master
   
   ```

   4.4. 推送到GithubPages。在命令行（即Git Bash）依次输入以下命令， 返回`INFO Deploy done: git`即成功推送：

   ```
   $ hexo g
   $ hexo d
   
   ```

5. 域名解析

   1. 添加 CNAME 记录指向 <Coding账号名称>.coding.me

      类型选择为 CNAME；

      主机记录即域名前缀，填写为www；

      记录值填写为自定义域名；

      解析线路，TTL 默认即可。

   2. 添加 两条A 记录指向 192.30.252.153和192.30.252.154

      类型选择为 A；

      主机记录即域名前缀，填写为@；

      记录值填写为192.30.252.153和192.30.252.154；

      解析线路，境外或谷歌。

   3. 在『Pages 服务』设置页（`https://dev.tencent.com/u/<Coding账号名称>/p/<Coding账号名称>/git/pages/settings`）中绑定自定义域名。

至此，您的Hexo博客已经解析到自定义域名，`https://<Github账号名称>.github.io`和`https://<Coding账号名称>.coding.me`依然可用。

##### 方案四：云服务器 + 域名

该方案需要先购买云服务器和域名。

1. 在云服务器安装Git 和 Nginx。(Git 用于版本管理和部署，Nginx 用于静态博客托管。)

   登陆root用户，运行：

   ```
   $ yum -y update
   $ yum install -y git nginx
   
   ```

2. Nginx配置

   2.1. 创建文件目录(用于博客站点文件存放)

   ```
   cd /usr/local/
   mkdir hexo
   chmod 775 -R /usr/local/hexo/
   
   ```

   2.2. 添加 index.html(用于检测配置 Nginx 是否成功)

   ```
   vim /usr/local/hexo/index.html
   
   ```

   添加以下代码，并保存。

   ```
   <!DOCTYPE html>
   <html>
     <head>
       <title></title>
       <meta charset="UTF-8">
     </head>
     <body>
       <p>Nginx running</p>
     </body>
   </html>
   
   ```

   2.3. 配置 Nginx 服务器

   ```
   vim /etc/nginx/nginx.conf
   
   ```

   修改server_name和root：

   ```
   server {
         listen       80 default_server;
         listen       [::]:80 default_server;
         server_name  www.baidu.com; # 填个人域名      
         root         /usr/local/hexo/;
     }      
   
   ```

   2.4. 启动nginx服务；

   ```
   service nginx start
   
   ```

   2.5. 云服务器浏览器访问个人域名或IP，若跳转index.html，则配置完成，否则检查以上配置。

3. git配置

   3.1. 创建文件目录, 用于私人 Git 仓库搭建, 并更改目录读写权限。

   ```
   cd /usr/local/
   mkdir hexoRepo
   chmod 775 -R /usr/local/hexoRepo/
   
   ```

   3.2. Git 初始化裸库。

   ```
   cd hexoRepo/
   git init --bare hexo.git
   
   ```

   3.3. 创建 Git 钩子(hook)。

   ```
   vim /usr/local/hexoRepo/hexo.git/hooks/post-receive
   
   ```

   3.4. 输入以下信息，用于指定 Git 的源代码 和 Git 配置文件。

   ```
   #!/bin/bash
   
   git --work-tree=/usr/local/hexo --git-dir=/usr/local/hexoRepo/hexo.git checkout -f
   
   ```

   3.5. 保存并退出后, 给该文件添加可执行权限。

   ```
   chmod +x /usr/local/hexoRepo/hexo.git/hooks/post-receive
   
   ```

4. 本地博客推送到云服务器

   4.1. 安装`hexo-deployer-git`插件。在命令行（即Git Bash）运行以下命令即可：

   ```
   $ npm install hexo-deployer-git --save
   
   ```

   4.2. 添加SSH key。

   - 创建一个 SSH key 。在命令行（即Git Bash）输入以下命令， 回车三下即可：

     ```
     $ ssh-keygen -t rsa -C "邮箱地址"
     
     ```

   - 添加到 github。 复制密钥文件内容（路径形如`C:\Users\Administrator\.ssh\id_rsa.pub`），粘贴到[New SSH Key](https://link.juejin.im?target=https%3A%2F%2Fgithub.com%2Fsettings%2Fkeys)即可。

   - 测试是否添加成功。在命令行（即Git Bash）依次输入以下命令，返回“You've successfully authenticated”即成功：

     ```
     $ ssh -T git@github.com
     $ yes
     
     ```

   4.3. 修改`_config.yml`（在站点目录下）。文件末尾修改为：

   ```
   # Deployment
   ## Docs: https://hexo.io/docs/deployment.html
   deploy:
     type: git
     repo: root@xxx.xxx.xxx.xxx:/usr/local/hexoRepo/hexo  //用户名@域名或 IP 地址:/usr/local/hexoRepo/hexo
     branch: master
   
   ```

   注意：上面仓库地址写ssh地址，不写http地址。

   4.4. 推送到GithubPages。在命令行（即Git Bash）依次输入以下命令， 返回`INFO Deploy done: git`即成功推送：

   ```
   $ hexo g
   $ hexo d
   
   ```

5. 等待1分钟左右，浏览器访问个人域名。

   至此，您的Hexo博客已经搭建在云服务器, 域名为个人域名。



## Hexo常用命令



```shell
hexo new "postName" #新建文章
hexo new page "pageName" #新建页面
hexo clean #清除部署緩存
hexo n == hexo new #新建文章
hexo g == hexo generate #生成静态页面至public目录
hexo s == hexo server #开启预览访问端口（默认端口4000，可在浏览器输入localhost:4000预览）
hexo d == hexo deploy #将.deploy目录部署到GitHub
hexo g -d #生成加部署
hexo g -s #生成加预览
```



**注：**当本地预览和远程部署的浏览结果不同的时候，不妨使用`hexo clean && hexo g -d`试试。



#### 创建文章

命令：

```
$ hexo new [layout] <title>

复制代码
```

参数说明：

- [layout]可以为以下三种：

| 参数名 | 功能                    | 文章路径       |
| ------ | ----------------------- | -------------- |
| post   | 新建博文                | source/_posts  |
| page   | 新建页面（如404，分类） | source         |
| draft  | 草稿                    | source/_drafts |

草稿可通过一下命令发布：

```
$ hexo publish [layout] <title>

复制代码
```

- title注意：

  不是博文标题，

  是博文markdown文件的名字，

  也是博文链接的后缀（如`https://www.simon96.online/2018/10/12/hexo-tutorial/`中的hexo-tutorial）

#### 文章模版

- 创建模版

  在新建文章时，Hexo 会根据 `scaffolds` 文件夹内相对应的文件来建立文件，例如：

> $ hexo new blog "simon"

​	在执行这行指令时，Hexo 会尝试在 `scaffolds` 文件夹中寻找 `blog.md`，并根据其内容建立文章。

- 修改参数

  以下是您可以在模版中使用的变量：

| 变量   | 描述         |
| ------ | ------------ |
| layout | 布局         |
| title  | 标题         |
| date   | 文件建立日期 |

#### Front-matter

就是博文最上方以 `---` 分隔的那部分。

默认可以使用的Front-matter：

| 参数         | 描述                 | 默认值       |
| ------------ | -------------------- | ------------ |
| `layout`     | 布局                 |              |
| `title`      | 标题                 |              |
| `date`       | 建立日期             | 文件建立日期 |
| `updated`    | 更新日期             | 文件更新日期 |
| `comments`   | 开启文章的评论功能   | true         |
| `tags`       | 标签（不适用于分页） |              |
| `categories` | 分类（不适用于分页） |              |
| `permalink`  | 覆盖文章网址         |              |







## 主题配置

[hexo主题wiki](<https://github.com/hexojs/hexo/wiki/Themes>)

可以在[此处](<https://github.com/hexojs/hexo/wiki/Themes>)寻找自己喜欢的主题下载所有的主题文件，保存到Hexo目录下的`themes`文件夹下。然后在`_config.yml`文件中修改：

```
# Extensions
## Plugins: http://hexo.io/plugins/
## Themes: http://hexo.io/themes/
theme: landscape //themes文件夹中对应文件夹的名称
```

然后先执行`hexo clean`，然后重新`hexo g`，并且`hexo d`，很快就能看到新主题的效果了~





## 主题优化

- **设置「RSS」**

- **添加「标签」页面**

- **添加「分类」页面**

- **设置「字体」**

- **设置「代码高亮主题」**

- **侧边栏社交链接**

  问题：图标哪里找？

  解决：[Font Awesome](https://link.juejin.im?target=https%3A%2F%2Ffontawesome.com%2Ficons%3Fd%3Dgallery)

- **开启打赏功能**

  问题：微信支付宝二维码不美观，规格不一。

  解决：[在线生成二维码](https://link.juejin.im?target=https%3A%2F%2Fcli.im%2Fweixin)

- **设置友情链接**

- **添加个人联系方式**

- **腾讯公益404页面**

- **站点建立时间**

- **订阅微信公众号**

- **设置「动画效果」**

  问题：慢，需要等待 JavaScript 脚本完全加载完毕后才会显示内容。 解决：将主题配置文件`_config.yml`中，use_motion字段的值设为 `false` 来关闭动画。

- **设置「背景动画」**

- **添加背景图**

- **修改Logo字体**

- **修改内容区域的宽度**

- **网站标题栏背景颜色**

- **自定义鼠标样式**

- **文章加密访问**

- **实现点击出现桃心效果**

- **静态资源压缩（博文压缩）**

- **修改访问url路径**

- **博文置顶**

- **在右上角或左上角实现fork me on github**

- **主页文章添加边框阴影效果**

- **显示当前浏览记录**

- **常见分类页**

- **加入广告**

- **添加萌萌哒**

- **搜索功能**

- **网易云外链播放器**

- **[花里胡哨的玩意儿](<http://www.iamlj.com/2016/08/add-special-effect-harlem-shake-for-hexo/>)**

- **修改作者头像并旋转**

- **修改``代码块自定义样式**

- **点击爆炸效果**

- **添加萌妹子动图**

- **侧栏设置**

- **透明背景设置**

- **添加阅读全文**

- **设置网站缩略图标**

- **添加站点访问计数**





前几个可参考[next官方文档配置](<http://theme-next.iissnan.com/theme-settings.html#use-bg-animation>)

（以下用到外部工具）

评论系统

数据统计与分析

内容分享服务



[文章加密访问](<https://www.jianshu.com/p/44e211829447>)

[hexo-blog-encrypt](<https://github.com/MikeCoder/hexo-blog-encrypt>)








## SEO

[Hexo NexT 主题SEO优化指南](<https://www.jianshu.com/p/0d54a590b81a>)



seo这东西是使自己的文章能被百度、谷歌搜录，能被搜索到。

因为暂时不想被搜到/doge，所有暂不配置







## GitPage 国内优化



参考大佬的博客：https://blog.lgf.im/2020/03/speedup-github-page/#



* 对于html/js/css的压缩：gulp

  ```sh
  $ # 本机安装
  $ npm install gulp -g
  $ #为了github Action 和其他CI\CD平台也能进行安装，推荐
  $ npm install gulp --save-dev
  $ # 安装依赖
  $ npm install gulp-minify-css \
              gulp-babel \
              gulp-uglify \
              gulp-htmlmin \
              gulp-htmlclean \
              --save-dev
  ```

  

  * 创建配置文件：在博客hexo的根目录下，新建 `gulpfile.js` 配置文件

  ```js
  var gulp = require('gulp');
  var minifycss = require('gulp-minify-css');
  var uglify = require('gulp-uglify');
  var htmlmin = require('gulp-htmlmin');
  var htmlclean = require('gulp-htmlclean');
  var imagemin = require('gulp-imagemin');
  
  // 压缩css文件
  gulp.task('minify-css', function() {
    return gulp.src('./public/**/*.css')
    .pipe(minifycss())
    .pipe(gulp.dest('./public'));
  });
  
  // 压缩html
  gulp.task('minify-html', function() {
    return gulp.src('./public/**/*.html')
        .pipe(htmlclean())
        .pipe(htmlmin({
            collapseWhitespace: true,
            collapseBooleanAttributes: true,
            removeComments: true,
            removeEmptyAttributes: true,
            removeScriptTypeAttributes: true,
            removeStyleLinkTypeAttributes: true,
            minifyJS: true,
            minifyCSS: true,
            minifyURLs: true,
            ignoreCustomFragments: [ /\{\{[\s\S]*?\}\}/ ],
        }))
        .pipe(gulp.dest('./public'));
  });
  
  // 压缩js文件
  gulp.task('minify-js', function() {
      return gulp.src(['./public/**/*.js','!./public/js/**/*min.js'])
          .pipe(uglify())
          .pipe(gulp.dest('./public'));
  });
  
  // 压缩图片
  gulp.task('minify-images', function() {
      return gulp.src(['./public/**/*.png', './public/**/*.jpg', './public/**/*.gif', './public/**/*.svg'])
          .pipe(imagemin({
             optimizationLevel: 5, //类型：Number  默认：3  取值范围：0-7（优化等级）
             progressive: true, //类型：Boolean 默认：false 无损压缩jpg图片
             interlaced: false, //类型：Boolean 默认：false 隔行扫描gif进行渲染
             multipass: false, //类型：Boolean 默认：false 多次优化svg直到完全优化
          }))
          .pipe(gulp.dest('./public'));
  });
  
  
  gulp.task('default', gulp.series(gulp.parallel('minify-html', 'minify-css', 'minify-js', 'minify-images')));
  
  
  ```

  gulp 压缩完之后快了50%

* cdn加速
  我的博客还没应用，先mark一下，可以用jsDelivr进行CDN分发
  jsDelivr 是一家开源免费CDN，主要是对npm包进行CDN分发
  绝妙的是它还能对Github和Wordpress进行CDN分发
  我们可以借助 jsDelivr 的 Github资源分发 服务来对我们博客中的css\js\小图片进行加速
  
* 加载时文字可见

* 使用懒加载















