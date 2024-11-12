#include "WasteDisposalTask.h"
#include "wasteDisposalStates/DangerousTemp.h"

WasteDisposalTask::WasteDisposalTask() {
    currentState->init();
}

void WasteDisposalTask::tick() {
    State* nextState = nullptr;
    bool isCurrentTempHigh = tempController->isTempHigh();
    nextState = currentState->handle();
    if (nextState != nullptr) {
        delete currentState;
        currentState = nextState;
        currentState->init();
    }
    /**
     * se avviene lo switch dalla temperatura alta alla temperatura bassa, stateBeforeHighTemp 
     * serve nel caso in cui la temperatura tornasse normale oppure operatore clicca bottone "restore" 
     * lo stato venga tornato allo stato prima della high temperature.
     * else if avviene quando c'è lo switch da uno stato qualsiasi alla temperatura alta.
    */
    if ((isPrevTempHigh && !isCurrentTempHigh) || (isCurrentTempHigh && stateMsg == "RESTORE")) {
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