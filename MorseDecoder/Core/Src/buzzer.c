/*
 * buzzer.c
 *
 *	@brief   Implementation of buzzer control using STM32 TIM PWM.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#include "buzzer.h"

/**
 * @brief  Initialize the buzzer with PWM on TIM1_CH1.
 * @param  htim: Pointer to the TIM handle.
 */
void Buzzer_Init(TIM_HandleTypeDef *htim) {
    HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);  // Start PWM on TIM1_CH1 (PA8)
}

/**
 * @brief  Activate the buzzer for a specified duration.
 * @param  duration_ms: Duration in milliseconds.
 */
void Buzzer_Beep(uint32_t duration_ms) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);  // Turn buzzer ON
    HAL_Delay(duration_ms);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);  // Turn buzzer OFF
}

