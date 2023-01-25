Every everyFiveSeconds(5, "seconds");

void setup() {
}

void loop() {
  everyFiveSeconds.update();
  if (everyFiveSeconds.triggered()) {
    Serial.println("Every 5 seconds");
  }
  if(Serial.available()){
    char command = Serial.read();
    if(command == 'p') everyFiveSeconds.pause();
    if(command == 'r') everyFiveSeconds.resume();
  }
}
