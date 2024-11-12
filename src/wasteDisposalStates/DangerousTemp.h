#ifndef __DANGEROUSTEMP__
#define __DANGEROUSTEMP__

#include "State.h"
#include "controllers/LedController.h"
#include "controllers/DoorController.h"
#include "controllers/TemperatureController.h"
#include "LiquidCrystal_I2C.h"

extern LedController* ledController;
extern DoorController* doorController;
extern TemperatureController* tempController;
extern String stateMsg;
extern LiquidCrystal_I2C* lcd;

class DangerousTemp: public State {
    public:
        DangerousTemp();
        void init() override;
        State* handle() override;
};

#endif