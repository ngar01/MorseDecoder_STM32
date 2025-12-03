/*
 * uart_debug.h
 *
 *	@brief   Header for UART-based debug printing.
 *
 *  Created on: Dec 2, 2025
 *      Author: ngard
 */

#ifndef INC_UART_DEBUG_H_
#define INC_UART_DEBUG_H_

#include "stm32f4xx_hal.h"

/**
 * @brief  Print a string via UART.
 * @param  str: String to print.
 */
void Debug_Print(const char *str);

#endif /* INC_UART_DEBUG_H_ */
