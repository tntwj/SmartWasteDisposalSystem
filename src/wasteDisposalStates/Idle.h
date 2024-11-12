#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include <LiquidCrystal_I2C.h>
#include "controllers/MotionDetector.h"

extern LedController* ledController;
extern MotionDetector* motionDetector;
extern String stateMsg;
extern LiquidCrystal_I2C* lcd;

class Idle : public State {
    private:
    unsigned long currentTime;
    public:
        Idle();
        void init() override;
        State* handle() override;
};

#endif
