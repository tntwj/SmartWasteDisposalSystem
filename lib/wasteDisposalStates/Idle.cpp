#include "State.h"

State::State() {
    ledController->switchOnGreen();
}

State* State::handle() {
    return nullptr;
}