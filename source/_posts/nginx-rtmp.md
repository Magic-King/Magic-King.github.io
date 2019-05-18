---
title: nginx+rtmp
date: 2019-05-17 22:22:38
tags: [nginx,rtmp]
categories:nginx
description:
password:
---





# nginx+rtmp 搭建视频直播服务器



## 服务器安装配置

pass



>windows安装包(已编译好的版本)参考：
>
>[nginx for windows](<http://nginx-win.ecsds.eu/>)
>
>[windows下搭建基于nginx的rtmp服务器](<http://blog.chinaunix.net/uid-26000296-id-5748243.html>)
>
>[在Windows下搭建基于nginx的视频直播和点播系统](<https://my.oschina.net/gaga/blog/478480>)



>搬运源码（未编译）
>
>[Car-eye-RTMP-server(github)](<https://github.com/Car-eye-team/Car-eye-RTMP-server>)
>
>[car-eye-http-flv-module](<https://github.com/Car-eye-team/car-eye-http-flv-module>)
>
>



> nginx+rtmp在windows下编译
>
> [Windows下编译nginx-rtmp-module](<https://www.cnblogs.com/KendoCross/p/7585654.html>)
>
> [windows下编译nginx+nginx_rtmp_modue(vs2013)](<https://blog.csdn.net/kenny25/article/details/39399689>)



> CentOS搭建nginx+rtmp服务器
>
> [nginx+rtmp直播流服务搭建 centos7](<https://www.jianshu.com/p/0a4a34d9eb8f>)
>
> [centos7 Nginx+rtmp 搭建流媒体服务器](<https://blog.csdn.net/sz76211822/article/details/79225716>)

linux下建议将nginx.conf中的http端口改为1024以上，好像是80端口每次运行都需要su权限。



## nginx服务器常用命令



```shell
./nginx -v//查看nginx版本号
./nginx -V //查看nginx详细的版本信息
start ./nginx -c conf/nginx.conf //以nginx.conf的配置启动nginx
./nginx -s stop//停止nginx服务器
./nginx -s quit//停止nginx服务器
./nginx -s reload//重启nginx服务器
service nginx reload//重启nginx服务器
./nginx -t (-c conf/nginx.conf)//检查配置文件是否正确
./nginx -h//显示帮助信息
./nginx -?//显示帮助信息

```







## nginx+rtmp加入权限控制



>本文参考：
>
>*[rtmp-module官方wiki](<https://github.com/arut/nginx-rtmp-module/wiki/Directives>)
>
>*[视频直播点播nginx-rtmp开发手册中文版(参考wiki版本粗译)](<http://www.cnblogs.com/zx-admin/p/5783523.html>)
>
>[如何给 nginx rtmp 服务加入鉴权机制(改源码)](<https://blog.csdn.net/cui918/article/details/53540397#commentBox>)
>
>*[「自己开发直播」实现nginx-rtmp-module多频道输入输出与权限控制](<https://blog.csdn.net/weixin_34368949/article/details/85991563>)
>
>[nginx-rtmp-module授权机制实现直播推流多房间授权认证](<https://blog.csdn.net/weixin_42579642/article/details/85263210>)
>
>[nginx-rtmp-module 权限控制](<https://blog.csdn.net/iam_shuaidaile/article/details/50599943>)
>
>[nginx-rtmp加入权限验证的简单方法](<https://blog.csdn.net/luoc83/article/details/79240774>)
>
>[视频直播点播nginx-rtmp开发手册中文版](<https://blog.csdn.net/kevinw9/article/details/52984826>)
>
>*[nginx.conf中关于nginx-rtmp-module配置指令详解](<https://www.cnblogs.com/lidabo/p/7099501.html>)
>
>*[nginx-rtmp多房间和授权实现](<https://blog.csdn.net/wei389083222/article/details/78721074/>)
>
>> *博客比较有用



nginx的rtmp-module默认不限制推流权限、播放权限。

想加入权限验证有很多种方法。

其中一个是改源码，一个是利用nginx+rtmp的配置文件调用后台接口进行验证。

第一种方法没成功过，第二种方法比较简单。此文介绍第二种方法，第一种方法可见博客->[如何给 nginx rtmp 服务加入鉴权机制(改源码)](<https://blog.csdn.net/cui918/article/details/53540397#commentBox>)

原理主要是利用on_publish跳转到当前配置的一个“location”，在这里进行验证。关键点在于rtmp application节点下面要配置“notify_method get;”为什么呢？因为跳转的时候，默认以POST方式传输参数，修改成GET方式，nginx配置里就可以轻松处理了。（当然nginx通过配置文件也可以处理post，只是复杂一些）。

我们在此使用python的后台框架flask处理on_publish的post请求。

后台返回http200即为通过验证，返回http500即为验证失败，服务器拒绝连接。

nginx的配置文件（位于nginx安装目录下：.../nginx/conf/nginx.conf）修改如下:



```
rtmp {
	server {
		#listen 1935;
		listen 10077;

		chunk_size 4000;
		application live {
			live on;
			on_publish http://localhost:10078/user/auth;//后面的url即flask监听的地址
			
		}

	application hls {
			live on;
			hls on;
			#hls_path ../nginx-1.7.11.3-Gryphon/html/hls;
			hls_path ../hls;
			hls_fragment 5s;
			on_publish http://localhost:10078/user/auth;
		}
	}
}
```



python的flask后台代码如下：

```python
#!/usr/bin/env python
# -*- coding:utf-8 -*-

#https://www.jianshu.com/p/0d14ae8f081c

#https://blog.csdn.net/wei389083222/article/details/78721074/
#https://blog.csdn.net/weixin_34368949/article/details/85991563
#验证只能用post方法
#虽然流密钥的格式像是get类型，但是必须使用POST获取参数。
from flask import Flask, request, Response
app = Flask(__name__)

#传入url格式为: xx.xx.xx.xx:10078/user/auth?usr=xxx&passWord=xxx
@app.route('/user/auth',methods=['POST'])
def auth():
    usr = request.form['usr']#从url后获取的数据
    passWord = request.form['passWord']
    print(usr,'\t',passWord)
    #此处可改为从数据库获取数据
    auth_user='abc'
    auth_passWord='123'
    if auth_user == usr and auth_passWord ==passWord:
        return Response(response='success',status=200)#返回200状态码
    else:
        return Response(status=500)#返回500状态码
        #Flask.abort(404)
    return passWord


if __name__ == '__main__':
    app.run(host='0.0.0.0',port=10078,debug=True)
```





播放权限也可用类似on_publish的验证方法进行控制。

on_play和on_publish 一样，只接受post方法，若需要接受get方法需要在rtmp中application的配置中添加<pre>notify_method get;</pre>，然后可在http{}部分中处理调用（这部分语法我不太清楚，不详细展开）。





以下是nginx.conf关于on_play的用法

on_play
语法：on_play url
上下文：rtmp, server, application
描述：设置 HTTP 播放回调。每次一个客户分发播放命令时，一个 HTTP 请求异步发送，命令处理会挂起 - 直到它返回结果码。之后再解析 HTTP 结果码。

* HTTP 2XX 返回码的话继续 RTMP 会话。
* HTTP 3XX 返回码的话 重定向 RTMP 到另一个流，这个流的名字在 HTTP 返回头的 Location 获取。如果新流的名字起始于 rtmp:// 然后远程 relay 会被创建。relay 要求 IP 地址是指定的而不是域名，并且只工作在 1.3.10 版本以上的 nginx。另请参考 notify_relay_redirect。
* 其他返回码的话 RTMP 连接丢弃。
重定向例子：
http {
    ...
    location /local_redirect {
        rewrite ^.*$ newname? permanent;
    }
    location /remote_redirect {
        # no domain name here, only ip
        rewrite ^.*$ rtmp://192.168.1.123/someapp/somename? permanent;
    }
    ...
}


rtmp {
    ...
    application myapp1 {
        live on;
        # stream will be redirected to 'newname'
        on_play http://localhost:8080/local_redirect;
    }
    application myapp2 {
        live on;
        # stream will be pulled from remote location
        # requires nginx >= 1.3.10
        on_play http://localhost:8080/remote_redirect;
    }
    ...
}
HTTP 请求接收到一些个参数。在 application/x-www-form-urlencoded MIME 类型下使用 POST 方法。以下参数会被传送给调用者：
* call=play。
* addr - 客户端 IP 地址。
* app - application 名。
* flashVer - 客户端 flash 版本。
* swfUrl - 客户端 swf url。
* tcUrl - tcUrl。
* pageUrl - 客户端页面 url。
* name - 流名。
出了上述参数之外其他所有播放命令参数显式地发送回调。例如如果一个流由 url rtmp://localhost/app/movie?a=100&b=face&foo=bar 访问，然后呢 a,b 和 foo 发送回调。
on_play http://example.com/my_callback;





## 过程中使用到的额外软件

* obs
* 手机端:快直播
* ffmpeg推流（没用过）


