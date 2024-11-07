#include <Arduino.h>
#include "Scheduler.h"

Scheduler sched;

void setup() {
  Serial.begin(9600);
  Serial.println("ArduinoUno");
  sched.init(50);
}

void loop() {
  sched.schedule();
}
