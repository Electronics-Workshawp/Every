#include <Every.h>

Every everyFiveSeconds(5, Every::seconds);

void setup() {
 Serial.begin(115200)
}

void loop() {
  everyFiveSeconds.update();
  if (everyFiveSeconds.trigger()) {
    Serial.println("EVERY 5 SECONDS!!");
  }
}
