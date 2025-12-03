/*
 * morse_decoder.c
 *
 * @brief   Implementation of Morse code decoding logic.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#include "morse_decoder.h"
#include "lcd_i2c.h"
#include "buzzer.h"
#include <string.h>  /* For strcmp() */

/* Morse code table (A-Z) */
static const char* morseTable[] = {
    ".-", "-...", "-.-.", "-.", "..", "...-", "--.", "....", "..",    /* A-I */
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", /* J-R */
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."       /* S-Z */
};

static uint8_t currentLetter[8];  /* Buffer for current Morse letter */
static uint8_t letterIndex = 0;     /* Index for current letter */

/**
 * @brief  Initialize the Morse decoder.
 */
void MorseDecoder_Init(void) {
    letterIndex = 0;
}

/**
 * @brief  Process a button press (short/long) for Morse decoding.
 * @param  duration_ms: Duration of the button press in milliseconds.
 */
void MorseDecoder_ProcessPress(uint32_t duration_ms) {
    if (duration_ms < 50) return;  /* Debounce */

    if (duration_ms < 300) {  /* Short press (.) */
        currentLetter[letterIndex++] = '.';
        Buzzer_Beep(100);  /* Short beep */
    } else {  /* Long press (-) */
        currentLetter[letterIndex++] = '-';
        Buzzer_Beep(300);  /* Long beep */
    }

    /* Decode letter if pause > 700ms */
    if (duration_ms > 700 && letterIndex > 0) {
        currentLetter[letterIndex] = '\0';
        char letter = MorseDecoder_DecodeLetter(currentLetter);
        LCD_PutChar(letter);
        letterIndex = 0;
    }
}

/**
 * @brief  Decode a Morse code letter.
 * @param  morseCode: Morse code string (e.g., ".-" for 'A').
 * @return Decoded character.
 */
char MorseDecoder_DecodeLetter(const uint8_t* morseCode) {
    for (int i = 0; i < 26; i++) {
        if (strcmp((char*)morseCode, morseTable[i]) == 0) {
            return 'A' + i;
        }
    }
    return '?';  /* Unknown character */
}
