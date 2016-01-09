/*
 * isl29125.c
 *
 *  Created on: Dec 13, 2015
 *      Author: Chris
 */

#include "isl29125.h"


uint8_t readDevID_ISL29125(void){
	uint8_t rxWord;
	rxWord = i2cReadByte(ISL_I2C_ADDR, ISL_DEVICE_ID);  //read isl device ID to see if it's there
	return rxWord;
}

void initISL29125(void){
	i2cWriteByte(ISL_I2C_ADDR, ISL_CONFIG_1,CFG1_MODE_RGB);
}
