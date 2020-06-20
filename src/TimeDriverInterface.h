#pragma once
#include "TimeWheelInterface.h"

class TimeDriverInterface
{
public:
    enum
    {
        DEFAULT_GRANULARITY=1
    };
public:
    TimeDriverInterface(long granularity = DEFAULT_GRANULARITY);
    void mountTimeWheel(TimeWheelInterface* timewheel);
    int totalTimeWheels();
    int getGranularity();
    virtual void start() = 0;
protected:
    std::vector<TimeWheelInterface*> fTimeWheelArry;
    int fGranularity;
};
