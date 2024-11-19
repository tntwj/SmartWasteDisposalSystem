#ifndef __CONTAINER_FULL__
#define __CONTAINER_FULL__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include "controllers/DoorController.h"
#include <LiquidCrystal_I2C.h>

extern LedController* ledController;
extern DoorController* doorController;
extern String stateMsg;
extern LiquidCrystal_I2C* lcd;

class ContainerFull : public State {
    private:
        unsigned long currentTime;
    public:
        ContainerFull();
        void init() override;
        State* handle() override;
};

#endif
