#include "EmptyingProcess.h"
#include "headers/Defines.h"
#include "tasks/WasteDisposalTask.h"
#include "Idle.h"

EmptyingProcess::EmptyingProcess() {
        doorController->openBack();
    }
State* EmptyingProcess::handle() {
    count++;
    if (count > limit) {
        doorController->close();
        ledController->switchOffRed();
        count = 0;
        return new Idle();
    }
    return nullptr;
}
