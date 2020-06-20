#include "TimeDriverInterface.h"
#include <sys/select.h>

class TimeDriver: public TimeDriverInterface
{
public:
    virtual ~TimeDriver()
    {}
    TimeDriver(int granularity):
        TimeDriverInterface(granularity)
    {}
    void start()
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        int64_t curMicrosecTMS = tv.tv_sec * 1000000 + tv.tv_usec;
        int64_t nextMicrosecTMS = curMicrosecTMS + fGranularity * 1000;
        while (true)
        {
            gettimeofday(&tv, NULL);
            curMicrosecTMS = tv.tv_sec * 1000000 + tv.tv_usec;
            if (nextMicrosecTMS - curMicrosecTMS > 0)
                usleep(nextMicrosecTMS - curMicrosecTMS);
            for (auto& timeWheelPtr : fTimeWheelArry)
                timeWheelPtr->run(fGranularity);
            nextMicrosecTMS = curMicrosecTMS + fGranularity * 1000;
        }
    }
};
