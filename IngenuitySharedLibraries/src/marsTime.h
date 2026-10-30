#pragma once
#include <stdint.h>

static constexpr int SECONDS_IN_HOUR = 3600;
static constexpr int SECONDS_IN_MINUTE = 60;

struct marsClockObject
{
    uint32_t marsSol;
    uint8_t marsSecond;
    uint8_t marsMinute;
    uint8_t marsHour;
};

/*
 *  @brief Converts current earth time that was read by the RTC moudle / arduino board to equivalent mars time
 *  @returns marsClockObject with the current equivalent mars time 
*/
marsClockObject earthTimeToMarsFunct(uint32_t earthSeconds); // Function input is a placeholder for now till I figure out my time struct correctly)