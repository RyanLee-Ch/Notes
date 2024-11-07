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
  UBaseType_t stackUsage = uxTaskGetStackHighWaterMark(NULL);
  Serial.print(functionName);
  Serial.print(" Stack high water mark: ");
  Serial.println(stackUsage);
  // 打印系统的总内存和剩余内存
  size_t totalMemory = ESP.getHeapSize();
  size_t freeMemory = ESP.getFreeHeap();
  Serial.print("Total heap memory: ");
  Serial.println(totalMemory);
  Serial.print("Free heap memory: ");
  Serial.println(freeMemory);
}

void setup() {
}

void loop() {
  printMemoryInfo();
}
