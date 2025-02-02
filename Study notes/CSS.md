# 目录
- [第一：基础标签](#基础标签)
- []

<a name="基础标签">

#### 基础标签
##### 输入与选择标签

```html
<input type="输入类型">
```

| <div align="center"> 属性补全 </div>          | 作用               | 备注属性                            |
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
