#include "TimerInterface.h"

void TimerInterface::stop()
{
    fStop = true;
}

int TimerInterface::getTimeSpan()
{
    return fTimespan;
}
void TimerInterface::setTimeSpan(int timespan)
{
    fTimespan = timespan;
}
bool TimerInterface::needRepeat()
{
    return fNeedRepeat;
}

