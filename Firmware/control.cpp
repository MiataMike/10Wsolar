#include "control.h"
#include "arduino.h"

int initControl()
{
  pinMode(HighsidePin, OUTPUT);
  //analogWriteFrequency(HighsidePin, 375000);
	//analogWrite(HighsidePin, 32);
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
