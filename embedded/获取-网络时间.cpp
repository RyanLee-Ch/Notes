#include <WiFi.h>  // 导入wifi库
#include <WiFiUdp.h>  // 导入wifi的udp通信库
#include <NTPClient.h>  // 连接NTP服务器，获取时间

const char *ssid     = "Celitron";  // Wi-Fi名
const char *password = "Celitron2022";  // Wi-Fi密码
WiFiUDP ntpUDP;  // 配置Wifi与NTP服务器UDP通信
NTPClient timeClient(ntpUDP, "pool.ntp.org", 8*3600, 60000); // 连接UTC+8（3600秒）时区，每分钟更新一次

void setup() {
  initializeTime();  // 初始化时间
}

void loop() {
  String curTime = getTime();  // 获取时间
}


// 时间函数：
void initializeTime() {  // 初始化时间
  Serial.begin(115200);  // 启用监测口
  WiFi.begin(ssid, password);  // 连接到Wi-Fi网络
  while (WiFi.status() != WL_CONNECTED) {  // 等待wifi连接
    delay(500);  // 0.5秒检测一次是否成功连接
    Serial.print(".");  // 打印，尝试连接
  }
  Serial.println("");
  Serial.println("WiFi connected.");  // 打印Wi-Fi连接成功信息
  Serial.println("IP address: ");  // 打印"IP address:"字符串
  Serial.println(WiFi.localIP());  // 打印ESP32的IP地址
  timeClient.begin();  // // 初始化NTP客户端
}
void getTime() {  // 获取时间
  timeClient.update();  // 更新NTP客户端
  String formattedTime = timeClient.getFormattedTime();  // 获取格式化的时间字符串
  Serial.print("Current time: ");  // 打印当前时间到串行监视器
  Serial.println(formattedTime);
  return formattedTime;  // 返回格式化的时间字符串
  delay(1000); // 每秒获取一次时间
}
