---
title: pacman
date: 2019-10-11 21:33:53
tags: [ArchLinux, linux]
categories: linux
description:
password:
---









# 包管理工具 Pacman



> 参考：
>
> [Pacman Home Page](https://www.archlinux.org/pacman/)
>
> [pacman wiki]([https://wiki.archlinux.org/index.php/Pacman_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)](https://wiki.archlinux.org/index.php/Pacman_(简体中文))
>
> [ArchLinux 的 pacman 命令详解](https://blog.csdn.net/lu_embedded/article/details/50520647)
>
> 





***

**警告:** 在Arch下安装软件包时，未[更新](https://wiki.archlinux.org/index.php/Pacman_(简体中文)#升级软件包)系统前，**不要**更新软件包数据库（例如，可能出现某软件包不再出现在官方库）。操作时，应使用`pacman -Syu *package_name*`, 而不要使用（`pacman -Sy *package_name*`），否则可能会有依赖问题。参见 [System maintenance (简体中文)#不支持部分升级](https://wiki.archlinux.org/index.php/System_maintenance_(简体中文)#不支持部分升级) 和 [BBS#89328](https://bbs.archlinux.org/viewtopic.php?id=89328).

***





### 安装指定的包



安装或者升级单个软件包，或者一列软件包（包含依赖包），使用如下命令：

```sh
$ pacman -S package_name1 package_name2 ...
```



用正则表达式安装多个软件包（参见 [pacman 小贴士](https://wiki.archlinux.org/index.php/Pacman_tips_(简体中文)#巧用_Bash_语法): invalid section]和[这个帖子](https://bbs.archlinux.org/viewtopic.php?id=7179)）：

```sh
$ pacman -S $(pacman -Ssq package_regex)
```

有时候在不同的软件仓库中，一个软件包有多个版本（比如[extra]和[testing]）。可以选择一个来安装：

```sh
$ pacman -S extra/package_name
```

安装多个含有相似名称的软件包，而并非整个包组或全部匹配的软件包； 例如，plasma:

```sh
$ pacman -S plasma-{desktop,mediacenter,nm}
```

当然，可以多层扩展，并不作限制：

```sh
$ pacman -S plasma-{workspace{,-wallpapers},pa}
```





### 安装包组

一些包属于一个可以同时安装的软件包组。例如，运行下面的命令

```sh
$ pacman -S gnome
```

会提醒用户选择 `gnome` 内需要安装的包。

有的包组包含大量的软件包，有时用户只需其中几个。除了逐一键入序号外，pacman 还支持选择或排除某个区间内的的软件包：

```sh
Enter a selection (default=all): 1-10 15
```

这将选中序号 1 至 10 和 15 的软件包。而

```sh
Enter a selection (default=all): ^5-8 ^2
```

将会选中除了序号 5 至 8 和 2 之外的所有软件包。

想要查看哪些包属于 gnome 组，运行：

```sh
$ pacman -Sg gnome
```

也可以访问 https://www.archlinux.org/groups/ 查看可用的包组。

**注意:** 如果列表中的包已经安装在系统中，它会被重新安装，即使它已经是最新的。可以用                `--needed` 选项覆盖这种行为。





### 删除软件包

删除单个软件包，保留其全部已经安装的依赖关系

```shell
$ pacman -R package_name
```

删除指定软件包，及其所有没有被其他已安装软件包使用的依赖关系：

```sh
$ pacman -Rs package_name
```

要删除软件包和所有依赖这个软件包的程序:

**警告:** 此操作是递归的，请小心检查，可能会一次删除大量的软件包。

```sh
$ pacman -Rsc package_name
```

要删除软件包，但是不删除依赖这个软件包的其他程序：

```sh
$ pacman -Rdd package_name
```

*pacman* 删除某些程序时会备份重要配置文件，在其后面加上*.pacsave扩展名。-n 选项可以避免备份这些文件：

```sh
$ pacman -Rn package_name
```

**注意:** *pacman* 不会删除软件自己创建的文件(例如主目录中的 `.dot` 文件不会被删除。





### 升级软件包



***

**警告:** * 建议所有用户都[经常性的更新系统](https://wiki.archlinux.org/index.php/System_maintenance#Upgrading_the_system)

- Arch 只支持系统完整升级，详细参见[不支持部分升级](https://wiki.archlinux.org/index.php/System_maintenance#Partial_upgrades_are_unsupported)和[#安装软件包](https://wiki.archlinux.org/index.php/Pacman_(简体中文)#安装软件包)。

***



一个 *pacman* 命令就可以升级整个系统。花费的时间取决于系统有多老。这个命令会同步非本地(local)软件仓库并升级系统的软件包：

```sh
$ pacman -Syu
```





### 查询包数据库

*pacman* 使用 `-Q` 参数查询本地软件包数据库。参见：

```shell
$ pacman -Q --help
```

使用 `-S` 参数来查询远程同步的数据库。参见：

```sh
$ pacman -S --help
```

*pacman* 可以在包数据库中查询软件包，查询位置包含了软件包的名字和描述：

```sh
$ pacman -Ss string1 string2 ...
```

有时，`-s`的内置正则会匹配很多不需要的结果，所以应当指定仅搜索包名，而非描述或其他子段，下面的命令就会返回很多不必要结果:

```sh
$ pacman -Ss '^vim-'
```

要查询已安装的软件包：

```sh
$ pacman -Qs string1 string2 ...
```

按文件名查找软件库：

```sh
$ pacman -Fs string1 string2 ...
```

显示软件包的详尽的信息：

```sh
$ pacman -Si package_name
```

查询本地安装包的详细信息：

```sh
$ pacman -Qi package_name
```

使用两个 `-i` 将同时显示备份文件和修改状态：

```sh
$ pacman -Qii package_name
```

要获取已安装软件包所包含文件的列表：

```sh
$ pacman -Ql package_name
```

查询远程库中软件包包含的文件：

```sh
$ pacman -Fl package_name
```

检查软件包安装的文件是否都存在：

```sh
$ pacman -Qk package_name
```

两个参数`k`将会执行一次更彻底的检查。 查询数据库获取某个文件属于哪个软件包：

```sh
$ pacman -Qo /path/to/file_name
```

查询文件属于远程数据库中的哪个软件包：

```shell
$ pacman -Fo /path/to/file_name
```

要罗列所有不再作为依赖的软件包(孤立orphans)：

```sh
$ pacman -Qdt
```

要罗列所有明确安装而且不被其它包依赖的软件包：

```sh
$ pacman -Qet
```

要显示软件包的依赖树：

```sh
$ pactree package_name
```

检查一个*安装*的软件包被那些包依赖，可以使用 [pkgtools](https://aur.archlinux.org/packages/pkgtools/)AUR中的*whoneeds*:

```sh
$ whoneeds package_name
```

或者*pactree*中使用`-r`:

```sh
$ pactree -r package_name
```



#### 数据库结构

pacman数据库通常位于 `/var/lib/pacman/sync`. 对于每一个在`/etc/pacman.conf`中指定的软件仓库， 这里都有一个一致的数据库。数据库文件夹里每个tar.gz文件都包含着一个仓库的软件包信息。例如which 包:

```
% tree which-2.20-6 	
which-2.20-6
|-- depends
`-- desc
```

这个 `depends` 项列出了该软件的依赖包， 而`desc`有该包的介绍，例如文件大小和MD5值 。





### 清理软件包缓存

*pacman* 将下载的软件包保存在 `/var/cache/pacman/pkg/` 并且不会自动移除旧的和未安装版本的软件包，因此需要手动清理，以免该文件夹过于庞大。

使用内建选项即可清除未安装软件包的缓存：

```sh
$ pacman -Sc
```

**警告:**

- 仅在确定当前安装的软件包足够稳定且不需要[降级](https://wiki.archlinux.org/index.php/Downgrading_packages_(简体中文))时才执行清理。`pacman -Sc`仅会保留软件包的当前有效版本，旧版本的软件包被清理后，只能从其他地方如 [Arch Linux Archive (简体中文)](https://wiki.archlinux.org/index.php/Arch_Linux_Archive_(简体中文))中获取了。
- `pacman -Scc` 可以清理所有缓存，但这样 pacman 在重装软件包时就只能重新下载了。除非空间不足，否则不应这么做。

由于以上种种局限，建议使用专门的脚本去处理清理哪些、清理多少缓存：

[pacman-contrib](https://www.archlinux.org/packages/?name=pacman-contrib) 提供的 *paccache* 命令默认会删除近3个版本前的软件包

```
# paccache -r
```

**Tip:** 可以使用 [pacman hooks](https://wiki.archlinux.org/index.php/Pacman_hooks) 自动执行清理，[这里](https://bbs.archlinux.org/viewtopic.php?pid=1694743#p1694743)是参考示例。

也可以自己设置保留最近几个版本：

```
# paccache -rk 1
```

清理所有未安装包的缓存文件，再此运行`paccache`:

```
# paccache -ruk0
```

更多功能参见`paccache -h`。

*paccache*，还可以使用 [Arch User Repository](https://wiki.archlinux.org/index.php/Arch_User_Repository_(简体中文)) 中的 [pkgcacheclean](https://aur.archlinux.org/packages/pkgcacheclean/)AUR：

```
# pkgcacheclean
```

，以及[pacleaner](https://aur.archlinux.org/packages/pacleaner/)AUR，这两个是未来的替代工具.

### 其它命令

升级系统时安装其他软件包：

```sh
$ pacman -Syu package_name1 package_name2 ...
```

下载包而不安装它：

```sh
$ pacman -Sw package_name
```

安装一个**本地**包(不从源里下载）：

```sh
$ pacman -U /path/to/package/package_name-version.pkg.tar.xz
```

要将本地包保存至缓存，可执行：

```sh
$ pacman -U file://path/to/package/package_name-version.pkg.tar.xz
```

安装一个**远程**包（不在 *pacman* 配置的源里面）：

```sh
$ pacman -U http://www.example.com/repo/example.pkg.tar.xz
```

要禁用 `-S`, `-U` 和 `-R` 动作，可以使用 `-p` 选项.

*pacman* 会列出需要安装和删除的软件，并在执行动作前要求需要的权限。

### 安装原因

*pacman*数据库按照软件包被安装的原因，将其分为两类：

- **指定安装包**：通过*pacman*`-S`或者`-U`指令安装的软件包。
- **依赖包**：指定安装包所依赖的软件包，尽管命令中未传入，但仍然会被安装。

当安装软件包时，可以把安装原因指定设为**依赖**:

```
# pacman -S --asdeps package_name
```

但是当重新安装该软件包时，安装原因将会被设为软件包所默认的。 指定安装的软件包列表可用`pacman -Qe`, 已安装的依赖包可用`pacman -Qd`获取。 改变某个已安装软件包的安装原因，可以执行：

```
# pacman -D --asdeps package_name
```

使用`--asexplicit`改为**指定安装**。

### 查询一个包含具体文件的包名

同步文件数据库:

```
# pacman -Fy
```

查询包含某个文件的包名，比如:

```
# pacman -Fs pacman
core/pacman 5.0.1-4
    usr/bin/pacman
    usr/share/bash-completion/completions/pacman
extra/xscreensaver 5.36-1
    usr/lib/xscreensaver/pacman
```

**提示：** 可以设置一个 `crontab` 或者 `systemd timer` 来定期同步文件信息数据库。

如果需要高级功能请安装 [pkgfile](https://wiki.archlinux.org/index.php/Pkgfile)，它使用一个单独的数据库来保存文件和它们所关联的软件包的信息。





















ArchLinux的版本库里面包括：

　　core-核心软件包
　　extra-其他常用软件
　　community-社区软件包，譬如Mysql等。
　　testing-正在测试阶段，还没有正式加入源的软件包。通常软件版本比较新，但是不是非常稳定
　　release-已经发布的软件包
　　unstable-非正式的软件包，可能包括以前版本的软件或者测试软件

　　因为Pacman的软件都是从源里面更新，因此在/etc/pacman.d里面配置这些软件源的地址。在/etc/pacman.d目录里面分别有上面几种软件类型对应的文件名，可以自己手工配置这些软件源的地址。























