#pragma once // Include guard for this header file 
#include <cstdint>
#include <Adafruit_BME320_Library>
#include <DS3231-RTC>

// Need to read about a case of power shutdown mid writing and how to counter it


constexpr uint8_t BME280_I2C_ADDRESS = 0x76; // GND address
constexpr uint8_t RTC_I2C_ADDRESS = 0x68; // GND address 


static Adafruit_BME280 weatherSensor; // Global private weather object 

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

/*
 *  @brief Initalize BME280 weather sensor
*/
bool weatherSensorStart();

/*
    @brief Initalize DS3231-RTC module 
*/
bool timeClockStart();

/*
 *  @brief Read weather data from the BME280 sensor.
 *  @returns weatherEntry object with read values.
*/
weatherEntry weatherRead();