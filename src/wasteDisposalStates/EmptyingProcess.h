#ifndef __EMPTYINGPROCESS__
#define __EMPTYINGPROCESS__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"
#include "controllers/LedController.h"

extern LedController* ledController;
extern DoorController* doorController;
extern String stateMsg;

class EmptyingProcess : public State {
    private:
    unsigned long currentTime;
    public:
        EmptyingProcess();
        void init() override;
        State* handle() override;
};

#endif
