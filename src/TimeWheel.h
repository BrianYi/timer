#include "TimeWheelInterface.h"

class TimeWheel: public TimeWheelInterface
{
public:
    TimeWheel(){};
    void run(int milliseconds);
private:
};
