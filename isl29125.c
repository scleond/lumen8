/*
 * isl29125.c
 *
 *  Created on: Dec 13, 2015
 *      Author: Chris
 */

#include "isl29125.h"


void initISL29125(void){
	i2cTx(ISL_I2C_ADDR, ISL_CONFIG_1, CFG1_MODE_RGB | CFG1_10KLUX | CFG1_12BIT );		//RGB mode, bright environment, fast read
	_delay_cycles(1000);
}
