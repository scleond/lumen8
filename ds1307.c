/*
 * ds1307.c
 *
 *  Created on: Jan 4, 2016
 *      Author: Chris
 */

#include "ds1307.h"

uint8_t readSeconds(){
	uint8_t rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_SEC);
	return rxWord;
}

uint8_t readMinutes(){
	uint8_t rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_MIN);
	return rxWord;
}

uint8_t readHours(){
	uint8_t rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_HR);
	return rxWord & 0xBF;  // remove the 24 hr flag in bit 6 for easier reading
}

uint8_t readDate(){
	uint8_t rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_DD);
	return rxWord;
}

uint8_t readMonth(){
	uint8_t rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_MM);
	return rxWord;
}

uint8_t readYear(){
	uint8_t rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_YY);
	return rxWord;
}


