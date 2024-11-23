#ifndef __WASTE_RECEIVED__
#define __WASTE_RECEIVED__

#include "headers/Defines.h"
#include "State.h"
#include "controllers/DoorController.h"
#include "controllers/LcdController.h"

extern DoorController* doorController;
extern LcdController* lcdController;
extern String stateMessage;

class WasteReceived : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
