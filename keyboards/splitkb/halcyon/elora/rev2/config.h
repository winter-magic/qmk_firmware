// Copyright 2025 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//Markus Features
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define RGB_MATRIX_DEFAULT_ON true

#ifdef TAPPING_TERM
# undef TAPPING_TERM
# define TAPPING_TERM 250
#endif
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150

//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 20000
//#define SPLIT_USB_TIMEOUT_POLL 1
//#define SPLIT_MAX_CONNECTION_ERRORS 50

#define LEADER_TIMEOUT 400
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY

#define LUMBERJACK_COLOR
#define ACTION_DEBUG

//Ende Markus Features



// Make it easier to enter the bootloader
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// UART1, communication between the two halves
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP28   // USART TX pin
#define SERIAL_USART_RX_PIN GP29   // USART RX pin
#define SERIAL_PIO_USE_PIO1        // Use PIO1 as PIO0 is used for WS2812 driver

// VBUS detection
#define USB_VBUS_PIN GP1

//// VIK

// GPIO1 = GP27
// GPIO2 = GP26
// CS = GP13

#define I2C_DRIVER I2C0
#define I2C1_SDA_PIN GP16
#define I2C1_SCL_PIN GP17

#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP14
#define SPI_MOSI_PIN GP15
#define SPI_MISO_PIN GP12
