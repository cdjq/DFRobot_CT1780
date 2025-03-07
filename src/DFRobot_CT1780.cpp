/*!
 * @file  DFRobot_CT1780.cpp
 * @brief  This is the method implementation file of CT1780
 * @copyright   Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2025-03-07
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#include "DFRobot_CT1780.h"
bool is_all_equal(const uint8_t *data, size_t len) {
  for (size_t i = 1; i < len; i++) {
    if (data[i] != data[0]) {
      return false;
    }
  }
  return true;
}

int DFRobot_CT1780::begin() {
  const int maxRetries = 3;
  for(int i = 0; i < maxRetries; i++) {
    if (search(address)) {
      if(crc8(address, 7) != address[7]) {
        reset_search();
        delay(250);
        continue;
      }
      if(address[0] != 0x3B) {
        reset_search();
        delay(250);
        continue;
      }
      return 1; // 成功
    }
    reset_search();
    delay(250);
  }
  return 0;
}

float DFRobot_CT1780::getCelsius(){
  uint8_t data[9];
  reset();
  select(address);
  write(CMD_CONVERT_T);
  delay(750); // Wait for the conversion to complete
  
  reset();
  select(address);
  write(CMD_READ_SCRATCHPAD);
  
  for(int i = 0; i < 9; i++) {
    data[i] = read();
  }
  
  if(is_all_equal(data,9)||crc8(data, 8) != data[8]) {
    return NAN;
  }
  
  // Analytic temperature data
  int16_t rawTemperature = (data[1] << 8) | data[0];
  return rawTemperature / 4 * 0.25; // The temperature resolution is 0.25°C
}

uint8_t* DFRobot_CT1780::getUniqueAddr(){
  if(getConfigAddr()==-1){
    return NULL;
  }
  return address;
}

int DFRobot_CT1780::getConfigAddr(){
  uint8_t data[9];
  reset();
  select(address);
  write(CMD_READ_SCRATCHPAD);
  for(int i = 0; i < 9; i++) {
    data[i] = read();
  }
  
  if(is_all_equal(data,9)||crc8(data, 8) != data[8]) {
    return -1;
  }
  // Extract AD0-AD3 information
  uint8_t configRegister = data[4];
  uint8_t adPins = configRegister & 0x0F; // The lower 4 bits are AD0-AD3
  return adPins;
}