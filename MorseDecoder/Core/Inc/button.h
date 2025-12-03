/*
 * button.h
 *
 *	@brief   Header for button input handling.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"

/**
 * @brief  Initialize the button (PC13).
 */
void Button_Init(void);

/**
 * @brief  Check if the button is pressed.
 * @return 1 if pressed, 0 otherwise.
 */
uint8_t Button_IsPressed(void);

/**
 * @brief  Get the duration of the button press in milliseconds.
 * @return Duration in milliseconds.
 */
uint32_t Button_GetPressDuration(void);

#endif /* INC_BUTTON_H_ */
