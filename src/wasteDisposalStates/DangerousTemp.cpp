#include "DangerousTemp.h"

void DangerousTemp::execute() {
    state = "DANGEROUS_TEMP";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("PROBLEM DETECTED");
}

State* DangerousTemp::next() {
    if (!tempController->isTempHigh()) {
        ledController->switchOffRed();
    }
    return nullptr;
}
