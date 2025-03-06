DFRobot_CT1780
===========================

* [中文版](./README_CN.md)

1-Wire High Temperature Sersor (K-type)

![产品效果图片](../../resources/images/CT1780.png)
  
## Product Link (https://www.dfrobot.com)
    SKU: SEN0652

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Credits](#credits)

## Summary

1-Wire High Temperature Sersor (K-type)

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.
This library depends on the OneWire library. Please install OneWire before using this library.
## Methods

```C++
/**
 * @fn: begin
 * @brief: Initialize object
 * @return: 1 is returned if initialization succeeds, 0 is returned if initialization fails
 */
int begin();

/**
 * @fn: getCelsius
 * @brief: Read probe temperature data
 * @return: float Temperature value (in degrees Celsius)
 */
float getCelsius();

/**
 * @fn: getUniqueAddr()
 * @brief: Gets the 64-bit unique address of CT1780
 * @return: Address data (array)
*/
uint8_t* getUniqueAddr();


/**
 * @fn: getConfigAddr()
 * @brief: Get the user-configured address of CT1780 (in ScratchPad)
 * @return: address data
 */
uint8_t getConfigAddr();

```

## Compatibility

MCU                | Work Well    | Work Wrong   |   Untested   |
------------------ | :----------: | :----------: | :----------: | 
Arduino Uno        |      √       |              |              |
Mega2560           |      √       |              |              |
Leonardo           |      √       |              |              |
ESP32              |      √       |              |              |
ESP8266            |      √       |              |              |
micro:bit          |      √       |              |              |
FireBeetle M0      |      √       |              |              |


## History

- 2024-12-16 - Version 1.0.0 released.

## Credits

Written by fary(feng.yang@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))
