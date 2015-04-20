/*
 * lcd_dufflebag.h
 */

#include <Arduino.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include "lcd_dufflebag.h"

byte brightness = 0x7f;

SoftwareSerial nouart(RX, TX);
LiquidCrystal lcd = LiquidCrystal(RS, RW, E, DB4, DB5, DB6, DB7);

void display_setup() {

  pinMode(BACKLIGHT, OUTPUT);
  analogWrite(BACKLIGHT, brightness);

  lcd.begin(COLS, ROWS);
  lcd.print("DICKBUTT");
  delay(300);
  lcd.clear();

}

void cmd_clear() {
  lcd.clear();
}

void cmd_home() {
  lcd.home();
}

void cmd_reset() {
  display_setup();
}

void setup() {

  display_setup();

  nouart.begin(9600);

}

void loop() {
  
  // Poll for new data
  if (nouart.available()) {
    byte c = nouart.read();

    // Check for and handle magical command bytes. Should make this a proper
    // state machine.
    if (c >= UART_CMD_MIN) {
      switch (c) {
        case UART_CMD_HOME:
          break;
        case UART_CMD_CLEAR:
          break;
        case UART_CMD_RESET:
          break;
        default:
          break;
      }

    // Default is to write a character to the display
    } else {
      lcd.write(c);
    }

  }

}
