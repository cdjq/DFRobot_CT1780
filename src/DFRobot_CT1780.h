/*!
 * @file  DFRobot_CT1780.h
 * @brief  This is the user manual of CT1780
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [fary](feng.yang@dfrobot.com)
 * @version     V1.0
 * @date        2024-12-16
 * @url         https://github.com/DFRobor/DFRobot_CT1780
 */
#ifndef _DFRobot_CT1780_H_ 
#define _DFRobot_CT1780_H_
#include "OneWire.h"

class DFRobot_CT1780 :public OneWire
{
public:
	#define CMD_READ_ROM 0x33
	#define CMD_MATCH_ROM 0x55
	#define CMD_SKIP_ROM 0xCC
	#define CMD_CONVERT_T 0x44
	#define CMD_READ_SCRATCHPAD 0xBE
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
private:
	uint8_t  CT1780Pin;
	uint8_t  address[8];
};
#endif