#ifndef __SYSTEM_INTERRUPTS__
#define __SYSTEM_INTERRUPTS__

extern bool openPressed;
extern bool closePressed;

void setupButtons(int openPin, int closePin);

void openButtonISR();

void closeButtonISR();

void sleep();

void wake();

#endif
