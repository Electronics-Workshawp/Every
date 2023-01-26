#include <Every.h>

Every timer(5, Every::seconds);



void setup() {
  Serial.begin(115200);
  
}

void loop() {
  timer.update();
  
int remaining = timer.remaining(Every::milliseconds);
Serial.println(remaining);  

 if(Serial.available()){
    char command = Serial.read();
    if(command == 'p') timer.pauseTask();
    if(command == 'r') timer.resumeTask();
  }

};



