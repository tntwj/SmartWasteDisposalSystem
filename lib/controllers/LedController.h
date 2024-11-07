#ifndef __LED_CONTROLLER__
#define __LED_CONTROLLER__

#include "Led.h"

class LedController {

    public:
        LedController();
        void attachGreenLed(Led* led);
        void attachRedLed(Led* led);
        void detachAll();
        void switchOnRed();
        void switchOffRed();
        void switchOnGreen();
        void switchOffGreen();
        bool isRedOn();
        bool isGreenOn();
    private:
        Led* greenLed;
        Led* redLed;
};

#endif
