#include "DangerousTemp.h"
#include "tasks/WasteDisposalTask.h"
#include "tasks/MeasureTemperatureTask.h"

class DangerousTemp: public State {
    DangerousTemp() {
        ledController->switchOffGreen();
        ledController->switchOnRed();
        doorController->close();
    }

    State* handle() override {
        if (!tempController->isTempHigh()) {
            ledController->switchOffRed();
        }
        return nullptr;
    }
};