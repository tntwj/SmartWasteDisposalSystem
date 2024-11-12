#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"



extern LedController* ledController;
extern bool movementDetected;

class Idle : public State {
    private:
    unsigned long currentTime;
    public:
        Idle();
        void init() override;
        State* handle() override;
};

#endif
