#include "WasteDisposalTask.h"

void WasteDisposalTask::tick() {
    State* nextState = currentState->handle();
    delete currentState;
    currentState = nextState;
}