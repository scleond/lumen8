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
		P5OUT |= BIT5;
		_delay_cycles(10);  // on for 800 ns
		P5OUT &= ~BIT5;
		_delay_cycles(10);  // off for 450 ns, may need to adjust
	}
	else{
		P5OUT |= BIT5;
		_delay_cycles(2);  // on for 400 ns
		P5OUT &= ~BIT5;
		_delay_cycles(10);  // off for 850 ns, may need to adjust
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
		if(loc == 0){
			setColor(loc,0x0F,0x00,0x00);
		}
		if(loc == 1){
			setColor(loc,0x00,0x0F,0x00);
		}
		if(loc == 2){
			setColor(loc,0x00,0x00,0x0F);
		}

//		if(loc < 10){
//			setColor(loc,0x0A,0x00,0x00);
//		}
//		else if((loc >= 10) & (loc < 20)){
//			setColor(loc,0x0A,0x0A,0x00);
//		}
//		else if((loc >= 20) & (loc < 30)){
//			setColor(loc,0x00,0x0A,0x00);
//		}
//		else if((loc >= 30) & (loc < 40)){
//			setColor(loc,0x00,0x0A,0x0A);
//		}
//		else if((loc >= 40) & (loc < 50)){
//			setColor(loc,0x00,0x00,0x0A);
//		}
//		else if(loc >= 50){
//			setColor(loc,0x0A,0x00,0x0A);
//		}
	}
}

void rotatePatternForward(void){
	uint8_t loc;
	uint8_t tempValRed = leds[0].red;
	uint8_t tempValBlue = leds[0].blue;
	uint8_t tempValGreen = leds[0].green;
	for(loc = 0; loc < numLED; loc++){
		if(loc == numLED - 1){
			leds[loc].red = tempValRed;
			leds[loc].green = tempValGreen;
			leds[loc].blue = tempValBlue;
		}
		else{
			leds[loc].red = leds[loc+1].red;
			leds[loc].green = leds[loc+1].green;
			leds[loc].blue = leds[loc+1].blue;
		}
	}
}

void rotatePatternBackward(void){
	int8_t loc;
	uint8_t tempValRed = leds[numLED - 1].red;
	uint8_t tempValBlue = leds[numLED - 1].blue;
	uint8_t tempValGreen = leds[numLED - 1].green;
	for(loc = numLED - 1; loc >= 0; loc--){
		if(loc == 0){
			leds[loc].red = tempValRed;
			leds[loc].green = tempValGreen;
			leds[loc].blue = tempValBlue;
		}
		else{
			leds[loc].red = leds[loc-1].red;
			leds[loc].green = leds[loc-1].green;
			leds[loc].blue = leds[loc-1].blue;
		}
	}
}
void sendPattern(void){
	_disable_interrupts();
	uint8_t loc,color;
	for(loc = 0; loc < numLED; loc++){
		uint8_t rgb[3] = {leds[loc].green, leds[loc].red, leds[loc].blue};
		for(color = 0; color < 3; color++){
			uint8_t colorToSend = rgb[color];
			sendByte(colorToSend);
		}
	}
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5);
	_delay_cycles(240); // delay 50 us
	_enable_interrupts();
}

void heartbeat(uint16_t maxLED){
	uint8_t j = 0;
	uint8_t i;
	for(i = 0; i < maxLED*2; i++){
		sendPattern();
		if(i < maxLED){
			j++;
			rotatePatternBackward();
		}
		else{
			j--;
			rotatePatternForward();
		}
		delay(10);
	}

}

void amplitudeDisplay(uint16_t maxLED){
	uint16_t loc;
	for(loc = 0; loc < numLED; loc++){
		if(loc < maxLED){
			if(loc < maxLED*.2){
				setColor(loc,0x0F,0x00,0x00);
			}
			else if(loc < maxLED*0.4){
				setColor(loc,0x0F,0x01,0x00);
			}
			else if(loc < maxLED*0.6){
				setColor(loc,0x0F,0x02,0x00);
			}
			else if(loc < maxLED*0.8){
				setColor(loc,0x0F,0x03,0x00);
			}
			else{
				setColor(loc,0x0F,0x04,0x00);
			}
		}
		else{
			setColor(loc,0x00,0x00,0x00);
		}
	}
}

void fillPattern(uint16_t brightness){
	uint16_t loc;
		for(loc = 0; loc < numLED; loc++){
			setColor(loc,brightness,brightness,brightness);
		}
}

