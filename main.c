/* Chris made this*/

#include "lumen8.h"

void initTimerA0(void);

uint8_t readSensors = 0;
uint8_t adjustLight = 0;

int main(void){
	MAP_WDT_A_holdTimer();  // stop watchdog



	static uint8_t tslIntegTime = TSL2561_INTEGRATIONTIME_101MS;  // integration time and gain used for lux calc. 101ms gives more consistent result than 13ms for now
	static uint8_t tslGain = TSL2561_GAIN_0X;

	static uint8_t avgCounts = 2;
	int32_t lux = 0;
	int32_t avgLux = 0;
	int32_t lastAvg = 0;
	int32_t newLux = 0;
	int32_t sum = 0;

	int8_t updatePattern = 0;

	uint8_t rtcSeconds;
	uint8_t rtcMinutes;
	uint8_t rtcHours;


	uint8_t senseState = READ_TSL2561;

	initCLK();  //set DCO for 48MHz. Adjusting this will require adjusting i2c baudrate settings
	initI2C();
	initGPIO();
	enableSensors(tslIntegTime, tslGain);
	initTimerA0();

    /* Enabling MASTER interrupts */
    MAP_Interrupt_enableMaster();

	testPattern();
	while(1){
		if(readSensors){
			if(senseState == READ_TSL2561){
				lastAvg = avgLux;
				lux = CalculateLux(tslGain, tslIntegTime, TSL2561_PACKAGE_T_FN_CL);
				avgLux = ((avgLux * (avgCounts-1)) + lux)/avgCounts;
				senseState = READ_DS1307;
			}
			else if(senseState == READ_ISL29125){  // skipping the rgb sensor for now
				//			islID = readDevID_ISL29125();
				senseState = READ_DS1307;
			}
			else if(senseState == READ_DS1307){
//				rtcSeconds = bcd2decimal(readSeconds());
				rtcMinutes = bcd2decimal(readMinutes());
				rtcHours = bcd2decimal(readHours());
				senseState = READ_TSL2561;
			}
			readSensors = 0;
		}

//		rotatePatternForward();
//		delay(lux*5000);
//		sendPattern();

		if((rtcHours > 17) & (rtcHours < 23)){
			updatePattern = 1;
		}
		else{
			updatePattern = 0;
			blankPattern();
			sendPattern();
		}

		if(updatePattern & (adjustLight >= 2)){
//			int32_t diff = avgLux - newLux;
//			sum += diff;
//			newLux += (diff)*0.005 + sum*0.0002;
			int8_t lightStep = 0;
			if(avgLux > newLux + 1){
				lightStep = 1;
			}
			if(avgLux < newLux){
				lightStep = -1;
			}

			newLux += lightStep;

			if(newLux > MAX_BRIGHTNESS){
				newLux = MAX_BRIGHTNESS;
			}
			if(newLux < 0){
				newLux = 0;
			}
			fillPattern(MAX_BRIGHTNESS - newLux);
			sendPattern();
			adjustLight = 0;
		}
	}
}

void timer_a_0_isr(void)  // must add this to interrupt vector stack in startup_ccs.c
{
	readSensors = 1;
	adjustLight++;
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_MODULE,
            TIMER_A_CAPTURECOMPARE_REGISTER_0);
}


