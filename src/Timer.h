#ifndef B87FA3F9_30F8_4BB6_BC46_E2287260C54A
#define B87FA3F9_30F8_4BB6_BC46_E2287260C54A

#include "StandardTypes.h"

#define NR_OF_TIMERS 3

typedef struct _Timer Timer;

Timer *new_Timer();
void Timer_start(Timer *me, uint32 delayInMillis);
boolean Timer_isExpired(Timer *me);
boolean Timer_isNotExpired(Timer *me);
uint32 Timer_getPassedTimeInMillis(Timer *me);
uint32 Timer_getDelayInMillis(Timer *me);
uint32 Timer_getTimeAtStartInMillis(Timer *me);

#endif /* B87FA3F9_30F8_4BB6_BC46_E2287260C54A */
