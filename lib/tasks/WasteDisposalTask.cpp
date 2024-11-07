#include "WasteDisposalTask.h"

void WasteDisposalTask::tick() {
    State* nextState = currentState->handle();
    if (nextState != nullptr) {
        delete currentState;
        currentState = nextState;
    }
}