/*!
 * @file  cascading.ino
 * @brief Demonstrates the cascading capabilities of the library
 * @copyright   Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2025-03-22
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#include "DFRobot_CT1780.h"
typedef struct 
{
  byte uniqueAddr[8];
  int configAddr;
}sCT1780_t;

sCT1780_t sensorCt1780[2];
DFRobot_CT1780 CT1780(2);
void setup() {
  Serial.begin(115200);
  
  for(uint8_t i=0;i<2;i++){
    Serial.print("search CT1780...");
    /**
     * @fn: searchDevice
     * @brief: Search for CT1780 device connected to the bus
     * @param newAddr:If a new device is retrieved, the 64-bit unique ID of the device is stored at that address,Please pass in an array of 8 bytes in length
     * @return: If a new address is returned, 1 is returned. Zero may indicate that the bus is short, there are no devices, or that you have retrieved all the devices. Or you provided the wrong parameters
     */
    if (!CT1780.searchDevice(/*newAddr=*/sensorCt1780[i].uniqueAddr)) {
      Serial.println("failed!");
    }else{
      Serial.print("Successed! ");
      Serial.print("unique addr is: ");
      for(uint8_t y=0;y<8;y++){
        if (sensorCt1780[i].uniqueAddr[y] < 0x10) Serial.print("0");
        Serial.print(sensorCt1780[i].uniqueAddr[y],HEX);
        Serial.print(" ");
      }
      // Get the user-configured address of CT1780 (in ScratchPad)
      sensorCt1780[i].configAddr = CT1780.getConfigAddr(sensorCt1780[i].uniqueAddr);
      if(sensorCt1780[i].configAddr!=-1){
        Serial.print(" . config addr is: ");
        if (sensorCt1780[i].configAddr < 0x10) Serial.print("0");
        Serial.println(sensorCt1780[i].configAddr,HEX);
      }else{
        Serial.println(". get config addr err!");
      }
    }
  }
}

void loop() {
  // Read probe temperature data
  for(uint8_t i=0;i<2;i++){
    Serial.print("CT1780 number: ");
    if (sensorCt1780[i].configAddr < 0x10) Serial.print("0");
    Serial.print(sensorCt1780[i].configAddr,HEX);
    Serial.print(" . Temperature: ");
    Serial.print(CT1780.getCelsius(sensorCt1780[i].uniqueAddr));
    Serial.println(" C");
  }
  delay(1000);
}
