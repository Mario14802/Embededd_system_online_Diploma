/*
 * UART.c
 *
 *  Created on: Sep 27, 2023
 *      Author: MARIO
 */

#include "Stm32_USART.h"

UART_Config * Global_UART_Config = NULL;


void MCAL_UART_init(USART_TypeDef*USARTx, UART_Config* UART_Config)
{
	uint32_t pclk,BRR;
	Global_UART_Config=UART_Config;

	if(USARTx==USART1)
	{
		RCC_USART1_CLK_EN();

	}
	else if(USARTx==USART2)
	{
		RCC_USART2_CLK_EN();

	}
	else if(USARTx==USART3)
	{
		RCC_USART3_CLK_EN();

	}


	USARTx->CR1 |= 1<<13;

	USARTx->CR1 |= UART_Config->USART_MODE;

	USARTx->CR1 |= UART_Config->Payload_Length;

	USARTx->CR1 |= UART_Config->Parity;

	USARTx->CR2 |= UART_Config->StopBits;

	USARTx->CR3 |= UART_Config->HwFlowCtl;


	if(USARTx==USART1)
	{
		pclk=MCAL_RCC_GetPCLK1Freq();
	}

	else
	{
		pclk=MCAL_RCC_GetPCLK2Freq();
	}

	BRR=UART_BRR_Register(pclk,UART_Config->BaudRate);

	USARTx->BRR = BRR;

	//enable disable interrupt

	if (UART_Config->IRQ_Enable  != UART_IRQ_ENABLE_NONE  )
	{
		USARTx->CR1 |= (UART_Config->IRQ_Enable);

		//ENABLE NVIC;

		if (USARTx == USART1)
		{
			NVIC_IRQ37_USART1_EN;
		}
		else if (USARTx == USART2)
		{
			NVIC_IRQ38_USART2_EN;
		}

		else if (USARTx == USART3)
		{
			NVIC_IRQ39_USART3_EN;
		}

	}

}


void MCAL_UART_Deinit(USART_TypeDef*USARTx)
{

	if (USARTx == USART1)
	{
		RCC_USART1_RESET();
		NVIC_IRQ37_USART1_DIS;
	}
	else if (USARTx == USART2)
	{
		RCC_USART2_RESET();
		NVIC_IRQ38_USART2_DIS;
	}

	else if (USARTx == USART3)
	{
		RCC_USART3_RESET();
		NVIC_IRQ39_USART3_DIS;
	}

}







void MCAL_UARt_SendData(USART_TypeDef*USARTx , uint16_t *pTxBuffer, PollingMechanism PollingEn)

{

	if(PollingEn==enable)
	{
		while(!(USARTx->SR & 1<<7));

	}


	if(Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
	{
		USARTx->DR =(*pTxBuffer & (uint16_t)0x01FF);
	}
	else
	{
		USARTx->DR =(*pTxBuffer&(uint8_t)0x01FF);
	}

}



void MCAL_UART_WAIT_TC(USART_TypeDef * USARTx)
{
	while(!(USARTx->SR & 1>>6));
}


void MCAL_UARt_RecieveData(USART_TypeDef*USARTx,uint16_t* pRxBuffer, PollingMechanism PollingEn)
{
	if(PollingEn==enable)
	{
		while(!(USARTx->SR & 1<<5));

	}

	//CHECH FRAME LENGHT
	if(Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
	{
		if(Global_UART_Config->Parity == UART_PARITY_NONE)
		{
			*((uint16_t*)pRxBuffer)=USARTx->DR;
		}


		else
		{
			*((uint16_t*)pRxBuffer)=(USARTx->DR & (uint8_t)0xFF);
		}

	}else
	{
		if(Global_UART_Config->Parity== UART_PARITY_NONE)
		{
			*((uint16_t*)pRxBuffer)=(USARTx->DR & (uint8_t)0xFF);

		}
		else
		{
			*((uint16_t*)pRxBuffer)=(USARTx->DR & (uint8_t)0x7F);

		}
	}


}


void MCAL_UART_GPIO_SET_PINS(USART_TypeDef*USARTx)
{
	if(USARTx==USART1)
	{
		GPIO_PinConfig PinCfg;

		// PA9 - TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOA, &PinCfg);
		// PA10 - RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_init(GPIOA, &PinCfg);

		// PA11 - CTS
		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_init(GPIOA, &PinCfg);	}

		// PA12 - RTS
		if (Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinCfg);
			//usart2 and usart3 are missing

		}
	}
}

//ISR



void USART1_IRQHandler()
{
	Global_UART_Config->P_IRQ_CallBack();

}

void USART2_IRQHandler()
{

	Global_UART_Config->P_IRQ_CallBack();
}

void USART3_IRQHandler()
{

	Global_UART_Config->P_IRQ_CallBack();
}

