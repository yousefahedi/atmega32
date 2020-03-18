/*
 * LCD.h
 *
 *  Created on: Sep 7, 2018
 *      Author: youse
 */

#ifndef LCD_H_
#define LCD_H_

#define CLR       0X01	// CLEAR DISPLAY
#define RESET_AC  0X02	// RESET ADDRESS COUNTER
#define INC_AC    0X06	// INCREMENT ADDRESS COUNTER
#define DISP_ON   0X0C	// TURNS DISPLAY ON
#define _2_LINE   0X38	// 2 LINE DISPLAY
#define _1_Line   0X30	// 1 LINE DISPLAY
#define SHL	   	  0X18	// Shift Left
#define SHR 	  0X1C // Shift Right




void LCD_vidSetAC(u8 Address);

void LCD_vidInit(void);

void LCD_vidSendCommand(u8 Command);

void LCD_vidSendData(u8 Data);

void LCD_vidPrintNumber(u16 number);

u8 LCD_u8SendString(u8* String);

u8 LCD_u8SendSineString(u8* Sine);

#endif /* LCD_H_ */
