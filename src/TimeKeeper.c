#include "TimeKeeper.h"
#include <time.h>

uint32 TimeKeeper_getCurrentTimeInMillis()
{
    uint32 currentTime = (uint32)(clock() / (CLOCKS_PER_SEC / 1000));
    return currentTime;
}