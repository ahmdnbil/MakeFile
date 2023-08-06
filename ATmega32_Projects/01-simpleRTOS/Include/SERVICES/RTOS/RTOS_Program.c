/*
 * RTOS_Program.c
 *
 *  Created on: Aug 2, 2023
 *      Author: User
 */

/*Libraries files*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*MCAL layer*/
#include "../../MCAL/TIMER1/TIMER1_Interface.h"
/*OS layer*/
#include "./RTOS_Interface.h"
#include "./RTOS_Private.h"
#include "./RTOS_Configurations.h"


TASK_TCB tasks[MAX_NO_OF_TASKS]={};

void RTOS_voidInit()
{
    //enable the global interrupt
    sei();
    //send scheduler to ISR
    TIMER1_voidSetCallBackCOMA(RTOS_voidStartScheduler);
    //set ocr1A value with 999 to be 1000us so get 1ms tick time
    TIMER1_voidSetOCR1AValue(999);
    //enable interrupt of comapre on match of unit A in timer1
    TIMER1_voidCompareAInterruptEnable();
    //configure the timer1
    TIMER1_voidInit(TIMER1_CTC_OCR1A,TIMER1_PRESCALER_8,TIMER1_COMPARE_OUTPUT_MODE_A_NORMAL,TIMER1_COMPARE_OUTPUT_MODE_B_NORMAL);
}
void RTOS_voidCreateTask(u8 A_u8Priority, u16 A_u16Preiodicity, u16 A_u16FirstDelay, void (*pf)(void))
{
    if((A_u8Priority<MAX_NO_OF_TASKS) & (A_u8Priority>=0))
    {
        tasks[A_u8Priority].periodicity = A_u16Preiodicity;
        tasks[A_u8Priority].firstdelay = A_u16FirstDelay;
        tasks[A_u8Priority].pf = pf;
    }
}
static void RTOS_voidStartScheduler(void)
{
    u8 counter;
    for(counter=0;counter<MAX_NO_OF_TASKS;counter++)
    {
        if(tasks[counter].firstdelay == 0)
        {
            tasks[counter].pf();
            tasks[counter].firstdelay=tasks[counter].periodicity-1;
        }
        else tasks[counter].firstdelay--;
    }
}