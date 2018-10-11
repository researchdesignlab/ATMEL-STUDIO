/*
 * Project Name
 * LCD display using 2560 and Atmelstudio
  * Copyright
   (c) Researchdesignlab.com
 * Description:
   In this program Data is displayed on LCD screen using atmega2560 and Atmelstudio
 * LCD Connections:
   LCD	  Micro-controller Pins
   RS  --> PC0
   RW  --> PC1
   EN  --> PC2
   DB7 --> PC7
   DB6 --> PC6
   DB5 --> PC5
   DB4 --> PC4

 * Test configuration:
	 MCU:             AT2560
	 Dev.Board:       2560
	 Oscillator:      14.74 MHz
	 Software:        Atmel Studio V6
 */ 
#define F_CPU 14745600// Setting up clock frequency

#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

// Main Function
int main(void)
{
	lcd_port_config();  /* Configure LCD pins */
	lcd_init();         /* Init LCD           */
	
	while(1) 
	{
		lcd_string(1, 4, "WELCOMES");  /* Display Data on line row = 1, Column = 4  */
		lcd_string(2, 1, "RDL");	   /* Display Data on line row = 2, Column = 1  */
	}
}
