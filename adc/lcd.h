/*
 * lcd.h
 *
 *  Created on: 6 kwi 2015
 *      Author: Marcin
 */

#ifndef LCD_H_
#define LCD_H_

#include "globals.h"
#include "HD44780.h"
#include "string.h"
#include "stdlib.h"

extern volatile unsigned char LCD_top[17];
extern volatile unsigned char LCD_bottom[17];


void lcd_display(char* top, char* bottom);
void mode_1(void);
void mode_2(void);

#endif /* LCD_H_ */
