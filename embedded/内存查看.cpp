#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 被检测的函数
void controlRelay() { 
}

// 内存信息查看
void callPrintMemoryInfo(int triggerOBJ, const char* FuncOBJ) {
  bool currentButtonState = (digitalRead(triggerOBJ) == LOW);
  if (currentButtonState && !buttonPressed) {  // 设置内存查看条件
    Serial.println(String(FuncOBJ) + " 任务栈剩余内存: " + String(uxTaskGetStackHighWaterMark(NULL)));  // 检查当前任务剩余内存
    // Serial.println(". 总堆内存: " + String(ESP.getHeapSize()) + ", 剩余堆内存: " + String(ESP.getFreeHeap()));  // 打印系统的总内存和剩余内存
    buttonPressed = true;
  } else if (!currentButtonState && buttonPressed) {
    buttonPressed = false;
  }
}

void setup() {
}

void loop() {
  callPrintMemoryInfo(1, "controlRelay");  // 放触发IO(可改为条件)、检测函数名；
}
