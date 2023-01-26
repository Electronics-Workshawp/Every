#include <Every.h>

Every everyFiveSeconds(5, Every::seconds);

void setup() {
  // Initialize any necessary hardware or variables here
}

void loop() {
  everyFiveSeconds.update();
  if (everyFiveSeconds.triggered()) {
    // Do something every 5 seconds
  }
}
