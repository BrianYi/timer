#pragma once
#include "PlatformHeader.h"

class TimerInterface
{
public:  
    virtual ~TimerInterface(){};
    TimerInterface(int timespan, bool needRepeat)
    {
        fTimespan = timespan;
        fNeedRepeat = needRepeat;
        fStop = false;
    }
    virtual void callback() = 0;
    void stop();
    bool isRegistered();
    int getTimeSpan();
    void setTimeSpan(int timespan);
    bool needRepeat();
private:
    bool fStop;
    bool fNeedRepeat;
    int fTimespan;
};
