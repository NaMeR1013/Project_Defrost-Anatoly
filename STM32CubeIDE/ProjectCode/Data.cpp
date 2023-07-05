/*
 * Data.cpp
 *
 *  Created on: Jul 3, 2023
 *      Author: gdr
 */
#include "Data.hpp"
#include "cmsis_os.h"


extern "C" {

void Data_Task_Func()
	{
		osDelay(1000);
	}

}
