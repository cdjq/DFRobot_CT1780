/*!
 * @file  DFRobot_CT1780.h
 * @brief  This is the user manual of CT1780
 * @copyright   Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2025-03-07
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#ifndef _DFRobot_CT1780_H_ 
#define _DFRobot_CT1780_H_
#include "OneWire.h"

class DFRobot_CT1780 :public OneWire
{
public:
  /**
   * @fn: DFRobot_CT1780
   * @brief: Constructor, passing in the data pin of the CT1780 connection
   * @pram(pin): The pin of the OneWire data cable connection, the example code is the D2 pin of UNO
   */
  DFRobot_CT1780(uint8_t pin):OneWire(pin){
  };
  /**
   * @fn: begin
   * @brief: Initialize object
   * @return: 1 is returned if initialization succeeds, 0 is returned if initialization fails
   */
  int begin();
  /**
   * @fn: getCelsius
   * @brief: Read probe temperature data
   * @return: float Temperature value (in degrees Celsius),Return NAN on failure.
   */
  float getCelsius();
  /**
   * @fn: getUniqueAddr()
   * @brief: Gets the 64-bit unique address of CT1780
   * @return: Address data (array),Return NULL on failure.
   */
  uint8_t* getUniqueAddr();
  /**
   * @fn: getConfigAddr()
   * @brief: Get the user-configured address of CT1780 (in ScratchPad)
   * @return: address data,Return -1 on failure.
   */
  int getConfigAddr();
private:
  #define CMD_CONVERT_T 0x44
  #define CMD_READ_SCRATCHPAD 0xBE
  uint8_t  CT1780Pin;
  uint8_t  address[8];
};
#endif