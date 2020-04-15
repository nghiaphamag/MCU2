/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f4xx_it.h"
extern TIM_HandleTypeDef htim2;


/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1);
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  while (1);
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  while (1);
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  while (1);
}


/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{

  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();

}

void TIM2_IRQHandler(void) {
	HAL_TIM_IRQHandler(&htim2);
}

