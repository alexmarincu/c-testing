#include "Timer.h"
#include "TimeSource.h"

struct _Timer
{
    uint32 delayInMillis;
    uint32 timeAtStartInMillis;
};

static Timer timersPool[NR_OF_TIMERS];

static boolean isInitialized(Timer const * const me);

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

void Timer_start(Timer * const me, uint32 const delayInMillis)
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

boolean Timer_isExpired(Timer const * const me)
{
    boolean isExpired = false;

    if (isInitialized(me))
    {
        uint32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();
        if ((currentTimeInMillis - me->timeAtStartInMillis) >= me->delayInMillis) { isExpired = true; }
    }
    else
    {
        /* error handling */
    }

    return isExpired;
}

uint32 Timer_getPassedTimeInMillis(Timer const * const me)
{
    uint32 passedTimeInMillis = 0;

    if (isInitialized(me))
    {
        uint32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();
        passedTimeInMillis = currentTimeInMillis - me->timeAtStartInMillis;
    }
    else
    {
        /* error handling */
    }

    return passedTimeInMillis;
}

uint32 Timer_getDelayInMillis(Timer const * const me)
{
    uint32 delayInMillis = 0;

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

uint32 Timer_getTimeAtStartInMillis(Timer const * const me)
{
    uint32 timeAtStartInMillis = 0;

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

static boolean isInitialized(Timer const * const me)
{
    boolean isInitialized = true;
    if ((me < &timersPool[0]) || (me > &timersPool[NR_OF_TIMERS - 1])) { isInitialized = false; }
    return isInitialized;
}
