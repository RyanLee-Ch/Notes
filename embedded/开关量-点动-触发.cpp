#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 点动函数
void setUpButton() {  // 定义按钮程序入口
  initializeButton(1, 11);  // 定义初始化情况：1入 2出
}
void loopButton() {  // 定义程序出口
  controlRelay(1, 11);  // 调用触发函数，1入, 2点动执行
}
void initializeButton(int inputPort, int outputPort) {  // 针脚初始化(输入针脚、输出针脚、输出针脚默认电平状态)
  pinMode(inputPort, INPUT_PULLUP), pinMode(outputPort, OUTPUT), digitalWrite(outputPort, HIGH);
}
void controlRelay(int buttonPin, int relayPin) {  // 控制继电器并打印内存信息
  if (digitalRead(buttonPin) == HIGH) {  // 检测按钮摁下则点动（按下时LOW）
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
  }
}


void setup() {  // 定义多线程任务
  Serial.begin(115200);
  while (!Serial) { };  // 等待串口连接
  xTaskCreate(  // 点动函数多线程
    buttonTask,  // 引用多线程任务对象
    "Button Task",  // 多线程名定义
    1200,  // 栈大小
    NULL,  
    1,  // 任务优先级
    NULL
    );  
}

void buttonTask(void *pvParameters) {  // 多线程setup、loop
  Serial.println("Starting " + String(__FUNCTION__));
  setUpButton();  // setup
  while (true) {
    loopButton();  // loop
    vTaskDelay(pdMS_TO_TICKS(100));  // LOOP短暂延时循环，避免任务占用过多资源
  }
}

void loop() {
  // 主循环不执行任何操作
}
