#pragma once
#include "TimeWheelInterface.h"
#include "ListNode.h"
#include "TimerInterface.h"

class AdvanceTimeWheel: public TimeWheelInterface
{
public:
    AdvanceTimeWheel()
    {
        fMilliSec = 0;
        fSecWheelSize = 60;
        fSecFreq = 1000;
        fSecPtr = 0;
        fMinWheelSize = 60;
        fMinPtr = 0;
        fHourWheelSize = 24;
        fHourPtr = 0;
        fTotalTimerNum = 0;
        fSecWheel.resize(fSecWheelSize);
        fMinWheel.resize(fMinWheelSize);
        fHourWheel.resize(fHourWheelSize);
    }
    void run(int milliseconds)
    {
        fMilliSec += milliseconds;
        int passedSec = fMilliSec / fSecFreq;
        fMilliSec %= 1000;
        while (passedSec--)
        {
            fSecPtr=(fSecPtr+1)%fSecWheelSize;
#if 1
            printf("Time %02d:%02d:%02d\r\n", fHourPtr, fMinPtr, fSecPtr);
#endif
            while (!fSecWheel[fSecPtr].empty())
            {
                ListNode* node = fSecWheel[fSecPtr].front();
                fSecWheel[fSecPtr].pop();
                node->timer->callback();
                if (node->timer->needRepeat())
                {
                    addTimer(node->timer);
                }
                else
                {
                    delete node->timer;
                    fTotalTimerNum--;
                }
                delete node;
            }
            
            if ((fSecPtr+1)/fSecWheelSize)
            {
                fMinPtr=(fMinPtr+1)%fMinWheelSize;
                while (!fMinWheel[fMinPtr].empty())
                {
                    ListNode* minNode = fMinWheel[fMinPtr].front();
                    fMinWheel[fMinPtr].pop();
                    fSecWheel[minNode->sec].push(minNode);
                }

                if ((fMinPtr+1)/fMinWheelSize)
                {
                    fHourPtr=(fHourPtr+1)%fHourWheelSize;
                    while (!fHourWheel[fHourPtr].empty())
                    {
                        ListNode* hourNode = fHourWheel[fHourPtr].front();
                        fHourWheel[fHourPtr].pop();
                        fMinWheel[hourNode->min].push(hourNode);
                    }
                }
            }
        } 
    }
    void addTimer(TimerInterface* timer)
    {
        int timespan = timer->getTimeSpan();
        int passedSec = timespan / fSecFreq;
        ListNode *node = new ListNode;
        node->timer = timer;
        node->sec = fSecPtr + passedSec;
        node->min = fMinPtr + node->sec / fSecWheelSize;
        node->hour = fHourPtr + node->min / fMinWheelSize;
        node->sec %= fSecWheelSize;
        node->min %= fMinWheelSize;
        node->hour %= fHourWheelSize;
        if (node->hour > fHourPtr)
            fHourWheel[node->hour].push(node);
        else if (node->min > fMinPtr)
            fMinWheel[node->min].push(node);
        else if (node->sec > fSecPtr)
            fSecWheel[node->sec].push(node);
        else
            printf("error: %d:%s\r\n", __LINE__, __FUNCTION__);
        
        fTotalTimerNum++;
    }

    int totalTimers()
    {
       return fTotalTimerNum; 
    }

private:
    int fMilliSec;
    int fSecFreq;
    int fSecWheelSize;
    int fSecPtr;
    int fMinWheelSize;
    int fMinPtr;
    int fHourWheelSize;
    int fHourPtr;
    std::atomic<int> fTotalTimerNum;
    std::vector<std::queue<ListNode*>> fSecWheel;
    std::vector<std::queue<ListNode*>> fMinWheel;
    std::vector<std::queue<ListNode*>> fHourWheel;
};
