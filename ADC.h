/*
 * ADC.h
 *
 *  Created on: Sept 29, 2018
 *      Author: yousef
 */

#ifndef ADC_H_
#define ADC_H_


/*Reference Voltages*/
#define OFF 0
#define ADC_REF_5V	  1  // reference voltage == 5v
#define ADC_REF_2.56V 2	 // reference voltage == 2.56v

/* PIN Defines */
#define PINA0   0
#define PINA1   1
#define PINA2   2
#define PINA3   3
#define PINA4   4
#define PINA5   5
#define PINA6   6
#define PINA7   7

/*Resolutions*/
#define ADC_RES_10_Bits 0
#define ADC_RES_8_Bits 1

/*conversion*/
#define START 0
#define AUTO 1

/*Factors*/
#define ADC_PreScaler_2   0
#define ADC_PreScaler_2   1
#define ADC_PreScaler_4   2
#define ADC_PreScaler_8   3
#define ADC_PreScaler_16  4
#define ADC_PreScaler_32  5
#define ADC_PreScaler_64  6
#define ADC_PreScaler_128 7




/*Functions Prototypes */
void ADC_vidSetReferenceVolt(u8 ref_volt);
void ADC_vidSetPin(u8 PinNumber);
void ADC_vidSetResolution(u8 Resolution);
void ADC_vidEnable(void);
void ADC_vidConversion(u8 type);
void ADC_vidEnableInterrupt(void);
void ADC_vidSetDivisionFactor(u8 Factor);
u16  ADC_u16Read_Channel(u8 resolution);

#endif /* ADC_H_ */
