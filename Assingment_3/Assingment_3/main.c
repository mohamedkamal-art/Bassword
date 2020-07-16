/*
 * Assingment_3.c
 *
 * Created: 7/15/2020 11:18:32 AM
 * Author : mohammed
 */ 

#define	F_CPU	16000000
#include<util/delay.h>
//#include <avr/io.h>
#include "LCD.h"

uint8 KeyPad_GetValue(void);

int main(void)
{
  
   
    while (1) 
    {
		
		 uint8 count=0, keypad_value, password_status=0;
		 uint8 password_set[5]="1234", password_entered[5];
		 uint8 value = 0;
		 
		 LCD_Init();
		 KeyPad_Init();
		 Temp_Sensor_Init();
		 
		 
		 while(password_status==0x00)
		 {
			 
			 while(count<4)
			 {
				 keypad_value = KeyPad_GetValue();
				 
				 
				 password_entered[count]=keypad_value+48;
				 
				 count++;
				 _delay_ms(500);
			 }
			 _delay_ms(300);
			 count=0;
			 
			 password_entered[4]=0;
			 
			 if(!(strcmp(password_set,password_entered)))
			 {
				 Temp_Sensor_GetValue(&value);
				 LCD_WriteString("PASSED");
				 _delay_ms(500);
				 LCD_Clear();
				 LCD_WriteInterger(value);
			 }
			 else{LCD_WriteString("WRONG BASSWORD");
			 }
		 }
		
		
    }
}

