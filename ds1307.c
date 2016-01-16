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
	return rxWord;
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

uint8_t bcd2decimal(uint8_t bcd){
	uint8_t dec;
	dec = ((bcd & 0xF0) >> 4) * 10;  // mask upper nibble (10s place)
	dec += (bcd & 0x0F);
	return dec;
}


