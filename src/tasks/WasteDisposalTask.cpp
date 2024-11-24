#include "WasteDisposalTask.h"
#include "wasteDisposalStates/DangerousTemp.h"
#include "wasteDisposalStates/Idle.h"

WasteDisposalTask::WasteDisposalTask() {
    this->currentState = new Idle();
    this->stateBeforeHighTemp = nullptr;
    this->isInDangerousTempState = false;
    this->currentState->execute();
}

WasteDisposalTask::~WasteDisposalTask() {
    delete this->currentState;
    delete this->stateBeforeHighTemp;
}

void WasteDisposalTask::tick() {
    /** 
     * This task controls the switching between dangerous temp and normal state too.
     */
    State* nextState = nullptr;
    bool isCurrentTempHigh = tempController->isTempHigh();
    nextState = this->currentState->next();
    if (nextState != nullptr && !isCurrentTempHigh && !this->isInDangerousTempState) {
        delete this->currentState;
        this->currentState = nextState;
        this->currentState->execute();
    } else if (isCurrentTempHigh && !this->isInDangerousTempState) {
        this->isInDangerousTempState = true;
        this->stateBeforeHighTemp = this->currentState;
        this->currentState = new DangerousTemp();
        this->currentState->execute();
    } else if (restorePressed && this->isInDangerousTempState) {
        this->isInDangerousTempState = false;
        delete currentState;
        this->currentState = this->stateBeforeHighTemp;
        this->stateBeforeHighTemp = nullptr;
    }
    restorePressed = false;
}
