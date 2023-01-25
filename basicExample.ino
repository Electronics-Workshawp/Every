 #include <Every.h>


Every timer(1000,"milliseconds");
Every timer2(2,"seconds");


void setup() {
Serial.begin(115200)

}

void loop() {
timer.update();
timer2.update();
 
if (timer.trigger()) {  Serial.print("this will happen every 1000 milliseconds!")   }
if (timer2.trigger()) {  Serial.print("this will happen every 2 seconds!")   }
  
}

