/*
 * spi_lumen8.c
 *
 *  Created on: Jan 9, 2016
 *      Author: Chris
 */

#include "spi_lumen8.h"

const eUSCI_SPI_MasterConfig spiMasterConfig =
{
		EUSCI_B_SPI_CLOCKSOURCE_SMCLK,             // SMCLK Clock Source
		SMCLK_HZ,                                  // SMCLK = DCO = 16MHz
        16000000,                                  // SPICLK = 16MHz
        EUSCI_A_SPI_MSB_FIRST,                     // MSB First
        EUSCI_A_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,    // Phase
        EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_HIGH, // High polarity
        EUSCI_A_SPI_3PIN                           // 3Wire SPI Mode
};

void initSPI(void){

	/* set pin 4 to primary function SIMO spi*/
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6,
            GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Initializing SPI Master to SMCLK at 16MHz*/
    MAP_SPI_initMaster(EUSCI_B1_MODULE, &spiMasterConfig);

    /* Enable I2C Module to start operations */
    MAP_SPI_enableModule(EUSCI_B1_MODULE);
//
    /* Enable and clear the interrupt flag */
    MAP_I2C_clearInterruptFlag(EUSCI_B0_MODULE,EUSCI_B_I2C_NAK_INTERRUPT);
    //Enable master Receive interrupt
    MAP_I2C_enableInterrupt(EUSCI_B0_MODULE, EUSCI_B_I2C_NAK_INTERRUPT);

}
