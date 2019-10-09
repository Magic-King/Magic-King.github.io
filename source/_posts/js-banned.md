---
title: js_banned
date: 2019-10-09 18:32:10
tags: [web, javascript, ]
categories: [web]
description:
password:
---







序：原本想从网页上搞些网课答案下来，懒得用爬虫，便想直接复制粘贴更方便，结果遭遇了网页的复制和控制台禁用，本着求知的精神，就有了这篇文章。





# 网页中部分禁用及破解





* ### 利用js实现



禁用F12

```javascript
<script>
document.οnkeydοwn=function (e){
        var currKey=0,evt=e||window.event;
        currKey=evt.keyCode||evt.which||evt.charCode;
        if (currKey == 123) {
            window.event.cancelBubble = true;
            window.event.returnValue = false;
        }
    }
</script>
```



```javascript
<script>
var h = window.innerHeight,w=window.innerWidth;
//禁用右键 （防止右键查看源代码）
window.oncontextmenu=function(){<br>   return false;<br>}
//在本网页的任何键盘敲击事件都是无效操作 （防止F12和shift+ctrl+i调起开发者工具）
window.onkeydown = window.onkeyup = window.onkeypress = function () {
    window.event.returnValue = false;
    return false;
}
//如果用户在工具栏调起开发者工具，那么判断浏览器的可视高度和可视宽度是否有改变，如有改变则关闭本页面
window.onresize = function () {
    if (h != window.innerHeight||w!=window.innerWidth){
        window.close();
        window.location = "about:blank";
    }
};
                                
</script>
```





```javascript
<script>
(document).keydown(function() {
    return key(arguments[0])
});
function key(e) {
    //f12
    var keynum;
    if (window.event) {
        keynum = e.keyCode;
    } else if (e.which) {
        keynum = e.which;
    }
    if (keynum == 123) {
        window.close();
        return false;
    }
    
    //ctrl+shift
    if (event.shiftKey&&event.ctrlKey) {
        window.close();
        return false;
    }
}

function Click() {
    window.event.returnValue = false;
}
document.oncontextmenu = Click;// 右击
</script>
```







禁用右键菜单

```javascript
<script>
document.oncontextmenu = function(){return false;}
</script>
```



禁用文本选择

```js
<script>
document.onselectstart = function(){return true;}
</script>
```





* 一个网页：当禁用js时无法打开，不禁用js，禁止复制、看源码、右键菜单、F12、文本选择

适合学习

原网页：http://www.gebidemengmianren.com/eryadaanfufei/198.html?btwaf=99961145



```html
<!DOCTYPE html>
<html lang="zh-CN">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="Cache-Control" content="no-transform" />
  <meta http-equiv="Cache-Control" content="no-siteapp" />
  <meta name="applicable-device" content="pc,mobile">
  <meta name="MobileOptimized" content="width" />
  <meta name="HandheldFriendly" content="true" />
  <meta name="viewport" content="width=device-width, initial-scale=1"> <noscript>
    <meta http-equiv="refresh" content="0; url=http://www.gebidemengmianren.com/my-plugins/no-js.html" /></noscript>
  <link type="text/css" media="all" href="http://www.gebidemengmianren.com/wp-content/cache/autoptimize/css/autoptimize_fbc8fb4f52ab77546156f37a7cb23309.css" rel="stylesheet" />
  <title>当代中国政府与政治2019 &#8211; 隔壁的萌面人</title>
  <link rel='stylesheet' id='dashicons-css' href='http://www.gebidemengmianren.com/wp-includes/css/dashicons.min.css?ver=6f0a90e1258fc95d5c87f731d5ec4784' type='text/css' media='all' />
  <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-includes/js/jquery/jquery.js?ver=1.12.4'></script>
  <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-includes/js/jquery/jquery-migrate.min.js?ver=1.4.1'></script>
  <!--[if lt IE 9]> <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-content/themes/wellington/js/html5shiv.min.js?ver=3.7.3'></script> <![endif]-->
  <script type='text/javascript'>
    var wellington_menu_title = "\u83dc\u5355";
  </script>
  <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-content/themes/wellington/js/navigation.js?ver=20160719'></script>
  <link rel='prev' title='密码保护：当代中国经济2019修正版' href='http://www.gebidemengmianren.com/eryadaanfufei/196.html' />
  <link rel='next' title='密码保护：当政府遇上互联网2019' href='http://www.gebidemengmianren.com/eryadaanfufei/200.html' />
  <link rel="canonical" href="http://www.gebidemengmianren.com/eryadaanfufei/198.html" />
  <script type="text/javascript">
    document.ondragstart = function() {
      return false
    }; //for image
    document.oncontextmenu = function(e) {
      return false
    }; //for right click disable
    document.onkeydown = function(e) {
      if (e.ctrlKey &&
        (e.keyCode === 65 ||
          e.keyCode === 67 ||
          e.keyCode === 73 ||
          e.keyCode === 74 ||
          e.keyCode === 80 ||
          e.keyCode === 83 ||
          e.keyCode === 85 ||
          e.keyCode === 86 ||
          e.keyCode === 117
        )) {
        return false;
      }
      if (e.keyCode == 18 || e.keyCode == 123) {
        return false
      }
    };
  </script>
  <link rel="icon" href="http://www.gebidemengmianren.com/wp-content/uploads/2019/08/g-150x150.jpg" sizes="32x32" />
  <link rel="icon" href="http://www.gebidemengmianren.com/wp-content/uploads/2019/08/g.jpg" sizes="192x192" />
  <link rel="apple-touch-icon-precomposed" href="http://www.gebidemengmianren.com/wp-content/uploads/2019/08/g.jpg" />
  <meta name="msapplication-TileImage" content="http://www.gebidemengmianren.com/wp-content/uploads/2019/08/g.jpg" />
</head>

<body class="post-template-default single single-post postid-198 single-format-standard post-layout-one-column" id='body'>
  <script type="text/javascript">
    ! function(t, e) {
      "object" == typeof exports && "object" == typeof module ? module.exports = e() : "function" == typeof define && define.amd ? define([], e) : "object" == typeof exports ? exports.ClipboardJS = e() : t.ClipboardJS = e()
    }(this, function() {
      return function(t) {
        function e(o) {
          if (n[o]) return n[o].exports;
          var r = n[o] = {
            i: o,
            l: !1,
            exports: {}
          };
          return t[o].call(r.exports, r, r.exports, e), r.l = !0, r.exports
        }
        var n = {};
        return e.m = t, e.c = n, e.i = function(t) {
          return t
        }, e.d = function(t, n, o) {
          e.o(t, n) || Object.defineProperty(t, n, {
            configurable: !1,
            enumerable: !0,
            get: o
          })
        }, e.n = function(t) {
          var n = t && t.__esModule ? function() {
            return t.default
          } : function() {
            return t
          };
          return e.d(n, "a", n), n
        }, e.o = function(t, e) {
          return Object.prototype.hasOwnProperty.call(t, e)
        }, e.p = "", e(e.s = 3)
      }([function(t, e, n) {
        var o, r, i;
        ! function(a, c) {
          r = [t, n(7)], o = c, void 0 !== (i = "function" == typeof o ? o.apply(e, r) : o) && (t.exports = i)
        }(0, function(t, e) {
          "use strict";

          function n(t, e) {
            if (!(t instanceof e)) throw new TypeError("Cannot call a class as a function")
          }
          var o = function(t) {
              return t && t.__esModule ? t : {
                default: t
              }
            }(e),
            r = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function(t) {
              return typeof t
            } : function(t) {
              return t && "function" == typeof Symbol && t.constructor === Symbol && t !== Symbol.prototype ? "symbol" : typeof t
            },
            i = function() {
              function t(t, e) {
                for (var n = 0; n < e.length; n++) {
                  var o = e[n];
                  o.enumerable = o.enumerable || !1, o.configurable = !0, "value" in o && (o.writable = !0), Object.defineProperty(t, o.key, o)
                }
              }
              return function(e, n, o) {
                return n && t(e.prototype, n), o && t(e, o), e
              }
            }(),
            a = function() {
              function t(e) {
                n(this, t), this.resolveOptions(e), this.initSelection()
              }
              return i(t, [{
                key: "resolveOptions",
                value: function() {
                  var t = arguments.length > 0 && void 0 !== arguments[0] ? arguments[0] : {};
                  this.action = t.action, this.container = t.container, this.emitter = t.emitter, this.target = t.target, this.text = t.text, this.trigger = t.trigger, this.selectedText = ""
                }
              }, {
                key: "initSelection",
                value: function() {
                  this.text ? this.selectFake() : this.target && this.selectTarget()
                }
              }, {
                key: "selectFake",
                value: function() {
                  var t = this,
                    e = "rtl" == document.documentElement.getAttribute("dir");
                  this.removeFake(), this.fakeHandlerCallback = function() {
                      return t.removeFake()
                    }, this.fakeHandler = this.container.addEventListener("click", this.fakeHandlerCallback) || !0, this.fakeElem = document.createElement("textarea"), this.fakeElem.style.fontSize = "12pt", this.fakeElem.style.border =
                    "0", this.fakeElem.style.padding = "0", this.fakeElem.style.margin = "0", this.fakeElem.style.position = "absolute", this.fakeElem.style[e ? "right" : "left"] = "-9999px";
                  var n = window.pageYOffset || document.documentElement.scrollTop;
                  this.fakeElem.style.top = n + "px", this.fakeElem.setAttribute("readonly", ""), this.fakeElem.value = this.text, this.container.appendChild(this.fakeElem), this.selectedText = (0, o.default)(this.fakeElem), this.copyText()
                }
              }, {
                key: "removeFake",
                value: function() {
                  this.fakeHandler && (this.container.removeEventListener("click", this.fakeHandlerCallback), this.fakeHandler = null, this.fakeHandlerCallback = null), this.fakeElem && (this.container.removeChild(this.fakeElem),
                    this.fakeElem = null)
                }
              }, {
                key: "selectTarget",
                value: function() {
                  this.selectedText = (0, o.default)(this.target), this.copyText()
                }
              }, {
                key: "copyText",
                value: function() {
                  var t = void 0;
                  try {
                    t = document.execCommand(this.action)
                  } catch (e) {
                    t = !1
                  }
                  this.handleResult(t)
                }
              }, {
                key: "handleResult",
                value: function(t) {
                  this.emitter.emit(t ? "success" : "error", {
                    action: this.action,
                    text: this.selectedText,
                    trigger: this.trigger,
                    clearSelection: this.clearSelection.bind(this)
                  })
                }
              }, {
                key: "clearSelection",
                value: function() {
                  this.trigger && this.trigger.focus(), window.getSelection().removeAllRanges()
                }
              }, {
                key: "destroy",
                value: function() {
                  this.removeFake()
                }
              }, {
                key: "action",
                set: function() {
                  var t = arguments.length > 0 && void 0 !== arguments[0] ? arguments[0] : "copy";
                  if (this._action = t, "copy" !== this._action && "cut" !== this._action) throw new Error('Invalid "action" value, use either "copy" or "cut"')
                },
                get: function() {
                  return this._action
                }
              }, {
                key: "target",
                set: function(t) {
                  if (void 0 !== t) {
                    if (!t || "object" !== (void 0 === t ? "undefined" : r(t)) || 1 !== t.nodeType) throw new Error('Invalid "target" value, use a valid Element');
                    if ("copy" === this.action && t.hasAttribute("disabled")) throw new Error('Invalid "target" attribute. Please use "readonly" instead of "disabled" attribute');
                    if ("cut" === this.action && (t.hasAttribute("readonly") || t.hasAttribute("disabled"))) throw new Error('Invalid "target" attribute. You can\'t cut text from elements with "readonly" or "disabled" attributes');
                    this._target = t
                  }
                },
                get: function() {
                  return this._target
                }
              }]), t
            }();
          t.exports = a
        })
      }, function(t, e, n) {
        function o(t, e, n) {
          if (!t && !e && !n) throw new Error("Missing required arguments");
          if (!c.string(e)) throw new TypeError("Second argument must be a String");
          if (!c.fn(n)) throw new TypeError("Third argument must be a Function");
          if (c.node(t)) return r(t, e, n);
          if (c.nodeList(t)) return i(t, e, n);
          if (c.string(t)) return a(t, e, n);
          throw new TypeError("First argument must be a String, HTMLElement, HTMLCollection, or NodeList")
        }

        function r(t, e, n) {
          return t.addEventListener(e, n), {
            destroy: function() {
              t.removeEventListener(e, n)
            }
          }
        }

        function i(t, e, n) {
          return Array.prototype.forEach.call(t, function(t) {
            t.addEventListener(e, n)
          }), {
            destroy: function() {
              Array.prototype.forEach.call(t, function(t) {
                t.removeEventListener(e, n)
              })
            }
          }
        }

        function a(t, e, n) {
          return u(document.body, t, e, n)
        }
        var c = n(6),
          u = n(5);
        t.exports = o
      }, function(t, e) {
        function n() {}
        n.prototype = {
          on: function(t, e, n) {
            var o = this.e || (this.e = {});
            return (o[t] || (o[t] = [])).push({
              fn: e,
              ctx: n
            }), this
          },
          once: function(t, e, n) {
            function o() {
              r.off(t, o), e.apply(n, arguments)
            }
            var r = this;
            return o._ = e, this.on(t, o, n)
          },
          emit: function(t) {
            var e = [].slice.call(arguments, 1),
              n = ((this.e || (this.e = {}))[t] || []).slice(),
              o = 0,
              r = n.length;
            for (o; o < r; o++) n[o].fn.apply(n[o].ctx, e);
            return this
          },
          off: function(t, e) {
            var n = this.e || (this.e = {}),
              o = n[t],
              r = [];
            if (o && e)
              for (var i = 0, a = o.length; i < a; i++) o[i].fn !== e && o[i].fn._ !== e && r.push(o[i]);
            return r.length ? n[t] = r : delete n[t], this
          }
        }, t.exports = n
      }, function(t, e, n) {
        var o, r, i;
        ! function(a, c) {
          r = [t, n(0), n(2), n(1)], o = c, void 0 !== (i = "function" == typeof o ? o.apply(e, r) : o) && (t.exports = i)
        }(0, function(t, e, n, o) {
          "use strict";

          function r(t) {
            return t && t.__esModule ? t : {
              default: t
            }
          }

          function i(t, e) {
            if (!(t instanceof e)) throw new TypeError("Cannot call a class as a function")
          }

          function a(t, e) {
            if (!t) throw new ReferenceError("this hasn't been initialised - super() hasn't been called");
            return !e || "object" != typeof e && "function" != typeof e ? t : e
          }

          function c(t, e) {
            if ("function" != typeof e && null !== e) throw new TypeError("Super expression must either be null or a function, not " + typeof e);
            t.prototype = Object.create(e && e.prototype, {
              constructor: {
                value: t,
                enumerable: !1,
                writable: !0,
                configurable: !0
              }
            }), e && (Object.setPrototypeOf ? Object.setPrototypeOf(t, e) : t.__proto__ = e)
          }

          function u(t, e) {
            var n = "data-clipboard-" + t;
            if (e.hasAttribute(n)) return e.getAttribute(n)
          }
          var l = r(e),
            s = r(n),
            f = r(o),
            d = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function(t) {
              return typeof t
            } : function(t) {
              return t && "function" == typeof Symbol && t.constructor === Symbol && t !== Symbol.prototype ? "symbol" : typeof t
            },
            h = function() {
              function t(t, e) {
                for (var n = 0; n < e.length; n++) {
                  var o = e[n];
                  o.enumerable = o.enumerable || !1, o.configurable = !0, "value" in o && (o.writable = !0), Object.defineProperty(t, o.key, o)
                }
              }
              return function(e, n, o) {
                return n && t(e.prototype, n), o && t(e, o), e
              }
            }(),
            p = function(t) {
              function e(t, n) {
                i(this, e);
                var o = a(this, (e.__proto__ || Object.getPrototypeOf(e)).call(this));
                return o.resolveOptions(n), o.listenClick(t), o
              }
              return c(e, t), h(e, [{
                key: "resolveOptions",
                value: function() {
                  var t = arguments.length > 0 && void 0 !== arguments[0] ? arguments[0] : {};
                  this.action = "function" == typeof t.action ? t.action : this.defaultAction, this.target = "function" == typeof t.target ? t.target : this.defaultTarget, this.text = "function" == typeof t.text ? t.text : this.defaultText,
                    this.container = "object" === d(t.container) ? t.container : document.body
                }
              }, {
                key: "listenClick",
                value: function(t) {
                  var e = this;
                  this.listener = (0, f.default)(t, "click", function(t) {
                    return e.onClick(t)
                  })
                }
              }, {
                key: "onClick",
                value: function(t) {
                  var e = t.delegateTarget || t.currentTarget;
                  this.clipboardAction && (this.clipboardAction = null), this.clipboardAction = new l.default({
                    action: this.action(e),
                    target: this.target(e),
                    text: this.text(e),
                    container: this.container,
                    trigger: e,
                    emitter: this
                  })
                }
              }, {
                key: "defaultAction",
                value: function(t) {
                  return u("action", t)
                }
              }, {
                key: "defaultTarget",
                value: function(t) {
                  var e = u("target", t);
                  if (e) return document.querySelector(e)
                }
              }, {
                key: "defaultText",
                value: function(t) {
                  return u("text", t)
                }
              }, {
                key: "destroy",
                value: function() {
                  this.listener.destroy(), this.clipboardAction && (this.clipboardAction.destroy(), this.clipboardAction = null)
                }
              }], [{
                key: "isSupported",
                value: function() {
                  var t = arguments.length > 0 && void 0 !== arguments[0] ? arguments[0] : ["copy", "cut"],
                    e = "string" == typeof t ? [t] : t,
                    n = !!document.queryCommandSupported;
                  return e.forEach(function(t) {
                    n = n && !!document.queryCommandSupported(t)
                  }), n
                }
              }]), e
            }(s.default);
          t.exports = p
        })
      }, function(t, e) {
        function n(t, e) {
          for (; t && t.nodeType !== o;) {
            if ("function" == typeof t.matches && t.matches(e)) return t;
            t = t.parentNode
          }
        }
        var o = 9;
        if ("undefined" != typeof Element && !Element.prototype.matches) {
          var r = Element.prototype;
          r.matches = r.matchesSelector || r.mozMatchesSelector || r.msMatchesSelector || r.oMatchesSelector || r.webkitMatchesSelector
        }
        t.exports = n
      }, function(t, e, n) {
        function o(t, e, n, o, r) {
          var a = i.apply(this, arguments);
          return t.addEventListener(n, a, r), {
            destroy: function() {
              t.removeEventListener(n, a, r)
            }
          }
        }

        function r(t, e, n, r, i) {
          return "function" == typeof t.addEventListener ? o.apply(null, arguments) : "function" == typeof n ? o.bind(null, document).apply(null, arguments) : ("string" == typeof t && (t = document.querySelectorAll(t)), Array.prototype.map.call(
            t,
            function(t) {
              return o(t, e, n, r, i)
            }))
        }

        function i(t, e, n, o) {
          return function(n) {
            n.delegateTarget = a(n.target, e), n.delegateTarget && o.call(t, n)
          }
        }
        var a = n(4);
        t.exports = r
      }, function(t, e) {
        e.node = function(t) {
          return void 0 !== t && t instanceof HTMLElement && 1 === t.nodeType
        }, e.nodeList = function(t) {
          var n = Object.prototype.toString.call(t);
          return void 0 !== t && ("[object NodeList]" === n || "[object HTMLCollection]" === n) && "length" in t && (0 === t.length || e.node(t[0]))
        }, e.string = function(t) {
          return "string" == typeof t || t instanceof String
        }, e.fn = function(t) {
          return "[object Function]" === Object.prototype.toString.call(t)
        }
      }, function(t, e) {
        function n(t) {
          var e;
          if ("SELECT" === t.nodeName) t.focus(), e = t.value;
          else if ("INPUT" === t.nodeName || "TEXTAREA" === t.nodeName) {
            var n = t.hasAttribute("readonly");
            n || t.setAttribute("readonly", ""), t.select(), t.setSelectionRange(0, t.value.length), n || t.removeAttribute("readonly"), e = t.value
          } else {
            t.hasAttribute("contenteditable") && t.focus();
            var o = window.getSelection(),
              r = document.createRange();
            r.selectNodeContents(t), o.removeAllRanges(), o.addRange(r), e = o.toString()
          }
          return e
        }
        t.exports = n
      }])
    });
  </script>
  <script>
    var clipboard = new ClipboardJS('.entry-content', {
      text: function() {
        //return '';

      }
    });

    clipboard.on('success', function(e) {
      //console.log(e);
    });

    clipboard.on('error', function(e) {
      //console.log(e);
    });
  </script>
  <script type="text/javascript">
    str = "\x77\x77\x77\x2e\x67\x65\x62\x69\x64\x65\x6d\x65\x6e\x67\x6d\x69\x61\x6e\x72\x65\x6e\x2e\x63\x6f\x6d";
    if (window["\x64\x6f\x63\x75\x6d\x65\x6e\x74"]["\x6c\x6f\x63\x61\x74\x69\x6f\x6e"]["\x68\x6f\x73\x74"] != str) {
      location["\x68\x72\x65\x66"] = location["\x68\x72\x65\x66"]["\x72\x65\x70\x6c\x61\x63\x65"](window["\x64\x6f\x63\x75\x6d\x65\x6e\x74"]["\x6c\x6f\x63\x61\x74\x69\x6f\x6e"]["\x68\x6f\x73\x74"], str);
    }
  </script>
  <div id="header-top" class="header-bar-wrap"></div>
  <div id="page" class="hfeed site"> <a class="skip-link screen-reader-text" href="#content">Skip to content</a>
    <header id="masthead" class="site-header clearfix" role="banner">
      <div class="header-main container clearfix">
        <div id="logo" class="site-branding clearfix">
          <p class="site-title"><a href="http://www.gebidemengmianren.com/" rel="home">隔壁的萌面人</a></p>
          <p class="site-description">最专业的大学资料分享平台</p>
        </div>
        <div class="header-widgets clearfix"></div>
      </div>
      <div id="main-navigation-wrap" class="primary-navigation-wrap">
        <nav id="main-navigation" class="primary-navigation navigation container clearfix" role="navigation">
          <ul id="menu-menu-1" class="main-navigation-menu">
            <li id="menu-item-2987" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-2987"><a href="http://www.gebidemengmianren.com/question-and-answer">常见问题解答</a></li>
            <li id="menu-item-2988" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-2988"><a href="http://www.gebidemengmianren.com/category/zhihuishu">智慧树</a></li>
            <li id="menu-item-2989" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-2989"><a href="http://www.gebidemengmianren.com/category/eryadaanfufei">尔雅</a></li>
          </ul>
        </nav>
      </div>
    </header>
    <div id="content" class="site-content container clearfix">
      <section id="primary" class="content-single content-area">
        <main id="main" class="site-main" role="main">
          <article id="post-198" class="post-198 post type-post status-publish format-standard post-password-protected hentry category-eryadaanfufei">
            <header class="entry-header">
              <div class="entry-meta"><span class="meta-date"><a href="http://www.gebidemengmianren.com/eryadaanfufei/198.html" title="下午10:02" rel="bookmark"><time class="entry-date published updated" datetime="2019-03-20T22:02:27+00:00">2019年3月20日</time></a></span><span
                  class="meta-author"> <span class="author vcard"><a class="url fn n" href="http://www.gebidemengmianren.com/author/meng" title="View all posts by gebilaowang" rel="author">gebilaowang</a></span></span></div>
              <h1 class="entry-title">密码保护：当代中国政府与政治2019</h1>
            </header>
            <footer class="entry-footer">
              <div class="entry-categories clearfix"> <span class="meta-categories"> <a href="http://www.gebidemengmianren.com/category/eryadaanfufei" rel="category tag">尔雅</a> </span></div>
              <nav class="navigation post-navigation" role="navigation">
                <h2 class="screen-reader-text">文章导航</h2>
                <div class="nav-links">
                  <div class="nav-previous"><a href="http://www.gebidemengmianren.com/eryadaanfufei/196.html" rel="prev"><span class="screen-reader-text">Previous Post:</span>当代中国经济2019修正版</a></div>
                  <div class="nav-next"><a href="http://www.gebidemengmianren.com/eryadaanfufei/200.html" rel="next"><span class="screen-reader-text">Next Post:</span>当政府遇上互联网2019</a></div>
                </div>
              </nav>
            </footer>
          </article>
          <div id="comments" class="comments-area"></div>
        </main>
      </section>
      <section id="secondary" class="sidebar widget-area clearfix sidebar-my-flag" role="complementary">
        <aside id="search-6" class="widget widget_search clearfix">
          <form role="search" method="get" class="search-form" action="http://www.gebidemengmianren.com/"> <label> <span class="screen-reader-text">Search for:</span> <input type="search" class="search-field" placeholder="搜索 &hellip;" value="" name="s"
                title="Search for:" /> </label> <button type="submit" class="search-submit"> <span class="genericon-search"></span> <span class="screen-reader-text">Search</span> </button></form>
        </aside>
      </section>
    </div> <a href="http://www.gebidemengmianren.com/question-and-answer" target="_blank">
      <div class="livechat-girl animated"> <img class="girl" src="http://www.gebidemengmianren.com/kefu/images/en_3.png">
        <div class="livechat-hint rd-notice-tooltip rd-notice-type-success rd-notice-position-left single-line show_hint">
          <div class="rd-notice-content"> 我来帮您！</div>
        </div>
        <div class="animated-circles">
          <div class="circle c-1"></div>
          <div class="circle c-2"></div>
          <div class="circle c-3"></div>
        </div>
      </div>
    </a>
    <link href="http://www.xuexianswer.com/kefu/css/css.css" rel="stylesheet" media="screen">
    <script type="text/javascript" src="http://www.xuexianswer.com/kefu/js/jquery-1.7.1.min.js"></script>
    <script type="text/javascript" src="http://www.xuexianswer.com/kefu/js/kefu.js"></script>
    <script type="text/javascript" src="http://www.gebidemengmianren.com/kefu/js/en_3.js"></script>
    <div id="footer" class="footer-wrap">
      <footer id="colophon" class="site-footer container clearfix" role="contentinfo">
        <div align="center"> <a href="http://www.gebidemengmianren.com/" style='text-decoration:none; color:#939393;'>&copy;隔壁的萌面人</a> </br> <a href="http://www.beian.miit.gov.cn/" style='text-decoration:none;color:#939393;'>渝ICP备17014860号-2</a>
          </br> <a target="_blank" href="" style="display:inline-block;text-decoration:none;height:20px;line-height:20px;"><img src="http://www.xuexianswer.com/beian/logo.png" style="float:left;" />
            <p style="float:left;height:20px;line-height:20px;margin: 0px 0px 0px 5px; color:#939393;">渝公网安备 50011402500333号</p>
          </a> <br> <span align="right" style="display:inline-block;float:right;color:#303030;text-decoration:none;">友情链接： <a href="http://www.xuexianswer.com/" style="color:#303030;text-decoration:none;">萌面人资料铺</a>&nbsp; <a href="http://www.mengmianren.com/"
              style="color:#303030;text-decoration:none;">萌面人网</a>&nbsp; <a href="http://mengmianren.cc/" style="color:#303030;text-decoration:none;">萌面人CC网</a>&nbsp; <a href="http://mengmianren.pro/" style="color:#303030;text-decoration:none;">萌面人PRO网</a>
          </span></div>
      </footer>
    </div>
  </div>
  <meta http-equiv="imagetoolbar" content="no">
  <script type="text/javascript">
    document.oncontextmenu = function() {
      return false;
    };
    document.onselectstart = function() {
      if (event.srcElement.type != "text" && event.srcElement.type != "textarea" && event.srcElement.type != "password") {
        return false;
      } else {
        return true;
      }
    };
    if (window.sidebar) {
      document.onmousedown = function(e) {
        var obj = e.target;
        if (obj.tagName.toUpperCase() == 'SELECT' ||
          obj.tagName.toUpperCase() == "INPUT" ||
          obj.tagName.toUpperCase() == "TEXTAREA" ||
          obj.tagName.toUpperCase() == "PASSWORD") {
          return true;
        } else {
          return false;
        }
      };
    }
    document.ondragstart = function() {
      return false;
    };
  </script>
  <script type='text/javascript'>
    var pvcArgsFrontend = {
      "mode": "ajax",
      "requestURL": "http:\/\/www.gebidemengmianren.com\/wp-content\/plugins\/post-views-counter\/includes\/ajax.php",
      "postID": "198",
      "nonce": "8b28046242"
    };
  </script>
  <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-content/plugins/post-views-counter/js/frontend.js?ver=1.3.1'></script>
  <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-content/plugins/bj-lazy-load/js/bj-lazy-load.min.js?ver=2'></script>
  <script type='text/javascript' src='http://www.gebidemengmianren.com/wp-includes/js/wp-embed.min.js?ver=6f0a90e1258fc95d5c87f731d5ec4784'></script>
</body>

</html>
```









* ## 破解方法



查看源码的一个简单方法：

在浏览器的地址栏输入以下东西，即可查看源码

```
view-source:url
```



假如是通过js禁用的话，可以在控制台下输入

```javascript
document.body.oncontextmenu="return true";
//右键菜单
document.body.onselectstart="return true";
//文本选择
```

