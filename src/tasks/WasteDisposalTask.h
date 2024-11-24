#ifndef __WASTEDISPOSALTASK__
#define __WASTEDISPOSALTASK__

#include "Task.h"
#include "wasteDisposalStates/State.h"
#include "controllers/TemperatureController.h"
#include "controllers/MotionDetector.h"
#include "controllers/DoorController.h"
#include "controllers/LedController.h"
#include "wasteDisposalStates/Idle.h"

/**controllers as global because every state should use controllers to act/verify events */
extern MotionDetector* motionDetector;
extern DoorController* doorController;
extern LedController* ledController;
extern TemperatureController* tempController;
extern String stateMsg;
extern bool restorePressed;

class WasteDisposalTask: public Task {
    private:
        State* currentState = new Idle();
        State* stateBeforeHighTemp = nullptr;
        bool isPrevTempHigh = tempController->isTempHigh();

    public:
        WasteDisposalTask();
        /*every time this method has been called, the current state should update,
        it could remains in the same state (it depends on what state returned by state.handle()). */
        void tick();
};

#endif
