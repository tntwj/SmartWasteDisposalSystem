#ifndef __SLEEP_STATE__
#define __SLEEP_STATE__

#include "State.h"
#include "controllers/LcdController.h"

extern LcdController* lcdController;
extern String stateMessage;

enum PreviousState {IDLE, CONTAINER_FULL};

class SleepState: public State {
    private:
        PreviousState prevState;
    public:
        SleepState(PreviousState);
        void execute() override;
        State* next() override;
};

#endif
