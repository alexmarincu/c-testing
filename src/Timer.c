#include "Timer.h"
#include "TimeKeeper.h"

struct _Timer
{
    uint32 delayInMillis;
    uint32 timeAtStartInMillis;
};

static Timer timersPool[NR_OF_TIMERS];

Timer *new_Timer()
{
    static uint8_t timerCount = 0;
    Timer *newTimer = null;

    if (timerCount < NR_OF_TIMERS)
    {
        newTimer = &timersPool[timerCount];
        newTimer->delayInMillis = 0;
        newTimer->timeAtStartInMillis = 0;
        timerCount++;
    }

    return newTimer;
}

void Timer_start(Timer *me, uint32 delayInMillis)
{
    me->timeAtStartInMillis = TimeKeeper_getCurrentTimeInMillis();
    me->delayInMillis = delayInMillis;
}

boolean Timer_isExpired(Timer *me)
{
    boolean isExpired = false;
    uint32 currentTimeInMillis = TimeKeeper_getCurrentTimeInMillis();

    if ((currentTimeInMillis - me->timeAtStartInMillis) >= me->delayInMillis)
    {
        isExpired = true;
    }

    return isExpired;
}

boolean Timer_isNotExpired(Timer *me)
{
    boolean isNotExpired = true;
    uint32 currentTimeInMillis = TimeKeeper_getCurrentTimeInMillis();

    if ((currentTimeInMillis - me->timeAtStartInMillis) >= me->delayInMillis)
    {
        isNotExpired = false;
    }

    return isNotExpired;
}

uint32 Timer_getPassedTimeInMillis(Timer *me)
{
    uint32 currentTimeInMillis = TimeKeeper_getCurrentTimeInMillis();
    uint32 passedTimeInMillis = currentTimeInMillis - me->timeAtStartInMillis;
    return passedTimeInMillis;
}

uint32 Timer_getDelayInMillis(Timer *me)
{
    return me->delayInMillis;
}

uint32 Timer_getTimeAtStartInMillis(Timer *me)
{
    return me->timeAtStartInMillis;
}