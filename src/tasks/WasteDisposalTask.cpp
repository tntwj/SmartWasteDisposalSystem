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
     * To let after restored dangerous temperature state it will return in state before the dangerous state.
     * I choose to let this class to control the switching states between dangerous and normal state.
     */
    if (restorePressed && stateMsg=="DANGEROUS_TEMP") {
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