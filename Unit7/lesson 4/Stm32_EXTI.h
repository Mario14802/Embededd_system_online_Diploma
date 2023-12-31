/*
 * Stm32_EXTI.h
 *
 *  Created on: Sep 19, 2023
 *      Author: MARIO
 */

#ifndef INC_STM32_EXTI_H_
#define INC_STM32_EXTI_H_
#include "Stm32f103x6.h"
#include "Stm32_GPIO.h"

typedef struct
{
	uint16_t ETI_InputLineNumber;
	GPIO_Type_Def* GPIO_PORT;
	uint16_t GPIO_PIN;
	uint8_t IVT_IRQ_Number;

}EXTI_GPIO_Maping_t;


typedef struct
{
	EXTI_GPIO_Maping_t EXTI_PIN;

	uint8_t Trigger_case;

	uint8_t IRQ_EN;

	void (*P_IRQ_CallBack)(void);
}EXTI_PinConfig_t;



//Refrenece macros//
#define EXTI0    0
#define EXTI1    1
#define EXTI2    2
#define EXTI3    3
#define EXTI4    4
#define EXTI5    5
#define EXTI6    6
#define EXTI7    7
#define EXTI8    8
#define EXTI9    9
#define EXTI10 	10
#define EXTI11 	11
#define EXTI12 	12
#define EXTI13 	13
#define EXTI14 	14
#define EXTI15  15

//ref macros trigger case
#define EXTI_Trigger_Rising					 0
#define EXTI_Trigger_Falling				 1
#define EXTI_Trigger_Rising_Falling  		 2

//ref macros enable

#define EXTI_IRQ_EN      1
#define EXTI_IRQ_DIS     0

//Ref macros
#define EXTI0PA0 (EXTI_GPIO_Maping_t) {EXTO0, GPIOA, GPIO_PIN0, EXTI0_IRQ}
#define EXTI0PB0 (EXTI_GPIO_Maping_t) {EXTO0, GPIOB, GPIO_PIN0, EXTI0_IRQ}
#define EXTI0PC0 (EXTI_GPIO_Maping_t) {EXTO0, GPIOC, GPIO_PIN0, EXTI0_IRQ}
#define EXTI0PD0 (EXTI_GPIO_Maping_t) {EXTO0, GPIOD, GPIO_PIN0, EXTI0_IRQ}

#define EXTI1PA1 (EXTI_GPIO_Maping_t) {EXTO1, GPIOA, GPIO_PIN1, EXTI1_IRQ}
#define EXTI1PB1 (EXTI_GPIO_Maping_t) {EXTO1, GPIOB, GPIO_PIN1, EXTI1_IRQ}
#define EXTI1PC1 (EXTI_GPIO_Maping_t) {EXTO1, GPIOC, GPIO_PIN1, EXTI1_IRQ}
#define EXTI1PD1 (EXTI_GPIO_Maping_t) {EXTO1, GPIOD, GPIO_PIN1, EXTI1_IRQ}

#define EXTI2PA2  (EXTI_GPIO_Maping_t) {EXTO2, GPIOA, GPIO_PIN2, EXTI2_IRQ}
#define EXTI2PB2  (EXTI_GPIO_Maping_t) {EXTO2, GPIOB, GPIO_PIN2, EXTI2_IRQ}
#define EXTI2PC2  (EXTI_GPIO_Maping_t) {EXTO2, GPIOC, GPIO_PIN2, EXTI2_IRQ}
#define EXTI2PD2  (EXTI_GPIO_Maping_t) {EXTO2, GPIOD, GPIO_PIN2, EXTI2_IRQ}

#define EXTI3PA3  (EXTI_GPIO_Maping_t) {EXTO3, GPIOA, GPIO_PIN3, EXTI3_IRQ}
#define EXTI3PB3  (EXTI_GPIO_Maping_t) {EXTO3, GPIOB, GPIO_PIN3, EXTI3_IRQ}
#define EXTI3PC3  (EXTI_GPIO_Maping_t) {EXTO3, GPIOC, GPIO_PIN3, EXTI3_IRQ}
#define EXTI3PD3  (EXTI_GPIO_Maping_t) {EXTO3, GPIOD, GPIO_PIN3, EXTI3_IRQ}

#define EXTI4PA4  (EXTI_GPIO_Maping_t) {EXTO4, GPIOA, GPIO_PIN4, EXTI4_IRQ}
#define EXTI4PB4  (EXTI_GPIO_Maping_t) {EXTO4, GPIOB, GPIO_PIN4, EXTI4_IRQ}
#define EXTI4PC4  (EXTI_GPIO_Maping_t) {EXTO4, GPIOC, GPIO_PIN4, EXTI4_IRQ}
#define EXTI4PD4  (EXTI_GPIO_Maping_t) {EXTO4, GPIOD, GPIO_PIN4, EXTI4_IRQ}

#define EXTI5PA5  (EXTI_GPIO_Maping_t) {EXTO5, GPIOA, GPIO_PIN5, EXTI5_IRQ}
#define EXTI5PB5  (EXTI_GPIO_Maping_t) {EXTO5, GPIOB, GPIO_PIN5, EXTI5_IRQ}
#define EXTI5PC5  (EXTI_GPIO_Maping_t) {EXTO5, GPIOC, GPIO_PIN5, EXTI5_IRQ}
#define EXTI5PD5  (EXTI_GPIO_Maping_t) {EXTO5, GPIOD, GPIO_PIN5, EXTI5_IRQ}

#define EXTI6PA6  (EXTI_GPIO_Maping_t) {EXTO6, GPIOA, GPIO_PIN6, EXTI6_IRQ}
#define EXTI6PB6  (EXTI_GPIO_Maping_t) {EXTO6, GPIOB, GPIO_PIN6, EXTI6_IRQ}
#define EXTI6PC6  (EXTI_GPIO_Maping_t) {EXTO6, GPIOC, GPIO_PIN6, EXTI6_IRQ}
#define EXTI6PD6  (EXTI_GPIO_Maping_t) {EXTO6, GPIOD, GPIO_PIN6, EXTI6_IRQ}

#define EXTI7PA7  (EXTI_GPIO_Maping_t) {EXTO7, GPIOA, GPIO_PIN7, EXTI7_IRQ}
#define EXTI7PB7  (EXTI_GPIO_Maping_t) {EXTO7, GPIOB, GPIO_PIN7, EXTI7_IRQ}
#define EXTI7PC7  (EXTI_GPIO_Maping_t) {EXTO7, GPIOC, GPIO_PIN7, EXTI7_IRQ}
#define EXTI7PD7  (EXTI_GPIO_Maping_t) {EXTO7, GPIOD, GPIO_PIN7, EXTI7_IRQ}

#define EXTI8PA8  (EXTI_GPIO_Maping_t) {EXTO8, GPIOA, GPIO_PIN8, EXTI8_IRQ}
#define EXTI8PB8  (EXTI_GPIO_Maping_t) {EXTO8, GPIOB, GPIO_PIN8, EXTI8_IRQ}
#define EXTI8PC8  (EXTI_GPIO_Maping_t) {EXTO8, GPIOC, GPIO_PIN8, EXTI8_IRQ}
#define EXTI8PD8  (EXTI_GPIO_Maping_t) {EXTO8, GPIOD, GPIO_PIN8, EXTI8_IRQ}

#define EXTI9PA9  (EXTI_GPIO_Maping_t) {EXTO9, GPIOA, GPIO_PIN9, EXTI9_IRQ}
#define EXTI9PB9  (EXTI_GPIO_Maping_t) {EXTO9, GPIOB, GPIO_PIN9, EXTI9_IRQ}
#define EXTI9PC9  (EXTI_GPIO_Maping_t) {EXTO9, GPIOC, GPIO_PIN9, EXTI9_IRQ}
#define EXTI9PD9  (EXTI_GPIO_Maping_t) {EXTO9, GPIOD, GPIO_PIN9, EXTI9_IRQ}


#define EXTI10PA10 (EXTI_GPIO_Maping_t) {EXTO10, GPIOA, GPIO_PIN10, EXTI10_IRQ}
#define EXTI10PB10 (EXTI_GPIO_Maping_t) {EXTO10, GPIOB, GPIO_PIN10, EXTI10_IRQ}
#define EXTI10PC10 (EXTI_GPIO_Maping_t) {EXTO10, GPIOC, GPIO_PIN10, EXTI10_IRQ}
#define EXTI10PD10 (EXTI_GPIO_Maping_t) {EXTO10, GPIOD, GPIO_PIN10, EXTI10_IRQ}

#define EXTI11PA11 (EXTI_GPIO_Maping_t) {EXTO11, GPIOA, GPIO_PIN11, EXTI11_IRQ}
#define EXTI11PB11 (EXTI_GPIO_Maping_t) {EXTO11, GPIOB, GPIO_PIN11, EXTI11_IRQ}
#define EXTI11PC11 (EXTI_GPIO_Maping_t) {EXTO11, GPIOC, GPIO_PIN11, EXTI11_IRQ}
#define EXTI11PD11 (EXTI_GPIO_Maping_t) {EXTO11, GPIOD, GPIO_PIN11, EXTI11_IRQ}

#define EXTI12PA12 (EXTI_GPIO_Maping_t) {EXTO12, GPIOA, GPIO_PIN12, EXTI12_IRQ}
#define EXTI12PB12 (EXTI_GPIO_Maping_t) {EXTO12, GPIOB, GPIO_PIN12, EXTI12_IRQ}
#define EXTI12PC12 (EXTI_GPIO_Maping_t) {EXTO12, GPIOC, GPIO_PIN12, EXTI12_IRQ}
#define EXTI12PD12 (EXTI_GPIO_Maping_t) {EXTO12, GPIOD, GPIO_PIN12, EXTI12_IRQ}

#define EXTI13PA13 (EXTI_GPIO_Maping_t) {EXTO13, GPIOA, GPIO_PIN13, EXTI13_IRQ}
#define EXTI13PB13 (EXTI_GPIO_Maping_t) {EXTO13, GPIOB, GPIO_PIN13, EXTI13_IRQ}
#define EXTI13PC13 (EXTI_GPIO_Maping_t) {EXTO13, GPIOC, GPIO_PIN13, EXTI13_IRQ}
#define EXTI13PD13 (EXTI_GPIO_Maping_t) {EXTO13, GPIOD, GPIO_PIN13, EXTI13_IRQ}

#define EXTI14PA14 (EXTI_GPIO_Maping_t) {EXTO14, GPIOA, GPIO_PIN14, EXTI14_IRQ}
#define EXTI14PB14 (EXTI_GPIO_Maping_t) {EXTO14, GPIOB, GPIO_PIN14, EXTI14_IRQ}
#define EXTI14PC14 (EXTI_GPIO_Maping_t) {EXTO14, GPIOC, GPIO_PIN14, EXTI14_IRQ}
#define EXTI14PD14 (EXTI_GPIO_Maping_t) {EXTO14, GPIOD, GPIO_PIN14, EXTI14_IRQ}

#define EXTI15PA15 (EXTI_GPIO_Maping_t) {EXTO15, GPIOA, GPIO_PIN15, EXTI15_IRQ}
#define EXTI15PB15 (EXTI_GPIO_Maping_t) {EXTO15, GPIOB, GPIO_PIN15, EXTI15_IRQ}
#define EXTI15PC15 (EXTI_GPIO_Maping_t) {EXTO15, GPIOC, GPIO_PIN15, EXTI15_IRQ}
#define EXTI15PD15 (EXTI_GPIO_Maping_t) {EXTO15, GPIOD, GPIO_PIN15, EXTI15_IRQ}

//API

void MCAL_EXTI_GPIO_init (EXTI_PinConfig_t * EXTI_Config);
void MCAL_EXTI_GPIO_Deinit (void);

void MCAL_EXTI_GPIO_Update (EXTI_PinConfig_t * EXTI_Config);


#endif /* INC_STM32_EXTI_H_ */
