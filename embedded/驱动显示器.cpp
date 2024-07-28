#include <Wire.h>  // 导入IIC通信库
#include <Adafruit_GFX.h>  // 
#include <Adafruit_SSD1306.h>

// 定义屏幕的宽度和高度
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// 声明一个Adafruit_SSD1306对象
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// 自定义I2C引脚
#define OLED_SDA 47
#define OLED_SCL 48

void setup() {
  initializeDisplay();
}

void loop() {
  executeDisplay("Hello, World");  // 带入显示内容
}

void initializeDisplay() {
  Serial.begin(115200);  // 初始化串行通信
  Wire.begin(OLED_SDA, OLED_SCL);  // 初始化I2C通信，使用自定义的SDA和SCL引脚
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 初始化OLED显示屏，0x3C 是OLED显示器的I2C地址
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();  // 清空显示屏缓冲区
  display.setTextColor(SSD1306_WHITE);  // 设置文本颜色为白色
  display.setTextSize(1);  // 设置文本大小
}

void executeDisplay(String content) {
  display.clearDisplay();  // 清空显示屏缓冲区
  display.setTextColor(SSD1306_WHITE);  // 设置文本颜色为白色
  display.setTextSize(1);  // 设置文本大小
  display.setCursor(0, 0);  // 设置文本位置
  display.println(content);  // 显示文本
  display.display();  // 显示缓冲区内容
}

