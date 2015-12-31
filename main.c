/* Chris made this*/

#include "msp.h"
#include "tsl2561.h"
#include "isl29125.h"

#include "driverlib.h"
#include "i2c_lumen8.h"
#include "clk_lumen8.h"
#include "uart_lumen8.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "printf.h"

#define READ_TSL2561 		(0x00)
#define READ_ISL29125		(0x01)

unsigned int data;
unsigned int lux = 0;
unsigned char islID;

unsigned char integTime = TSL2561_INTEGRATIONTIME_13MS;  // integration time and gain are used to calculate lux
unsigned char tslGain = TSL2561_GAIN_0X;

unsigned char senseState = READ_TSL2561;

int main(void){
	MAP_WDT_A_holdTimer();  // stop watchdog

	initCLK();  //set DCO for 2MHz. Adjusting this will require adjusting i2c baudrate settings
	initI2C();
//	initUART();  // attempting to use usb backchannel uart.....PC issues with COM port, haven't tested with printf

	enableTSL2561(integTime, tslGain);  //TSL2561 is default inactive. turn on here
	initISL29125();  // set for full RGB mode

	while(1){
		_delay_cycles(5000);
		switch(senseState){
		case READ_TSL2561:
			lux = CalculateLux(tslGain, integTime, TSL2561_PACKAGE_T_FN_CL);
			senseState = READ_ISL29125;
		case READ_ISL29125:
//			islID = readDevID_ISL29125();
			senseState = READ_TSL2561;
		}
	}
}
