/*
 * main.c
 *
 *  Created on: 21 maj 2015
 *      Author: Marcin
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "HD44780.h"
#include "globals.h"
#include "string.h"
#include "LED.h"
#include "lcd.h"
#include "adc.h"
#include <math.h>

int main(void)
{
	MCUCSR |=(1<<JTD);
	MCUCSR |=(1<<JTD);

	LCD_Initalize();

	_delay_ms(500);
	init_adc();

	_delay_ms(500);
	sei();

	char tekst[]="aaaaa";


	int a=10;


	while(1)
	{
		a=ADC;
		itoa(a,tekst,10);
		strcat(tekst,"   ");

		lcd_display(tekst,"ADC");
		_delay_ms(300);
	}

	return 0;
}

