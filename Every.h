#ifndef Every_h
#define Every_h

class Every {
  public:
	 enum Unit {milliseconds,seconds,minutes,hours};
    Every(uint32_t  interval, Unit unit);
    bool trigger();
	bool ready();
    void update();
    void pauseTask();
    void resumeTask();
	void updateEvery();
    uint32_t  remaining(Unit unit);
    void setInterval(float interval, Unit unit);
	uint32_t  getInterval(Unit unit);
    void setRepeat(bool repeat);
	uint32_t  percent();
	uint32_t  mapValue(uint32_t  source,uint32_t  target);
    void setCallback(void (*callback)());
    
  private:
    uint32_t  _interval;
    uint32_t  _previousTime;
    bool _triggered;
	bool _isReady;
    bool _paused;
    bool _repeat;
    void (*_callback)();
};

#endif
