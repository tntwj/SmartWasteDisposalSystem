#include "ContainerFull.h"
#include "tasks/WasteDisposalTask.h"
#include "SleepState.h"

ContainerFull::ContainerFull() {
}

void ContainerFull::init() {
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
}

State* ContainerFull::handle() {
    count++;
    if (count > limit) {
        count = 0;
        return new SleepState();
    }
    return nullptr;
}