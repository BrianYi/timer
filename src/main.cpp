#include "AdvanceTimeWheel.h"
#include "TimeDriver.h"
#include "SecTimer.h"
#include "MinTimer.h"
#include "HourTimer.h"

int main()
{
    TimeDriver* timeDriver = new TimeDriver(1);
    AdvanceTimeWheel* advTimeWheel = new AdvanceTimeWheel;
    SecTimer* secTimer1 = new SecTimer(5);    
    SecTimer* secTimer2 = new SecTimer(10);
    SecTimer* secTimer3 = new SecTimer(60);
    MinTimer* minTimer1 = new MinTimer(1); 
    advTimeWheel->addTimer(secTimer1);
    advTimeWheel->addTimer(secTimer2);
    advTimeWheel->addTimer(secTimer3);
    advTimeWheel->addTimer(minTimer1);
    timeDriver->mountTimeWheel(advTimeWheel);
    timeDriver->start();
    delete timeDriver;
    delete advTimeWheel;
    delete secTimer1;
    delete secTimer2;
    delete secTimer3;
    delete minTimer1;
    exit(EXIT_SUCCESS);
}
