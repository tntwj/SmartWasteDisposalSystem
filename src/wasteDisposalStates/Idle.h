#ifndef __IDLE__
#define __IDLE__

#include "State.h"
#include "headers/Defines.h"
#include "controllers/LedController.h"
#include <LiquidCrystal_I2C.h>
#include "controllers/MotionDetector.h"

extern LedController* ledController;
extern MotionDetector* motionDetector;
extern String state;
extern LiquidCrystal_I2C* lcd;
extern volatile bool openPressed;

class Idle : public State {
    private:
        unsigned long startTime;
    public:
        void execute() override;
        State* next() override;
};

#endif
