#ifndef CONTROL_H
#define CONTROL_H

#define HighsidePin 23
#define LowsidePin 22

int initControl();
void updateControl(float Vbus);
int highPower(float Vbus, float Abatt, int duty);
int dutyDown(int duty);
int dutyUp(int duty);
#endif
