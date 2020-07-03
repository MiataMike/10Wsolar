#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"
#include "gauges.h"
#include "reading.h"
#include "control.h"
#include "math.h"

#define EPD_CS      4
#define EPD_DC      5
#define SRAM_CS     6
#define EPD_RESET   8 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    9 // can set to -1 to not use a pin (will wait a fixed delay)
#define SD_CS       7

int chartData1[85];
char chartTitle1[] = "SOC";
int chartData2[84];
char chartTitle2[] = "Power";
Adafruit_IL0373 display(296, 128, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  
  for(int i = 0; i<84; i++)
  {
    chartData1[i] = 42*cos(i*6.28/42)+42;
    //Serial.println(chartData1[i]);
  }
    for(int i = 0; i<84; i++)
  {
    chartData2[i] = 42*sin(i*6.28/42)+42;
    //Serial.println(chartData2[i]);
  }
  
  display.begin();
  display.clearBuffer();
  drawWindow(&display);
  drawGraph( 5, 32, 86,86,chartData1, chartTitle1, &display);
  drawGraph(96, 32, 86,86,chartData2, chartTitle2, &display);
  drawTerminal(&display);
  display.display();

  
}

void loop() {
  // put your main code here, to run repeatedly:

while(1)
{
  
  delay(1000);
}
}
