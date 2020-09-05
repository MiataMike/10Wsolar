#include "control.h"
#include "arduino.h"

int initControl()
{
  pinMode(HighsidePin, OUTPUT);
  analogWriteResolution(6);
  analogWriteFrequency(HighsidePin, 1500000);
	analogWrite(HighsidePin, 0);
	//digitalWrite(HighsidePin, HIGH);
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

int highPower(float Vbus, float Abatt, int duty)
{
  static float lastPow = 0; // filter this?
  static bool upLast = false; // hillclimbing state
  if(Abatt < .02){return dutyUp(duty);} // keep it from getting stuck
  else if(Vbus > 13.7){return dutyDown(duty);}// don't overcharge
  else if(lastPow > Vbus*Abatt)//if it got worse
  {
    if(upLast){duty = dutyDown(duty);}//and it was going up, go down
    else{duty = dutyUp(duty);}        //if it was going down, go up
    upLast = !upLast;             //change direction
  }
  else                            //if it got better
  {
    if(upLast){duty = dutyUp(duty);}  //keep going up
    else{duty = dutyDown(duty);}      //GJ 
  }
  lastPow = Vbus*Abatt;
  return duty;
}


//Bounds checking I didn't want to include in the function
#define dutyMin 0 //so it doesnt get lost
int dutyDown(int duty)
{
  if (duty <= dutyMin)
  {
    duty = dutyMin;
  }
  else{duty--;}
  return duty;
}

#define dutyMax 64
int dutyUp(int duty)
{
  if (duty >= dutyMax)
  {
    duty = dutyMax;
  }
  else{duty++;}
  return duty;
}
