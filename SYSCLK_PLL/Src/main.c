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
void SystemClock_ConfigHSI(uint8_t clockFreq);
void SystemClock_ConfigHSE(uint8_t clockFreq);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	char msg[100];

	HAL_Init();

	SystemClock_ConfigHSE(SYS_CLK_FREQ_120MHz);

	MX_USART2_UART_Init();

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "SYSCLK: %ld Hz \r\n", HAL_RCC_GetSysClockFreq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "HCLK: %ld Hz \r\n", HAL_RCC_GetHCLKFreq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "PCLK1: %ld Hz \r\n", HAL_RCC_GetPCLK1Freq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(&msg, 0, strlen(msg));
	sprintf(msg, "PCLK2: %ld Hz \r\n", HAL_RCC_GetPCLK2Freq());
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	while(1);
	return 0;
}


/**
  * @brief System Clock Configuration by HSI
  * @retval None
  * @memo	1MHz <= PLLM >= 2MHz
  * 		40MHz <= PLLN >= 432MHz
  */
void SystemClock_ConfigHSE(uint8_t clockFreq) {

	uint32_t Flatency = 0;
	RCC_OscInitTypeDef OSC_Init;
	RCC_ClkInitTypeDef CLK_Init;

	memset(&OSC_Init, 0, sizeof(OSC_Init));
	memset(&CLK_Init, 0, sizeof(CLK_Init));

	OSC_Init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	OSC_Init.HSEState = RCC_HSE_BYPASS;
	OSC_Init.PLL.PLLState  = RCC_PLL_ON;
	OSC_Init.PLL.PLLSource = RCC_PLLSOURCE_HSE;

	switch (clockFreq) {
		case SYS_CLK_FREQ_50MHz:
		{
			OSC_Init.PLL.PLLM = 8;
			OSC_Init.PLL.PLLN = 100;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
								 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV2;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;
			Flatency = FLASH_ACR_LATENCY_1WS;
			break;
		}
		case SYS_CLK_FREQ_84MHz:
		{
			OSC_Init.PLL.PLLM = 8;
			OSC_Init.PLL.PLLN = 168;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
								 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV2;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;
			Flatency = FLASH_ACR_LATENCY_2WS;
			break;
		}
		case SYS_CLK_FREQ_120MHz:
		{
			OSC_Init.PLL.PLLM = 8;
			OSC_Init.PLL.PLLN = 240;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
								 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV4;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;
			Flatency = FLASH_ACR_LATENCY_3WS;
			break;
		}
		case SYS_CLOCK_FREQ_180_MHZ:
		{
			//Enable the clock for the power controller
			__HAL_RCC_PWR_CLK_ENABLE();

			//set regulator voltage scale as 1
			__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

			//turn on the over drive mode of the voltage regulator
			__HAL_PWR_OVERDRIVE_ENABLE();

			OSC_Init.PLL.PLLM = 8;
			OSC_Init.PLL.PLLN = 360;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
						RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV4;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;

			Flatency = FLASH_ACR_LATENCY_5WS;
			break;
		}
		default:
			return;
	}
	if (HAL_RCC_OscConfig(&OSC_Init) != HAL_OK) {
	    Error_Handler();
	}
	if (HAL_RCC_ClockConfig(&CLK_Init, Flatency) != HAL_OK) {
	    Error_Handler();
	}

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}

/**
  * @brief System Clock Configuration by HSE
  * @retval None
  * @memo	1MHz <= PLLM >= 2MHz
  * 		40MHz <= PLLN >= 432MHz
  */
void SystemClock_ConfigHSI(uint8_t clockFreq) {
	uint32_t Flatency = 0;
	RCC_OscInitTypeDef OSC_Init;
	RCC_ClkInitTypeDef CLK_Init;

	memset(&OSC_Init, 0, sizeof(OSC_Init));
	memset(&CLK_Init, 0, sizeof(CLK_Init));

	OSC_Init.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	OSC_Init.HSIState = RCC_HSI_ON;
	OSC_Init.HSICalibrationValue = 16;
	OSC_Init.PLL.PLLState  = RCC_PLL_ON;
	OSC_Init.PLL.PLLSource = RCC_PLLSOURCE_HSI;

	switch (clockFreq) {
		case SYS_CLK_FREQ_50MHz:
		{
			OSC_Init.PLL.PLLM = 16;
			OSC_Init.PLL.PLLN = 100;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
								 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV2;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;
			Flatency = FLASH_ACR_LATENCY_1WS;
			break;
		}
		case SYS_CLK_FREQ_84MHz:
		{
			OSC_Init.PLL.PLLM = 16;
			OSC_Init.PLL.PLLN = 168;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
								 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV2;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;
			Flatency = FLASH_ACR_LATENCY_2WS;
			break;
		}
		case SYS_CLK_FREQ_120MHz:
		{
			OSC_Init.PLL.PLLM = 16;
			OSC_Init.PLL.PLLN = 240;
			OSC_Init.PLL.PLLP = 2;
			OSC_Init.PLL.PLLQ = 2;
			OSC_Init.PLL.PLLR = 2;

			CLK_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			CLK_Init.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|	\
								 RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
			CLK_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
			CLK_Init.APB1CLKDivider = RCC_HCLK_DIV4;
			CLK_Init.APB2CLKDivider = RCC_HCLK_DIV2;
			Flatency = FLASH_ACR_LATENCY_3WS;
			break;
		}
		default:
			return;
	}
	if (HAL_RCC_OscConfig(&OSC_Init) != HAL_OK) {
	    Error_Handler();
	}
	if (HAL_RCC_ClockConfig(&CLK_Init, Flatency) != HAL_OK) {
	    Error_Handler();
	}

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance 			= USART2;
  huart2.Init.BaudRate 		= 115200;
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

