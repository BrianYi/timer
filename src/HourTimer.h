#include "Timer.h"

class HourTimer: public Timer
{
public:
    HourTimer(const int& hour, bool isrepeat = true):Timer(hour * 60 * 60 * 1000, isrepeat)
    {
        fCounter=0;
    }
    virtual void callback()
    {
        printf("[%p]HourTimer timespan %d, count: %d\r\n", this, getTimeSpan(), ++fCounter);
    }
private:
    int fCounter;
};
