#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define CONC_BIT(b7, b6, b5, b4, b3, b2, b1, b0) Conc_help(b7, b6, b5, b4, b3, b2, b1, b0)
#define Conc_help(b7, b6, b5, b4, b3, b2, b1, b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#define SET_BIT(register,bitNo) (register |= (1<<bitNo))
#define CLR_BIT(register,bitNo) (register &= ~(1<<bitNo))
#define GET_BIT(register,bitNo) ((register & ( ~(1<<bitNo) ) ) != register)
#define TOGGLE_BIT(register,bitNo)  (register ^=(1<<bitNo))

/**************ISR**********************/
// Enable global interrupt using Assembly instructions
#define sei() __asm__ __volatile__("sei" ::)
// disable global interrupt using Assembly instructions
#define cli() __asm__ __volatile__("cli" ::)
#define ISR_NOBLOCK __attribute__((interrupt))
#define ISR_NAKED __attribute__((naked))
#define ISR_ALIASOF(v) __attribute__((alias(__STRINGIFY(v))))

#define ISR(vector, ...)                                   \
    void vector(void) __attribute__((signal)) __VA_ARGS__; \
    void vector(void)
/**************************************/

/*************Vector Table*************/
#define EXTI0_VECT __vector_1
#define EXTI1_VECT __vector_2
#define EXTI2_VECT __vector_3

#define TIMER2_CTC_VECT __vector_4
#define TIMER2_OVF_VECT __vector_5

#define TIMER1_CAPT_VECT __vector_6
#define TIMER1_COMA_VECT __vector_7
#define TIMER1_COMB_VECT __vector_8
#define TIMER1_OVF_VECT __vector_9

#define TIMER0_CTC_VECT __vector_10
#define TIMER0_OVF_VECT __vector_11

#define SPI_VECT __vector_12

#define USART_RXC_VECT __vector_13
#define USART_UDRE_VECT __vector_14
#define USART_TXC_VECT __vector_15

#define ADC_VECT __vector_16

#define TWI_VECT __vector_19

/**************************************/

#define NULLPTR ((void *)0)
#define NULL 0

#endif
