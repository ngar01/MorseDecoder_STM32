# STM32 Morse Decoder

**A Morse code decoder project using STM32F411RE, I2C LCD 1602A, buzzer, and user button.**

---

## 📌 About the Project

This project implements a Morse code decoder using an STM32F411RE microcontroller. It decodes Morse code input from a user button and displays the decoded letters on an I2C LCD 1602A. A buzzer provides audio feedback for short and long button presses.

### Features
- Decodes Morse code input from a user button.
- Displays decoded letters on an I2C LCD 1602A.
- Provides audio feedback using a buzzer.
- Uses STM32CubeIDE for project configuration and code generation.

---

## 📌 Hardware Requirements

| Component               | Quantity | STM32F411RE Pins       |
|-------------------------|----------|----------------------|
| STM32F411RE (Nucleo)     | 1        | -                    |
| I2C LCD 1602A           | 1        | PB6 (SCL), PB7 (SDA) |
| Buzzer                  | 1        | PA8 (TIM1_CH1)       |
| 220Ω Resistor           | 1        | For buzzer          |

---

## 📌 Wiring Instructions

### I2C LCD 1602A
| LCD Pin | STM32F411RE Pin |
|---------|----------------|
| VCC     | 5V             |
| GND     | GND            |
| SCL     | PB6            |
| SDA     | PB7            |

### Buzzer
| Buzzer Pin | STM32F411RE Pin |
|------------|----------------|
| +          | PA8            |
| -          | GND            |

*(Add a 220Ω resistor in series with the buzzer.)*

### User Button
The user button is already connected to **PC13** on the Nucleo board.

---

## 📌 Software Requirements

- **STM32CubeIDE**: For project configuration and code generation.
- **Git**: For version control.
- **Terminal Emulator** (e.g., PuTTY, STM32CubeIDE Serial Monitor): For debugging output.

---

## 📌 Setup Instructions

### 1. Clone the Repository
```bash
git clone https://github.com/ngar01/MorseDecoder_STM32.git
cd MorseDecoder_STM32

