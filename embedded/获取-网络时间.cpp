#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const char *ssid     = "Celitron";  // Wi-Fi名
const char *password = "Celitron2022";  // Wi-Fi密码
WiFiUDP ntpUDP;  // NTP客户端设置
NTPClient timeClient(ntpUDP, "pool.ntp.org", 8*3600, 60000); // 时区为UTC+1（3600秒），每分钟更新一次

void setup() {
  initializeTime();  // 初始化时间
}

void loop() {
  getTime();  // 获取时间
}


// 时间函数：
void initializeTime() {  // 初始化时间
  Serial.begin(115200);
  WiFi.begin(ssid, password);  // 连接到Wi-Fi网络
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  timeClient.begin();  // // 初始化NTP客户端
}
void getTime() {  // 获取时间
  timeClient.update();  // 更新NTP客户端
  Serial.print("Current time: ");  // 获取当前时间并打印到串行监视器
  Serial.println(timeClient.getFormattedTime());
  delay(1000); // 每秒获取一次时间
}
