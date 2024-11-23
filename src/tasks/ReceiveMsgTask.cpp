#include "ReceiveMsgTask.h"
#include <Arduino.h>

extern String state;

void ReceiveMsgTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "1" && state == "CONTAINER_FULL") {
            state = "EMPTYING_PROCESS";
        } else if (msg->getContent() == "0") {
            restorePressed = true;
        } 
        delete msg;
    }
}
