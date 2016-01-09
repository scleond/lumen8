/*
 * ws2812.c
 *
 *  Created on: Jan 9, 2016
 *      Author: Chris
 */

//
#include "ws2812.h"

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} LED;

#define OUTPUT_PIN	(0x80)			// Set to whatever UCB0SIMO is on your processor (Px.7 here)

#define NUM_LEDS	(60)			// NUMBER OF LEDS IN YOUR STRIP

LED leds[NUM_LEDS] = {{0,0,0}};

// Initializes everything needed to use this library. This clears the strip.
void initStrip(){
//	P1SEL |= OUTPUT_PIN;			// configure output pin as SPI output
//	P1SEL2 |= OUTPUT_PIN;
//	UCB0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; 	// 3-pin, MSB, 8-bit SPI master
//	UCB0CTL1 |= UCSSEL_2;			// SMCLK source (16 MHz)
//	UCB0BR0 = 3;					// 16 MHz / 3 = .1875 us per bit
//	UCB0BR1 = 0;
//	UCB0CTL1 &= ~UCSWRST;			// Initialize USCI state machine
	clearStrip();					// clear the strip
}

// Sets the color of a certain LED (0 indexed)
void setLEDColor(uint16_t p, uint8_t r, uint8_t g, uint8_t b){
	leds[p].red = r;
	leds[p].green = g;
	leds[p].blue = b;
}

uint8_t txBusySPI(void){
	return !(UCB1IFG & UCTXIFG0);
}

// Send colors to the strip and show them. Disables interrupts while processing.
void showStrip(){
//	__bic_SR_register(GIE);       	// disable interrupts
	MAP_Interrupt_disableMaster();

	// send RGB color for every LED
	int i, j;
	for (i = 0; i < NUM_LEDS; i++){
		uint8_t rgb[3] = {leds[i].green, leds[i].red, leds[i].blue};	// get RGB color for this LED

		// send green, then red, then blue
		for (j = 0; j < 3; j++){
			uint8_t mask = 0x80;					// b1000000

			// check each of the 8 bits
			while(mask != 0){
				while (txBusySPI());	// wait to transmit

				if (rgb[j] & mask){			// most significant bit first
					UCB1TXBUF = HIGH_CODE;		// send 1
				}
				else {
					UCB1TXBUF = LOW_CODE;		// send 0
				}

				mask >>= 1;						// check next bit
			}
		}
	}

	// send RES code for at least 50 us (800 cycles at 16 MHz)
	_delay_cycles(800);

//	__bis_SR_register(GIE);       	// enable interrupts
	MAP_Interrupt_enableMaster();
}

// Clear the color of all LEDs (make them black/off)
void clearStrip(){
	fillStrip(0x00, 0x00, 0x00);	// black
}

// Fill the strip with a solid color. This will update the strip.
void fillStrip(uint8_t r, uint8_t g, uint8_t b){
	int i;
	for (i = 0; i < NUM_LEDS; i++){
		setLEDColor(i, r, g, b);		// set all LEDs to specified color
	}
	showStrip();						// refresh strip
}

