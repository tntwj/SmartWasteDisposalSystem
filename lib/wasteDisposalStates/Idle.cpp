#include "Idle.h"
#include "EnteringWaste.h"
#include "SleepState.h"
#include <Defines.h>
#include <WasteDisposalTask.h>

class Idle: public State {
    private:
        /**using simplest count version to switch states.
         * @TODO to be optimized
        */
        int count = 0;
        int limit = AWAKE_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        Idle() {
            ledController->switchOnGreen();
        }

    State* handle() override{
        if (buttonPadController->isOpenPressed()) {
            return new EnteringWaste();
        }
        count++;
        if (count > limit) {
            count = 0;
            return new SleepState();
        }
        return nullptr;
    }
};
