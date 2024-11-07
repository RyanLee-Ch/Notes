void setup() {
  setUpButton();
}
void loop() {
  loopButton();
}

// 点动函数
void setUpButton() {
  initializeButton(1, 2);  // 定义初始化情况：1入 2出
}
void loopButton() {
  controlRelay(1, 2);  // 调用触发函数，1入, 2点动执行
}
void initializeButton(int inputPort, int outputPort) {  // 定义初始化情况
  pinMode(inputPort, INPUT_PULLUP);  // 设置 1口 为输入
  pinMode(outputPort, OUTPUT);  // 设置 2口 为输出
  digitalWrite(2, LOW);  // 设置 2口 默认为低电平0
}
void controlRelay(int buttonPin, int relayPin) {  // 定义触发函数
  delay(100);  // 抖动防止
  if (digitalRead(buttonPin) == HIGH) {  // 检测按钮摁下则点动
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
