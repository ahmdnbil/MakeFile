/*
 * TIMER1_Private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_

/******************************************/
// Timer/Counter1 Control Register A
#define TCCR1A (*(volatile u8*)0x4F)

//Compare Output Mode for Compare uint A pin0
#define COM1A0 6
//Compare Output Mode for Compare uint B pin0
#define COM1B0 4
//Wave Generator Mode first Two bits
#define WGM10 0


/******************************************/



/******************************************/
// Timer/Counter1 Control Register A
#define TCCR1B (*(volatile u8*)0x4E)
//Wave Generator Mode second Two bits
#define WGM12 3
//Prescaler
#define CS10 0
//edge select for ICU
#define ICES1 6


/******************************************/

#define TCNT1H (*(volatile u8*)0x4D)
#define TCNT1L (*(volatile u8*)0x4C)
#define TCNT1 (*(volatile u16*)0x4C)

#define OCR1AH (*(volatile u8*)0x4B)
#define OCR1AL (*(volatile u8*)0x4A)
#define OCR1A (*(volatile u16*)0x4A)

#define OCR1BH (*(volatile u8*)0x49)
#define OCR1BL (*(volatile u8*)0x48)
#define OCR1B (*(volatile u16*)0x48)

#define ICR1H (*(volatile u8*)0x47)
#define ICR1L (*(volatile u8*)0x46)
#define ICR1  (*(volatile u16*)0x46)

//Timer/Counter Interrupt Mask
#define TIMSK (*(volatile u8 *) 0x59)

#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2
/******************************************/


#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
