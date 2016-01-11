/*
 * ws2812.c
 *
 *  Created on: Jan 10, 2016
 *      Author: Chris
 */

#include "ws2812.h"

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} LED;

LED leds[numLED] = {{0,0,0}};

void sendBit(uint8_t bit){
	if(bit == 1){
		MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN5);
		_delay_cycles(6);  // on for 800 ns
		MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5);
		_delay_cycles(2);  // off for 450 ns, may need to adjust
	}
	else{
		MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN5);
		_delay_cycles(6);  // on for 400 ns
		MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5);
		_delay_cycles(2); // off for 850 ns
	}
}

void sendByte(uint8_t byte){
	int8_t bitCount;
	for(bitCount = 7; bitCount >= 0; bitCount--){
		uint8_t mask = 1 << bitCount;
		uint8_t maskedByte = byte & mask;
		uint8_t bitToSend = maskedByte >> bitCount;
		sendBit(bitToSend);
	}
}

void setColor(uint8_t i, uint8_t rVal, uint8_t gVal, uint8_t bVal){
	leds[i].red = rVal;
	leds[i].green = gVal;
	leds[i].blue = bVal;
}

void blankPattern(void){
	uint8_t loc;
	for(loc = 0; loc < numLED; loc++){
		if(loc < 20){
			setColor(loc,0x00,0x00,0x00);
		}
		else if((loc >= 20) & (loc < 40)){
			setColor(loc,0x00,0x00,0x00);
		}
		else if(loc >= 40){
			setColor(loc,0x00,0x00,0x00);
		}
	}
}

void testPattern(void){
	uint8_t loc;
	for(loc = 0; loc < numLED; loc++){
		if(loc < 20){
			setColor(loc,0x0F,0x0F,0x0F);
		}
		else if((loc >= 20) & (loc < 40)){
			setColor(loc,0x0F,0x0F,0x0F);
		}
		else if(loc >= 40){
			setColor(loc,0x0F,0x0F,0x0F);
		}
	}
}

void sendPattern(void){
	uint8_t loc,color;
	for(loc = 0; loc < numLED; loc++){
		uint8_t rgb[3] = {leds[loc].green, leds[loc].red, leds[loc].blue};
		for(color = 0; color < 3; color++){
			uint8_t colorToSend = rgb[color];
			sendByte(colorToSend);
		}
	}
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5);
	_delay_cycles(2400); // delay 50 us
}
