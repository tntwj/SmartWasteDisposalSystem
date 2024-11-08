#ifndef __BUTTON_PAD_CONTROLLER__
#define __BUTTON_PAD_CONTROLLER__

#include "Button.h"

class ButtonPadController {
    public:
        ButtonPadController(Button* openButton, Button* closeButton);
        ~ButtonPadController();
        bool isOpenPressed();
        bool isClosePressed();
    private:
        Button* openButton;
        Button* closeButton;
};

#endif
