/*
 * ADC.c
 *
 * Created: 7/14/2020 1:24:24 AM
 *  Author: mohammed
 */ 

#include "ADC.h"

void ADC_Init(void)
{
/******************************************** ADC_VOLTAGE_REFRENCE **************************/

    #if     ADC_VOLTAGE_REFRENCE   ==  ADC_EXternal_source
	
		CLR_BIT(ADMUX , 6);
	    CLR_BIT(ADMUX , 7);
		
	#elif   ADC_VOLTAGE_REFRENCE   ==  ADC_VREF_Avcc

		SET_BIT(ADMUX , 6);       //  Voltage reference work as AVCC  ADMUX pit 6 = 1 , pit 7 = 0
		CLR_BIT(ADMUX , 7);
		
	#elif ADC_VOLTAGE_REFRENCE   ==  ADC_Internal_2_56v
	
		SET_BIT(ADMUX , 6);
		SET_BIT(ADMUX , 7);
		
   #endif 
 
   /******************************************** ADC_CHANNEL  **********************************/
   
    #if   ADC_CHANNEL        ==       ADC_CHANNEL_0   
	
	CLR_BIT( ADMUX , 0 );
	
    #elif ADC_CHANNEL        ==       ADC_CHANNEL_1 // bit 0 of register ADMUX  = 1 to select channel 1
	
    SET_BIT(ADMUX , 0);
	
	#elif ADC_CHANNEL        ==       ADC_CHANNEL_2
	
	SET_BIT(ADMUX , 1);
	
	#elif ADC_CHANNEL        ==       ADC_CHANNEL_3
	
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	
	#elif ADC_CHANNEL        ==       ADC_CHANNEL_4
	
	SET_BIT(ADMUX , 2);
	
	#elif ADC_CHANNEL        ==       ADC_CHANNEL_5
	
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 2);
	
	#elif ADC_CHANNEL        ==       ADC_CHANNEL_6
	
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	
	#elif ADC_CHANNEL        ==       ADC_CHANNEL_7
	
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	
    #endif
	
	
	/******************************************** ADC_ADJUCENT  **********************************/
   
   #if ADC_ADJUCENT        ==     ADC_RIGHT_ADJUST // bit 5 of register ADMUX (ADLAR) control with adjust 
   
   CLR_BIT(ADMUX , 5);                             //clr bit 5 to RIGHT ADJUST
   
   #elif ADC_ADJUCENT        ==     ADC_LEFT_ADJUST
   
   SET_BIT(ADMUX , 5);

   #endif
   
   /************************************************ ADC_CONVERSION_TRIGGER ****************************/
   
   #if ADC_CONVERSION_TRIGGER  ==  ADC_OUTO_TRIGGER //bit 5 in ADCSRA = 1 (auto triggered) be default is free running mode
   
   SET_BIT(ADCSRA , 5);

   #endif
   
   /************************************************* ADC_PRESCALLER ***********************************/
   #if ADC_PRESCALLER     ==      ADC_PRESC_0 
   
   CLR_BIT(ADCSRA , 0);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_2 
   
   SET_BIT(ADCSRA , 0);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_4 
   SET_BIT(ADCSRA , 1);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_8 
   SET_BIT(ADCSRA , 0);
   SET_BIT(ADCSRA , 1);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_16 
   SET_BIT(ADCSRA , 2);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_32 
   
   SET_BIT(ADCSRA , 0);
   SET_BIT(ADCSRA , 2);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_64 
   
   SET_BIT(ADCSRA , 1);
   SET_BIT(ADCSRA , 2);
   
   #elif ADC_PRESCALLER     ==      ADC_PRESC_128 // bits 2,1,0 in ADCSRA register to make scaler 128
   
   SET_BIT(ADCSRA , 2);
   SET_BIT(ADCSRA , 1);
   SET_BIT(ADCSRA , 0);

   #endif
   
  /************************************************* ADC_INTERRUPT_STATUS *****************************/
   
   #if ADC_INTERRUPT_STATUS  ==   ADC_INTERRUPT_DISABLE // bit 3 in ADCSRA register to disable interrupts
   
    SET_BIT(ADCSRA , 3 );

	#elif ADC_INTERRUPT_STATUS  ==   ADC_INTERRUPT_ENABLE
	
	CLR_BIT(ADCSRA , 3);
	 
   #endif
   
   /*Enable ADC*/
   SET_BIT(ADCSRA , 7);
}

void ADC_Read(uint16*value)
{
	uint16 Digital_value = 0; // output of ADC
	
	 SET_BIT(ADCSRA , 6); // start conversion
	 
	  #if ADC_INTERRUPT_STATUS  ==   ADC_INTERRUPT_DISABLE // using polling way
	 
	 while(! GET_BIT(ADCSRA , 4)); // stuck if conversion not complete 
	 
	 Digital_value = MERGE_REG; // get digital output value
	 
	 *value = ((Digital_value * 500 )/1024);
	 
	 #endif // if interrupt enable you can't polling on flag
	 
	 
	
}