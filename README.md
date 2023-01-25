# Every - Arduino Timer/Scheduler library

The Every library allows you to create a timer/scheduler for the Arduino platform. It allows you to trigger an action or function after a specific interval of time has passed. This is useful for scheduling tasks or creating timed events in an Arduino sketch.

## Getting Started

- Download the Every library from GitHub by clicking on the "Clone or Download" button and then selecting "Download ZIP".
- In the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library, and select the downloaded ZIP file.
- Include the library in your sketch by adding `#include <Every.h>` at the top of your sketch.
- You can now create an object of the Every class, set the interval, units, repeat, callback function, etc.
- Call the `update()` method in the `loop()` function of your sketch to check if the interval has passed.


## API Reference

The library has several methods that can be used to control the timer, here is a brief description of each method:
- `Every(unsigned long interval, char* unit)`: Constructor method to create an object of the `Every` class. It takes in an interval and a unit of time (microseconds, milliseconds, seconds, or minutes) and initializes the timer.
- `update()`: Method that should be called in the `loop()` function of the sketch to check if the interval has passed and trigger the action if necessary.
- `trigger()`: Method that should be called to check if the action should be triggered. It returns true if the interval has passed and the action should be triggered, and false otherwise.
- `pause()`:  Stops the timer from running and prevents the `update()` method from triggering the action.
- `resume()`: Starts the timer again and allows the `update()` method to trigger the action.
- `remaining()`: returns the amount of time remaining until the next trigger.
