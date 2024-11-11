#include "WasteReceived.h"
#include "headers/Defines.h"
#include "tasks/WasteDisposalTask.h"
#include "Idle.h"

WasteReceived::WasteReceived() {
}

void WasteReceived::init() {
    doorController->close();
}

State* WasteReceived::handle() {
    count++;
    if (count > limit) {
        count = 0;
        return new Idle();
    }
    return nullptr;
}
