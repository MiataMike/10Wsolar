#include "control.h"
#include "arduino.h"
//for now just lock on the top mosfet and let current roll through like a direct connection
int initControl()
{
	digitalWrite(HighsidePin, HIGH);
	return 0;
}

#define Vcutoff 14.4
void updateControl(float Vbus)
{
	if (Vbus < Vcutoff)
	{
		digitalWrite(HighsidePin, HIGH); //allow charging
	}
	else
	{
		digitalWrite(HighsidePin, LOW);// turn off in all other cases
	}
	return;
}
