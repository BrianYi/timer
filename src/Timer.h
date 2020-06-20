#pragma once
#include "TimerInterface.h"
#include "AdvanceTimeWheel.h"

class Timer: public TimerInterface
{
public:
    virtual ~Timer(){};
    Timer(int timespan, bool needRepeat);
    virtual void callback() = 0;
    AdvanceTimeWheel* getAdvanceTimeWheel() {return fTimeWheel;}
private:
    AdvanceTimeWheel* fTimeWheel;
};
