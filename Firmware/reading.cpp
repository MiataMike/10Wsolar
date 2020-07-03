#include "reading.h"

float readSolar()
{
	static float solar = -1;
	int tmp = 0;
	tmp = analogRead(solarPin);
	solar = tmp * sscale;
	return solar;
}
float readBatt()
{	
	static float batt = -1;
	int tmp = 0;
	tmp = analogRead(battPin);
	batt = tmp * bscale;
	return batt;
}
float readCurr()
{
	static float curr = -1;
	int tmp = 0;
	tmp = analogRead(currPin);
	curr = tmp * cscale;
	return curr;
}
