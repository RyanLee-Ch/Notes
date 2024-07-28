#include <OneWire.h>  // 引入单总线传感器通信库
#include <DallasTemperature.h>  // 引入Dallas传感器库

#define ONE_WIRE_BUS 5  // 定义单总线传感器接入口为 5口

OneWire oneWire(ONE_WIRE_BUS);  // 标志传感器为单总线
DallasTemperature sensors(&oneWire);  // 标志传感器为单总线通信

void setup() {
  Serial.begin(115200);  // 启动115200串行通信，用于IDE监测
  sensors.begin();  // 启用通信
}

void loop() {
  float currentTemperature = readTemp();  // 调用读温感函数，存值
}

void readTemp() {
  delay(1000);  // 每秒读取一次
  sensors.requestTemperatures();  // 请求所有传感器测量温度
  Serial.println("Temperature: " + String(sensors.getTempCByIndex(0)) + " *C");  // 将第0个温感的值打印至115200监测口
  return sensors.getTempCByIndex(0);  // 返回第0个温感值
}
