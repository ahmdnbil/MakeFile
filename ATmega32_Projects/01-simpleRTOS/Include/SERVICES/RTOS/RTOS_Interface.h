/*
 * RTOS_Interface.h
 *
 *  Created on: Aug 2, 2023
 *      Author: User
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void RTOS_voidInit();
void RTOS_voidCreateTask(u8 A_u8Priority,u16 A_u16Preiodicity,u16 A_u16FirstDelay,void (*pf)(void));

#endif /* INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_ */
