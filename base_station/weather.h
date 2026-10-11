include <cstdint>

// Need to read about a case of power shutdown mid writing and how to counter it

struct timeStampEntry
{
    uint32_t seconds;
    uint8_t timeBase; // Log flag: time logged using Arduino board  or RTC module
    uint8_t timeContext; // Tag for later use 
};

struct weatherEntry 
{
    uint16_t hPa; 
    int8_t tempCelsius; // BME280 sensor temp range is 0 to 65 celsius degrees 
    uint8_t humidity; // Humidity range will be 0 to 100 without the decimal point values
    timeStampEntry currentTime;
};
