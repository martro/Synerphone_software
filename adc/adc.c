/*
 * adc.c
 *
 *  Created on: 21 maj 2015
 *      Author: Marcin
 */
#include "adc.h"

void init_adc()
{

	ADMUX |= (1<<REFS0);//VCC as reference, ADC0



	ADCSRA |= (1<<ADPS1) // Prescaler = 64, freq=125kHz
			|(1<<ADPS2)
			|(1<<ADATE)	// Free Running mode
			|(1<<ADEN)	// turn on ADC
			|(1<<ADSC); //initialize

	//wynik odczytac np. a= ADC;
}

