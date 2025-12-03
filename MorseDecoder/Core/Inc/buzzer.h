/*
 * buzzer.h
 *
 *	@brief   Header for buzzer control using STM32 TIM PWM.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "stm32f4xx_hal.h"

/**
 * @brief  Initialize the buzzer with PWM on TIM1_CH1.
 * @param  htim: Pointer to the TIM handle (e.g., &htim1).
 */
void Buzzer_Init(TIM_HandleTypeDef *htim);

/**
 * @brief  Activate the buzzer for a specified duration.
 * @param  duration_ms: Duration in milliseconds.
 */
void Buzzer_Beep(uint32_t duration_ms);



#endif /* INC_BUZZER_H_ */
