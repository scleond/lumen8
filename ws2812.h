/*
 * ws2812.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Chris
 */

#ifndef WS2812_H_
#define WS2812_H_

#include "msp.h"
#include "driverlib.h"

// Transmit codes
#define HIGH_CODE	(0xF0)			// b11110000
#define LOW_CODE	(0xC0)			// b11000000

// Configure processor to output to data strip
void initStrip(void);

// Send colors to the strip and show them. Disables interrupts while processing.
void showStrip(void);

// Set the color of a certain LED
void setLEDColor(uint16_t p, uint8_t r, uint8_t g, uint8_t b);

// Clear the color of all LEDs (make them black/off)
void clearStrip(void);

// Fill the strip with a solid color. This will update the strip.
void fillStrip(uint8_t r, uint8_t g, uint8_t b);


#endif /* WS2812_H_ */
