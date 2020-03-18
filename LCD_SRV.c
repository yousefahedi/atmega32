/*
 * LCD_SRV.c
 *
 *  Created on: Oct 13, 2018
 *      Author: youse
 */

#include"STD_TYPES.h"
#include "DIO.h"
#include "LCD.h"



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
