# 目录
- [一、基础标签](#基础标签)
  - [1. div标签](#div)
  - [2. input标签](#input)
  - [3. img标签](#img)
- [二、基础应用](#基础应用)
  - [1. HTML应用CSS](#HTML应用CSS)
    - [1.1 类名选择器](#类名选择器)
- [三、常用CSS样式](#常用CSS样式)
  - [1. 渐变](#渐变)
  - [2. 字体](#字体)

<a name="基础标签"></a>
### 基础标签
<a name="div"></a>
#### 盒子标签（div）
```html
<div><div>
```
|<div align="center">属性补全</div>|作用|示例|备注|
|:---------------------------------|:---:|:----:|:-----:|
|`width`|宽度|`width: 100px;`|盒子宽度为100px|
|`height`|高度|`height: 100px;`|盒子高度为100px|
|`background-color`|背景颜色|`background-color: red;`、`background-color: #f00;`|设置盒子背景颜色|
|`margin`|全向边距|`margin: 10px;`、`margin: 10px 20px 30px 40px`|盒子的全向外部距离|
|`margin-top`|上外边距|`margin-top: 10px;`|盒子距离顶部10px|
|`margin-bottom`|下外边距|`margin-bottom: 10px;`|盒子距离底部10px|
|`margin-left`|左外边距|`margin-left: 10px;`|盒子距离左部10px|
|`margin-right`|右外边距|`margin-right: 10px;`|盒子距离右部10px|
|`padding`|全向内边距|用法与margin一致||
|`border-raduis`|圆角|`border-raduis: 10px;`|绘制四个角均为10px的圆角，可以通过类似margin的方式设置4个角不同的圆弧度，50%为圆形|
> 注意：在分辨率不固定的情况下，可以采用%为单位替代px。
<a name="input"></a>
#### 输入与选择标签（input）
```html
<input type="输入类型">
```
| <div align="center"> type属性补全 </div>  |       作用      |     备注属性     |
|:-----------------|:------------------:|:----------------------------------:|
| `type="text"`     | 单行文本输入       |                                    |
| `type="password"` | 密码输入           |                                    |
| `type="email"`    | 邮件输入           |                                    |
| `type="number"`   | 数字输入           | `min="最小值"` `max="最大值"`      |
| `type="date"`     | 日期选择           |                                    |
| `type="checkbox"` | 复选               | `value="yes"`: 携带name的值送入后端|
| `type="radio"`    | 单选               | 每个radio需设置不同的`value`       |
| `type="submit"`   | 提交               | `value="提交按钮示意文字"`         |
| `type="reset"`    | 重置               | `value="重置按钮示意文字"`         |
| `type="button"`   | 按钮               | `value="按钮示意文字"` `onclick="触发JS代码"` |
| `type="file"`     | 文件上传           |                                    |
| `type="hidden"`   | 隐藏输入           | `value="默认值"`                   |
| `type="color"`    | 颜色选择器         |                                    |
| `type="range"`    | 滑动条             | `min="最小值"` `max="最大值"`      |
| `type="search"`   | 搜索框             |                                    |
| `type="tel"`      | 电话输入           |                                    |
| `type="url"`      | 网址输入           |                                    |
<a name="img"></a>
#### 图片标签（img）
```html
<img src="图片路径" alt="替代文本">
```
|属性补全| 作用 |示例|备注|
|:------|:---:|:---:|:---:|
|`src`|图片路径/地址|`src="images/logo.png"`|调用指定路径的图片文件|
|`alt`|替代文本|`alt="提示文"`|未能完全加载时替换文本与SEO|
|`width`|宽度像素|`width="800"`|图片宽度为800px|
|`height`|高度像素|`height="600"`|高度像素为600px|
|`title`|悬停提示|`title="示意图"`|鼠标位于上方时显示|
|`srcset`|多图片候选|`srcset="s.jpg 480w, m.jpg 800w, l.jpg 1200w"`|在不同宽度的情况下调用不同的图片|
|`sizes`|响应式图片显示宽度|`sizes="(max-width: 600px) 100vw, 800px"`|在屏幕≤600px时，图片宽度占满，否则固定800px|
<a name="基础应用"></a>
### 基础应用
<a name="HTML应用CSS"></a>
#### HTML应用CSS
<a name="类名选择器"></a>
##### 应用class类名选择器：
```html
<body>
  /* 被作用标签为div，使用class调用box样式 */
  <div class="box"></div>
  <div class="box2"></div>
  /* 在style内使用"."符号创建名为box样式的class选择器 */
  <style>
    .box {
      width: 100px;
      height: 100px;
    }
  </style>
</body>
```
<a name="常用CSS样式"></a>
### 常用CSS样式
<a name="渐变"></a>
#### 渐变
##### 线性渐变
```css
/* purple, blue, cyan三色渐变，可以自定义多色或更少色，可以使用#十六进制或rgb/rgba */
background: linear-gradient(to right, purple, blue, cyan);
```
<a name="字体"></a>
#### 字体
|字体设置|说明|示例|备注|
|-------|----|----|----|
|`font-family`|字体类型|`font-family: "Helvetica Neue", Arial, sans-serif;`|依次设置字体类型|
|`font-size`|字体大小|`font-size: 2rem;`|设置字体大小为2rem，1rem=16px|
|`font-weight`|字体粗细|`font-weight: normal;`、`font-weight: bold;`|设置字体类型，normal(默认)、bold(加粗)|
|`color`|字体颜色|`color: #FF0000;`|字体颜色设置为#FF0000|
|`line-height`|行间距|`line-height: 1.6`|行高/间距设置为1.6倍|
