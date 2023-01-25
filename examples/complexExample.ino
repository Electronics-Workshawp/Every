#include <Every.h>

Every everySecond(1, "seconds");
Every everyFiveSeconds(5, "seconds");
Every everyTenSeconds(10, "seconds");

int ledPin = 13;

void firstEvent() {
  // Blink the LED every second
  digitalWrite(ledPin, !digitalRead(ledPin));
}

void secondEvent() {
  // Print a message every 5 seconds
  Serial.println("This message is printed every 5 seconds");
}

void thirdEvent() {
  // Change the LED blink rate to every 2 seconds
  everySecond.setInterval(2, "seconds");
}

void fourthEvent() {
  // Reset the LED blink rate to every 1 second
  everySecond.setInterval(1, "seconds");
}

void setup() {
  // Initialize the LED pin
  pinMode(ledPin, OUTPUT);
  // Set the callback functions for each event
  everySecond.setCallback(firstEvent);
  everyFiveSeconds.setCallback(secondEvent);
  everyTenSeconds.setCallback(thirdEvent);
  everyTenSeconds.setRepeat(false); // this event will happen once
  everyTenSeconds.setCallback(fourthEvent);
}

void loop() {
  // Update all the timers
  everySecond.update();
  everyFiveSeconds.update();
  everyTenSeconds.update();
}
