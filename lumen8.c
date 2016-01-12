/*
 * lumen8.c
 *
 *  Created on: Dec 31, 2015
 *      Author: Chris
 */

#include "lumen8.h"

void enableSensors(uint8_t tslIntegTime, uint8_t tslGain){
	enableTSL2561(tslIntegTime, tslGain);  //TSL2561 is default inactive. turn on here
	initISL29125();  // set for full RGB mode
}

void initGPIO(void){
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN5);
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5);
}

void delay(uint32_t delay){
    while (delay--)
    {
        _delay_cycles(1);
    }
}
