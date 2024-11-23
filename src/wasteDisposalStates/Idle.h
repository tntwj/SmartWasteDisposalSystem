#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include "controllers/LcdController.h"
#include "controllers/MotionDetector.h"

extern LedController* ledController;
extern MotionDetector* motionDetector;
extern LcdController* lcdController;
extern String stateMessage;
extern volatile bool openPressed;

class Idle : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
