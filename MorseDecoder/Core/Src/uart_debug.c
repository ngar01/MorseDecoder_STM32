/*
 * uart_debug.c
 *
 *	@brief   Implementation of UART-based debug printing.
 *
 *  Created on: Dec 2, 2025
 *      Author: ngard
 */

#include "uart_debug.h"
#include <string.h>

extern UART_HandleTypeDef huart2;  /* Assume UART2 is configured in STM32CubeIDE */

/**
 * @brief  Print a string via UART.
 * @param  str: String to print.
 */
void Debug_Print(const char *str) {
    HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}
