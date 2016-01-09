/*
 * ds1307.h
 *
 *  Created on: Jan 4, 2016
 *      Author: Chris
 */

#ifndef DS1307_H_
#define DS1307_H_

#include <msp.h>
#include "i2c_lumen8.h"

#define DS1307_ADDR		(0x68)

#define DS1307_SEC				(0x00)
#define DS1307_MIN				(0x01)
#define DS1307_HR				(0x02)
#define DS1307_DOW				(0x03)  //day of week
#define DS1307_DD				(0x04)
#define DS1307_MM				(0x05)
#define DS1307_YY				(0x06)

uint8_t readSeconds(void);
uint8_t readMinutes(void);
uint8_t readHours(void);
uint8_t readDate(void);
uint8_t readMonth(void);
uint8_t readYear(void);


/* used in main.c to set time once. very hacky.*/
//	i2cWriteByte(DS1307_ADDR, DS1307_SEC,0x00);
//	i2cWriteByte(DS1307_ADDR, DS1307_MIN,0x37);
//	i2cWriteByte(DS1307_ADDR, DS1307_HR,0x59);
//	i2cWriteByte(DS1307_ADDR, DS1307_DD,0x04);
//	i2cWriteByte(DS1307_ADDR, DS1307_MM,0x01);
//	i2cWriteByte(DS1307_ADDR, DS1307_YY,0x16);
//	i2cWriteByte(DS1307_ADDR, DS1307_YY,0x16);
//	i2cWriteByte(DS1307_ADDR, DS1307_YY,0x16);



#endif /* DS1307_H_ */
