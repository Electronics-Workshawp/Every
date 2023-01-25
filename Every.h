#ifndef Every_h
#define Every_h

class Every {
  public:
    Every(unsigned long interval, char* unit);
    bool trigger();
    void update();
    void pause();
    void resume();
    unsigned long remaining();
    void setInterval(float interval, char* unit);
    void setRepeat(bool repeat);
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