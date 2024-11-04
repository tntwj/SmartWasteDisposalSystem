#include "Button.h"
#include "Arduino.h"

// Could add debounce and pullup input

Button::Button(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
    return digitalRead(pin);
}
