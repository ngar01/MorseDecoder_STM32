/*
 * morse_decoder.h
 *
 *	@brief   Header for Morse code decoding logic.
 *
 *  Created on: Nov 30, 2025
 *      Author: ngard
 */

#ifndef INC_MORSE_DECODER_H_
#define INC_MORSE_DECODER_H_

#include "stm32f4xx_hal.h"

/**
 * @brief  Initialize the Morse decoder.
 */
void MorseDecoder_Init(void);

/**
 * @brief  Process a button press (short/long) for Morse decoding.
 * @param  duration_ms: Duration of the button press in milliseconds.
 */
void MorseDecoder_ProcessPress(uint32_t duration_ms);

/**
 * @brief  Decode a Morse code letter.
 * @param  morseCode: Morse code string (e.g., ".-" for 'A').
 * @return Decoded character.
 */
char MorseDecoder_DecodeLetter(const uint8_t* morseCode);

#endif /* INC_MORSE_DECODER_H_ */
