#ifndef __CONTAINERFULL__
#define __CONTAINERFULL__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include "controllers/DoorController.h"

extern LedController* ledController;
extern DoorController* doorController;
extern String stateMsg;

class ContainerFull : public State {
    private:
    unsigned long currentTime;
    public:
        ContainerFull();
        void init() override;
        State* handle() override;
};

#endif
