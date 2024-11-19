#include "SendMsgTask.h"

/**
 * The agreed protocol for sending information to the Dashboard was sending messages in this format: STATE:x|TEMP:y|LEVEL:z
 */
void SendMsgTask::tick() {
    if (!MsgService.isMsgAvailable()) {
        MsgService.sendMsg(
            "STATE:" + String(stateMsg) 
            + "|TEMP:" + String(tempController->getTemp()) 
            + "|LEVEL:" + String(wasteDetector->getLevel())
        );
    }
}
