#ifndef __LCD_DUFFLEBAG_H
#define __LCD_DUFFLEBAG_H

#include<Arduino.h>

//#define Wire TinyWireS

//#ifndef TWI_RX_BUFFER_SIZE
//#define TWI_RX_BUFFER_SIZE (16)
//#endif

// Address where the i2c address should be stored in EEPROM
//#define EEPROM_I2C_ADDR 0x00

// Default i2c address if one has not been stored yet
//#define DEFAULT_I2C_ADDR 0x42

//#define REG_LINE1  (0x00)
//#define REG_LINE2  (0x10)
//#define REG_BRIGHT (0x11)
//#define REG_MAX    (0x12)

// Pin mappings
#define RS  (PB2)
#define RW  (PB1)
#define E   (PB0)

#define DB4 (PA0)
#define DB5 (PA1)
#define DB6 (PA2)
#define DB7 (PA3)

#define BACKLIGHT (PA5)

// LCD parameters
#define COLS (8)
#define ROWS (2)

#endif
