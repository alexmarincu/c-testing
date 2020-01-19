#include "Timer.h"
#include "TimeSource.h"

struct _Timer
{
    uint32 delayInMillis;
    uint32 timeAtStartInMillis;
};

static boolean isInitialized(Timer *me);
static Timer *getValidatedTimer(Timer *me);

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
    me = getValidatedTimer(me);
    me->timeAtStartInMillis = TimeSource_getCurrentTimeInMillis();
    me->delayInMillis = delayInMillis;
}

boolean Timer_isExpired(Timer *me)
{
    me = getValidatedTimer(me);
    boolean isExpired = false;
    uint32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();

    if ((currentTimeInMillis - me->timeAtStartInMillis) >= me->delayInMillis)
    {
        isExpired = true;
    }

    return isExpired;
}

boolean Timer_isNotExpired(Timer *me)
{
    me = getValidatedTimer(me);
    boolean isNotExpired = true;
    uint32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();

    if ((currentTimeInMillis - me->timeAtStartInMillis) >= me->delayInMillis)
    {
        isNotExpired = false;
    }

    return isNotExpired;
}

uint32 Timer_getPassedTimeInMillis(Timer *me)
{
    me = getValidatedTimer(me);
    uint32 currentTimeInMillis = TimeSource_getCurrentTimeInMillis();
    uint32 passedTimeInMillis = currentTimeInMillis - me->timeAtStartInMillis;
    return passedTimeInMillis;
}

uint32 Timer_getDelayInMillis(Timer *me)
{
    me = getValidatedTimer(me);
    return me->delayInMillis;
}

uint32 Timer_getTimeAtStartInMillis(Timer *me)
{
    me = getValidatedTimer(me);
    return me->timeAtStartInMillis;
}

static boolean isInitialized(Timer *me)
{
    boolean isInitialized = true;

    if ((me < &timersPool[0]) || me > &timersPool[NR_OF_TIMERS - 1])
    {
        isInitialized = false;
    }

    return isInitialized;
}

static Timer *getValidatedTimer(Timer *me)
{
    if (!isInitialized(me))
    {
        me = null;
    }

    return me;
}
