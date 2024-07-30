#include <WiFi.h>  // 导入wifi库

const char* ssid = "Celitron";  // wifi名称
const char* password = "Celitron2022";  // wifi密码

void setup() {
  connWifi();
}

void loop() {
}

// wifi函数
void connWifi() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
