#include "ReceiveMsgTask.h"
#include <Arduino.h>
extern String stateMsg;

void ReceiveMsgTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "1" && stateMsg == "CONTAINER_FULL") {
            stateMsg = "EMPTYING_PROCESS";
        } else if (msg->getContent() == "0") {
            restorePressed = true;
        } 
        delete msg;
    }
}