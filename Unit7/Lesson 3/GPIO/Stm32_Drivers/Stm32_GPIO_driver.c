/*
 * Stm32_GPIO_driver.c
 *
 *  Created on: Aug 24, 2023
 *      Author: MARIO
 */


#include "Stm32_GPIO_driver.h"

uint8_t GET_CRLH_POSITION(uint16_t PINNumber)
{
	switch (PINNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;


	}
	return 0;
}

void MCAL_GPIO_init(GPIO_Type_Def* GPIOx ,GPIO_PinConfig *PinConfig)
{
	//port config low CRL from 0 to 7
	//port config high CRH from 0 to 7
	volatile uint32_t *configregister=NULL;
	uint8_t Pin_Config=0;

	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH ;
	//CLEAR CNF8[0:8] MODE8
	(*configregister) &= ~(0xf<<GET_CRLH_POSITION(PinConfig->GPIO_PinNumber));

	if ((PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_OD)|| (GPIO_MODE_OUTPUT_AF_PP) || (GPIO_MODE_OUTPUT_AF_OD)||(GPIO_MODE_OUTPUT_PP))
	{
		//set CNF8[0:8] MODE8
		Pin_Config= ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_OUTPUT_SPEED)) & 0x0f) ;

	}
	//if pin is input
	else
	{
		if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) ||  (PinConfig->GPIO_MODE==GPIO_MODE_ANALOGE))
		{
			//Set CNF8[1:0] MODE8 [1:0]00
			Pin_Config= ((((PinConfig->GPIO_MODE ) << 2) | (0X0)) & 0x0f) ;

		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)
		{
			Pin_Config= ((((GPIO_MODE_INPUT_FLO ) << 2) | (0X0)) & 0x0f) ;
		}
		else
		{
			Pin_Config= ((((GPIO_MODE_INPUT_PU ) << 2) | (0X0)) & 0x0f) ;
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else
			{
				GPIOx->ODR &= ~ (PinConfig->GPIO_PinNumber);
			}
		}


	}
	(*configregister) |= ((Pin_Config) << GET_CRLH_POSITION(PinConfig->GPIO_PinNumber) );

}

void MCAL_GPIO_Deinit(GPIO_Type_Def* GPIOx )

{
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}

	if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}


}


uint8_t MCAL_GPIO_Read_Pin  (GPIO_Type_Def* GPIOx ,uint16_t PinNumber)

{
	uint8_t  bitstatus;
	if (((GPIOx->IDR)& PinNumber )!= (uint32_t) GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}
	else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}





uint16_t MCAL_GPIO_Read_Port(GPIO_Type_Def* GPIOx)
{
	uint8_t  port_value;
	port_value = (uint16_t) (GPIOx->IDR);
	return port_value;

}


//WRITE APIS
void MCAL_GPIO_WritePin(GPIO_Type_Def* GPIOx ,uint16_t PinNumber,uint16_t Value)
{

	if ( Value == GPIO_PIN_RESET)
	{
		GPIOx->BSRR = (uint32_t)PinNumber;


	}
	else
	{
		GPIOx->BRR = (uint32_t)PinNumber;

	}

}
void MCAL_GPIO_WritePort(GPIO_Type_Def* GPIOx ,uint16_t value)
{
GPIOx->ODR =(uint32_t)value;
}

void MCAL_GPIO_TogglePin(GPIO_Type_Def* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}

uint8_t MCAL_GPIO_LockPin(GPIO_Type_Def* GPIOx,uint16_t PinNumber)
{
volatile uint32_t tmp = 1<<16;
//set the lcky
tmp |= PinNumber;

GPIOx->LCKR = tmp;

GPIOx->LCKR = PinNumber;

GPIOx->LCKR = tmp;

tmp = GPIOx->LCKR;

if ((uint32_t)(GPIOx->LCKR & 1<<16 ))
{
	return GPIO_RETURN_LOCK_ENABLED;
}
else
{
	return GPIO_RETURN_LOCK_ERROR;
}



}
