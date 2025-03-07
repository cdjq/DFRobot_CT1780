/*!
 * @file  readTemp.ino
 * @brief Obtain the temperature value
 * @copyright   Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2025-03-07
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#include "DFRobot_CT1780.h"
DFRobot_CT1780 CT1780(2);
void setup() {
  Serial.begin(9600);
  Serial.print("init CT1780...");
  uint8_t address[8];
  if (!CT1780.begin()) {
    Serial.println("failed!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("Successed!");
  // Gets the 64-bit unique address of CT1780,return: Address data (array)
  uint8_t *uniqueAddr = CT1780.getUniqueAddr();
  if(uniqueAddr!=NULL){
    Serial.print("unique addr is: ");
    for(uint8_t i=0;i<8;i++){
      Serial.print(uniqueAddr[i],HEX);
      Serial.print(" ");
    }
    Serial.println();
  }else{
    Serial.println("get Unique addr err!");
  }
  // Get the user-configured address of CT1780 (in ScratchPad)
  uint8_t configAddr = CT1780.getConfigAddr();
  if(configAddr!=-1){
    Serial.print("config addr is: ");
    Serial.println(configAddr,HEX);
  }else{
    Serial.println("get config addr err!");
  }

}

void loop() {
  // Read probe temperature data
  Serial.print("Temperature : ");
  Serial.print(CT1780.getCelsius());
  Serial.println(" C");
  delay(1000);
}
