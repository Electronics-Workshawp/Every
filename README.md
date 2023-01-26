# Every - Arduino Timer/Scheduler library

The Every library allows you to create a timer/scheduler for the Arduino platform. It allows you to trigger an action or function after a specific interval of time has passed. This is useful for scheduling tasks or creating timed events in an Arduino sketch.

## Features
- Ability to set the interval in milliseconds, seconds, minutes, or hours.
- Ability to pause and resume the task.
- Ability to set the task to repeat or run only once.
- Ability to check if the task is ready to be run.
- Ability to check the remaining time before the task runs.
- Ability to check the percentage of time passed since the last run.
- Ability to map a value based on the time passed since the last run.
- Ability to set a callback function to be called when the task is run.

## Getting Started

- Download the Every library from GitHub by clicking on the "Clone or Download" button and then selecting "Download ZIP".
- In the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library, and select the downloaded ZIP file.
- Include the library in your sketch by adding `#include <Every.h>` at the top of your sketch.
- You can now create an object of the Every class, set the interval, units, repeat, callback function, etc.
- Call the `update()` method in the `loop()` function of your sketch to check if the interval has passed.


## API Reference

- Every() constructor sets the time interval for the class and the unit of time (milliseconds, seconds, minutes, or hours) to use for the interval.
- trigger() returns true if the interval has been reached and the trigger has been activated.
- ready() returns true if the interval has been reached and ready has been activated.
- update() updates the internal state of the class to check if the interval has been reached and triggers the trigger or ready.
- pauseTask() pauses the task from updating.
- resumeTask() resumes the task from updating.
- remaining() returns the remaining time until the interval is reached in the specified unit of time.
- setInterval() sets the new time interval for the class and the unit of time to use for the interval.
- getInterval() returns the current time interval in the specified unit of time.
- percent() returns the percentage of the time interval that has passed.
- mapValue() maps a value between a source and a target based on the percentage of the time interval that has passed.
- setRepeat() sets whether the class should repeat the interval after it's been reached or not.
- setCallback() sets a callback function to be called when the interval has been reached.


