/*
 * Data.cpp
 *
 *  Created on: Jul 3, 2023
 *      Author: gdr
 */
#include "Data.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

int16_t CurrentTime = 0;	// current number of measure
int8_t ArrayCnt = 0;		// counter for measure array

struct Sensor {				// structure definition
	int16_t Time;			// number of time quantum measuring
	int16_t T, H;			// temperature, humidity

};

//int PopData(int16_t TimeFromStart, int8_t SensNum, int8_t Param);

struct Sensor Measure[TQ][SQ];	// define Measure array


void DataFunc()
	{

	osDelay(1000);
	PushData();
	}

void PushData() {
	int8_t i=0;
	CurrentTime += 1;		// this is counter of measure from the start

	ArrayCnt =+ 1;			// array counter value must be inside the array size
	if (ArrayCnt == TQ) ArrayCnt = 0;


	for (i = 0; i < SQ; ++i) {
		Measure[ArrayCnt][i].Time = CurrentTime;
		Measure[ArrayCnt][i].T = 15+i;
		Measure[ArrayCnt][i].H = 80+i;
	}


}

// Return integer value from measure array
// TimeFromStart - value of measure counter give correct data only for last TQ measures
// SensNum - number of interesting sensor
// Param - 1 for temperature, 2 for humidity
int PopData(int TimeFromStart, int SensNum, int Param) {
	int8_t i= TimeFromStart % TQ;

	switch (Param) {
		case 1:
			return Measure[i][SensNum].T;
			break;
		case 2:
			return Measure[i][SensNum].H;
			break;
		default:
			return 0;
			break;
	}
}
