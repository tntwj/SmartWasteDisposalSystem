#include "ReceiveMsgTask.h"
extern String stateMsg;

void ReceiveMsgTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "1" && stateMsg == "CONTAINERFULL") {
            stateMsg = "EMPTYINGPROCESS";
        } else if (msg->getContent() == "0") {
            stateMsg = "RESTORE";
        } 
        delete msg;
    }
}