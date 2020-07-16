/*
 * ADC.h
 *
 * Created: 7/14/2020 1:24:45 AM
 *  Author: mohammed
 */ 


#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"
#include "ADC_Cfg.h"

#ifndef ADC_H_
#define ADC_H_

/******************************************** ADC_VOLTAGE_REFRENCE **************************/
#define ADC_EXternal_source  0
#define ADC_VREF_Avcc        1
#define ADC_Internal_2_56v   4

/******************************************** ADC_ADJUCENT  **********************************/

#define ADC_RIGHT_ADJUST     0
#define ADC_LEFT_ADJUST      1

/************************************************ ADC_CHANNEL ********************************/
#define ADC_CHANNEL_0         0 
#define ADC_CHANNEL_1         1
#define ADC_CHANNEL_2         2
#define ADC_CHANNEL_3         3
#define ADC_CHANNEL_4         4
#define ADC_CHANNEL_5         5
#define ADC_CHANNEL_6         6
#define ADC_CHANNEL_7         7

/************************************************ ADC_CONVERSION_TRIGGER ****************************/

#define  ADC_OUTO_TRIGGER    0

/************************************************* ADC_PRESCALLER ***********************************/
#define ADC_PRESC_0        0
#define ADC_PRESC_2        1
#define ADC_PRESC_4        2
#define ADC_PRESC_8        3
#define ADC_PRESC_16       4
#define ADC_PRESC_32       5
#define ADC_PRESC_64       6
#define ADC_PRESC_128      7

/************************************************* ADC_INTERRUPT_STATUS *****************************/
#define ADC_INTERRUPT_DISABLE 0
#define ADC_INTERRUPT_ENABLE  1



/*************************************************** API'S ******************************************************************************/

void ADC_Init(void);

void ADC_Read(uint16*value);



#endif /* ADC_H_ */