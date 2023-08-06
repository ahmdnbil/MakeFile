/*
 * DIO_Interface.h
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PIN_OUTPUT 1
#define PIN_INPUT 0

//in case of being output
#define PIN_LOW 0
#define PIN_HIGH 1

//in case of being input
#define PIN_FLOATING 0
#define PIN_PULLUP 1

void DIO_voidInit();
void DIO_voidSetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 A_u8Value);
u8 DIO_u8GetPinValue(u8 A_u8Port, u8 A_u8Pin);
void DIO_voidSetPortValue(u8 A_u8Port, u8 A_u8Value);
void DIO_voidSetPortDirection(u8 A_u8Port, u8 A_u8Value);
void DIO_voidTogglePin(u8 A_u8Port, u8 A_u8Pin);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
