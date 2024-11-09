#ifndef __BUTTON_PAD_CONTROLLER__
#define __BUTTON_PAD_CONTROLLER__

#include <ButtonImpl.h>

class ButtonPadController {
    public:
        ButtonPadController(ButtonImpl* openButton, ButtonImpl* closeButton);
        ~ButtonPadController();
        bool isOpenPressed();
        bool isClosePressed();
    private:
        ButtonImpl* openButton;
        ButtonImpl* closeButton;
};

#endif
