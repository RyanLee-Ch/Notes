#include <ESP32Servo.h>

Servo myservo;  // 声明舵机应用

const int RCW = 1;  // 顺时针 控制端
const int RCCW = 2;  // 逆时针 控制端
const int resetPin = 42;  // 复位 控制端
const int servoPin = 13;  // 舵机信号 连接端
int currentAngle = 0;  // 舵机初始化定义角度，并存储当前角度值
int activeInitializationAngle = 0;  // 定义主动复位角，一般与currentAngle相同

void setup() {
  initializeServo();  // 调用舵机初始化
}

void loop() {
  rotateServo();  // 调用舵机应用
}

// 舵机程序
void initializeServo() {  // 初始化舵机连接
  Serial.begin(115200);  // 初始化串口监视器
  myservo.setPeriodHertz(50);    // 标准舵机频率为50Hz
  myservo.attach(servoPin, 500, 2500); // 将舵机连接到指定的端口，设置最小和最大脉宽
  pinMode(RCW, INPUT_PULLUP);  // 启用内部上拉电阻
  pinMode(RCCW, INPUT_PULLUP);  // 启用内部上拉电阻
  pinMode(resetPin, INPUT_PULLUP);  // 启用内部上拉电阻
  myservo.write(currentAngle);  // 将舵机设置到初始化位置
  Serial.print("Initial Angle: " + String(currentAngle) + "\n");
}

void rotateServo() {  // 响应按钮
  if (digitalRead(RCW) == LOW) {  // 按钮1按下时状态为LOW
    currentAngle = max(currentAngle - 1, 0);  // 左转，角度减少，最小为0度
    myservo.write(currentAngle);
    Serial.print("Current Angle: ");
    Serial.println(currentAngle);  // 打印当前角度
  } else if (digitalRead(RCCW) == LOW) {  // 按钮2按下时状态为LOW
    currentAngle = min(currentAngle + 1, 180);  // 右转，角度增加，最大为180度
    myservo.write(currentAngle);
    Serial.print("Current Angle: ");
    Serial.println(currentAngle);  // 打印当前角度
  }
  if (digitalRead(resetPin) == LOW) {  // 复位按钮按下时状态为LOW
    myservo.write(activeInitializationAngle);
    Serial.print("Reset to Initial Angle: " + String(currentAngle) + "\n");  // 打印当前角度
    delay(1000);  // 添加延迟以避免重复复位
  }

  delay(5);  // 延迟5毫秒，角速度控制，不允许小于5，越大越慢
}
