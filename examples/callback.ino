#include "Every.h"

Every timer(3000, Every::milliseconds);

void myCallback() {
  Serial.println("CALLBACK TRIGGERED!!");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  timer.setCallback(myCallback);
}

void loop() {
  timer.update();
}
