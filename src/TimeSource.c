#include "TimeSource.h"
#include <time.h>

UInt32 TimeSource_getCurrentTimeInMillis()
{
    UInt32 currentTime = (UInt32)(clock() / (CLOCKS_PER_SEC / 1000));
    return currentTime;
}
