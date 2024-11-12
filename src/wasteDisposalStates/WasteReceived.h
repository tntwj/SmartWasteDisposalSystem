#ifndef __WASTERECEIVED__
#define __WASTERECEIVED__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"

extern DoorController* doorController;
extern String stateMsg;
class WasteReceived : public State {
    private:
    unsigned long currentTime;
    public:
        WasteReceived();
        void init() override;
        State* handle() override;
};

#endif
