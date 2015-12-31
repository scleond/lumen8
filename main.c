#include "msp.h"
#include "driverlib.h"
#include "i2c_lumen8.h"
#include "clk_lumen8.h"
#include "uart_lumen8.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "printf.h"

static volatile uint32_t smclk;
unsigned int data;
unsigned int lux;

char integTime = TSL2561_INTEGRATIONTIME_13MS;
char tslGain = TSL2561_GAIN_0X;

int main(void){
	MAP_WDT_A_holdTimer();  // stop watchdog

	initCLK();
	initI2C();
//	initUART();

	enableTSL2561(integTime, tslGain);

	smclk = CS_getSMCLK();

	while(1){
		_delay_cycles(5000);
		lux = CalculateLux(tslGain, integTime, TSL2561_PACKAGE_T_FN_CL);
//		printf(EUSCI_A0_MODULE, "Brightness =  %u\r\n", data);
	}
}
