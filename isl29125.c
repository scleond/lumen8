/*
 * isl29125.c
 *
 *  Created on: Dec 13, 2015
 *      Author: Chris
 */

#include "isl29125.h"


unsigned char readDevID_ISL29125(void){
	unsigned char rxWord;
	rxWord = i2cReadByte(ISL_I2C_ADDR, ISL_DEVICE_ID) <<8 ;  //read isl device ID to see if it's there
	return rxWord;
}

void initISL29125(void){
	i2cWriteByte(ISL_I2C_ADDR, ISL_CONFIG_1,CFG1_MODE_RGB);
	_delay_cycles(1000);
}
