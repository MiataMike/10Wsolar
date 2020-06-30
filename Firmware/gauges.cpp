#include "gauges.h"
//display is 296x128
#define display_width 296
#define display_height 128

const unsigned char T [] PROGMEM = {
  // 'T logo, 12x12px
  0x80, 0x10, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xcf, 0x30, 0x8f, 0x10, 0x8f, 0x10, 
  0x0f, 0x00, 0x0f, 0x00, 0x1f, 0x80, 0x3f, 0xc0
};
void drawGraph(int x, int y, int w, int h, int* data, Adafruit_IL0373 display)
{
  display.drawRect(x,y,w,h,EPD_BLACK);
  for(int i = 0; i<w; i++)
  {
    display.drawFastVLine((x+i), y+h, -i, EPD_RED);
  }
	return;
}

void drawWindow(Adafruit_IL0373 display)
{
  display.drawRect(0,0, display_width, 18, EPD_BLACK);//bar
  display.drawFastHLine(0,1, display_width, EPD_RED);
  display.drawFastHLine(0,2, display_width, EPD_BLACK);
  display.drawRect(282,4,12,12, EPD_BLACK);// X square
    display.drawLine(282+9,4+2, 282+2, 4+9, EPD_BLACK);    
    display.drawLine(282+9,4+9, 282+2, 4+2, EPD_BLACK);
  display.drawRect(268,4,12,12, EPD_BLACK);// Max square
    display.drawRect(268+2,8, 6, 6, EPD_BLACK); //small left sq
    display.drawRect(268+4,6, 6, 6, EPD_BLACK); // larger right sq
  display.drawRect(254,4,12,12, EPD_BLACK);// min square
    display.drawFastHLine(256,13,8, EPD_BLACK); 
  display.setCursor(70, 7);//mid bar
  display.setTextColor(EPD_BLACK);
  display.print("Lunar Power Monitor V0.1");
  display.drawBitmap(3, 4, T, 12, 12, EPD_RED);
}
