/*
 * i2c_lumen8.c
 *
 *  Created on: Dec 30, 2015
 *      Author: Chris
 */

#include "i2c_lumen8.h"

#define i2cDelay	1000

uint8_t TXData[2];        // Pointer to TX data
uint8_t TXByteCtr;

const eUSCI_I2C_MasterConfig i2cConfig =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        500000,                                	// SMCLK = 3MHz
        50000,      							// Desired I2C Clock of 50khz
        0,                                      // No byte counter threshold
        EUSCI_B_I2C_NO_AUTO_STOP                // No Autostop
};

void initI2C(void){

	i2cFlush();

	/* set pin 6 and 7 to primary function i2c*/
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
            GPIO_PIN6 + GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Initializing I2C Master to SMCLK at 100kbs with no autostop */
    MAP_I2C_initMaster(EUSCI_B0_MODULE, &i2cConfig);

    /* Enable I2C Module to start operations */
    MAP_I2C_enableModule(EUSCI_B0_MODULE);
//
    /* Enable and clear the interrupt flag */
    MAP_I2C_clearInterruptFlag(EUSCI_B0_MODULE,EUSCI_B_I2C_NAK_INTERRUPT);
    //Enable master Receive interrupt
    MAP_I2C_enableInterrupt(EUSCI_B0_MODULE, EUSCI_B_I2C_NAK_INTERRUPT);

}

void i2cFlush(void){
	P1DIR |= BIT7;					 //Set7 to output
	P1OUT &= ~BIT7;				  //toggle  7 to clear I2C lines
	P1OUT |= BIT7;
	P1DIR &= ~BIT7;				//set bit 7back to default??
}

char txBusy(void){
	return !(UCB0IFG & UCTXIFG0);
}

char startBusy(void){
	return (UCB0CTLW0 & UCTXSTT);
}

char stopBusy(void){
	return (UCB0CTLW0 & UCTXSTP);
}

char rxBusy(void){
	return !(UCB0IFG & UCRXIFG0);
}

void i2cWriteByte(const unsigned char slvAddr, const unsigned char regAddr, const unsigned char txData) {
	while(stopBusy());
	UCB0I2CSA = slvAddr; // set slave address
	UCB0CTLW0 |= UCTR + UCTXSTT;	// put in transmitter mode and send start bit
	while(txBusy() | startBusy());
	UCB0TXBUF = regAddr; // setting TXBUF clears the TXIFG flag
	while(txBusy());
	UCB0TXBUF = txData; // setting TXBUF clears the TXIFG flag
	while(txBusy());
	UCB0CTLW0 |= UCTXSTP; 				// I2C stop condition
	while(stopBusy());
	_delay_cycles(i2cDelay);
}

unsigned char i2cReadByte(const unsigned char slvAddr, const unsigned char regAddr){
	char rxByte;
	while(stopBusy());
	UCB0I2CSA = slvAddr;  // set slave addr
	UCB0CTLW0 |= UCTR | UCTXSTT;  // i2c start
	while(startBusy());
	UCB0TXBUF = regAddr;
	while(txBusy());
	UCB0CTLW0 &= ~UCTR ;
	UCB0CTLW0 |= UCTXSTT;
	while(startBusy());
	UCB0CTLW0 |= UCTXSTP;  // i2c stop
	while(rxBusy());
	rxByte = UCB0RXBUF;
//	while(stopBusy());
	_delay_cycles(i2cDelay);
	return rxByte;

//	// set slave address
//	MAP_I2C_setSlaveAddress(EUSCI_B0_MODULE,
//			slvAddr);
//
//	/*this was called after set slave address in an example HAL_I2C*/
//    MAP_I2C_clearInterruptFlag(EUSCI_B0_MODULE,
//        EUSCI_B_I2C_TRANSMIT_INTERRUPT0 + EUSCI_B_I2C_RECEIVE_INTERRUPT0);
//
//    // set to TX
//	MAP_I2C_setMode(EUSCI_B0_MODULE,
//			EUSCI_B_I2C_TRANSMIT_MODE);
//
//	// clear an flags
//	MAP_I2C_clearInterruptFlag(EUSCI_B0_MODULE,
//			EUSCI_B_I2C_TRANSMIT_INTERRUPT0);
//
//	// wait until bus ready
//	while (MAP_I2C_isBusBusy(EUSCI_B0_MODULE));
//
//	// send multibytestart (should be single byte?) to register
//	MAP_I2C_masterSendMultiByteStart(EUSCI_B0_MODULE, regAddr);
//
//	// wait for TX to finish
//    while(!(MAP_I2C_getInterruptStatus(EUSCI_B0_MODULE,
//        EUSCI_B_I2C_TRANSMIT_INTERRUPT0)));
//
//    // send stop
//    MAP_I2C_masterSendMultiByteStop(EUSCI_B0_MODULE);
//
//    // wait for stop
//    while(!MAP_I2C_getInterruptStatus(EUSCI_B0_MODULE,
//        EUSCI_B_I2C_STOP_INTERRUPT));
//
//    // set to receive
//    MAP_I2C_masterReceiveStart(EUSCI_B0_MODULE);
//
//    // wait for RX to finish
//    while(!(I2C_getInterruptStatus(EUSCI_B0_MODULE,
//        EUSCI_B_I2C_RECEIVE_INTERRUPT0)));
//
//    // read from rx buf
//    rxByte = MAP_I2C_masterReceiveMultiByteFinish(EUSCI_B0_MODULE);
}

