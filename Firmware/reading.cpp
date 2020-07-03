#include "reading.h"

float readSolar()
{
	static float solar = -1;
	int tmp = 0;
	tmp = analogRead(solarPin);
	solar = tmp * 3.3 / 65536 * 10 * 4.13/5.76; //3.3vref, 16 bit converter with 1/10 divider on front end, calibrated
	return solar;
}
float readBatt()
{	
	static float batt = -1;
	int tmp = 0;
	tmp = analogRead(battPin);
	batt = tmp * 3.3 / 65536 * 10 * 4.6/6.51 ; //3.3vref, 16 bit converter with 1/10 divider on front end, calibrated
	return batt;
}
float readCurr()
{
	static float curr = -1;
	int tmp = 0;
	tmp = analogRead(currPin);
	curr = tmp * 3.3 / 65536; // 1V/A
	return curr;
}
