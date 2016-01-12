/*
 * ws2812.h
 *
 *  Created on: Jan 10, 2016
 *      Author: Chris
 */

#ifndef WS2812_H_
#define WS2812_H_

#include <stdint.h>
#include "driverlib.h"
#include "lumen8.h"

#define numLED	60

void sendBit(uint8_t bit);
void sendByte(uint8_t byte);
void setColor(uint8_t i, uint8_t rVal, uint8_t gVal, uint8_t bVal);
void testPattern(void);
void blankPattern(void);
void sendPattern(void);
void rotatePatternForward(void);
void rotatePatternBackward(void);
void heartbeat(uint16_t maxLED);

#endif /* WS2812_H_ */
