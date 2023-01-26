#ifndef Every_h
#define Every_h

class Every {
  public:
	 enum Unit {
        milliseconds,
        seconds,
        minutes
    };
    Every(unsigned long interval, Unit unit);
    bool trigger();
    void update();
    void pause();
    void resume();
    unsigned long remaining(Unit unit);
    void setInterval(float interval, Unit unit);
	unsigned long getInterval(Unit unit);
    void setRepeat(bool repeat);
	unsigned long percent();
	unsigned long mapValue(unsigned long target);
    void setCallback(void (*callback)());
    
  private:
    unsigned long _interval;
    unsigned long _previousTime;
    bool _triggered;
    bool _paused;
    bool _repeat;
    void (*_callback)();
};

#endif
