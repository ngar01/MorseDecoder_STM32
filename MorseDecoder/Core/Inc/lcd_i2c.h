/*
 * lcd_i2c.h
 *
 * @brief   I2C Driver for HD44780-based LCD (e.g., 1602A) using STM32 HAL.
 * @details This driver communicates with the LCD via I2C using a PCF8574 I/O expander.
 *          It supports basic operations like initialization, cursor positioning, and text display.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_

#include "stm32f4xx_hal.h"

/* LCD Command Definitions */
#define LCD_CLEARDISPLAY   0x01  /**< Clear display command */
#define LCD_RETURNHOME     0x02  /**< Return cursor to home position */
#define LCD_ENTRYMODESET   0x04  /**< Set entry mode */
#define LCD_DISPLAYCONTROL 0x08  /**< Control display */
#define LCD_CURSORSHIFT    0x10  /**< Move cursor/shift display */
#define LCD_FUNCTIONSET    0x20  /**< Set LCD function */
#define LCD_SETCGRAMADDR   0x40  /**< Set CGRAM address */
#define LCD_SETDDRAMADDR   0x80  /**< Set DDRAM address */

/* Display Control Flags */
#define LCD_DISPLAYON  0x04  /**< Turn display on */
#define LCD_CURSORON   0x02  /**< Turn cursor on */
#define LCD_BLINKON    0x01  /**< Turn cursor blink on */

/* LCD Dimensions */
#define LCD_COLS 16  /**< Number of columns */
#define LCD_ROWS 2   /**< Number of rows */

/**
 * @brief  Initialize the LCD in 4-bit mode.
 * @param  hi2c: Pointer to the I2C handle.
 */
void LCD_Init(I2C_HandleTypeDef *hi2c);

/**
 * @brief  Clear the LCD display.
 */
void LCD_Clear(void);

/**
 * @brief  Set the cursor position.
 * @param  x: Column (0 to 15).
 * @param  y: Row (0 or 1).
 */
void LCD_SetCursor(uint8_t x, uint8_t y);

/**
 * @brief  Write a single character to the LCD.
 * @param  c: Character to display.
 */
void LCD_PutChar(char c);

/**
 * @brief  Write a string to the LCD.
 * @param  str: String to display.
 */
void LCD_Puts(char *str);

/**
 * @brief  Scan the I2C bus to find the LCD address.
 * @param  hi2c: Pointer to the I2C handle.
 */
void LCD_ScanI2C(I2C_HandleTypeDef *hi2c);

#endif /* INC_LCD_I2C_H_ */
