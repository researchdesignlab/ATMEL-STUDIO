/*
 * Project Name
 * LED blinking using 2560 and Atmelstudio
 * Created: 10-10-2018 09:13:05 AM
 * Copyright
   (c) Researchdesignlab.com
 * Description:
   This program illustrates simple IO operation of atmega2560 using Atmelstudio
 * LED is connected to Port C pin no 3
 * Test configuration:
	 MCU:             AT2560
	 Dev.Board:       2560
	 Oscillator:      14.74 MHz
	 Software:        Atmel Studio V6
 */ 
#define F_CPU 14745600 //setting Clock frequency 
#include <avr/io.h>
#include <util/delay.h>// Library to call delay function


void Dout_pin_conf(void) 
{
	DDRC=0x08;	     /* PORT C3 pin is assigned as output by making c3 pin as high */
	PORTC=0x00;      /* Setting initial value of PORT C3 as 00                     */
	
}
void Dout_pin_on(void)
{
	PORTC= PORTC|0x08;  /* PORTC3 pin made high which turns ON Dout_pin*/
}

void Dout_pin_off(void) 
{
	PORTC=PORTC & 0xF7; /* PORTC3 pin made LOW which turns OFF Dout_pin*/
	
}

int main(void) 
{Dout_pin_conf();     /*    Configure Dout pins                           */
	while(1)   
	{
		Dout_pin_on(); /*   Dout_pin is ON                                */
		_delay_ms(1000);/*  Dout_pin is ON for delay of 1000 mili seconds */
		Dout_pin_off(); /*  Dout_pin is OFF                               */
		_delay_ms(1000);/*  Dout_pin is ON for delay of 1000 mili seconds */
		
	}
}