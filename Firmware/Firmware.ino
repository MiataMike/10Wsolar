#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"
#include "gauges.h"
#include "reading.h"
#include "control.h"
#include "math.h"
#include "TimeLib.h"
#include <SD.h>


#define EPD_CS      4
#define EPD_DC      5
#define SRAM_CS     6
#define EPD_RESET   8 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    9 // can set to -1 to not use a pin (will wait a fixed delay)
#define SD_CS       7

int chartData1[85];
String chartTitle1 = "Battery V";
int chartData2[84];
String chartTitle2 = "Power W";
Adafruit_IL0373 display(296, 128, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);
Graph SOCgraph(5, 32, 86,86,"SOC %", &display);
Graph POWgraph(96, 32, 86,86, "Power W", &display);
float Vbatt = -1;
float Vpan = -1;
float Abatt = -1;

int duty = 32;

File datalog;


#define hr 9
#define minute 24
#define sec 45
#define day 7
#define month 7
#define yr 2020



void setup() {
  setTime(hr,minute,sec,day,month,yr);
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReadRes(16);
  delay(1000);
  
  for(int i = 0; i<84; i++)
  {
    chartData1[i] = 0;
    //chartData1[i] = 42*cos(i*6.28/42)+42;
    //Serial.println(chartData1[i]);
  }
    for(int i = 0; i<84; i++)
  {
    chartData2[i] = 0;
    //chartData2[i] = 42*sin(i*6.28/42)+42;
    //Serial.println(chartData2[i]);
  }
  SOCgraph.updateData(chartData1);
  POWgraph.updateData(chartData2);

  display.begin();
  SD.begin(SD_CS);
  initControl();
}

void loop() {
  // put your main code here, to run repeatedly:

while(1)
{
  Vpan = readSolar();
  Abatt = readCurr();
  Vbatt = readBatt();
 Serial.println(Vpan);
 Serial.println(Abatt);
 Serial.println(Vbatt); 
 Serial.println("_________");
 updateControl(Vbatt);

  SOCgraph.updateData2(84, (int)(Vbatt * 84 / 15.0));
  POWgraph.updateData2(84, (int)(Vbatt * Abatt * 84/13.0));

  display.clearBuffer();
  drawWindow(&display);
  SOCgraph.draw();
  POWgraph.draw();
  drawTerminal(Vbatt, Vpan, Abatt, &display);
  display.display();
  datalog = SD.open("datalog.csv", FILE_WRITE);
  if (datalog)
  {// Time, Vpanel, Abatt, Vbatt, duty
    datalog.print(now());
    datalog.print(",");
    datalog.print(Vpan);
    datalog.print(",");
    datalog.print(Abatt);
    datalog.print(",");
    datalog.print(Vbatt);
    datalog.print(",");
    datalog.println(duty);  
    datalog.close();
  }
  
  delay(60000*5);
  
}
}
