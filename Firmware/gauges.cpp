#include "gauges.h"
//display is 296x128
#define display_width 296
#define display_height 128

const unsigned char T [] PROGMEM = {
  // 'T logo, 12x12px
  0x80, 0x10, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0xcf, 0x30, 0x8f, 0x10, 0x8f, 0x10, 
  0x0f, 0x00, 0x0f, 0x00, 0x1f, 0x80, 0x3f, 0xc0
};

Graph::Graph(int x, int y, int w, int h, String title, Adafruit_IL0373* display)
{
  X = x;
  Y = y;
  W = w;
  H = h;
  //Data;
  Title = title;
  Display = display;
}

void Graph::draw()
{
  Display->setCursor(X,Y-10);
  Display->setTextColor(EPD_BLACK);
  Display->print(Title);
  Display->drawRect(X,Y,W,H,EPD_BLACK);
  for(int i = 0; i<W-2; i++)//data should be 2 less than the width
  {
    Display->drawFastVLine((X+i+1), Y+H, -(Data[i]), EPD_BLACK);
  }
  for(int i = 0; i<W; i++)
  {
    if ((i)%16==0)
    {
        Display->drawFastVLine(X+W-(i+1),Y+H, 8, EPD_BLACK);//x+w starts from the right, and moves left
    }
    else if ((i)%8==0)
    {
        Display->drawFastVLine(X+W-(i+1),Y+H, 6, EPD_BLACK);
    }
    else if ((i)%4==0)
    {
        Display->drawFastVLine(X+W-(i+1),Y+H, 4, EPD_BLACK);
    }
  }
  return;
}

void Graph::updateData(int* input)
{
  Data = input;
}

void drawGraph(int x, int y, int w, int h, int* data, String title, Adafruit_IL0373* display)
{
  display->setCursor(x,y-10);
  display->setTextColor(EPD_BLACK);
  display->print(title);
  display->drawRect(x,y,w,h,EPD_BLACK);
  for(int i = 0; i<w-2; i++)//data should be 2 less than the width
  {
    display->drawFastVLine((x+i+1), y+h, -(data[i]), EPD_BLACK);
  }
  for(int i = 0; i<w; i++)
  {
    if ((i)%16==0)
    {
        display->drawFastVLine(x+w-(i+1),y+h, 8, EPD_BLACK);//x+w starts from the right, and moves left
    }
    else if ((i)%8==0)
    {
        display->drawFastVLine(x+w-(i+1),y+h, 6, EPD_BLACK);
    }
    else if ((i)%4==0)
    {
        display->drawFastVLine(x+w-(i+1),y+h, 4, EPD_BLACK);
    }
  }
	return;
}
#define closeYoffset1 2// for drawing diagonals; corners
#define closeYoffset2 9
#define closeXoffset1 2
#define closeXoffset2 9

void drawWindow(Adafruit_IL0373* display)
{
  display->drawRect(0,0, display_width, 18, EPD_BLACK);//bar
  display->drawFastHLine(0,1, display_width, EPD_RED);
  display->drawFastHLine(0,2, display_width, EPD_BLACK);
/*  display->drawRect(282,4,12,12, EPD_BLACK);// X square
    display->drawLine(282+closeXoffset2,4+closeYoffset1, 282+closeXoffset1, 4+closeYoffset2, EPD_BLACK);//diagonal lines    
    display->drawLine(282+closeXoffset2,4+closeYoffset2, 282+closeXoffset1, 4+closeYoffset1, EPD_BLACK);
  display->drawRect(268,4,12,12, EPD_BLACK);// Max square
    display->drawRect(268+2,8, 6, 6, EPD_BLACK); //small left sq
    display->drawRect(268+4,6, 6, 6, EPD_BLACK); // larger right sq
  display->drawRect(254,4,12,12, EPD_BLACK);// min square
    display->drawFastHLine(256,13,8, EPD_BLACK); 
*/
  display->setCursor(70, 7);//mid bar
  display->setTextColor(EPD_BLACK);
  display->print("Lunar Power Monitor V0->1");
  display->drawBitmap(3, 4, T, 12, 12, EPD_RED);
  return;
}

#define terminalYoffset 19
#define textH 10
void drawTerminal(Adafruit_IL0373* display)
{
  display->drawRect(187,terminalYoffset, 296-187, 18, EPD_BLACK);//bar
  display->drawFastHLine(188,terminalYoffset+1,295-188,EPD_RED);//flair
  display->setCursor(200,terminalYoffset+6);
  display->setTextColor(EPD_BLACK);
  display->print("");
  display->drawRect(282,4+terminalYoffset,12,12, EPD_BLACK);// X square
    display->drawLine(282+closeXoffset2,4+closeYoffset1+terminalYoffset, 282+closeXoffset1, 4+closeYoffset2+terminalYoffset, EPD_BLACK);//diagonal lines    
    display->drawLine(282+closeXoffset2,4+closeYoffset2+terminalYoffset, 282+closeXoffset1, 4+closeYoffset1+terminalYoffset, EPD_BLACK);
  display->drawRect(268,4+terminalYoffset,12,12, EPD_BLACK);// Max square
    display->drawRect(268+2,8+terminalYoffset, 6, 6, EPD_BLACK); //small left sq
    display->drawRect(268+4,6+terminalYoffset, 6, 6, EPD_BLACK); // larger right sq
  display->drawRect(254,4+terminalYoffset,12,12, EPD_BLACK);// min square
    display->drawFastHLine(256,13+terminalYoffset,8, EPD_BLACK);
  display->fillRect(187, terminalYoffset+18, 296-187, 128-(terminalYoffset+18)-2,EPD_BLACK);
  display->setCursor(187+2, terminalYoffset+18+2);
  display->setTextColor(EPD_INVERSE);
  display->print("$stat->sh");
  display->setCursor(187+2, terminalYoffset+18+2+textH);
  display->print("Panel Voltage: 0V");
  display->setCursor(187+2, terminalYoffset+18+2+textH*2);
  display->print("Panel Power:   0W");
  display->setCursor(187+2, terminalYoffset+18+2+textH*3);
  display->print("Panel Current: 0A");
  display->setCursor(187+2, terminalYoffset+18+2+textH*4);
  display->print("SOC:        50->0%");
  display->setCursor(187+2, terminalYoffset+18+2+textH*5);
  display->print("$_");
      
  return;
}

//use 0-100
void updateGraphData(int* data, int len, int input)
{
  for(int i = 1; i < len; i++)
  {
    data[i] = data[i-1];// shift everything (oldest results in lowest index)
  }
  data[len-1] = input;
  return;
}
