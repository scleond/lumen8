/*
 * lumen8.h
 *
 *  Created on: Dec 31, 2015
 *      Author: Chris
 */

#ifndef LUMEN8_H_
#define LUMEN8_H_

#include "tsl2561.h"
#include "isl29125.h"
#include "ds1307.h"
#include "driverlib.h"
#include "i2c_lumen8.h"
#include "clk_lumen8.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "msp.h"

#define READ_TSL2561 		(0x00)  // lux sensor
#define READ_ISL29125		(0x01)  // rgb sensor
#define READ_DS1307			(0x02)  // RTC

void enableSensors(unsigned char tslIntegTime, unsigned char tslGain);

#endif /* LUMEN8_H_ */
