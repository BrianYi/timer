#include "Timer.h"

class MinTimer: public Timer
{
public:
    MinTimer(const int& min, bool isrepeat = true):Timer(min * 60 * 1000, isrepeat)
    {
        fCounter=0;
    }
    virtual void callback()
    {
        printf("[%p]MinTimer timespan %d, count: %d\r\n", this, getTimeSpan(), ++fCounter);
    }
private:
    int fCounter;
};
