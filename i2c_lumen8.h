/*
 * i2c.h
 *
 *  Created on: Dec 30, 2015
 *      Author: Chris
 */

#ifndef I2C_LUMEN8_H_
#define I2C_LUMEN8_H_

#include "driverlib.h"
#include "tsl2561.h"

void initI2C(void);
void i2cFlush(void);
char txBusy(void);
char startBusy(void);
void enableTSL2561(unsigned char integTime, unsigned char tslGain);

void i2cWriteByte(const unsigned char slvAddr, const unsigned char regAddr, const unsigned char txData);
unsigned char i2cReadByte(const unsigned char slvAddr, const unsigned char regAddr);



#endif /* I2C_LUMEN8_H_ */
