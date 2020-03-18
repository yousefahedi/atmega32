/*
 * ADC.c
 *
 *  Created on: Sept 29, 2018
 *      Author: yousef
 */

#include "STD_TYPES.h"
#define F_CPU 12000000UL
#include "DIO.h"
#include "BIT_MATh.h"
#include <avr/delay.h>
#include "ADC.h"
#include "REG.h"
/*************************************************************************************/
void ADC_vidSetReferenceVolt(u8 ref_volt)
{
	switch (ref_volt)
	{
		case OFF :
			CLR_BIT(ADMUX_Register, 6);
			CLR_BIT(ADMUX_Register, 7);
			break;
		case ADC_REF_5V :
			SET_BIT(ADMUX_Register, 6);
			CLR_BIT(ADMUX_Register, 7);
			break;
		case ADC_REF_2.56V :
			SET_BIT(ADMUX_Register, 6);
			SET_BIT(ADMUX_Register, 7);
			break;
	}
}
/*************************************************************************************/
void ADC_vidSetPin(u8 PinNumber)
{
	switch (PinNumber)
	{
		case PINA0 :
			CLR_BIT(ADMUX_Register, 0);
			CLR_BIT(ADMUX_Register, 1);
			CLR_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA1 :
			SET_BIT(ADMUX_Register, 0);
			CLR_BIT(ADMUX_Register, 1);
			CLR_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA2 :
			CLR_BIT(ADMUX_Register, 0);
			SET_BIT(ADMUX_Register, 1);
			CLR_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA3 :
			SET_BIT(ADMUX_Register, 0);
			SET_BIT(ADMUX_Register, 1);
			CLR_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA4 :
			CLR_BIT(ADMUX_Register, 0);
			CLR_BIT(ADMUX_Register, 1);
			SET_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA5 :
			SET_BIT(ADMUX_Register, 0);
			CLR_BIT(ADMUX_Register, 1);
			SET_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA6 :
			CLR_BIT(ADMUX_Register, 0);
			SET_BIT(ADMUX_Register, 1);
			SET_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
		case PINA7 :
			SET_BIT(ADMUX_Register, 0);
			SET_BIT(ADMUX_Register, 1);
			SET_BIT(ADMUX_Register, 2);
			CLR_BIT(ADMUX_Register, 3);
			CLR_BIT(ADMUX_Register, 4);
			break;
	}
}
/******************************************************************************************/
ADC_vidSetResolution(u8 Resolution)
{
	switch(Resolution)
	{
		case ADC_RES_10_Bits :
			CLR_BIT(ADMUX_Register, 5);
			break;
		case ADC_RES_8_Bits :
			SET_BIT(ADMUX_Register, 5);
			break;
	}
}
/**********************************************************************************************/
ADC_vidEnable(void)
{
	SET_BIT(ADCSRA_Register, 7);
}
/***********************************************************************************************/
ADC_vidConversion(u8 type)
{
	switch(type)
	{
		case START:
			SET_BIT(ADCSRA_Register, 6);
			break;
		case AUTO:
			SET_BIT(ADCSRA_Register, 5);
			break;
	}
}
/******************************************************************************************************/
ADC_vidEnableInterrupt(void)
{
	SET_BIT(ADCSRA_Register, 3);
}
/****************************************************************************************/
ADC_vidSetDivisionFactor(u8 Factor)
{
	switch(Factor)
	{
		case ADC_PreScaler_2:
			CLR_BIT(ADCSRA_Register, 0);
			CLR_BIT(ADCSRA_Register, 1);
			CLR_BIT(ADCSRA_Register, 2);
			break;
		
		case ADC_PreScaler_2:
			SET_BIT(ADCSRA_Register, 0);
			CLR_BIT(ADCSRA_Register, 1);
			CLR_BIT(ADCSRA_Register, 2);
			break;
			
		case ADC_PreScaler_4:
			CLR_BIT(ADCSRA_Register, 0);
			SET_BIT(ADCSRA_Register, 1);
			CLR_BIT(ADCSRA_Register, 2);
			break;
			
		case ADC_PreScaler_8:
			SET_BIT(ADCSRA_Register, 0);
			SET_BIT(ADCSRA_Register, 1);
			CLR_BIT(ADCSRA_Register, 2);
			break;
			
		case ADC_PreScaler_16:
			CLR_BIT(ADCSRA_Register, 0);
			CLR_BIT(ADCSRA_Register, 1);
			SET_BIT(ADCSRA_Register, 2);
			break;
		
		case ADC_PreScaler_32:
			SET_BIT(ADCSRA_Register, 0);
			CLR_BIT(ADCSRA_Register, 1);
			SET_BIT(ADCSRA_Register, 2);
			break;
		
		case ADC_PreScaler_64:
			CLR_BIT(ADCSRA_Register, 0);
			SET_BIT(ADCSRA_Register, 1);
			SET_BIT(ADCSRA_Register, 2);
			break;
		
		case ADC_PreScaler_128:
			SET_BIT(ADCSRA_Register, 0);
			SET_BIT(ADCSRA_Register, 1);
			SET_BIT(ADCSRA_Register, 2);
			break;
	}
}

u16  ADC_u16Read_Channel(u8 resolution)
{
	u16 conversion_value;
	
	switch(resolution)
	{
		case ADC_RES_10_Bits:
			conversion_value = (ADCH_Register << 8) | ADCL_Register;
			break;
		case ADc_RES_8_Bits:
			conversion value = ADCL_Register;
			break;
	}
	
	return conversion_value;
}



