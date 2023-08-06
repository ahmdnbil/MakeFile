/*
 * RTOS_Private.h
 *
 *  Created on: Aug 3, 2023
 *      Author: User
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

typedef struct
{
    u16 periodicity;
    u16 firstdelay;
    void(*pf)(void);
}TASK_TCB;

static void RTOS_voidStartScheduler(void);

#endif /* INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_ */
