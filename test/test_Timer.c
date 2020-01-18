#include "unity.h"

#include "Timer.h"
#include "mock_TimeKeeper.h"

Timer *timers[NR_OF_TIMERS + 1];

void setUpBeforeAll(void)
{
    for (uint8_t i = 0; i < NR_OF_TIMERS - 1; i++)
    {
        timers[i] = new_Timer();
    }
}

void setUp(void)
{
    static bool isSetUpBeforeAllDone = false;

    if (!isSetUpBeforeAllDone)
    {
        setUpBeforeAll();
        isSetUpBeforeAllDone = true;
    }
}

void tearDown(void)
{
}

void test_new_Timer_should_assign_new_timer_if_available(void)
{
    timers[NR_OF_TIMERS - 1] = new_Timer();

    TEST_ASSERT_NOT_NULL(timers[0]);

    timers[NR_OF_TIMERS] = new_Timer();

    TEST_ASSERT_NULL(timers[NR_OF_TIMERS]);
}

void test_Timer_start_should_initialize_timer(void)
{
    TimeKeeper_getCurrentTimeInMillis_ExpectAndReturn(651);
    Timer_start(timers[0], 500);

    uint32_t delay = Timer_getDelayInMillis(timers[0]);
    uint32_t timeAtStart = Timer_getTimeAtStartInMillis(timers[0]);

    TEST_ASSERT_EQUAL_UINT32(500, delay);
    TEST_ASSERT_EQUAL_UINT32(651, timeAtStart);
}
