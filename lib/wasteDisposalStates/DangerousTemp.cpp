#include <DangerousTemp.h>
#include <WasteDisposalTask.h>
#include <MeasureTemperatureTask.h>

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