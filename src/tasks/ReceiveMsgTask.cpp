#include "ReceiveMsgTask.h"
#include <Arduino.h>

extern String stateMessage;

void ReceiveMsgTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "1") {
            isContainerBeingEmptied = true;
        } else if (msg->getContent() == "0") {
            restorePressed = true;
        } 
        delete msg;
    }
}
