#ifndef __DANGEROUS_TEMP__
#define __DANGEROUS_TEMP__

#include "State.h"
#include "controllers/LedController.h"
#include "controllers/DoorController.h"
#include "controllers/TemperatureController.h"
#include "controllers/LcdController.h"

extern LedController* ledController;
extern DoorController* doorController;
extern TemperatureController* tempController;
extern LcdController* lcdController;
extern String stateMessage;

class DangerousTemp: public State {
    public:
        void execute() override;
        State* next() override;
};

#endif
