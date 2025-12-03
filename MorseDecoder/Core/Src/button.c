/*
 * button.c
 *
 *	@brief   Implementation of button input handling.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#include "button.h"

static uint32_t pressStartTime = 0;  /**< Timestamp when button was pressed */

/**
 * @brief  Initialize the button (PC13).
 */
void Button_Init(void) {
    /* Button initialization is handled in STM32CubeIDE (EXTI13) */
}

/**
 * @brief  Check if the button is pressed.
 * @return 1 if pressed, 0 otherwise.
 */
uint8_t Button_IsPressed(void) {
    return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET;
}

/**
 * @brief  Get the duration of the button press in milliseconds.
 * @return Duration in milliseconds.
 */
uint32_t Button_GetPressDuration(void) {
    if (Button_IsPressed()) {
        if (pressStartTime == 0) {
            pressStartTime = HAL_GetTick();
        }
        return HAL_GetTick() - pressStartTime;
    } else {
        uint32_t duration = pressStartTime > 0 ? HAL_GetTick() - pressStartTime : 0;
        pressStartTime = 0;
        return duration;
    }
}

