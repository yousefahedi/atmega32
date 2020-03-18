/*
 * LCD_SRV.h
 *
 *  Created on: Oct 13, 2018
 *      Author: youse
 */

#ifndef LCD_SRV_H_
#define LCD_SRV_H_

void LCD_vidPrintNumber(u16 number);

u8 LCD_u8SendString(u8* String);

u8 LCD_u8SendSineString(u8* Sine);

#endif /* LCD_SRV_H_ */
