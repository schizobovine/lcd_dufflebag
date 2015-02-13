/*
 * lcd_dufflebag.h
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <TinyWireS.h>
#include <EEPROM.h>
#include "lcd_dufflebag.h"

byte my_i2c_addr = 0;
byte my_reg_addr = 0;
byte brightness = 0x7f;

//byte display_buff[32];

LiquidCrystal lcd = LiquidCrystal(RS, RW, E, DB4, DB5, DB6, DB7);

/*
void recv_handler(uint8_t num_bytes) {

  // TODO Somehow inform user of buffer overflow?
  if (num_bytes < 1 || num_bytes > TWI_RX_BUFFER_SIZE) {
    return;
  }

  byte a = TinyWireS.receive();
  num_bytes--;

  if (a < 0 || a >= REG_MAX) {
    return;
  } else {
    my_reg_addr = a;
  }

  // If there's only a single byte, that was an address set, so go ahead and
  // return
  if (!num_bytes) {
    return;
  }

  //
  // TODO Dispatch code based on address. Cases to handle:
  //
  // 1. Read/write display buffer. If write, set some flag to check to push the
  // data to the display next chance we get in the main loop.
  //
  // 2. Read/write brightness level. Same flag deal (may need to use single
  // flag due to memory limitations?)
  //
  // 3. Read/write backlight color (RGB). Same flag deal (may need to use
  // single flag due to memory limitations?)
  //
  // 4. (Optional) Read/write i2c address.
  // 5. (Optional) Read/write display size (maybe just read?)
  // 6. (Optional) Pass-through to LCD controller somehow? Could be useful to
  // upload character glyphs, for example.
  //

  // IDEA: Discard brightness, just deal in RGB.

#if 0
  // Otherwise, handle further reads based on address specified
  if (my_reg_addr >= REG_LINE1 && my_reg_addr < REG_BRIGHT) {
    while (num_bytes-- && my_reg_addr >= REG_LINE1 && my_reg_addr < REG_BRIGHT) {
      byte b = TinyWireS.receive();
      display_buff[
    }
  }
#endif

}

void req_handler() {

  // Allow master to read display buffer
  if (my_reg_addr >= REG_LINE1 && my_reg_addr < REG_BRIGHT) {
    TinyWireS.send(display_buff[my_reg_addr - REG_LINE1]);

  // Allow master to read display brightness level
  } else if (my_reg_addr == REG_BRIGHT) {
    TinyWireS.send(brightness);
  }

  // Increment register pointer, wrapping around if we're at the end
  my_reg_addr++;
  if (my_reg_addr >= REG_MAX) {
    my_reg_addr = 0x00;
  }

}
*/

void setBacklight() {
  pinMode(BACKLIGHT, OUTPUT);
  analogWrite(BACKLIGHT, brightness);
}

void setup() {

  // Get i2c address from EEPROM
  //my_i2c_addr = EEPROM.read(EEPROM_I2C_ADDR);
  //if (my_i2c_addr > 127) {
  //  my_i2c_addr = DEFAULT_I2C_ADDR;
  //  EEPROM.write(EEPROM_I2C_ADDR, my_i2c_addr);
  //}

  //Wire.begin(my_i2c_addr);
  //Wire.onRequest(req_handler);
  //Wire.onReceive(recv_handler);

  pinMode(BACKLIGHT, OUTPUT);
  
  lcd.begin(COLS, ROWS);
  lcd.print("DICKBAGS");

}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis());
  setBacklight();
  delay(1000);
}
