#ifndef __WASTEDISPOSALTASK__
#define __WASTEDISPOSALTASK__

#include <Task.h>
#include <State.h>
#include <MeasureTemperatureTask.h>
#include <TemperatureController.h>
#include <MotionDetector.h>
#include <DoorController.h>
#include <LedController.h>
#include <ButtonPadController.h>

/**controllers as global because every state should use controllers to act/verify events */
extern ButtonPadController* buttonPadController;
extern MotionDetector* motionDetector;
extern DoorController* doorController;
extern LedController* ledController;

class WasteDisposalTask: public Task{
    private:
        State* currentState;

    public:
        /*every time this method has been called, the current state should update,
        it could remains in the same state (it depends on what state returned by state.handle()). */
        void tick();
};

#endif
