/* Chris made this*/

#include "lumen8.h"

void initTimerA0(void);

int main(void){
	MAP_WDT_A_holdTimer();  // stop watchdog

	static uint8_t tslIntegTime = TSL2561_INTEGRATIONTIME_101MS;  // integration time and gain used for lux calc. 101ms gives more consistent result than 13ms for now
	static uint8_t tslGain = TSL2561_GAIN_0X;

	static uint8_t avgCounts = 2;
	uint16_t lux = 0;
	uint16_t avgLux = 0;

	uint16_t milliseconds = 0;

	uint8_t islID;
	uint8_t rtcSeconds;
	uint8_t rtcMinutes;
	uint8_t rtcHours;

	uint8_t senseState = READ_TSL2561;

	initCLK();  //set DCO for 48MHz. Adjusting this will require adjusting i2c baudrate settings
	initI2C();
	initGPIO();
	enableSensors(tslIntegTime, tslGain);
//	initTimerA0();

	uint32_t smclk = CS_getSMCLK();
	uint32_t mclk = CS_getMCLK();

    /* Enabling MASTER interrupts */
//    MAP_Interrupt_enableMaster();

	testPattern();
	while(1){
		heartbeat(lux);
		if(senseState == READ_TSL2561){
			lux = CalculateLux(tslGain, tslIntegTime, TSL2561_PACKAGE_T_FN_CL);
			avgLux = ((avgLux * (avgCounts-1)) + lux)/avgCounts;
			senseState = READ_ISL29125;
		}
		else if(senseState == READ_ISL29125){
//			islID = readDevID_ISL29125();
			senseState = READ_DS1307;
		}
		else if(senseState == READ_DS1307){
			rtcMinutes = readMinutes();
			rtcHours = readHours();
			senseState = READ_TSL2561;
		}
	}
}

void timer_a_0_isr(void)  // must add this to interrupt vector stack in startup_ccs.c
{
//    MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P5, GPIO_PIN5);
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_MODULE,
            TIMER_A_CAPTURECOMPARE_REGISTER_0);
}


