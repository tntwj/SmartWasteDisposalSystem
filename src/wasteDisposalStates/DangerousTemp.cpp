#include "DangerousTemp.h"

void DangerousTemp::execute() {
    stateMessage = "DANGEROUS_TEMP";
    ledController->switchOffGreen();
    ledController->switchOnRed();
    doorController->close();
    lcdController->printDangerousTempMessage();
}

State* DangerousTemp::next() {
    if (!tempController->isTempHigh()) {
        ledController->switchOffRed();
    }
    return nullptr;
}
