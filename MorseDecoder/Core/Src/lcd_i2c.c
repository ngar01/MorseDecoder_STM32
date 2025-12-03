/*
 * lcd_i2c.c
 *
 *	@brief   Implementation of the I2C LCD driver.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#include "lcd_i2c.h"
#include "uart_debug.h"  // For Debug_Print()

static I2C_HandleTypeDef *lcd_i2c;  /**< I2C handle for communication */
static uint8_t lcd_addr = 0x27;      /**< Default I2C address (adjust based on scan) */

/**
 * @brief  Send a 4-bit nibble to the LCD.
 * @param  nibble: 4-bit data to send.
 * @param  mode:   Control mode (RS bit: 0=command, 1=data).
 */
static void LCD_SendNibble(uint8_t nibble, uint8_t mode) {
    uint8_t data = (nibble << 4) | mode | 0x08;  /* 0x08 = backlight ON */

    /* Send high nibble with EN=0 */
    HAL_I2C_Master_Transmit(lcd_i2c, lcd_addr << 1, &data, 1, HAL_MAX_DELAY);

    /* Pulse EN (Enable) */
    data |= 0x04;  /* EN = 1 */
    HAL_I2C_Master_Transmit(lcd_i2c, lcd_addr << 1, &data, 1, HAL_MAX_DELAY);
    HAL_Delay(1);

    data &= ~0x04; /* EN = 0 */
    HAL_I2C_Master_Transmit(lcd_i2c, lcd_addr << 1, &data, 1, HAL_MAX_DELAY);
    HAL_Delay(1);
}

/**
 * @brief  Send a full byte to the LCD (split into two nibbles).
 * @param  data:  Byte to send.
 * @param  mode:  Control mode (RS bit: 0=command, 1=data).
 */
static void LCD_SendByte(uint8_t data, uint8_t mode) {
    LCD_SendNibble(data >> 4, mode);   /* Send high nibble */
    LCD_SendNibble(data & 0x0F, mode); /* Send low nibble */
}

/**
 * @brief  Initialize the LCD in 4-bit mode.
 * @param  hi2c: Pointer to the I2C handle.
 */
void LCD_Init(I2C_HandleTypeDef *hi2c) {
    lcd_i2c = hi2c;

    /* Wait for LCD to power on (50ms) */
    HAL_Delay(50);

    /* Initialization sequence (3x) */
    LCD_SendNibble(0x03, 0);
    HAL_Delay(5);
    LCD_SendNibble(0x03, 0);
    HAL_Delay(1);
    LCD_SendNibble(0x03, 0);
    HAL_Delay(1);

    /* Switch to 4-bit mode */
    LCD_SendNibble(0x02, 0);
    HAL_Delay(1);

    /* Function set: 4-bit, 2 lines, 5x8 dots */
    LCD_SendByte(0x28, 0);
    HAL_Delay(1);

    /* Display off */
    LCD_SendByte(0x08, 0);
    HAL_Delay(1);

    /* Clear display */
    LCD_Clear();

    /* Entry mode: increment, no shift */
    LCD_SendByte(0x06, 0);
    HAL_Delay(1);

    /* Display on, cursor off, blink off */
    LCD_SendByte(0x0C, 0);
    HAL_Delay(1);
}

/**
 * @brief  Clear the LCD display.
 */
void LCD_Clear(void) {
    LCD_SendByte(LCD_CLEARDISPLAY, 0);
    HAL_Delay(2);  /* Clear command requires 2ms delay */
}

/**
 * @brief  Set the cursor position.
 * @param  x: Column (0 to 15).
 * @param  y: Row (0 or 1).
 */
void LCD_SetCursor(uint8_t x, uint8_t y) {
    uint8_t addr = (y == 0) ? (0x00 + x) : (0x40 + x);
    LCD_SendByte(LCD_SETDDRAMADDR | addr, 0);
}

/**
 * @brief  Write a single character to the LCD.
 * @param  c: Character to display.
 */
void LCD_PutChar(char c) {
    LCD_SendByte(c, 1);  /* RS = 1 (data mode) */
}

/**
 * @brief  Write a string to the LCD.
 * @param  str: String to display.
 */
void LCD_Puts(char *str) {
    while (*str) {
        LCD_PutChar(*str++);
    }
}

/**
 * @brief  Scan the I2C bus to find the LCD address.
 * @param  hi2c: Pointer to the I2C handle.
 */
void LCD_ScanI2C(I2C_HandleTypeDef *hi2c) {
    HAL_StatusTypeDef status;
    Debug_Print("Scanning I2C bus...\n");
    for (uint8_t i = 1; i < 128; i++) {
        status = HAL_I2C_IsDeviceReady(hi2c, i << 1, 1, 10);
        if (status == HAL_OK) {
            char buffer[32];
            sprintf(buffer, "Device found at 0x%02X\n", i);
            Debug_Print(buffer);
        }
    }
}
