#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 示例被多线程执行函数1
void setUpButton() {  // 被setup函数
  initializeButton(1, 2);
}
void loopButton() {  // 被loop函数
  controlRelay(1, 2);
}
void initializeButton(int inputPort, int outputPort) {
  pinMode(inputPort, INPUT_PULLUP), pinMode(outputPort, OUTPUT), digitalWrite(outputPort, LOW);
}
void controlRelay(int buttonPin, int relayPin) {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
  }
}

// 内存信息打印函数（直接copy），触发后即可显示当前任务的内存使用量，以及系统总内存
void printMemoryInfo(const char* functionName) {
  // 检查当前任务的栈高水位标记
  Serial.print(String(functionName) + " Stack high water mark: " + String(uxTaskGetStackHighWaterMark(NULL)));
  // 打印系统的总内存和剩余内存
  Serial.println(". Total heap memory: " + String(ESP.getHeapSize()) + ", Free heap memory: " + String(ESP.getFreeHeap()));
}

// 多线程任务函数
void buttonTask(void *pvParameters) {  // 多线程setup、loop
  Serial.println("Starting " + String(__FUNCTION__));
  setUpButton();  // setup对象
  while (true) {
    loopButton();  // loop对象
    if (digitalRead(1) == LOW) {  // 设置内存查看条件
      printMemoryInfo(__FUNCTION__);  // 调用内存信息打印函数（放在函数主要资源消耗的位置）
    }
    vTaskDelay(pdMS_TO_TICKS(100));  // LOOP短暂延时循环，避免任务占用过多资源
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial) { };  // 等待串口连接
  xTaskCreate(  // 多线程任务创建
    buttonTask,  // 引用多线程任务对象
    "Button Task",  // 多线程名定义
    1200,  // 栈大小
    NULL,  
    1,  // 任务优先级
    NULL
    );  
}

void loop() {
  // 主循环不执行任何操作
}
