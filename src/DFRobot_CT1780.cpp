/*!
 * @file  DFRobot_CT1780.cpp
 * @brief  This is the method implementation file of CT1780
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2024-12-16
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#include "DFRobot_CT1780.h"

int DFRobot_CT1780::begin(){
    if (!search(address)) {
        reset_search();
        delay(250);
        return 0;
    }
    if (crc8(address, 7) != address[7]) {
        return 0;
    }
    if (address[0] != 0x3B) { // Check the family code of the device
        return 0;
    }
    return 1;
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

    for (int i = 0; i < 9; i++) {
        data[i] = read();
    }

    if (crc8(data, 8) != data[8]) {
        return NAN;
    }

    // Analytic temperature data
    int16_t rawTemperature = (data[1] << 8) | data[0];
    return rawTemperature / 4 * 0.25; // The temperature resolution is 0.25°C
}
uint8_t* DFRobot_CT1780::getUniqueAddr(){
	return address;
}

uint8_t DFRobot_CT1780::getConfigAddr(){
	uint8_t data[9];
    reset();
    select(address);
    write(CMD_READ_SCRATCHPAD);
    for (int i = 0; i < 9; i++) {
        data[i] = read();
    }

    if (crc8(data, 8) != data[8]) {
        return -1;
    }
    // Extract AD0-AD3 information
    uint8_t configRegister = data[4];
    uint8_t adPins = configRegister & 0x0F; // The lower 4 bits are AD0-AD3
	return adPins;
}