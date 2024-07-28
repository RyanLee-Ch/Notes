#include <Wire.h>  // 导入IIC通信库
#include <Adafruit_GFX.h>  // 导入绘图库
#include <Adafruit_SSD1306.h>  // 导入SSD1306绘图库，SSD1306具有泛用性

#define SCREEN_WIDTH 128  // 定义屏幕的宽度
#define SCREEN_HEIGHT 64  // 定义屏幕的高度

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);  // 声明一个Adafruit_SSD1306对象

#define OLED_SDA 47  // 自定义I2C.SDA引脚为 47口 
#define OLED_SCL 48  // 自定义I2C.SDA引脚为 47口 

void setup() {
  initializeDisplay();  // 显示器初始化
}

void loop() {
  executeDisplay("Hello, World");  // 执行显示显示内容
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
  display.setTextSize(1);  // 设置文本大小
}
void executeDisplay(String content) {  // 定义执行显示函数
  display.clearDisplay();  // 清空显示屏缓冲区
  display.setTextColor(SSD1306_WHITE);  // 设置文本颜色为白色
  display.setTextSize(1);  // 设置文本大小
  display.setCursor(0, 0);  // 设置文本位置
  display.println(content);  // 显示文本
  display.display();  // 显示缓冲区内容
}

