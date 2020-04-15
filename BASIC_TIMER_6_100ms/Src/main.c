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

TIM_HandleTypeDef htim6;

void SystemClock_Config(void);
static void MX_TIM6_Init(void);
void GPIO_Init(void);
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_TIM6_Init();
  GPIO_Init();

  HAL_TIM_Base_Start(&htim6);
  while (1)
  {
	  while (!TIM6->SR & TIM_SR_UIF);
	  TIM6->SR = 0;
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
  }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{
	htim6.Instance = TIM6;
	htim6.Init.Prescaler = 4999;
	htim6.Init.Period = 3200-1;

	if (HAL_TIM_Base_Init(&htim6) != HAL_OK) {
		Error_Handler();
	}
}

void GPIO_Init(void) {
	GPIO_InitTypeDef gpio5;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio5.Mode = GPIO_MODE_OUTPUT_PP;
	gpio5.Pin = GPIO_PIN_5;
	gpio5.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOA, &gpio5);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{

}

void TIM6_DAC_IRQHandler(void) {
	HAL_TIM_IRQHandler(&htim6);
}
