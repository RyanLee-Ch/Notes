#include <WiFi.h>  // 导入wifi库

const char* ssid = "小宝贝";  // wifi名称
const char* password = "lyj3112424";  // wifi密码

void setup() {
  Serial.begin(115200);  // 连接检测器，可以在检测器中查看ip，然后通过http://ip地址访问，配合web服务应用
  connWifi();
}

void loop() {
}

// wifi函数
void connWifi() {
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to " + String(ssid) + "：");
  WiFi.begin(ssid, password);  // 开始连接WiFi
  while (WiFi.status() != WL_CONNECTED) {delay(1000);Serial.print("·");}
  Serial.print("\nWiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
}
