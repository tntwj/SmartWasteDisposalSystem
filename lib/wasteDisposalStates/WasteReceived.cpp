#include "WasteReceived.h"
#include <Defines.h>
#include <WasteDisposalTask.h>
#include "Idle.h"

class WasteReceived: public State {
    private:
    /**using simplest count version to switch states.
     * @TODO to be optimized
    */
    int count = 0;
    int limit = WASTE_RECEIVED_PERIOD / WASTE_DISPOSAL_TASK_PERIOD;
    public:
        WasteReceived() {
            doorController->close();
        }
    State* handle() override {
        count++;
        if (count > limit) {
            count = 0;
            return new Idle();
        }
        return nullptr;
    }
};