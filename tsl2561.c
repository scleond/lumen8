/*
 * tsl2561.c
 *
 *  Created on: Dec 13, 2015
 *      Author: Chris
 */

#include "tsl2561.h"

void enableTSL2561(uint8_t integTime, uint8_t tslGain) {
	i2cWriteByte(TSL2561_ADDR_FLOAT, TSL2561_COMMAND_BIT | TSL2561_REGISTER_CONTROL,TSL2561_COMMAND_BIT | TSL2561_CONTROL_POWERON);
	i2cWriteByte(TSL2561_ADDR_FLOAT, TSL2561_COMMAND_BIT | TSL2561_REGISTER_TIMING ,TSL2561_COMMAND_BIT | integTime | tslGain );
}

uint16_t readChan0_TSL2561(){
	int rxWord;
	rxWord = i2cReadByte(TSL2561_ADDR_FLOAT,TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN0_LOW);  //load CHAN0_LOW into most significant byte
	rxWord |= i2cReadByte(TSL2561_ADDR_FLOAT,TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN0_HIGH) << 8;
	return rxWord;
}

uint16_t readChan0Word_TSL2561(){
	int rxWord;
	rxWord = i2cReadWord(TSL2561_ADDR_FLOAT,TSL2561_COMMAND_BIT | TSL2561_WORD_BIT | TSL2561_REGISTER_CHAN0_LOW);  // read full word
	return rxWord;
}

uint16_t readChan1_TSL2561(){
	int rxWord;
	rxWord = i2cReadByte(TSL2561_ADDR_FLOAT,TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN1_LOW);  //load CHAN1_LOW into most significant byte
	rxWord |= i2cReadByte(TSL2561_ADDR_FLOAT,TSL2561_COMMAND_BIT | TSL2561_REGISTER_CHAN1_HIGH) << 8;
	return rxWord;
}

uint16_t readChan1Word_TSL2561(){
	int rxWord;
	rxWord = i2cReadWord(TSL2561_ADDR_FLOAT,TSL2561_COMMAND_BIT | TSL2561_WORD_BIT | TSL2561_REGISTER_CHAN1_LOW);
	return rxWord;
}



//taken from lux.cpp by taos
// lux equation approximation without floating point calculations
//////////////////////////////////////////////////////////////////////////////
// Routine: uint16_t CalculateLux(uint16_t ch0, uint16_t ch0, int iType)
//
// Description: Calculate the approximate illuminance (lux) given the raw
// channel values of the TSL2560. The equation if implemented
// as a piece-wise linear approximation.
//
// Arguments: uint16_t iGain - gain, where 0:1X, 1:16X
// uint16_t tInt - integration time, where 0:13.7mS, 1:100mS, 2:402mS,
// 3:Manual
// uint16_t ch0 - raw channel value from channel 0 of TSL2560
// uint16_t ch1 - raw channel value from channel 1 of TSL2560
// uint16_t iType - package type (T or CS)
//
// Return: uint16_t - the approximate illuminance (lux)
//
//////////////////////////////////////////////////////////////////////////////
uint16_t CalculateLux(uint16_t iGain, uint16_t tInt, int16_t iType){


	unsigned short ch0 = readChan0_TSL2561();
	unsigned short ch1 = readChan1_TSL2561();

	unsigned long chScale;
	unsigned long channel1;
	unsigned long channel0;

	switch (tInt)
	{
	case 0: // 13.7 msec
		chScale = TSL2561_LUX_CHSCALE_TINT0;
		break;
	case 1: // 101 msec
		chScale = TSL2561_LUX_CHSCALE_TINT1;
		break;
	default: // assume no scaling
		chScale = (1 << TSL2561_LUX_CHSCALE);
		break;
	}

	// scale if gain is NOT 16X
	if (!iGain) chScale = chScale << 4; // scale 1X to 16X
	// scale the channel values
	channel0 = (ch0 * chScale) >> TSL2561_LUX_CHSCALE;
	channel1 = (ch1 * chScale) >> TSL2561_LUX_CHSCALE;
	//
	// find the ratio of the channel values (Channel1/Channel0)
	// protect against divide by zero
	unsigned long ratio1 = 0;
	if (channel0 != 0) ratio1 = (channel1 << (TSL2561_LUX_RATIOSCALE+1)) / channel0;
	// round the ratio value
	unsigned long ratio = (ratio1 + 1) >> 1;
	// is ratio <= eachBreak ?
	uint16_t b, m;
	switch (iType)
	{
	case 0: // T, FN and CL package
		if (ratio <= TSL2561_LUX_K1T)
		{b=TSL2561_LUX_B1T; m=TSL2561_LUX_M1T;}
		else if (ratio <= TSL2561_LUX_K2T)
		{b=TSL2561_LUX_B2T; m=TSL2561_LUX_M2T;}
		else if (ratio <= TSL2561_LUX_K3T)
		{b=TSL2561_LUX_B3T; m=TSL2561_LUX_M3T;}
		else if (ratio <= TSL2561_LUX_K4T)
		{b=TSL2561_LUX_B4T; m=TSL2561_LUX_M4T;}
		else if (ratio <= TSL2561_LUX_K5T)
		{b=TSL2561_LUX_B5T; m=TSL2561_LUX_M5T;}
		else if (ratio <= TSL2561_LUX_K6T)
		{b=TSL2561_LUX_B6T; m=TSL2561_LUX_M6T;}
		else if (ratio <= TSL2561_LUX_K7T)
		{b=TSL2561_LUX_B7T; m=TSL2561_LUX_M7T;}
		else if (ratio >= TSL2561_LUX_K8T)
		{b=TSL2561_LUX_B8T; m=TSL2561_LUX_M8T;}
		break;
	case 1:// CS package
		if (ratio <= TSL2561_LUX_K1C)
		{b=TSL2561_LUX_B1C; m=TSL2561_LUX_M1C;}
		else if (ratio <= TSL2561_LUX_K2C)
		{b=TSL2561_LUX_B2C; m=TSL2561_LUX_M2C;}
		else if (ratio <= TSL2561_LUX_K3C)
		{b=TSL2561_LUX_B3C; m=TSL2561_LUX_M3C;}
		else if (ratio <= TSL2561_LUX_K4C)
		{b=TSL2561_LUX_B4C; m=TSL2561_LUX_M4C;}
		else if (ratio <= TSL2561_LUX_K5C)
		{b=TSL2561_LUX_B5C; m=TSL2561_LUX_M5C;}
		else if (ratio <= TSL2561_LUX_K6C)
		{b=TSL2561_LUX_B6C; m=TSL2561_LUX_M6C;}
		else if (ratio <= TSL2561_LUX_K7C)
		{b=TSL2561_LUX_B7C; m=TSL2561_LUX_M7C;}
		else if (ratio >= TSL2561_LUX_K8C)
		{b=TSL2561_LUX_B8C; m=TSL2561_LUX_M8C;}
		break;
	}
	unsigned long temp;
	temp = ((channel0 * b) - (channel1 * m));
	// round lsb (2^(LUX_SCALE-1))
	temp += (1 << (TSL2561_LUX_LUXSCALE-1));
	// strip off fractional portion
	unsigned long lux = temp >> TSL2561_LUX_LUXSCALE;
	return(lux);
}

