	#include "Arduino.h"
	#include "Every.h"
	
	

	Every::Every(uint32_t  interval, Unit unit) {
	  _interval = interval;
	  _previousTime = millis();
	  _paused = false;
	  _repeat = true;
	  _callback = NULL;
	  if (unit == milliseconds) {_interval *= 1;}
	  else if (unit == seconds) {_interval *= 1000;}
	  else if (unit == minutes) {_interval *= 1000*60;}
	}



	bool Every::trigger() {
	  if (_triggered) {
		_triggered = false;
		if(!_repeat) _paused = true;
		if(_callback != NULL) _callback();
		return true;
	  }
	  return false;
	}

	void Every::update() {
	  if(_paused) return;
	  unsigned long currentTime = millis();
	  if (currentTime - _previousTime >= _interval) {
		_previousTime = currentTime;
		_triggered = true;
		if(_callback != NULL) _callback();
	  }
	  else if(currentTime < _previousTime) {
		_previousTime = currentTime;
	  }
	  if(_triggered && !_repeat){
		_paused = true;
	  }
	  _triggered = false;
	}


	uint32_t  Every::remaining(Unit unit) {
	  uint32_t  currentTime = millis();
	  if(_paused) return 0;
	  if (_previousTime > currentTime) {
		return 0;
	  } else if (_previousTime + _interval > currentTime) {
		uint32_t  remainingTime = _previousTime + _interval - currentTime;

		if (unit == milliseconds) {return remainingTime / 1;}
		else if (unit == seconds) {return remainingTime / 1000;}
		else if (unit == minutes) {return remainingTime / (1000 * 60);}
	  } 
	  else {
		return 0;
	  }
	}



	void Every::setInterval(float interval,Unit unit) {
	  _interval = interval;
	  
	  if (unit == milliseconds){_interval *= 1;}
	  else if (unit == seconds) {_interval *= 1000;}
	  else if (unit == minutes) {_interval *= 1000*60;}
	}


	uint32_t   Every::getInterval(Unit unit) {
	  uint32_t  interval = _interval;

	  if (unit == milliseconds){return interval /= 1;}
	  else if (unit == seconds){return interval /= 1000;}
	  else if (unit == minutes){return interval /= 1000*60;}
	  else{
		return 0;
	  }
	}


	uint32_t  Every::percent() {
	  uint32_t  currentTime = millis();
	  if(_paused) return 0;
	  if (_previousTime > currentTime) {
		return 0;
	  }
	  else if (_previousTime + _interval > currentTime) {
		uint32_t  timePassed = currentTime - _previousTime;
		return (timePassed / (float)_interval) * 100;
	  }
	  else {
		return 100;
	  }
	}

	uint32_t  Every::mapValue(uint32_t  target) {
	  uint32_t  output;
	  uint32_t  currentTime = millis();
	  if(_paused) return 0;
	  if (_previousTime > currentTime) {
		return 0;
	  }
	  else if (_previousTime + _interval > currentTime) {
		uint32_t  timePassed = currentTime - _previousTime;
		return (timePassed / (float)_interval) * target;
	  }
	  else {
		return target;
	  }
	}


	void Every::setRepeat(bool repeat) {
	  _repeat = repeat;
	}

	void Every::setCallback(void (*callback)()) {
	  _callback = callback;
	}
