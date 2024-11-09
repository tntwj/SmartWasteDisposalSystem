#ifndef __WASTEDISPOSALTASK__
#define __WASTEDISPOSALTASK__

#include "Task.h"
#include "State.h"
#include "ButtonPadController.h"
#include "MotionDetector.h"
#include "DoorController.h"
#include "LedController.h"
#include "Defines.h"
#include <Pins.h>

/**controllers as global because every state should use controllers to act/verify events */
ButtonPadController* buttonPadController = new ButtonPadController();
MotionDetector* motionDetector = new MotionDetector();
DoorController* doorController = new DoorController();
LedController* ledController = new LedController(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));

class WasteDisposalTask: public Task{
    private:
        State* currentState;

    public:
        /*every time this method has been called, the current state should update,
        it could remains in the same state (it depends on what state returned by state.handle()). */
        void tick();

};

#endif
