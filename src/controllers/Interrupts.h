#ifndef __SYSTEM_INTERRUPTS__
#define __SYSTEM_INTERRUPTS__

extern volatile bool openPressed;
extern volatile bool closePressed;

void setupButtons(int openPin, int closePin);

void openButtonISR();

void closeButtonISR();

void sleep();

void wake();

#endif
