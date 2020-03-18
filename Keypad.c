/*
 * Keypad.c
 *
 *  Created on: Sep 8, 2018
 *      Author: yousef
 */
#include "STD_TYPES.h"
#include "DIO.h"


u8 Keypad_u8GetPB(void)
{
	u8 col, row, retval = 0;

	u8 keypad_map[4][4] =
		 {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
		 };


	DIO_SetPortValue(MY_PORTA, 0xFF);

	for(col = 0; col < 4; col++)
	{
		DIO_SetPinValue(MY_PORTA, col, LOW);

		for(row = 0; row < 4; row++)
		{
			if(DIO_GetPinValue(MY_PORTA, row+4) == LOW)
			{
				retval = keypad_map[row][col];

				while(DIO_GetPinValue(MY_PORTA, row+4) == LOW);
			}
		}
		DIO_SetPinValue(MY_PORTA, col, HIGH);
	}

	return retval;
}

