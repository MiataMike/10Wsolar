#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"
#include "gauges.h"

#define EPD_CS      4
#define EPD_DC      5
#define SRAM_CS     6
#define EPD_RESET   8 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    9 // can set to -1 to not use a pin (will wait a fixed delay)
Adafruit_IL0373 display(296, 128, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);
void setup() {
  // put your setup code here, to run once:

  display.begin();
  display.clearBuffer();
  drawWindow(display);
  drawGraph(6, 24, 98,98,0,  display);
  drawGraph(192, 24, 98,98,0,  display);
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

while(1)
{
  delay(1000);
}
}
