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
#include "clk_lumen8.h"

void initI2C(void);
void i2cFlush(void);
uint8_t txBusy(void);
uint8_t startBusy(void);
uint8_t rxBusy(void);
void enableTSL2561(uint8_t integTime, uint8_t tslGain);

void i2cWriteByte(const uint8_t slvAddr, const uint8_t regAddr, const uint8_t txData);
uint8_t i2cReadByte(const uint8_t slvAddr, const uint8_t regAddr);
uint8_t i2cReadByteTSL(const uint8_t slvAddr, const uint8_t regAddr);
uint16_t i2cReadWord(const uint8_t slvAddr, const uint8_t regAddr);



#endif /* I2C_LUMEN8_H_ */
