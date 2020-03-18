#ifndef _REG_H
#define _REG_H
/* Group A Registers */
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)

/*External Interrupt Registers*/
#define GICR_Register	*((volatile u8*)0x5B)
#define GIFR_Register	*((volatile u8*)0x5A)
#define MCUCR_Register	*((volatile u8*)0x55)
#define MCUCSR_Register	*((volatile u8*)0x54)

/*Status Register*/
#define SREG_Register	*((volatile u8*)0x5F)


/*ADC Registers*/
#define ADMUX_Register  *((volatile u8*)0x27)
#define ADCSRA_Register	*((volatile u8*)0x26)
#define ADCH_Register   *((volatile u8*)0x25)
#define ADCL_Register   *((volatile u8*)0x24)



/*Timer Registers*/
#define TCCR0_Register	*((volatile u8*)0x53)
#define TCNT0_Register	*((volatile u8*)0x52)
#define OCR0_Register	*((volatile u8*)0x52)
#define TIMSK_Register	*((volatile u8*)0x59)
#define TCCR1A_Register	*((volatile u8*)0x4F)
#define TCCR1B_Register	*((volatile u8*)0x4E)
#define ICR1_Register	ICR1
#define TCCR2_Register	*((volatile u8*)0x45)

/*Watchdog Register*/
#define WDTCR_Register	*((volatile u8*)0x41)


/*UART Registers*/
#define UCSRC_Register	*((volatile u8*)0x40)
#define UCSRA_Register	*((volatile u8*)0x2B)
#define UCSRB_Register	*((volatile u8*)0x2A)
#define UDR_Register	*((volatile u8*)0x2C)
#define UBRRL_Register	*((volatile u8*)0x29)

/*SPI Registers*/
#define SPCR_Register	*((volatile u8*)0x2D)
#define SPSR_Register	*((volatile u8*)0x2E)
#define SPDR_Register	*((volatile u8*)0x2F)


/*I2C REGISTERS*/
#define TWCR_Register	*((volatile u8*)0x56)
#define TWDR_Register	*((volatile u8*)0x23)
#define TWAR_Register	*((volatile u8*)0x22)
#define TWSR_Register	*((volatile u8*)0x21)
#define TWBR_Register 	*((volatile u8*)0x20)




#endif
