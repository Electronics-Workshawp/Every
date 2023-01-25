#include <Every.h>

Every everyFiveSeconds(5, "seconds");

void doSomething(){
    // Do something every 5 seconds
}

void setup() {
  everyFiveSeconds.setCallback(doSomething);
  // Initialize any necessary hardware or variables here
}

void loop() {
  everyFiveSeconds.update();
}
