#ifndef __WASTE_RECEIVED__
#define __WASTE_RECEIVED__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"
#include <LiquidCrystal_I2C.h>

extern DoorController* doorController;
extern String state;
extern LiquidCrystal_I2C* lcd;

class WasteReceived : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
