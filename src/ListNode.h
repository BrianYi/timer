#pragma once
#include "PlatformHeader.h"
#include "TimerInterface.h"

struct ListNode
{
    ListNode()
    {
        timer = NULL;
        hour = 0;
        min = 0;
        sec = 0;
    }
    TimerInterface* timer; 
    int hour;
    int min;
    int sec;
};
