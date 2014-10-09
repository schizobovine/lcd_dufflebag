lcd_dufflebag
=============

Variation on the common LCD "backpack" design. Instead of using an IO expander or full blown ATMega, however, this design uses an ATTiny84 to drive the LCD, with just enough pins left over to be an I2C slave. Can control RGB LCDs via an optional WS2811 chip or monochrome displays via a simple BJT.
