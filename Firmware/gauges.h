#ifndef GAUGES_H
#define GAUGES_H

#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"


class Graph
{
  private:
    int len;
    int data[];
  public:
    void draw(int x, int y, int w, int h, int* data, char* title, Adafruit_IL0373* display);
    void updateData(int input);    
};
void drawGraph(int x, int y, int w, int h, int* data, char* title, Adafruit_IL0373* display);
void drawWindow(Adafruit_IL0373* display);
void drawTerminal(Adafruit_IL0373* display);
void updateGraphData(int* data, int len, float input);
#endif
