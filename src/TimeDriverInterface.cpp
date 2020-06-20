#include "TimeDriverInterface.h"
    
TimeDriverInterface::TimeDriverInterface(long granularity/* = DEFAULT_GRANULARITY*/)
{
    fGranularity = granularity;
}

void TimeDriverInterface::mountTimeWheel(TimeWheelInterface* timewheel)
{
    fTimeWheelArry.push_back(timewheel);
}

int TimeDriverInterface::totalTimeWheels()
{
    return fTimeWheelArry.size();
}

int TimeDriverInterface::getGranularity()
{
    return fGranularity;    
}

