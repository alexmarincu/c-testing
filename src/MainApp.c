#include "MainApp.h"
#include "StandardTypes.h"
#include "TimeSource.h"
#include "Timer.h"

Timer * timer1;

void MainApp_start(void)
{
    timer1 = new_Timer();
    Timer * timer2 = new_Timer();
    Timer * timer3 = new_Timer();

    for (UInt8 i = 0; i < 5; i++)
    {
        Timer_start(timer1, 200);
        Timer_start(timer2, 500);
        Timer_start(timer3, 10);

        while (!Timer_isExpired(timer1) && !Timer_isExpired(timer2) && !Timer_isExpired(timer3)) { ; }

        printf("%d\n", Timer_getPassedTimeInMillis(timer1));
        printf("%d\n", Timer_getPassedTimeInMillis(timer2));
    }
}
