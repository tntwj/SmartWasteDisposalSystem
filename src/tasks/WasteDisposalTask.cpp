#include "WasteDisposalTask.h"
#include "wasteDisposalStates/DangerousTemp.h"


void WasteDisposalTask::tick() {
    State* nextState = nullptr;
    bool isCurrentTempHigh = tempController->isTempHigh();
    nextState = currentState->handle();
    if (nextState != nullptr) {
        delete currentState;
        currentState = nextState;
        currentState->init();
    }
    if (isCurrentTempHigh) {
        isPrevTempHigh = isCurrentTempHigh;
        stateBeforeHighTemp = currentState;
        currentState = new DangerousTemp();
    }
    /**
     * se avviene lo switch dalla temperatura alta alla temperatura bassa, stateBeforeHighTemp 
     * serve nel caso in cui la temperatura tornasse normale venga tornato allo stato prima della high temperature.
    */
    if (isPrevTempHigh && !isCurrentTempHigh) {
        delete currentState;
        currentState = stateBeforeHighTemp;
        currentState->init();
        isPrevTempHigh = false;
    } else if (!isPrevTempHigh && isCurrentTempHigh) {
        currentState->init();
    }
}