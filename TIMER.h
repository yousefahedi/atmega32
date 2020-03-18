/*
 * TIMER.h
 *
 *  Created on: Oct 10, 2018
 *      Author: youse
 */

#ifndef TIMER_H_
#define TIMER_H_

/*Timer0 Modes*/
#define Normal 0
#define PWM 1
#define CTC 2
#define Fast_PWM 3

/*Timer1 Modes*/
#define Normal1 0
#define PWM_8 1
#define PWM_9 2
#define PWM_10 3
#define CTC_0 4
#define Fast_PWM_8 5
#define Fast_PWM_9 6
#define Fast_PWM_10 7
#define PWM_ICR1 8
#define PWM_OCR1A 9
#define CTC_1 10
#define Fast_PWM_ICR1 11
#define Fast_PWM_OCR1A 12


/*Prescaler Values*/
#define OFF 0
#define V_0 1
#define V_8 2
#define V_64 3
#define V_256 4
#define V_1024 5
#define EXT_Falling 6
#define EXT_Rising 7

/*CTC Mode*/
#define Normal 0
#define Toggle 1 // only in normal mode
#define CLR_Compare 2
#define SET_Compare 3

/*Functions*/
void TIMER0_vidSetMode(u8 Mode);
void TIMER0_vidSetPrescaler(u8 Value);
void TIMER0_vidOverFlowIntEnable(void);
void TIMER0_CompareMode(u8 Mode);
void TIMER1A_vidCompareMode(u8 Mode);
void TIMER1B_vidCompareMode(u8 Mode);
void TIMER1_vidSetMode(u8 Mode);
void TIMER1_vidSetPrescaler(u8 Value);

#endif /* TIMER_H_ */
