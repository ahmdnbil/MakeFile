/*
 * DIO_Program.c
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "./DIO_Private.h"
#include "./DIO_Configuration.h"
#include "./DIO_Interface.h"

void DIO_voidInit()
{
    PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE, PORTA_PIN6_VALUE, PORTA_PIN5_VALUE, PORTA_PIN4_VALUE, PORTA_PIN3_VALUE, PORTA_PIN2_VALUE, PORTA_PIN1_VALUE, PORTA_PIN0_VALUE);
    PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE, PORTB_PIN6_VALUE, PORTB_PIN5_VALUE, PORTB_PIN4_VALUE, PORTB_PIN3_VALUE, PORTB_PIN2_VALUE, PORTB_PIN1_VALUE, PORTB_PIN0_VALUE);
    PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE, PORTC_PIN6_VALUE, PORTC_PIN5_VALUE, PORTC_PIN4_VALUE, PORTC_PIN3_VALUE, PORTC_PIN2_VALUE, PORTC_PIN1_VALUE, PORTC_PIN0_VALUE);
    PORTD_REG = CONC_BIT(PORTD_PIN7_VALUE, PORTD_PIN6_VALUE, PORTD_PIN5_VALUE, PORTD_PIN4_VALUE, PORTD_PIN3_VALUE, PORTD_PIN2_VALUE, PORTD_PIN1_VALUE, PORTD_PIN0_VALUE);

    DDRA_REG = CONC_BIT(DDRA_PIN7_DIRECTION, DDRA_PIN6_DIRECTION, DDRA_PIN5_DIRECTION, DDRA_PIN4_DIRECTION, DDRA_PIN3_DIRECTION, DDRA_PIN2_DIRECTION, DDRA_PIN1_DIRECTION, DDRA_PIN0_DIRECTION);
    DDRB_REG = CONC_BIT(DDRB_PIN7_DIRECTION, DDRB_PIN6_DIRECTION, DDRB_PIN5_DIRECTION, DDRB_PIN4_DIRECTION, DDRB_PIN3_DIRECTION, DDRB_PIN2_DIRECTION, DDRB_PIN1_DIRECTION, DDRB_PIN0_DIRECTION);
    DDRC_REG = CONC_BIT(DDRC_PIN7_DIRECTION, DDRC_PIN6_DIRECTION, DDRC_PIN5_DIRECTION, DDRC_PIN4_DIRECTION, DDRC_PIN3_DIRECTION, DDRC_PIN2_DIRECTION, DDRC_PIN1_DIRECTION, DDRC_PIN0_DIRECTION);
    DDRD_REG = CONC_BIT(DDRD_PIN7_DIRECTION, DDRD_PIN6_DIRECTION, DDRD_PIN5_DIRECTION, DDRD_PIN4_DIRECTION, DDRD_PIN3_DIRECTION, DDRD_PIN2_DIRECTION, DDRD_PIN1_DIRECTION, DDRD_PIN0_DIRECTION);
}

u8 DIO_u8GetPinValue(u8 A_u8Port, u8 A_u8Pin)
{
    u8 local_u8Value;
    switch (A_u8Port)
    {
    case PORTA:
        local_u8Value = GET_BIT(PINA_REG, A_u8Pin);
        break;
    case PORTB:
        local_u8Value = GET_BIT(PINB_REG, A_u8Pin);
        break;
    case PORTC:
        local_u8Value = GET_BIT(PINC_REG, A_u8Pin);
        break;
    case PORTD:
        local_u8Value = GET_BIT(PIND_REG, A_u8Pin);
        break;
    }
    return local_u8Value;
}

void DIO_voidSetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 A_u8Value)
{
    switch (A_u8Port)
    {
    case PORTA:
        switch (A_u8Value)
        {
        case PIN_HIGH:
            SET_BIT(PORTA_REG, A_u8Pin);
            break;

        case PIN_LOW:
            CLR_BIT(PORTA_REG, A_u8Pin);
            break;
        };
        break;

    case PORTB:
        switch (A_u8Value)
        {
        case PIN_HIGH:
            SET_BIT(PORTB_REG, A_u8Pin);
            break;

        case PIN_LOW:
            CLR_BIT(PORTB_REG, A_u8Pin);
            break;
        };
        break;

    case PORTC:
        switch (A_u8Value)
        {
        case PIN_HIGH:
            SET_BIT(PORTC_REG, A_u8Pin);
            break;

        case PIN_LOW:
            CLR_BIT(PORTC_REG, A_u8Pin);
            break;
        };
        break;

    case PORTD:
        switch (A_u8Value)
        {
        case PIN_HIGH:
            SET_BIT(PORTD_REG, A_u8Pin);
            break;

        case PIN_LOW:
            CLR_BIT(PORTD_REG, A_u8Pin);
            break;
        };
        break;
    }
}

void DIO_voidSetPinDirection(u8 A_u8Port, u8 A_u8Pin, u8 A_u8Value)
{
    switch (A_u8Port)
    {
    case PORTA:
        switch (A_u8Value)
        {
        case PIN_OUTPUT:
            SET_BIT(DDRA_REG, A_u8Pin);
            break;

        case PIN_INPUT:
            CLR_BIT(DDRA_REG, A_u8Pin);
            break;
        };
        break;

    case PORTB:
        switch (A_u8Value)
        {
        case PIN_OUTPUT:
            SET_BIT(DDRB_REG, A_u8Pin);
            break;

        case PIN_INPUT:
            CLR_BIT(DDRB_REG, A_u8Pin);
            break;
        };
        break;

    case PORTC:
        switch (A_u8Value)
        {
        case PIN_OUTPUT:
            SET_BIT(DDRC_REG, A_u8Pin);
            break;

        case PIN_INPUT:
            CLR_BIT(DDRC_REG, A_u8Pin);
            break;
        };
        break;

    case PORTD:
        switch (A_u8Value)
        {
        case PIN_OUTPUT:
            SET_BIT(DDRD_REG, A_u8Pin);
            break;

        case PIN_INPUT:
            CLR_BIT(DDRD_REG, A_u8Pin);
            break;
        };
        break;
    }
}

void DIO_voidTogglePin(u8 A_u8Port, u8 A_u8Pin)
{
    switch (A_u8Port)
    {
        case PORTA: TOGGLE_BIT(PORTA_REG,A_u8Pin); break;
        case PORTB: TOGGLE_BIT(PORTB_REG,A_u8Pin); break;
        case PORTC: TOGGLE_BIT(PORTC_REG,A_u8Pin); break;
        case PORTD: TOGGLE_BIT(PORTD_REG,A_u8Pin); break;
        default: break;
    }
}

void DIO_voidSetPortValue(u8 A_u8Port, u8 A_u8Value)
{
    switch (A_u8Port)
    {
    case PORTA:
        PORTA_REG = A_u8Value;
        break;
    case PORTB:
        PORTB_REG = A_u8Value;
        break;
    case PORTC:
        PORTC_REG = A_u8Value;
        break;
    case PORTD:
        PORTD_REG = A_u8Value;
        break;
    }
}

void DIO_voidSetPortDirection(u8 A_u8Port, u8 A_u8Value)
{
    switch (A_u8Port)
    {
    case PORTA:
        DDRA_REG = A_u8Value;
        break;
    case PORTB:
        DDRB_REG = A_u8Value;
        break;
    case PORTC:
        DDRC_REG = A_u8Value;
        break;
    case PORTD:
        DDRD_REG = A_u8Value;
        break;
    }
}