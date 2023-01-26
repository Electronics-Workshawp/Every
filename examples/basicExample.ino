#include <Every.h>

Every timer(1, Every::seconds);



void setup() {
 Serial.begin(115200);

}

void loop() {
  timer.update();
 if (timer.ready()){Serial.println("test");}
  
}
