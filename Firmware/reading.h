#include "arduino.h"
#ifndef READING_H
#define READING_H

#define solarPin 	A0
#define battPin 	A1
#define currPin		A2

#define sscale 1
#define bscale 1
#define cscale 1

float readSolar();
float readBatt();
float readCurr();

#endif
