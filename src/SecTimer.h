#include "Timer.h"

class SecTimer: public Timer
{
public:
    SecTimer(const int& sec, bool isrepeat = true):Timer(sec * 1000, isrepeat)
    {
        fCounter=0;
    }
    virtual void callback()
    {
        printf("[%p]SecTimer timespan %d, count: %d\r\n", this, getTimeSpan(), ++fCounter);
    }
private:
    int fCounter;
};
