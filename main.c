/* Chris made this*/


#include "lumen8.h"

unsigned char senseState = READ_TSL2561;

int main(void){
	MAP_WDT_A_holdTimer();  // stop watchdog

	static unsigned char tslIntegTime = TSL2561_INTEGRATIONTIME_13MS;  // integration time and gain used for lux calc. 101ms gives more consistent result than 13ms for now
	static unsigned char tslGain = TSL2561_GAIN_0X;

	static unsigned char avgCounts = 4;

	unsigned short lux = 0;
	unsigned short ch0;
	unsigned short ch1;
	unsigned short avgLux = 0;

	unsigned char islID;
	unsigned char rtcSeconds;
	unsigned char rtcMinutes;
	unsigned char rtcHours;
	unsigned char rtcDate;
	unsigned char rtcMonth;
	unsigned char rtcYear;

	initCLK();  //set DCO for 2MHz. Adjusting this will require adjusting i2c baudrate settings
	initI2C();
	enableSensors(tslIntegTime, tslGain);

	while(1){
		_delay_cycles(1000);
		if(senseState == READ_TSL2561){
//			lux = CalculateLux(tslGain, tslIntegTime, TSL2561_PACKAGE_T_FN_CL);
			ch0 = readChan0_TSL2561();
			ch1 = readChan1_TSL2561();
//			avgLux = ((avgLux * (avgCounts-1)) + lux)/avgCounts;
			senseState = READ_ISL29125;
		}
		else if(senseState == READ_ISL29125){
			islID = readDevID_ISL29125();
			senseState = READ_DS1307;
		}
		else if(senseState == READ_DS1307){
			rtcSeconds = readSeconds();
			rtcMinutes = readMinutes();
			rtcHours = readHours();
			rtcDate = readDate();
			rtcMonth = readMonth();
			rtcYear = readYear();
			senseState = READ_TSL2561;
		}
	}
}


