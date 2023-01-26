#include <Every.h>

Every everyFiveSeconds(5, Every::seconds);

void firstEvent() {
  // Do something every 5 seconds
}

void secondEvent() {
  // Do something else when the first event is half way between triggers
}

void setup() {
  everyFiveSeconds.setCallback(firstEvent);
  // Initialize any necessary hardware or variables here
}

void loop() {
  everyFiveSeconds.update();
  if (everyFiveSeconds.remaining(Every::milliseconds) <= (everyFiveSeconds.getInterval(Every::milliseconds)/2)) {
    // Trigger the second event when the first event is half way between triggers
    secondEvent();
  }
}
