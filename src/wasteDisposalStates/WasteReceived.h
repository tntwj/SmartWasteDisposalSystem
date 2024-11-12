#ifndef __WASTERECEIVED__
#define __WASTERECEIVED__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"
#include "LiquidCrystal_I2C.h"

extern DoorController* doorController;
extern String stateMsg;
extern LiquidCrystal_I2C* lcd;

class WasteReceived : public State {
    private:
    unsigned long currentTime;
    public:
        WasteReceived();
        void init() override;
        State* handle() override;
};

#endif
