/*
 * Project Name
 * Reading Analog values and Printing on LCD screen using 2560 and Atmelstudio
 * Created: 10-10-2018 10:15:05 AM
 * Copyright
   (c) Researchdesignlab.com
 * Description:
	In this program Analog vales are read from ADC port 3 and displaying it on LCD screen    
*  LCD Connections:
	LCD	  Micro-controller Pins
	RS  --> PC0
	RW  --> PC1
	EN  --> PC2
	DB7 --> PC7
	DB6 --> PC6
	DB5 --> PC5
	DB4 --> PC4
*ADC connection
   ACD CH.	PORT	
   3		PF3
   

 * Test configuration:
	 MCU:             AT2560
	 Dev.Board:       2560
	 Oscillator:      14.74 MHz
	 Software:        Atmel Studio V6
 */ 


#define F_CPU 14745600// Setting up clock frequency
#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include "lcd.h" // Including Library for LCD

void adc_pin_config (void) // Configure ADC Ports
{
	DDRF=0x00;
	DDRK=0x00;
}

void adc_init() // Set Register Values for starting ADC
{
	ADCSRA =0x00;
	ADCSRB =0x00;
	ADMUX =0x20;
	ADCSRA =0x86;
	ACSR =0x80;
}

/* This Function accepts the Channel Number and returns the corresponding Analog Value  */
unsigned char ADC_Conversion(unsigned char Ch)
{
	unsigned char a;
	if(Ch>7)
	{
		ADCSRB = 0x08;
	}
	Ch = Ch & 0x07;
	ADMUX= 0x20 | Ch;
	ADCSRA = ADCSRA | 0x40; // Set start conversion bit
	while((ADCSRA&0x10)==0); // Wait for ADC conversion to complete
	a=ADCH;
	ADCSRA = ADCSRA|0x10; // Clear ADIF (ADC Interrupt Flag) by writing 1 to it
	ADCSRB = 0x00;
	return a;
}

/*  This Function prints the Analog Value Of Corresponding Channel No. at required Row
 and Column Location.*/

void print_sensor(char row, char column, unsigned char channel)
{
	unsigned char ADC_Value;// Variable to store ADC values
	ADC_Value = ADC_Conversion(channel);// Reading ADC values from channel specified and store it in variable
	lcd_numeric_value(row, column, ADC_Value, 3);// Pring Numeric values on LCD screen
}

int main(void)
{
	lcd_port_config();// LCD pin configuration function
	lcd_init();       // LCD Initialization function
	adc_pin_config ();// ADC pin configuration function
	adc_init();      // ADC Initialization function
	while(1)
	{
		print_sensor(1,1,3); // Reading Analog values from ADC channel 3 and printing on LCD
	}
}

