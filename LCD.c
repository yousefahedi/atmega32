
/*
 * LCD.c
 *
 *  Created on: Sep 7, 2018
 *      Author: youse
 */
#include "STD_TYPES.h"
#define F_CPU 12000000UL
#include <util/delay.h>

#include "DIO.h"
#include "LCD.h"
#include "LCD_CFG.h"

void LCD_vidInit(void)
{
	_delay_ms(50);

	/*2-Line Display*/
	LCD_vidSendCommand(_2_LINE);

	_delay_ms(1);

	/*Display ON*/
	LCD_vidSendCommand(DISP_ON);

	_delay_ms(1);

	/*CLEARS DISPLAY*/
	LCD_vidSendCommand(CLR);

	_delay_ms(2);

	/*INCREMENT AC*/
	LCD_vidSendCommand(INC_AC);
}

void LCD_vidSendCommand(u8 Command)
{
	DIO_SetPinValue(RS_PORT, RS_PIN, LOW);

	DIO_SetPinValue(RW_PORT, RW_PIN, LOW);

	DIO_SetPortValue(DATA_PORT, Command);

	DIO_SetPinValue(E_PORT, E_PIN, HIGH);

	_delay_ms(2);

	DIO_SetPinValue(E_PORT, E_PIN, LOW);
}

void LCD_vidSendData(u8 Data)
{
	DIO_SetPinValue(RS_PORT, RS_PIN, HIGH);

	DIO_SetPinValue(RW_PORT, RW_PIN, LOW);

	DIO_SetPortValue(DATA_PORT, Data);

	DIO_SetPinValue(E_PORT, E_PIN, HIGH);

	_delay_ms(2);

	DIO_SetPinValue(E_PORT, E_PIN, LOW);
}
void LCD_vidSetAC(u8 Address)
{
	LCD_vidSendCommand(Address);
}

u8 LCD_u8SendString(u8* String)
{
	u8 i = 0;

	while(String[i] != 0)
	{
		LCD_vidSendData(String[i]);
		i++;
	}
	return i;
}

u8 LCD_u8SendSineString(u8* Sine)
{
	u8 i = 0;

	while(Sine[i] != 0)
	{
		if(i % 2 == 0)
		{
			LCD_vidSendCommand(0x80 + i);

			LCD_vidSendData(Sine[i]);
		}
		else
		{
			LCD_vidSendCommand(0xC0 + i);

			LCD_vidSendData(Sine[i]);
		}
		i++;
	}

	return i;
}
LCD_vidPrintNumber(u16 number)
{
	u8 digit;

	if(number > 1000)
	{
		digit = number / 1000;

		LCD_vidSendData(digit + 48);

		number = number - digit * 1000;

		digit = number / 100;

		LCD_vidSendData(digit + 48);

		number = number - digit * 100;

		digit = number / 10;

		number = number - digit * 10;

		LCD_vidSendData(digit + 48);

		LCD_vidSendData(number + 48);

	}
	else if(number > 100)
	{
		digit = number / 100;

		LCD_vidSendData(digit + 48);

		number = number - digit * 100;

		digit = number / 10;

		number = number - digit * 10;

		LCD_vidSendData(digit + 48);

		LCD_vidSendData(number + 48);
	}
	else if(number > 10)
	{
		digit = number / 10;

		number = number - digit * 10;

		LCD_vidSendData(digit + 48);

		LCD_vidSendData(number + 48);
	}
	else if(number > 0)
	{
		LCD_vidSendData(number + 48);
	}
}
