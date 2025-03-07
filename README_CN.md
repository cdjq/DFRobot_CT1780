DFRobot_CT1780
===========================

- [英文版](./README.md)

数字K型高温传感器

![产品效果图片](./resources/images/DFRobot_CT1780.png)


## 产品链接（https://www.dfrobot.com.cn）

    SKU：SEN0652

## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

数字K型高温传感器

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。
本库依赖OneWire库，使用此库前，请先安装OneWire。安装方式：在Arduino IDE → Tools → Manage Libraries下搜索Onewire并下载。

## 方法

```C++
/**
 * @fn: begin
 * @brief: 初始化对象
 * @return: 初始化成功返回1，初始化失败返回0
 */
int begin();

/**
 * @fn: getCelsius
 * @brief: 读取探头温度数据
 * @return: float 温度值（单位：摄⽒度）
 */
float getCelsius();

/**
 * @fn: getUniqueAddr()
 * @brief: 获取CT1780的64位唯⼀地址
 * @return: 地址数据（数组），失败返回NULL
 */
uint8_t* getUniqueAddr();


/**
 * @fn: getConfigAddr()
 * @brief: 获取CT1780的⽤⼾配置地址（在ScratchPad中）
 * @return: 地址数据,失败返回-1
 */
int getConfigAddr();
```
## 兼容性
MCU                | Work Well    | Work Wrong   |   Untested   |
------------------ | :----------: | :----------: | :----------: | 
Arduino Uno        |      √       |              |              |
Mega2560           |      √       |              |              |
Leonardo           |      √       |              |              |
ESP32              |      √       |              |              |
ESP8266            |      √       |              |              |
micro:bit          |      √       |              |              |
FireBeetle M0      |      √       |              |              |

## 历史

- 2025/03/07 -1.0.0 版本.

## 创作者

作者：fary（feng.yang@dfrobot.com）， 2025年。（欢迎浏览我们的[网站](https://www.dfrobot.com/)）





