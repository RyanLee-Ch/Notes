#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 被检测的函数
void controlRelay(int buttonPin, int relayPin) { 
  if (digitalRead(buttonPin) == LOW) { 
    digitalWrite(relayPin, HIGH);
    printMemoryInfo(__FUNCTION__);  // 调用内存查看函数
  } else {
    digitalWrite(relayPin, LOW);
  }
}

// 内存信息打印函数，触发后即可显示当前任务的内存使用量，以及系统总内存
void printMemoryInfo(const char* functionName) {
  // 检查当前任务的栈高水位标记
  Serial.println(String(functionName) + " Stack high water mark: " + String(uxTaskGetStackHighWaterMark(NULL)));
  // 打印系统的总内存和剩余内存
  Serial.println("Total heap memory: " + String(ESP.getHeapSize()) + "Free heap memory: " + String(ESP.getFreeHeap()));
}

void setup() {
}

void loop() {
  printMemoryInfo();
}
