#ifndef __LCD_DUFFLEBAG_H
#define __LCD_DUFFLEBAG_H

#include<Arduino.h>

#if 0
//#define Wire TinyWireS

#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE (16)
#endif

// Address where the i2c address should be stored in EEPROM
#define EEPROM_I2C_ADDR 0x00

// Default i2c address if one has not been stored yet
#define DEFAULT_I2C_ADDR 0x42

#define REG_LINE1  (0x00)
#define REG_LINE2  (0x10)
#define REG_BRIGHT (0x11)
#define REG_MAX    (0x12)
#endif

// Pin mappings
#define RS  (8)
#define RW  (9)
#define E   (10)

#define DB4 (0)
#define DB5 (1)
#define DB6 (2)
#define DB7 (3)

#define BACKLIGHT (7)

#define RX  (6)
#define TX  (5)
#define CLK (4)

// LCD parameters
#define COLS (8)
#define ROWS (2)

// Serial commands
#define UART_CMD_MIN    (0x7F)
#define UART_CMD_HOME   (0xFD)
#define UART_CMD_CLEAR  (0xFE)
#define UART_CMD_RESET  (0xFF)

#endif
