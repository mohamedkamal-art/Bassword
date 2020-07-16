/*
 * Temp_Sensor.h
 *
 * Created: 7/14/2020 7:56:29 AM
 *  Author: mohammed
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC.h"

void Temp_Sensor_Init(void);

void Temp_Sensor_GetValue(uint16* Temp);





#endif /* TEMP_SENSOR_H_ */