/*
 * Data.hpp
 *
 *  Created on: Jul 3, 2023
 *      Author: gdr
 */

#ifndef DATA_H_
#define DATA_H_

#define TQ 16				// time quantity for saving measures in array
#define SQ 9				// sensors quantity for measures
#define FLAG_ReadData 1ul		// read data event flag 0x00000001ul


void DataFunc(void);
void DataTimerFunc();
void PushData();
int PopData(int TimeFromStart, int SensNum, int Param);
void ReadDataFunc();


#endif /* DATA_H_ */

