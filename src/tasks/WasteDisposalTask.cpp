#include "WasteDisposalTask.h"
#include "wasteDisposalStates/DangerousTemp.h"

WasteDisposalTask::WasteDisposalTask() {
    currentState->init();
}

void WasteDisposalTask::tick() {
    State* nextState = nullptr;
    bool isCurrentTempHigh = tempController->isTempHigh();
    nextState = currentState->handle();
    if (nextState != nullptr && !isCurrentTempHigh) {
        delete currentState;
        currentState = nextState;
        currentState->init();
    }
    /** 
     * We also decided to let this task control the switching between dangerous temp and normal state.
     * It has to be said that an operator might push the restore button, meaning that the high temp issue
     * has supposedly been fixed. In that case the system upon restore will go to into a dangerous temp state again
     * if the problem was not actually fixed.
     */
    if (restorePressed && stateMsg == "DANGEROUS_TEMP") {
        restorePressed = false;
        delete currentState;
        currentState = stateBeforeHighTemp;
        currentState->init();
        isPrevTempHigh = false;
    } else if (!isPrevTempHigh && isCurrentTempHigh) {
        isPrevTempHigh = isCurrentTempHigh;
        stateBeforeHighTemp = currentState;
        currentState = new DangerousTemp();
        currentState->init();
    }
}
