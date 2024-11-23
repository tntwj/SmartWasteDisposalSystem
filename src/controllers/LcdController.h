#ifndef __LCD_CONTROLLER__
#define __LCD_CONTROLLER__

#include "LiquidCrystal_I2C.h"

class LcdController {
    private:
        LiquidCrystal_I2C* lcd;
    public:
        LcdController(LiquidCrystal_I2C* lcd);
        LiquidCrystal_I2C* getLcd();
        void turnOff();
        void turnOn();
        void printWasteReceivedMessage();
        void printIdleMessage();
        void printEnteringWasteMessage();
        void printEmptyingMessage();
        void printDangerousTempMessage();
        void printContainerFullMessage();
};

#endif
