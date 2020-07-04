#ifndef GAUGES_H
#define GAUGES_H

#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_EPD.h"
#include <string.h>

class Graph
{
  private:
    int X;
    int Y;
    int W;
    int H;
    int* Data;
    String Title;
    Adafruit_IL0373* Display;
  public:
    Graph(int x, int y, int w, int h, String title, Adafruit_IL0373* display);
    void draw();
    void updateData(int* input);    
    void updateData2(int len, int input);
};
void drawGraph(int x, int y, int w, int h, int* data, String title, Adafruit_IL0373* display);
void drawWindow(Adafruit_IL0373* display);
void drawTerminal(float Vbatt, float Vpan, float Apan, Adafruit_IL0373* display);
void updateGraphData(int* data, int len, float input);
#endif
