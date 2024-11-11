#include <ContainerFull.h>
#include <WasteDisposalTask.h>
#include <SleepState.h>
#include <Defines.h>

class ContainerFull: public State {
    private:
    /**using simplest count version to switch states.
     * @TODO to be optimized
    */
    int count = 0;
    int limit = WASTE_RECEIVED_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        ContainerFull() {
            ledController->switchOffGreen();
            ledController->switchOnRed();
            doorController->close();
        }
    State* handle() override{
        count++;
        if (count > limit) {
            count = 0;
            return new SleepState();
        }
        return nullptr;
    }

};