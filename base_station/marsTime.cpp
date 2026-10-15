#include "marsTime.h"

constexpr uint32_t MISSION_START_TIME = 0 ; // This will be the RTC epoch of mission start time, zero is used as a placeholder for now.
constexpr uint32_t FIRST_MARS_SOL = 0;
constexpr uint32_t MARS_SOL_SECONDS = 86400;


marsClockObject earthTimeToMarsFunct(uint32_t earthSeconds)
{
    /*
        Earth time to Mars time transformation formula:
        x = earth seconds - k
        y = x - (x >> 3) - (x / 53) + (x / 19820)
        mars seconds = x - (y >> 5)
    */
    uint32_t marsTimeX = (earthSeconds >= MISSION_START_TIME) ? earthSeconds - MISSION_START_TIME : 0;
    uint32_t marsTimeY = marsTimeX - (marsTimeX >> 3) - (marsTimeX / 53) + (marsTimeX / 19820);
    uint32_t marsSeconds = marsTimeX - (marsTimeY >> 5);

    marsClockObject currentMarsTime;

    currentMarsTime.marsSol = FIRST_MARS_SOL + (marsSeconds / MARS_SOL_SECONDS);
    currentMarsTime.marsHour = marsSeconds / SECONDS_IN_HOUR;
    currentMarsTime.marsMinute = (marsSeconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    currentMarsTime.marsSecond = (marsSeconds % SECONDS_IN_MINUTE);

    return currentMarsTime;
}