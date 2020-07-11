#include "arduino.h"
#ifndef READING_H
#define READING_H

#define solarPin 	A0
#define battPin 	A1
#define currPin		A2

#define bx 1
#define cx 1
#define sx 1

#define bb 0
#define cb -.02
#define sb 0


float readSolar();
float readBatt();
float readCurr();

#endif
