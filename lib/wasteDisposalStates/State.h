#ifndef __STATE__
#define __STATE__
#include "ButtonPadController.h"
#include "MotionDetector.h"
#include "DoorController.h"
#include "LedController.h"
#include "Defines.h"

class State{
    public:
        State();
        /**
         * every state should do his own job.
         * @return a new state which could be another state or nullptr if its the same state.
         */
        virtual State* handle();

    protected:
        ButtonPadController* buttonPadController = new ButtonPadController();
        MotionDetector* motionDetector = new MotionDetector();
        DoorController* doorController = new DoorController();
        LedController* ledController = new LedController(new Led(RED_LED_PIN), new Led(GREEN_LED_PIN));
};

#endif