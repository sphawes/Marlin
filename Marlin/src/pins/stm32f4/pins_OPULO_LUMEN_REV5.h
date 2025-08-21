/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2022 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * STM32F407VET6 on Opulo Lumen PnP Rev5
 * Website - https://opulo.io/
 */


#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME      "LumenPnP Motherboard REV05"
#define DEFAULT_MACHINE_NAME "LumenPnP"

// #if defined(ARDUINO_ARCH_STM32) && !defined(STM32GENERIC)
//   // Variant default conflicts with Servo timer
//   #define STEP_TIMER 1
// #endif

#define SRAM_EEPROM_EMULATION
#define MARLIN_EEPROM_SIZE                0x2000  // 8K

//
// Limit Switches
//
#define X_STOP_PIN                          PC6
#define Y_STOP_PIN                          PD15
#define Z_STOP_PIN                          PD14

//
// TMC Diag Pins 
//

#define X_DIAG_PIN                          PB10
#define Y_DIAG_PIN                          PB11
#define Y2_DIAG_PIN                         PC12
#define Z_DIAG_PIN                          PB5
#define I_DIAG_PIN                          PC10
#define J_DIAG_PIN                          PC11


//
// Steppers
//

#define X_STEP_PIN                          PB15
#define X_DIR_PIN                           PB14
#define X_ENABLE_PIN                        PD9

#define Y_STEP_PIN                          PE15
#define Y_DIR_PIN                           PE14
#define Y_ENABLE_PIN                        PB13

#define Y2_STEP_PIN                         PD6
#define Y2_DIR_PIN                          PD7
#define Y2_ENABLE_PIN                       PA3

#define Z_STEP_PIN                          PE7
#define Z_DIR_PIN                           PB1
#define Z_ENABLE_PIN                        PE9

#define I_STEP_PIN                          PC4
#define I_DIR_PIN                           PA4
#define I_ENABLE_PIN                        PB0

#define J_STEP_PIN                          PE11
#define J_DIR_PIN                           PE10
#define J_ENABLE_PIN                        PE13

// TMC UART

#define X_SERIAL_TX_PIN                   PD8
#define X_SERIAL_RX_PIN        X_SERIAL_TX_PIN

#define Y_SERIAL_TX_PIN                   PB12
#define Y_SERIAL_RX_PIN        Y_SERIAL_TX_PIN

#define Y2_SERIAL_TX_PIN                  PA2
#define Y2_SERIAL_RX_PIN       Y2_SERIAL_TX_PIN

#define Z_SERIAL_TX_PIN                   PE8
#define Z_SERIAL_RX_PIN        Z_SERIAL_TX_PIN

#define I_SERIAL_TX_PIN                   PC5
#define I_SERIAL_RX_PIN        I_SERIAL_TX_PIN

#define J_SERIAL_TX_PIN                   PE12
#define J_SERIAL_RX_PIN        J_SERIAL_TX_PIN



// Reduce baud rate to improve software serial reliability
#define TMC_BAUD_RATE                    19200


//
// Heaters / Fans
//
#define FAN0_PIN                            PB8
#define FAN1_PIN                            PB9
#define FAN2_PIN                            PE5
#define FAN3_PIN                            PE6

//#define FAN_SOFT_PWM_REQUIRED

#define BEEPER_PIN                          PA7

//
// Neopixel
//
#define NEOPIXEL_PIN                        PC7
#define NEOPIXEL2_PIN                       PC8

//
// SPI
//
#define MISO_PIN                            PB4
#define MOSI_PIN                            PB5
#define SCK_PIN                             PB3

#define TMC_SPI_MISO                    MISO_PIN
#define TMC_SPI_MOSI                    MOSI_PIN
#define TMC_SPI_SCK                      SCK_PIN

//
// I2C
//
#define I2C_SDA_PIN                         PB7
#define I2C_SCL_PIN                         PB6

/**
 * The LumenPnP Motherboard REV05 has one aux port. We define them here so they may be used
 * in other places and to make sure someone doesn't have to go look up the pinout
 * in the board files. The 8 pin aux port has this pinout:
 *
 *                               _________
 *                        3.3V  |  1   2  |  GND
 *      (LUMEN_AUX_PWM1)   PA5  |  3   4  |  PC0  (LUMEN_AUX_A1)
 *      (LUMEN_AUX_PWM2)   PA6  |  5   6  |  SCL  (I2C_SCL_PIN)
 *      (LUMEN_AUX_PWM3)  PA15  |  7   8  |  SDA  (I2C_SDA_PIN)
 *                               ---------
 */
#define LUMEN_AUX_PWM1                     PA5
#define LUMEN_AUX_PWM2                     PA6
#define LUMEN_AUX_PWM3                     PA15
#define LUMEN_AUX_A1                       PC0

#define RS485_TX_ENABLE_PIN                 PD11
#define RS485_RX_ENABLE_PIN                 PD12


/*

ID PINS

PD0, PD1, PD2, PD3

// setting input pullup

M42 P15 T2 // PD0
M42 P14 T2 // PD1
M42 P13 T2 // PD2
M42 P12 T2 // PD3

// reading values

M43 P43 // PD0
M43 P44 // PD1
M43 P45 // PD2
M43 P46 // PD3

// aux pin set input pullup

M42 I P31 T2  // PD13

//aux pin Write

M42 P31 S255 // PD13
M42 P31 S0 // PD13

// Aux pin Read

M43 P56


consistent settings:
M906 X1000 Y1000
M204 T4000
G0 F60000

*/