#ifndef __CONTAINER_FULL__
#define __CONTAINER_FULL__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include "controllers/DoorController.h"
#include "controllers/LcdController.h"

extern LedController* ledController;
extern DoorController* doorController;
extern LcdController* lcdController;
extern String stateMessage;
extern bool isContainerBeingEmptied;

class ContainerFull : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
