/*!
 * @file  readTemp.ino
 * @brief Obtain the temperature value
 * @copyright   Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2025-03-22
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#include "DFRobot_CT1780.h"
DFRobot_CT1780 CT1780(2);
typedef struct 
{
  uint8_t uniqueAddr[8];
  int configAddr;
}sCT1780_t;
sCT1780_t sensorCt1780;
void setup() {
  Serial.begin(115200);
  Serial.print("search CT1780...");
  /**
   * @fn: searchDevice
   * @brief: Search for CT1780 device connected to the bus
   * @param newAddr:If a new device is retrieved, the 64-bit unique ID of the device is stored at that address,Please pass in an array of 8 bytes in length
   * @return: If a new address is returned, 1 is returned. Zero may indicate that the bus is short, there are no devices, or that you have retrieved all the devices. Or you provided the wrong parameters
   */
  if (!CT1780.searchDevice(/*newAddr=*/sensorCt1780.uniqueAddr)) {
    Serial.println("failed!");
    while (1) {
      delay(1000);
    } 
  }
  Serial.println("Successed!");
  Serial.print("unique addr is: ");
  for(uint8_t i=0;i<8;i++){
    if (sensorCt1780.uniqueAddr[i] < 0x10) Serial.print("0");
    Serial.print(sensorCt1780.uniqueAddr[i],HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Get the user-configured address of CT1780 (in ScratchPad)
  sensorCt1780.configAddr = CT1780.getConfigAddr(sensorCt1780.uniqueAddr);
  if(sensorCt1780.configAddr!=-1){
    Serial.print("config addr is: 0x");
    if (sensorCt1780.configAddr < 0x10) Serial.print("0");
    Serial.println(sensorCt1780.configAddr,HEX);
  }else{
    Serial.println("get config addr err!");
  }

}

void loop() {
  // Read probe temperature data
  Serial.print("Temperature : ");
  Serial.print(CT1780.getCelsius(sensorCt1780.uniqueAddr));
  Serial.println(" C");
  delay(1000);
}
