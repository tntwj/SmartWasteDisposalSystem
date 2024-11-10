#include "WasteDisposalTask.h"
#include "DangerousTemp.h"

//problema: alla fine della temperatura alta, per tornare allo stato precedente, bisogna fare di nuovo entry 
void WasteDisposalTask::tick() {
    State* nextState = nullptr;
    State* dangerousTempState = nullptr;
    bool isTempNormal = tempController->isTempHigh();

    if (isTempNormal) {
        if (dangerousTempState != nullptr) {
            delete dangerousTempState;
        }
        nextState = currentState->handle();
        if (nextState != nullptr) {
            delete currentState;
            currentState = nextState;
        }
    } else {
        dangerousTempState = new DangerousTemp();
        dangerousTempState->handle();
    }
}