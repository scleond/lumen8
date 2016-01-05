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

unsigned char readSeconds(void);
unsigned char readMinutes(void);
unsigned char readHours(void);
unsigned char readDate(void);
unsigned char readMonth(void);
unsigned char readYear(void);



#endif /* DS1307_H_ */
