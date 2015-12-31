#include <msp.h>

#include "i2c_lumen8_MSP432.h"
#include "lumen8_MSP432.h"
#include "tsl2561.h"
#include "driverlib.h"

static volatile uint32_t smclk;

/* I2C Master Configuration Parameter */
const eUSCI_I2C_MasterConfig i2cConfig =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        3000000,                                // SMCLK = 3MHz
        EUSCI_B_I2C_SET_DATA_RATE_100KBPS,      // Desired I2C Clock of 100khz
        0,                                      // No byte counter threshold
        EUSCI_B_I2C_NO_AUTO_STOP                // No Autostop
};

void initI2C(void){

	i2cFlush();								//toggle SCL to clear possible SDA hangup after reset

    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
            GPIO_PIN6 + GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_I2C_initMaster(EUSCI_B0_MODULE, &i2cConfig);
    /* Specify slave address */
    MAP_I2C_setSlaveAddress(EUSCI_B0_MODULE, TSL2561_ADDR_FLOAT);

    /* Set Master in transmit mode */
    MAP_I2C_setMode(EUSCI_B0_MODULE, EUSCI_B_I2C_TRANSMIT_MODE);

    /* Enable I2C Module to start operations */
    MAP_I2C_enableModule(EUSCI_B0_MODULE);

	_delay_cycles(1000);

	while(UCB0STAT & UCBBUSY);

}


void i2cFlush(void){
	P1DIR |= BIT7;					 //Set7 to output
	P1OUT &= ~BIT7;				  //toggle  7 to clear I2C lines
	P1OUT |= BIT7;
	P1DIR &= ~BIT7;				//set bit 7back to default??
}


void i2cTx(char slvAddr, char regAddr, char txData){
	while (UCB0CTL1 & UCTXSTP);             // Wait for stop condition to send
	UCB0I2CSA = slvAddr;           // Slave Address is 039h when floating
	UCB0CTL1 |= UCTR + UCTXSTT;             // I2C start condition with TX
	UCB0TXBUF = regAddr;	//command bit needs to be send with each command per app note
	UCB0TXBUF = txData;
	UCB0CTL1 |= UCTXSTP;                    // I2C stop condition
	IFG2 &= ~UCB0TXIFG;                     // Clear TX interrupt flag
}

char i2cRx(char slvAddr, char regAddr){
	char rxByte;
	UCB0I2CSA = slvAddr;           // Slave Address is 039h when floating
	while (UCB0CTL1 & UCTXSTP);             // Ensure stop condition got sent
	UCB0CTL1 |= UCTR + UCTXSTT;             // I2C start condition with UCTR flag for transmit
	while(i2cTxBusy());
	UCB0TXBUF = regAddr;
	while(i2cTxBusy());
	UCB0CTL1 &= ~UCTR ;
	UCB0CTL1 |= UCTXSTT + UCTXNACK;
	while (UCB0CTL1 & UCTXSTT);
	while(UCB0RXIFG != (IFG2 & UCB0RXIFG));
	rxByte = UCB0RXBUF;
	UCB0CTL1 |= UCTXSTP;                    // I2C stop condition
	return rxByte;
}
