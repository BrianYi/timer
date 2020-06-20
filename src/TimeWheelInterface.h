#pragma once
#include "PlatformHeader.h"
#include "TimerInterface.h"

class TimeWheelInterface
{
public:
    virtual ~TimeWheelInterface(){}
    TimeWheelInterface(){};
    virtual void run(int milliseconds) = 0;
};
