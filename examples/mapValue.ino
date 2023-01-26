#include <Every.h>

Every timer(4, "seconds");

void doSomething(){
  Serial.println("test");
}

void setup() {
  Serial.begin(115200);
  timer.setCallback(doSomething);
  // Initialize any necessary hardware or variables here
}

void loop() {
  timer.update();
  int counter = timer.mapValue(255);
  Serial.println(counter);
};
