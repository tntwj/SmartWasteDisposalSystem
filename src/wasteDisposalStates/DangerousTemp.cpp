#include "DangerousTemp.h"

DangerousTemp::DangerousTemp() {
}

void DangerousTemp::init() {
    stateMsg="DANGEROUS_TEMP";
    Serial.println("Dangerous temp");
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