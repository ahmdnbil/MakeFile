/*
 * main.c
 *
 *  Created on: Aug 2, 2023
 *      Author: User
 */


#include "./Include/LIB/BIT_MATH.h"
#include "./Include/LIB/STD_TYPES.h"

//DIO
#include "./Include/MCAL/DIO/DIO_Interface.h"
//TIMER1
#include "./Include/MCAL/TIMER1/TIMER1_Interface.h"
//OS
#include "./Include/SERVICES/RTOS/RTOS_Interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void toggleLED1(void);
void toggleLED2(void);
void toggleLED3(void);

void main(void)
{
    DIO_voidInit();
    //sending functions to ISR
    RTOS_voidCreateTask(0,1000,0,toggleLED1);
    RTOS_voidCreateTask(1,2000,0,toggleLED2);
    RTOS_voidCreateTask(2,3000,0,toggleLED3);
    //start schdeulr
    RTOS_voidInit();
    while(1)
    {}
}

void toggleLED1(void)
{
    DIO_voidTogglePin(PORTA,PIN0);
}
void toggleLED2(void)
{

    DIO_voidTogglePin(PORTA,PIN1);
}
void toggleLED3(void)
{
    DIO_voidTogglePin(PORTA,PIN2);
}

// void toggleLED()
// {
//     static u8 flag=0;
//     static u16 counter=0;
//     counter++;
//     if(counter==1000)
//     {
//         counter=0;
//         if(flag==0)
//         {
//             DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
//             flag=1;
//         }
//         else
//         {
//             DIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
//             flag=0;
//         }
//     }
// }
