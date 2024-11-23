#ifndef __EMPTYING_PROCESS__
#define __EMPTYING_PROCESS__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"
#include "controllers/LedController.h"
#include "controllers/LcdController.h"

extern LedController* ledController;
extern DoorController* doorController;
extern LcdController* lcdController;
extern String stateMessage;

class EmptyingProcess : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
