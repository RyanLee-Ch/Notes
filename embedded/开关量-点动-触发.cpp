void setup() {
  pinMode(1, INPUT_PULLUP);  // 设置 1口 为输入
  pinMode(2, OUTPUT);  // 设置 2口 为输出
  digitalWrite(2, LOW);  // 设置 2口 默认为低电平0
}
void loop() {
  controlRelay(1, 2);  // 调用函数，1口入, 2口点动执行
  delay(100);  // 抖动防止
}
// 定义触发函数
void controlRelay(int buttonPin, int relayPin) {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
