/* Copyright 2022 @ Keychron(https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 9

/* left side matrix pins */
#define MATRIX_ROW_PINS \
    { A13, A14, A15, B3, B4, B5 }
#define MATRIX_COL_PINS \
    { A7, A6, A5, A4, A3, A2, A1, C15, NO_PIN }
/* right side matrix pins */
#define MATRIX_ROW_PINS_RIGHT \
    { B5, B4, B3, A15, A14, A13 }
#define MATRIX_COL_PINS_RIGHT \
    { A8, A7, A6, A5, A4, A3, A2, A1, A0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS { A8 }

/* handedness */
// #define SPLIT_HAND_MATRIX_GRID D0, F1
// #define EE_HANDS
// #define MASTER_LEFT

/* RGB Matrix Configuration */
#define DRIVER_COUNT 1
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_1_LED_TOTAL 89
#define RGB_MATRIX_LED_COUNT DRIVER_1_LED_TOTAL
#define RGB_MATRIX_SPLIT { 42, 47 }

/* Increase I2C speed to 1000 KHz */
#define I2C1_TIMINGR_PRESC 0U  // prescale i2c clock
#define I2C1_TIMINGR_SCLDEL 3U // data setup time
#define I2C1_TIMINGR_SDADEL 0U // data hold time
#define I2C1_TIMINGR_SCLH 15U  // high period
#define I2C1_TIMINGR_SCLL 30U  // low period

#define CKLED2001_CURRENT_TUNE \
    { 0x80, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0x80, 0xFF, 0xFF } // 300mA

/* EEPROM Driver Configuration */
#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)

/* Split Keyboard specific options. */
#define USE_SERIAL
// #define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN A9   // USART TX pin
// #define SERIAL_USART_RX_PIN A10  // USART RX pin

/* Encoder Configuration */
#define ENCODERS_PAD_A \
    { B0 }
#define ENCODERS_PAD_B \
    { B1 }
#define ENCODER_RESOLUTIONS \
    { 4 }
#define ENCODERS_PAD_A_RIGHT \
    { C14 }
#define ENCODERS_PAD_B_RIGHT \
    { C15 }
#define ENCODER_RESOLUTIONS_RIGHT \
    { 4 }
#define ENCODER_DEFAULT_POS 0x3

/* Disable RGB lighting when PC is in suspend */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_BAND_SAT
// #define ENABLE_RGB_MATRIX_BAND_VAL
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
// #define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* Enable receive custom command from host */
#define RAW_HID_CMD 0xAB
