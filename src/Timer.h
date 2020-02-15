#ifndef B87FA3F9_30F8_4BB6_BC46_E2287260C54A
#define B87FA3F9_30F8_4BB6_BC46_E2287260C54A

#include "StandardTypes.h"

#define NR_OF_TIMERS 3

typedef struct _Timer Timer;

Timer * new_Timer();
void Timer_start(Timer * const me, UInt32 const delayInMillis);
Boolean Timer_isExpired(Timer const * const me);
UInt32 Timer_getPassedTimeInMillis(Timer const * const me);
UInt32 Timer_getDelayInMillis(Timer const * const me);
UInt32 Timer_getTimeAtStartInMillis(Timer const * const me);

#endif /* B87FA3F9_30F8_4BB6_BC46_E2287260C54A */
