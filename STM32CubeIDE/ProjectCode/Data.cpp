/*
 * Data.c
 *
 *  Created on: Jul 3, 2023
 *      Author: gdr
 */
#include <Data.hpp>
#include "main.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

#include <gui/settings1_screen/Settings1View.hpp>
#include <touchgfx/utils.hpp>
#include <iostream>

// ReadDataEventHandle was defined in main.c
extern osEventFlagsId_t ReadDataEventHandle;
Settings1View Scr1;

uint CurrentTime = 0;	// current number of measure
int8_t ArrayCnt = 0;		// counter for measure array
uint32_t flags;				// flags for waiting event

extern "C"
{
	void DataTimerFunc_C()	// start from osTimer 1 sec
	{
		DataTimerFunc();
	}
	void ReadDataFunc_C()	// start ReadData after timer
	{
		ReadDataFunc();
	}
	void DataFunc_C()		// start DataAnalysis
	{
		DataFunc();
	}
	void InitDataVariables_C()
	{
// here must be initialization of variables
		//		InitData();
	}
}

class Sensor {
private:
	uint Time[TQ][SQ] = {{0}};	// number of time quantum measuring
	float T[TQ][SQ] = {{0}};		// temperature
	float H[TQ][SQ] = {{0}};		// humidity
public:
	Sensor() {};								// declare default constructor
	Sensor(int Time, float T, float H){};		// declare constructor

	// Return integer value from measure array
	// TimeFromStart - value of measure counter give correct data only for last TQ measures
	// SensNum - number of interesting sensor
	// Param - 1 for time, 2 for temperature, 3 for humidity
	// Val - value of data
	void PutData(uint TimeFromStart, int8_t SensNum, int8_t Param, float Val) {
			int8_t i= TimeFromStart % TQ;

			switch (Param) {
				case 1:
					Time[i][SensNum] = Val;
					break;
				case 2:
					T[i][SensNum] = Val;
					break;
				case 3:
					H[i][SensNum] = Val;
					break;
				default:
					break;
			}
		;
	}
	//	 Return integer value from measure array
	//	 TimeFromStart - value of measure counter give correct data only for last TQ measures
	//	 SensNum - number of interesting sensor
	//	 Param - 1 for time, 2 for temperature, 3 for humidity
	int16_t GetData(uint TimeFromStart, int8_t SensNum, int8_t Param) {
		uint i = TimeFromStart % TQ;
			switch (Param) {
				case 1:
					return Time[i][SensNum];
					break;
				case 2:
					return T[i][SensNum];
					break;
				case 3:
					return H[i][SensNum];
					break;
				default:
					return 0;
					break;
			}
	}
};

// 1. Operating system timer 1 sec will start this function
void DataTimerFunc()
{
	HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
	// Здесь установка флага события для запуска задачи по считыванию данных
	osEventFlagsSet(ReadDataEventHandle, FLAG_ReadData);
	osDelay(100);
	HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
}

// 2. The task ReadData reading data from sensors
void ReadDataFunc() {
	//Здесь ожидание флага, чтобы запустить задачу ReadData
	flags = osEventFlagsWait(ReadDataEventHandle, FLAG_ReadData, osFlagsWaitAny, osWaitForever);
	Sensor s;
	int8_t SensorNumder;
	float T, H;
	//Здесь код для считывания данных с датчиков:

	// Считывание с последовательной шины
	SensorNumder = 1;
	T = 10.31;
	H = 50.78;
	// запись в массив данных
	s.PutData(CurrentTime, SensorNumder, 1, CurrentTime);
	s.PutData(CurrentTime, SensorNumder, 2, T);
	s.PutData(CurrentTime, SensorNumder, 3, H);
	CurrentTime ++;
	// запись в очередь передачи данных в удалённый компьютер

	// запись в переменные экрана, если есть изменения
//	Unicode::snprintf(Settings1View::ValueCoreTSetBuffer, Settings1View::VALUECORETSET_SIZE, "%d", Settings1View::CoreTSet);
//	Scr1.BTNCoreTSetIncreaseClicked();
	// установка флага FLAG_DataAnalysis для запуска задачи DataAnalysis
}

// 3. The task DataAnalysis processing data from sensors
void DataFunc()
	{
	osDelay(1000);
//	PushData();
	}

//void Data() {
//	Sensor Measure(1, 2, 3);
//	int8_t i=0;
//	CurrentTime += 1;		// this is counter of measure from the start
//
//	ArrayCnt =+ 1;			// array counter value must be inside the array size
//	if (ArrayCnt == TQ) ArrayCnt = 0;
//
//
//	for (i = 0; i < SQ; ++i) {
//		CurrentTime = Sensor::Time;
////		Measure.T = 15+i;
////		Measure.H = 80+i;
//	}
//
//
//}

// Return integer value from measure array
// TimeFromStart - value of measure counter give correct data only for last TQ measures
// SensNum - number of interesting sensor
// Param - 1 for temperature, 2 for humidity
//int PopData(int TimeFromStart, int SensNum, int Param) {
////	int8_t i= TimeFromStart % TQ;
//
//	switch (Param) {
//		case 1:
////			return Measure[i][SensNum].T;
//			return 0;
//			break;
//		case 2:
//			//return Measure[i][SensNum].H;
//			return 0;
//			break;
//		default:
//			return 0;
//			break;
//	}
//}
//
