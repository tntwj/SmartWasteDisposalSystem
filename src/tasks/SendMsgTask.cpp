#include "SendMsgTask.h"

/**
 * The agreed format for sending info to the Dashboard is the following: STATE:x|TEMP:y|LEVEL:z
 */
void SendMsgTask::tick() {
    MsgService.sendMsg(
        "STATE:" + String(stateMsg) 
        + "|TEMP:" + String(tempController->getTemp()) 
        + "|LEVEL:" + String(wasteDetector->getLevel()));
}
