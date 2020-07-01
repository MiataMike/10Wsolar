#ifndef GAUGES_H
#define GAUGES_H

#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"

void drawGraph(int x, int y, int w, int h, int* data, char* title, Adafruit_IL0373 display);
void drawWindow(Adafruit_IL0373 display);
void drawTerminal(Adafruit_IL0373 display);

#endif
