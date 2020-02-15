#include "Timer.h"
#include "TimeSource.h"

struct _Timer
{
    UInt32 delayInMillis;
    UInt32 timeAtStartInMillis;
};

static Timer timersPool[NR_OF_TIMERS];

static Boolean isInitialized(Timer const * const me);

Timer * new_Timer()
{
    static uint8_t timerCount = 0;
    Timer * newTimer = null;

    if (timerCount < NR_OF_TIMERS)
    {
        newTimer = &timersPool[timerCount];
        newTimer->delayInMillis = 0;
        newTimer->timeAtStartInMillis = 0;
        timerCount++;
    }

    return newTimer;
}

void Timer_start(Timer * const me, UInt32 const delayInMillis)
{
    if (isInitialized(me))
    {
        me->timeAtStartInMillis = TimeSource_getCurrentTimeInMillis();
        me->delayInMillis = delayInMillis;
    }
    else
    {
        /* error handling */
    }
}

Boolean Timer_isExpired(Timer const * const me)
{
    Boolean isExpired = false;

    if (isInitialized(me))
    {
        UInt32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();
        if ((currentTimeInMillis - me->timeAtStartInMillis) >= me->delayInMillis) { isExpired = true; }
    }
    else
    {
        /* error handling */
    }

    return isExpired;
}

UInt32 Timer_getPassedTimeInMillis(Timer const * const me)
{
    UInt32 passedTimeInMillis = 0;

    if (isInitialized(me))
    {
        UInt32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();
        passedTimeInMillis = currentTimeInMillis - me->timeAtStartInMillis;
    }
    else
    {
        /* error handling */
    }

    return passedTimeInMillis;
}

UInt32 Timer_getDelayInMillis(Timer const * const me)
{
    UInt32 delayInMillis = 0;

    if (isInitialized(me))
    {
        delayInMillis = me->delayInMillis;
    }
    else
    {
        /* error handling */
    }

    return delayInMillis;
}

UInt32 Timer_getTimeAtStartInMillis(Timer const * const me)
{
    UInt32 timeAtStartInMillis = 0;

    if (isInitialized(me))
    {
        timeAtStartInMillis = me->timeAtStartInMillis;
    }
    else
    {
        /* error handling */
    }

    return timeAtStartInMillis;
}

static Boolean isInitialized(Timer const * const me)
{
    Boolean isInitialized = true;
    if ((me < &timersPool[0]) || (me > &timersPool[NR_OF_TIMERS - 1])) { isInitialized = false; }
    return isInitialized;
}
