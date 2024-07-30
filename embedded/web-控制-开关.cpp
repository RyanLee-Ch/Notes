#include <WebServer.h>

const char* GPIO1_ON_PATH = "/gpio1/on";  // 定义 路由1 , 该路由被访问后，经server.on触发修改 1端 为高电平状态
const char* GPIO1_OFF_PATH = "/gpio1/off";  // 定义 路由2 , 该路由被访问后，经server.on触发修改 1端 为低电平状态

void setup() {
  Serial.begin(115200); // 初始化串口通信
  // 该部分需要wifi连接支持，之后通过访问板子 http://ip地址 局域网连接控制
  startWebServer();  // 启用web服务
}

void loop() {
  server.handleClient();  // 循环应用
}

// 启动Web服务器函数
void flushHTML() {  // 编写、刷新HTML
  String html = "<html><head><meta charset=\"UTF-8\"></head><body><h1>连接控制测试</h1>";  // 首行声明
  html += "<p>1端<a href=\"" + String(GPIO1_ON_PATH) + "\"> 启用 </a> <a href=\"" + String(GPIO1_OFF_PATH) + "\"> 停用 </a></p>";  // 编写超链接，访问后调用对应的server.on()，通过digitalWrite修改对应 端口 的状态
  html += "<p>1端 状态: " + String(digitalRead(1) == LOW ? "开" : "关") + "</p>";  // 通过digitalRead访问电平状态，通过三元运算替换显示信息为"开"或"关"
  html += "</body></html>";
  server.send(200, "text/html", html);  // HTML发送至浏览器
}
void startWebServer() {  // 配置点击逻辑
  pinMode(1, OUTPUT);  // 定义1口为输出
  digitalWrite(1, HIGH);  // （初始）定义1口为高电平（根据板子的触发状态决定）
  server.on("/", flushHTML);  // 写入HTML页面
  server.on(GPIO1_ON_PATH, []() { digitalWrite(1, LOW); flushHTML(); });  // 1端 高电平路由访问后，触发digitalWrite（测试环境下继电器为低电平ON）
  server.on(GPIO1_OFF_PATH, []() { digitalWrite(1, HIGH); flushHTML(); });  // 1端 低电平路由访问后，触发digitalWrite（测试环境下继电器为低电平ON）
  server.begin();  // 启用 web 服务器
  Serial.println("Web server started.");
}
