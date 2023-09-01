/*
 * Stm32_GPIO_driver.h
 *
 *  Created on: Aug 24, 2023
 *      Author: MARIO
 */

#ifndef INC_STM32_GPIO_DRIVER_H_
#define INC_STM32_GPIO_DRIVER_H_



//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------


typedef struct
{
	uint16_t GPIO_PinNumber ;  //specifies the gpio pins to be config
	// the parameter bust be from @ref GPIO_PIN

	uint8_t  GPIO_MODE; 		  //specifies the gpio pins to be config
	// the parameter bust be from @ref GPIO_MODE

	uint8_t GPIO_OUTPUT_SPEED; //specifies the gpio pins to be config
	// the parameter bust be from @ref GPIO_SPEED

}GPIO_PinConfig;

#define GPIO_PIN_RESET 0

#define GPIO_PIN_SET 1

#define GPIO_RETURN_LOCK_ENABLED 1

#define GPIO_RETURN_LOCK_ERROR 0
//-----------------------------
//Macros Configuration References
//-----------------------------
//GPIO_PINS DEFINE
#define GPIO_PIN_0            (((uint16_t)0X0001))
#define GPIO_PIN_1            (((uint16_t)0X0002))
#define GPIO_PIN_2            (((uint16_t)0X0004))
#define GPIO_PIN_3            (((uint16_t)0X0008))
#define GPIO_PIN_4            (((uint16_t)0X0010))
#define GPIO_PIN_5            (((uint16_t)0X0020))
#define GPIO_PIN_6            (((uint16_t)0X0040))
#define GPIO_PIN_7            (((uint16_t)0X0080))
#define GPIO_PIN_8            (((uint16_t)0X0100))
#define GPIO_PIN_9            (((uint16_t)0X0200))
#define GPIO_PIN_10           (((uint16_t)0X0400))
#define GPIO_PIN_11           (((uint16_t)0X0800))
#define GPIO_PIN_12           (((uint16_t)0X1000))
#define GPIO_PIN_13           (((uint16_t)0X2000))
#define GPIO_PIN_14           (((uint16_t)0X4000))
#define GPIO_PIN_15           (((uint16_t)0X8000))
#define GPIO_PIN_all          (((uint16_t)0XFFFF))

#define GPIO_PIN_MASK         0X0000FFFF

//GPIO_MODE DEFINE

/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up / pull-down
3: Reserved
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: ALTERNATE FUNCTION INPUT
 */
#define GPIO_MODE_ANALOGE				0X00000000u
#define GPIO_MODE_INPUT_FLO				0X00000001u
#define GPIO_MODE_INPUT_PU				0X00000002u
#define GPIO_MODE_INPUT_PD				0X00000003u

#define GPIO_MODE_OUTPUT_PP				0X00000004u
#define GPIO_MODE_OUTPUT_OD				0X00000005u
#define GPIO_MODE_OUTPUT_AF_PP			0X00000006u
#define GPIO_MODE_OUTPUT_AF_OD			0X00000007u
#define GPIO_MODE_AF_INPUT				0X00000008u


//GPIO_SPEED
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
2: Output mode, max speed 50 MHz.
 */
#define GPIO_SPEED_10M  				0X00000001u
#define GPIO_SPEED_2M					0X00000002u
#define GPIO_SPEED_50M					0X00000003u


/*@ref Module_REF_NAME_define
 */
/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */
void MCAL_GPIO_init(GPIO_Type_Def* GPIOx ,GPIO_PinConfig *PinConfig);
void MCAL_GPIO_Deinit(GPIO_Type_Def* GPIOx);

//READ APIs
uint8_t MCAL_GPIO_Read_Pin  (GPIO_Type_Def* GPIOx ,uint16_t PinNumber);
uint16_t MCAL_GPIO_Read_Port(GPIO_Type_Def* GPIOx );

//WRITE APIS
void MCAL_GPIO_WritePin(GPIO_Type_Def* GPIOx ,uint16_t PinNumber,uint16_t Value);
void MCAL_GPIO_WritePort(GPIO_Type_Def* GPIOx ,uint16_t value);

void MCAL_GPIO_TogglePin(GPIO_Type_Def* GPIOx,uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_Type_Def* GPIOx,uint16_t PinNumber);


#endif /* INC_STM32_GPIO_DRIVER_H_ */
