/* Chris made this*/


#include "lumen8.h"

static unsigned char tslIntegTime = TSL2561_INTEGRATIONTIME_101MS;  // integration time and gain used for lux calc. 101ms gives more consistent result than 13ms for now
static unsigned char tslGain = TSL2561_GAIN_0X;

unsigned int lux;
unsigned int avgLux = 0;
static unsigned char avgCounts = 4;
unsigned char islID;

unsigned char senseState = READ_TSL2561;

int main(void){
	MAP_WDT_A_holdTimer();  // stop watchdog

	initCLK();  //set DCO for 2MHz. Adjusting this will require adjusting i2c baudrate settings
	initI2C();
	enableSensors(tslIntegTime, tslGain);




	while(1){
		_delay_cycles(25000);
		if(senseState == READ_TSL2561){
			lux = CalculateLux(tslGain, tslIntegTime, TSL2561_PACKAGE_T_FN_CL);
			lux = CalculateLux(tslGain, tslIntegTime, TSL2561_PACKAGE_T_FN_CL);
			avgLux = ((avgLux * (avgCounts-1)) + lux)/avgCounts;
			senseState = READ_ISL29125;
		}
		else if(senseState == READ_ISL29125){
			islID = readDevID_ISL29125();
			islID = readDevID_ISL29125();
			senseState = READ_TSL2561;
		}
	}
}


