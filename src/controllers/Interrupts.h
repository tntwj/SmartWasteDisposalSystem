#ifndef __SYSTEM_INTERRUPTS__
#define __SYSTEM_INTERRUPTS__

extern bool openPressed;
extern bool closePressed;

void setupButtons(int openPin, int closePin);

void setupMotionSensor(int pirPin);

void openButtonISR();

void closeButtonISR();

void pirISR();

#endif
