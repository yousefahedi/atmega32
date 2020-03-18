/*
 * TIMER.c
 *
 *  Created on: Oct 10, 2018
 *      Author: youse
 */
#include "STD_TYPES.h"
#include "Reg.h"
#include "BIT_MATH.h"
#include "TIMER.h"

void TIMER0_vidSetMode(u8 Mode)
{
	switch(Mode)
	{
		case Normal:
			CLR_BIT(TCCR0_Register, 6);
			CLR_BIT(TCCR0_Register, 3);
			break;

		case PWM:
			SET_BIT(TCCR0_Register, 6);
			CLR_BIT(TCCR0_Register, 3);
			break;

		case CTC:
			CLR_BIT(TCCR0_Register, 6);
			SET_BIT(TCCR0_Register, 3);
			break;

		case Fast_PWM:
			SET_BIT(TCCR0_Register, 6);
			SET_BIT(TCCR0_Register, 3);
			break;
	}
}

void TIMER0_vidSetPrescaler(u8 Value)
{
	switch(Value)
	{
		case OFF:
			CLR_BIT(TCCR0_Register, 0);
			CLR_BIT(TCCR0_Register, 1);
			CLR_BIT(TCCR0_Register, 2);
			break;

		case V_0:
			SET_BIT(TCCR0_Register, 0);
			CLR_BIT(TCCR0_Register, 1);
			CLR_BIT(TCCR0_Register, 2);
			break;

		case V_8:
			CLR_BIT(TCCR0_Register, 0);
			SET_BIT(TCCR0_Register, 1);
			CLR_BIT(TCCR0_Register, 2);
			break;

		case V_64:
			SET_BIT(TCCR0_Register, 0);
			SET_BIT(TCCR0_Register, 1);
			CLR_BIT(TCCR0_Register, 2);
			break;

		case V_256:
			CLR_BIT(TCCR0_Register, 0);
			CLR_BIT(TCCR0_Register, 1);
			SET_BIT(TCCR0_Register, 2);
			break;

		case V_1024:
			SET_BIT(TCCR0_Register, 0);
			CLR_BIT(TCCR0_Register, 1);
			SET_BIT(TCCR0_Register, 2);
			break;

		case EXT_Falling:
			CLR_BIT(TCCR0_Register, 0);
			SET_BIT(TCCR0_Register, 1);
			SET_BIT(TCCR0_Register, 2);
			break;

		case EXT_Rising:
			SET_BIT(TCCR0_Register, 0);
			SET_BIT(TCCR0_Register, 1);
			SET_BIT(TCCR0_Register, 2);
			break;
	}
}

void TIMER0_vidOverflowIntEnable(void)
{
	SET_BIT(TIMSK_Register, 0);
}

void TIMER0_CompareMode(u8 Mode)
{
	switch(Mode)
	{
		case Normal:
			CLR_BIT(TCCR0_Register, 4);
			CLR_BIT(TCCR0_Register, 5);
			break;

		case Toggle:
			SET_BIT(TCCR0_Register, 4);
			CLR_BIT(TCCR0_Register, 5);
			break;

		case CLR_Compare:
			CLR_BIT(TCCR0_Register, 4);
			SET_BIT(TCCR0_Register, 5);
			break;

		case SET_Compare:
			SET_BIT(TCCR0_Register, 4);
			SET_BIT(TCCR0_Register, 5);
			break;
	}
}

void TIMER1A_vidCompareMode(u8 Mode)
{

	switch(Mode)
	{
		case Normal:
			CLR_BIT(TCCR1A_Register, 6);
			CLR_BIT(TCCR1A_Register, 7);
			break;

		case Toggle:
			SET_BIT(TCCR1A_Register, 6);
			CLR_BIT(TCCR1A_Register, 7);
			break;

		case CLR_Compare:
			CLR_BIT(TCCR1A_Register, 6);
			SET_BIT(TCCR1A_Register, 7);
			break;

		case SET_Compare:
			SET_BIT(TCCR1A_Register, 6);
			SET_BIT(TCCR1A_Register, 7);
			break;
	}
}

void TIMER1B_vidCompareMode(u8 Mode)
{

	switch(Mode)
	{
		case Normal:
			CLR_BIT(TCCR1A_Register, 4);
			CLR_BIT(TCCR1A_Register, 5);
			break;

		case Toggle:
			SET_BIT(TCCR1A_Register, 4);
			CLR_BIT(TCCR1A_Register, 5);
			break;

		case CLR_Compare:
			CLR_BIT(TCCR1A_Register, 4);
			SET_BIT(TCCR1A_Register, 5);
			break;

		case SET_Compare:
			SET_BIT(TCCR1A_Register, 4);
			SET_BIT(TCCR1A_Register, 5);
			break;
	}
}

void TIMER1_vidSetPrescaler(u8 Value)
{
	switch(Value)
	{
		case OFF:
			CLR_BIT(TCCR1B_Register, 0);
			CLR_BIT(TCCR1B_Register, 1);
			CLR_BIT(TCCR1B_Register, 2);
			break;

		case V_0:
			SET_BIT(TCCR1B_Register, 0);
			CLR_BIT(TCCR1B_Register, 1);
			CLR_BIT(TCCR1B_Register, 2);
			break;

		case V_8:
			CLR_BIT(TCCR1B_Register, 0);
			SET_BIT(TCCR1B_Register, 1);
			CLR_BIT(TCCR1B_Register, 2);
			break;

		case V_64:
			SET_BIT(TCCR1B_Register, 0);
			SET_BIT(TCCR1B_Register, 1);
			CLR_BIT(TCCR1B_Register, 2);
			break;

		case V_256:
			CLR_BIT(TCCR1B_Register, 0);
			CLR_BIT(TCCR1B_Register, 1);
			SET_BIT(TCCR1B_Register, 2);
			break;

		case V_1024:
			SET_BIT(TCCR1B_Register, 0);
			CLR_BIT(TCCR1B_Register, 1);
			SET_BIT(TCCR1B_Register, 2);
			break;

		case EXT_Falling:
			CLR_BIT(TCCR1B_Register, 0);
			SET_BIT(TCCR1B_Register, 1);
			SET_BIT(TCCR1B_Register, 2);
			break;

		case EXT_Rising:
			SET_BIT(TCCR1B_Register, 0);
			SET_BIT(TCCR1B_Register, 1);
			SET_BIT(TCCR1B_Register, 2);
			break;
	}
}

void TIMER1_vidSetMode(u8 Mode)
{
	switch(Mode)
	{
		case Normal1:
			CLR_BIT(TCCR1A_Register, 0);
			CLR_BIT(TCCR1A_Register, 1);
			CLR_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case PWM_8:
			SET_BIT(TCCR1A_Register, 0);
			CLR_BIT(TCCR1A_Register, 1);
			CLR_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case PWM_9:
			CLR_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			CLR_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case PWM_10:
			SET_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			CLR_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case CTC_0:
			CLR_BIT(TCCR1A_Register, 0);
			CLR_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case Fast_PWM_8:
			SET_BIT(TCCR1A_Register, 0);
			CLR_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case Fast_PWM_9:
			CLR_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case Fast_PWM_10:
			SET_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			CLR_BIT(TCCR1B_Register, 4);
			break;

		case PWM_ICR1:
			CLR_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			CLR_BIT(TCCR1B_Register, 3);
			SET_BIT(TCCR1B_Register, 4);
			break;

		case PWM_OCR1A:
			SET_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			CLR_BIT(TCCR1B_Register, 3);
			SET_BIT(TCCR1B_Register, 4);
			break;

		case CTC_1:
			CLR_BIT(TCCR1A_Register, 0);
			CLR_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			SET_BIT(TCCR1B_Register, 4);
			break;

		case Fast_PWM_ICR1:
			CLR_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			SET_BIT(TCCR1B_Register, 4);
			break;

		case Fast_PWM_OCR1A:
			SET_BIT(TCCR1A_Register, 0);
			SET_BIT(TCCR1A_Register, 1);
			SET_BIT(TCCR1B_Register, 3);
			SET_BIT(TCCR1B_Register, 4);
			break;
	}
}
