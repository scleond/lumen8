/*
 * ds1307.c
 *
 *  Created on: Jan 4, 2016
 *      Author: Chris
 */

#include "ds1307.h"

unsigned char readSeconds(){
	char rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_SEC);
	return rxWord;
}

unsigned char readMinutes(){
	char rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_MIN);
	return rxWord;
}

unsigned char readHours(){
	char rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_HR);
	return rxWord & 0xBF;  // remove the 24 hr flag in bit 6 for easier reading
}

unsigned char readDate(){
	char rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_DD);
	return rxWord;
}

unsigned char readMonth(){
	char rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_MM);
	return rxWord;
}

unsigned char readYear(){
	char rxWord;
	rxWord = i2cReadByte(DS1307_ADDR,DS1307_YY);
	return rxWord;
}


