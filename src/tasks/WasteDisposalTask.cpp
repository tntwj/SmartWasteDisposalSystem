#include "WasteDisposalTask.h"
#include "wasteDisposalStates/DangerousTemp.h"

WasteDisposalTask::WasteDisposalTask() {
    this->currentState = new Idle();
    this->stateBeforeHighTemp = nullptr;
    this->isInDangerousTempState = false;
    this->currentState->init();
}

void WasteDisposalTask::tick() {
    State* nextState = nullptr;
    bool isCurrentTempHigh = tempController->isTempHigh();
    nextState = this->currentState->handle();
    if (nextState != nullptr && !isCurrentTempHigh && !this->isInDangerousTempState) {
        delete this->currentState;
        this->currentState = nextState;
        this->currentState->init();
    }
    /** 
     * This task controls the switching between dangerous temp and normal state too.
     * An operator may push the restore button, meaning that the high temp issue has supposedly been fixed.
     * If the operator did not actually fix the issue the system will go into a dangerous temp state again.
     */
    if (isCurrentTempHigh && !this->isInDangerousTempState) {
        this->isInDangerousTempState = true;
        this->stateBeforeHighTemp = this->currentState;
        this->currentState = new DangerousTemp();
        this->currentState->init();
    } else if (restorePressed && this->isInDangerousTempState) {
        restorePressed = false;
        this->isInDangerousTempState = false;
        delete currentState;
        this->currentState = this->stateBeforeHighTemp;
        this->currentState->init();
    }
}
