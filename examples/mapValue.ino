#include <Every.h>

Every timer(4, Every::seconds);

void setup() {
  Serial.begin(115200);
}

void loop() {
  timer.update();
  int counter = timer.mapValue(255);
  Serial.println(counter);
};
