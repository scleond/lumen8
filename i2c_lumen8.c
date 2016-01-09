/*
 * i2c_lumen8.c
 *
 *  Created on: Dec 30, 2015
 *      Author: Chris
 */

#include "i2c_lumen8.h"

const eUSCI_I2C_MasterConfig i2cConfig =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        1000000,                                // SMCLK = 1MHz
		EUSCI_B_I2C_SET_DATA_RATE_100KBPS,      // Desired I2C Clock of 100khz
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
	P1DIR &= ~BIT7;				//set bit 7back to default
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

void i2cWriteByte(const uint8_t slvAddr, const uint8_t regAddr, const uint8_t txData) {
	while(stopBusy());
	UCB0I2CSA = slvAddr; // set slave address
	UCB0CTLW0 |= UCTR | UCTXSTT;	// put in transmitter mode and send start bit
	while(txBusy() | startBusy());
	UCB0TXBUF = regAddr; // setting TXBUF clears the TXIFG flag
	while(txBusy());
	UCB0TXBUF = txData; // setting TXBUF clears the TXIFG flag
	while(txBusy());
	UCB0CTLW0 |= UCTXSTP; 				// I2C stop condition
}

uint8_t i2cReadByte(const uint8_t slvAddr, const uint8_t regAddr){
	uint8_t rxByte;
	while(stopBusy());
	UCB0I2CSA = slvAddr;  // set slave addr
	UCB0CTLW0 |= UCTR | UCTXSTT;  // i2c start condition
	while(startBusy());  // wait for start to send
	UCB0TXBUF = regAddr;  // send register value
	while(txBusy());
	UCB0CTLW0 &= ~UCTR;  // set to rx mode
	UCB0CTLW0 |= UCTXSTT;  // send repeated start
	while( startBusy());
	UCB0CTLW0 |= UCTXSTP;  // i2c stop should be sent BEFORE final rx is received
	while(rxBusy());
	rxByte = UCB0RXBUF;
	return rxByte;
}

uint16_t i2cReadWord(const uint8_t slvAddr, const uint8_t regAddr){
	uint16_t rxWord;
	while(stopBusy());
	UCB0I2CSA = slvAddr;  // set slave addr
	UCB0CTLW0 |= UCTR | UCTXSTT;  // i2c start
	while(startBusy());
	UCB0TXBUF = regAddr;
	while(txBusy());
	UCB0CTLW0 &= ~UCTR ;
	UCB0CTLW0 |= UCTXSTT;
	while(startBusy());
	while(rxBusy());
	rxWord = UCB0RXBUF << 8;
	UCB0CTLW0 |= UCTXSTP;  // i2c stop
	while(rxBusy());
	rxWord |= UCB0RXBUF;
	return rxWord;
}

