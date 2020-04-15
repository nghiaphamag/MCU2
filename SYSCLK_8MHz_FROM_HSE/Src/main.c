/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include <string.h>
#include <stdio.h>

UART_HandleTypeDef huart2;

static void MX_USART2_UART_Init(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	char msg[100];
	HAL_Init();


	RCC_OscInitTypeDef OSC_Init;
	RCC_ClkInitTypeDef CLK_Init;

	memset(&OSC_Init, 0, sizeof(OSC_Init));
	memset(&CLK_Init, 0, sizeof(CLK_Init));

	OSC_Init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	OSC_Init.HSEState = RCC_HSE_BYPASS;

	if (HAL_RCC_OscConfig(&OSC_Init) != HAL_OK) {
	    Error_Handler();
	}

	CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
						 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
	CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV2;
	CLK_Init.APB1CLKDivider = RCC_HCLK_DIV2;
	CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&CLK_Init, FLASH_ACR_LATENCY_0WS) != HAL_OK) {
	    Error_Handler();
	}

	//HSI can not be stopped if it is used as system clock source.
	__HAL_RCC_HSI_DISABLE();

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	MX_USART2_UART_Init();

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "SYSCLK: %ldHz \r\n", HAL_RCC_GetSysClockFreq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "HCLK: %ldHz \r\n", HAL_RCC_GetHCLKFreq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "PCLK1: %ldHz \r\n", HAL_RCC_GetPCLK1Freq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "PCLK2: %ldHz \r\n", HAL_RCC_GetPCLK2Freq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	while(1);
	return 0;
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void) {

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance 			= USART2;
  huart2.Init.BaudRate 		= 9600;
  huart2.Init.WordLength	= UART_WORDLENGTH_8B;
  huart2.Init.StopBits 		= UART_STOPBITS_1;
  huart2.Init.Parity 		= UART_PARITY_NONE;
  huart2.Init.Mode 			= UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
  huart2.Init.OverSampling 	= UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{

}

