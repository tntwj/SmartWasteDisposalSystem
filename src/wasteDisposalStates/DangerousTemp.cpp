#include "DangerousTemp.h"

DangerousTemp::DangerousTemp() {
}

void DangerousTemp::init() {
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