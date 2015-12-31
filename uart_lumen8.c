/*
 * uart_lumen8.c
 *
 *  Created on: Dec 31, 2015
 *      Author: Chris
 */

#include "uart_lumen8.h"

const eUSCI_UART_Config uartConfig =
{
		/* Baud rate calculated with TI provided software:
		 	 http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
		 */
		EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
		3,                                     // BRDIV = 3
		4,                                       // UCxBRF = 4
		4,                                       // UCxBRS = 4
		EUSCI_A_UART_NO_PARITY,                  // No Parity
		EUSCI_A_UART_LSB_FIRST,                  // LSB First
		EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
		EUSCI_A_UART_MODE,                       // UART mode
		EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling = 1
};

void initUART(void){
    /* Selecting P1.1, P1.2 and P1.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
            GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring UART Module */
    MAP_UART_initModule(EUSCI_A0_MODULE, &uartConfig);

    /* Enable UART module */
    MAP_UART_enableModule(EUSCI_A0_MODULE);


}
