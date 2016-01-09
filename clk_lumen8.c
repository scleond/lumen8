/*
 * clk.c
 *
 *  Created on: Dec 30, 2015
 *      Author: Chris
 */

#include "clk_lumen8.h"

void initCLK(void){
	/* Enabling floating point for DCO Frequency calculation */
	MAP_FPU_enableModule();

    /* Setting the DCO Frequency to 16MHz */
    MAP_CS_setDCOFrequency(16000000);

    /* SMCLK = DCO/32 = 500kHz*/
    MAP_CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_16);
}

