#include "Every.h"

int seconds = 0;
int minutes = 0;
int hours = 0;

Every oneSecond(1, Every::seconds);
Every oneMinute(1, Every::minutes);
Every oneHour(1, Every::hours);

void updateSeconds() { seconds+=1; }
void updateMinutes() { minutes+=1; }
void updateHours() { hours+=1; }


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  oneSecond.setCallback(updateSeconds);
  oneMinute.setCallback(updateMinutes);
  oneHour.setCallback(updateHours);
}

void loop() {
  oneSecond.update();
  oneMinute.update();
  oneHour.update();
  String timerString = (String)seconds + ":" + (String)minutes + ":" + (String)hours;

  if (seconds >= 60){seconds = 0;}if (minutes >= 60){minutes = 0;};
 
  Serial.println(timerString);
}
