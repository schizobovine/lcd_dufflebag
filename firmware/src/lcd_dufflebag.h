#ifndef __LCD_DUFFLEBAG_H
#define __LCD_DUFFLEBAG_H

#include<Arduino.h>
//#include <TinyWireS.h>

#define Wire TinyWireS

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
