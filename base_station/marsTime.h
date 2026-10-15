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

marsClockObject earthTimeToMarsFunct(uint32_t earthSeconds); // Function input is a placeholder for now till I figure out my time struct correctly)