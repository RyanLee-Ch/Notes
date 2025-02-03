# 目录
- [一、基础标签](#基础标签)
  - [1.div标签](#div)
  - [2. input标签](#input)
  - [3. img标签](#img)

<a name="基础标签"></a>
#### 基础标签
<a name="div"></a>
##### 盒子标签（div）
```html
<div><div>
```
|<div align="center">属性补全</div>|作用|示例|备注|
|:---------------------------------|:---:|:----:|:-----:|
|`margin`|全向边距|`margin: 10px;`、`margin: 10px 20px 30px 40px`|盒子的全向外部距离|
|`margin-top`|上外边距|`margin-top: 10px;`|盒子距离顶部10px|
|`margin-bottom`|下外边距|`margin-bottom: 10px;`|盒子距离底部10px|
|`margin-left`|左外边距|`margin-left: 10px;`|盒子距离左部10px|
|`margin-right`|右外边距|`margin-right: 10px;`|盒子距离右部10px|
|`padding`|全向内边距|用法与margin一致|||

<a name="input"></a>
##### 输入与选择标签（input）
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
##### 图片标签（img）
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
