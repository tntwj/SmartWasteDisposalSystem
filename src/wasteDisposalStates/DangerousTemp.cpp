#include "DangerousTemp.h"
#include "tasks/WasteDisposalTask.h"
#include "tasks/MeasureTemperatureTask.h"

DangerousTemp::DangerousTemp() {
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
}

State* DangerousTemp::handle() {
    if (!tempController->isTempHigh()) {
        ledController->switchOffRed();
    }
    return nullptr;
}