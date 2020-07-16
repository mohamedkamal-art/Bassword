/*
 * Temp_Sensor.c
 *
 * Created: 7/14/2020 7:56:51 AM
 *  Author: mohammed
 */ 

#include "Temp_Sensor.h"

void Temp_Sensor_Init(void)
{
	 ADC_Init();
}


void Temp_Sensor_GetValue(uint16* Temp)
{
	ADC_Read(Temp);
}