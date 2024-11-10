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

/**
 * PUT THEM AS EXTERN AND DECLARE THEM IN MAIN"!!!!
 */
/**controllers as global because every state should use controllers to act/verify events */
ButtonPadController* buttonPadController = new ButtonPadController(new ButtonImpl(OPEN_BUTTON_PIN), new ButtonImpl(CLOSE_BUTTON_PIN));
MotionDetector* motionDetector = new MotionDetector(new PirSensor(PIR_SENSOR_PIN));
DoorController* doorController = new DoorController(new Servo());
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
