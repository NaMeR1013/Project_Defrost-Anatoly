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
//<gui/settings1_screen/Settings1View.hpp>

// ReadDataEventHandle was defined in main.c
extern osEventFlagsId_t ReadDataEventHandle;
// extern variables
//void BTN_TSetInc_C(void);

//#ifdef __c
//extern "C++" {
//#endif
//
//#include "Settings1View.hpp"
//extern int Settings1View::Settings1ViewBase::CoreTSet;
//
//#ifdef __c
//{
//#endif

int16_t CurrentTime = 0;	// current number of measure
int8_t ArrayCnt = 0;		// counter for measure array
uint32_t flags;				// flags for waiting event

struct Sensor {				// structure definition
	int16_t Time;			// number of time quantum measuring
	int16_t T, H;			// temperature, humidity

};

class Sensor1 {
public:
//	PushData1();

private:
	int TData;
};

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

// Operating system timer 1 sec will start this function

extern "C"
{
	void DataTimerFunc_C()
	{
		DataTimerFunc();
	}
	void ReadDataFunc_C()
	{
		ReadDataFunc();
	}
	void DataFunc_C()
	{
		DataFunc();
	}
}

void DataTimerFunc()
{
	HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
	// Здесь установка флага события для запуска задачи по считыванию данных
	osEventFlagsSet(ReadDataEventHandle, FLAG_ReadData);
	osDelay(100);
	HAL_GPIO_TogglePin(GPIOG, LD4_Pin);

}

// The task ReadData reading data from sensors
void ReadDataFunc() {
	//Здесь ожидание флага, чтобы запустить задачу ReadData
	flags = osEventFlagsWait(ReadDataEventHandle, FLAG_ReadData, osFlagsWaitAny, osWaitForever);
	//Здесь код для считывания данных с датчиков:

	// Считывание с последовательной шины

	// запись в массив данных

	// запись в очередь передачи данных в удалённый компьютер

	// запись в переменные экрана, если есть изменения
//	BTN_TSetInc_C();
	// установка флага FLAG_DataAnalysis для запуска задачи DataAnalysis
}
