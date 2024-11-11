#include <EmptyingProcess.h>
#include <Defines.h>
#include <WasteDisposalTask.h>
#include <Idle.h>

class EmptyingProcess: public State {
    private:
        /**using simplest count version to switch states.
         * @TODO to be optimized
        */
        int count = 0;
        int limit = EMPTYING_PROCESS / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        EmptyingProcess() {
            doorController->openBack();
        }
    State* handle() override{
        count++;
        if (count > limit) {
            doorController->close();
            ledController->switchOffRed();
            count = 0;
            return new Idle();
        }
        return nullptr;
    }
};