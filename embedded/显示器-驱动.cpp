#include <Wire.h>  // 导入IIC通信库
#include <Adafruit_GFX.h>  // 导入绘图库
#include <Adafruit_SSD1306.h>  // 导入SSD1306绘图库，SSD1306具有泛用性
#define SCREEN_WIDTH 128  // 定义屏幕的宽度
#define SCREEN_HEIGHT 64  // 定义屏幕的高度
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);  // 声明一个Adafruit_SSD1306对象
#define OLED_SDA 47  // 自定义I2C.SDA引脚为 47口 
#define OLED_SCL 48  // 自定义I2C.SDA引脚为 47口 
unsigned long previousMillis = 0;  // 记录上次显示更新的时间
const long interval = 500;  // 显示更新间隔时间（毫秒），刷新太快会影响性能，如果实在有过高的性能要求，可以采用多线程方案
String displayContent = "hello";  // 全局变量来保存显示内容

void setup() {
  initializeDisplay();  // 显示器初始化
}

void loop() {
  executeDisplay(String("Hello, World"));  // 执行显示显示内容
}


// 显示器函数
void initializeDisplay() {  // 定义显示器初始化函数
  Serial.begin(115200);  // 初始化串行通信
  Wire.begin(OLED_SDA, OLED_SCL);  // 初始化I2C通信，使用自定义的SDA和SCL引脚
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 初始化OLED显示屏，0x3C 是OLED显示器的I2C地址
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();  // 清空显示屏缓冲区
  display.setTextColor(SSD1306_WHITE);  // 设置文本颜色为白色
  display.setTextSize(2);  // 设置文本大小
}
void updateDisplay() {  // 定义更新显示函数
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {  // 检查是否达到更新间隔时间
    previousMillis = currentMillis;  // 保存当前时间
    executeDisplay(String(displayContent));  // 更新显示内容
  }
}
void executeDisplay(String content) {  // 定义执行显示函数
  // ----这里是默认显示左上角----
  // display.clearDisplay();  // 清空显示屏缓冲区
  // display.setTextColor(SSD1306_WHITE);  // 设置文本颜色为白色
  // display.setTextSize(1);  // 设置文本大小
  // display.setCursor(0, 0);  // 设置文本位置
  // display.println(content);  // 显示文本
  // display.display();  // 显示缓冲区内容
  // ----这里是默认显示正中央----
  display.clearDisplay();  // 清空显示屏缓冲区
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(content, 0, 0, &x1, &y1, &w, &h);  // 获取文本边界
  int16_t x = (SCREEN_WIDTH - w) / 2;  // 计算文本起始X位置
  int16_t y = (SCREEN_HEIGHT - h) / 2;  // 计算文本起始Y位置
  display.setCursor(x, y);  // 设置文本位置
  display.println(content);  // 显示文本
  display.display();  // 显示缓冲区内容
}

