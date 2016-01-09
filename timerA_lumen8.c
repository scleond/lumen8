/*
 * timerA.c
 *
 *  Created on: Jan 9, 2016
 *      Author: Chris
 */

#include "timerA_lumen8.h"

/* Timer_A UpMode Configuration Parameter */
const Timer_A_UpModeConfig upConfig =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_16,          // SMCLK/16 = 1MHz
        10000,                           		// 10000 tick period
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_SKIP_CLEAR                      // Clear value
};

void initTimerA0(void){
    /* Configuring Timer_A2 for Up Mode */
    MAP_Timer_A_configureUpMode(TIMER_A0_MODULE, &upConfig);

    /* Enabling interrupts and starting the timer */
    MAP_Interrupt_enableInterrupt(INT_TA0_0);
    MAP_Timer_A_startCounter(TIMER_A0_MODULE, TIMER_A_UP_MODE);
}

