---
title: QRCodeAttack
date: 2019-12-30 15:35:01
tags: QRCode
categories: QRCode
description: Something about QRCode.
password:
---













### 关于python的QRCode的用法



qrcode的用法

> https://blog.csdn.net/cungudafa/article/details/85871871
>
> 



利用`zxing`模块读二维码数据

```python
from PIL import Image
import qrcode
import os
import zxing


def make_qrcode(data):
    img = qrcode.make(data)
    img.sava("test.png")
    im = Image.open("test.png")
    im.show()


def read_qrcode_zxing(filename):
    '''
    logger = logging.getLogger(__name__)
    if not logger.handlers: logging.basicConfig(level=logging.INFO)
    DEBUG = (logging.getLevelName(logger.getEffectiveLevel()) == 'DEBUG')
    '''
    img = Image.open(filename)
    ran = int(random.random() * 100000)
    img.save('%s%s.jpg' % (os.path.basename(filename).split('.')[0], ran))
    zx = zxing.BarCodeReader()#调用zxing二维码读取包
    data = ''
    zxdata = zx.decode('%s%s.jpg' % (os.path.basename(filename).split('.')[0], ran))#图片解码
    # 删除临时文件
    os.remove('%s%s.jpg' % (os.path.basename(filename).split('.')[0], ran))
    if zxdata:
        logger.debug(u'zxing识别二维码:%s,内容: %s' % (filename, zxdata))
        data = zxdata
    else:
        logger.error(u'识别zxing二维码出错:%s' % (filename))
        img.save('%s-zxing.jpg' % filename)
    return data
```

但是，这只能识别标准的二维码，并不能识别图片中的二维码，由于这里需要用到tesseract，因此直接用二维码软件进行扫（注意不能用微信支付宝之类的，因为碰到url此类软件会直接跳转，好像QQ和一些第三方的扫码软件不会直接跳转url，而是显示其数据）



### 乌云的二维码攻击

>  [QR二维码的攻击方法与防御](https://wooyun.js.org/drops/QR二维码的攻击方法与防御.html)

1. 网络钓鱼
2. 诱导下载、传播恶意软件
3. 隐私泄露



#### 防御方式

1. QR码解码译码过程加入加解密环节
2. 第三方统一管理



##### 思考

1.加入加解密环节：这只是确保了原二维码的数据的完整性，隐匿性，并不能确保其不被中间人攻击，即直接替换二维码的行为







### 现有共享单车扫码探索



```
Mobike:
	8650262688:	 http://www.mobike.com/download/app.html?b=8650262688_1
	8641170177:	 http://www.mobike.com/download/app.html?b=8641170177_1
	8641176319:  http://www.mobike.com/download/app.html?b=8641176319_1
	
hello bike:
	3110469617:  http://c3x.me/?n=3110469617
	3110457021:  http://c3x.me/?n=3110457021
	5610663692:	 http://c3x.me/?n=5610663692
	
didi bike:
	https://dc.tt/htw?id=1B24C1D&p=2
	https://dc.tt/htw?id=1B4910D&p=2
	
```



用电脑直接访问该网址

* Mobike是直接跳转到app推荐页面，打开下载，是腾讯合作方的应用宝下载

* hello bike也是直接跳转至app推荐页面，打开下载，属于hellobike自己搭建的下载页面

* 滴滴是跳转到小程序推荐页面，

  

#### hello 



<img src="QRCodeAttack\11.jpg" style="zoom:150%;" />



由图可见，明显的一个env变量，推测是用来判断用的。

然后下面就是对enc进行逻辑判断，然后处理跳转

我的浏览器是跳转到了`http://c3x.me/bike.html?n=3110469617`

`https://c3x.me/wechat-ebike.html?n=3110469617`是对微信内置浏览器做的一些页面自适应

再次应该是对User-Agent进行判断，并跳转至相应页面，代码如下：

```
 // 基本环境及参数
    var ua = window.navigator.userAgent;
    var params = {};
    if (location.search) {
      var parts = location.search.substring(1).split('&');
```

> 关于window.navigator.userAgent：https://blog.csdn.net/liangyihe/article/details/78464656

以下是苹果的useragent，用去替换

```
UserAgent:Mozilla/5.0 (iPhone; CPU iPhone OS 11_0 like Mac OS X) AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Mobile/15A372 Safari/604.1

```

果然是同一个页面的不同适应性处理

对于aliBrowser，是对应跳转到相应的下载界面，采用`alipays://plat....`

对于哈喽bike App也是跳转到自身的路由，然后再其服务端做处理



#### Mobike

抓包访问，发现是直接301了（永久性转移），然后没找到解决办法

因为是直接跳转至下载界面，所有没有和此单车合作的app都是跳转至下载界面，抓包失败





#### didi

```
this.config 0  
{…}

__method__: "POST"

_source: "https://page.xiaojukeji.com/m/hellopage.html?id=1B24C1D&p=2"

api_version: "1.0.1"

app_version: "1.8.7"

appid: 30004

auto_fill_phone: true

canonical_country_code: "CN"

checkPhone: true

city_id: 0

country_calling_code: "+86"

country_filter: Array []

country_id: 156

from: "webapp"

imei: ""

lang: "zh-CN"

law_checked: false

origin_id: "1"

role: 1

scene: 3

showCodeSign: false

styleObj: Object {  }

useOauthCode: false

<prototype>: Object { … }
login.min.js:1:36888

```

明显的一个post请求，而且采用了https，不好抓包

但是预测是跳转至小程序，属于微信小程序的。



------

手机抓包工具：fiddler，frida

------

通过以上可发现，共享单车的二维码大多都是通过二维码的url格式存储，然后通过url访问判断其user-Agent推测出使用的浏览器，然后做不同的路由处理或使用自身协议，如`alipays://`



### 关于密码学与二维码的思考

在二维码多存入证书，存储的数据量应该会变大，但是不至于存不下，但是这是没有必要的。

当扫完二维码访问其指向的url时，该请求已向ocsp请求在线证书了；而且该种方法也无法避免中间人攻击。（参考https的ssl中间人攻击）

> https中的ssl中间人攻击
>
> [通过伪造CA证书，实现SSL中间人攻击](https://blog.csdn.net/u013152718/article/details/47081541)
>
> [SSL,TLS中间人攻击](https://blog.csdn.net/qq_26090065/article/details/81256662)
>
> [HTTPS中间人攻击实践（原理·实践）](https://www.cnblogs.com/lulianqi/p/10558719.html)
>
> 

至于二维码替换更加无可避免，因此还是采用信任可信第三方的(官方app，以及有合作的app)方法比较安全。（因为其用的是路由判断，不存在假的url能跳转）

其次，假如在二维码中加入hash判断，也是不可行的。因为密码学不能依赖于不公开的算法，而且可以通过暴力匹配算出hash算法的流程。因此得知流程，将假url和假url的hash一起替换原url以及其hash便可产生攻击。