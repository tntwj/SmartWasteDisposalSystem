#include "DangerousTemp.h"

void DangerousTemp::init() {
    stateMsg = "DANGEROUS_TEMP";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("PROBLEM DETECTED");
}

State* DangerousTemp::handle() {
    if (!tempController->isTempHigh()) {
        ledController->switchOffRed();
    }
    return nullptr;
}
