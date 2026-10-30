#pragma once // Include guard for this header file 
#include <stdint.h>
#include <Adafruit_BMP280.h> // change to BME280 later
#include <DS3231.h>
#include <Wire.h>

// Need to read about a case of power shutdown mid writing and how to counter it


constexpr uint8_t BME280_I2C_ADDRESS = 0x76; // GND address
constexpr uint8_t RTC_I2C_ADDRESS = 0x68; // GND address 
constexpr uint32_t MILLI_SECOND_PER_SECOND = 1000; 
constexpr float TEMP_UNITS_PER_ONE_CELSIUS = 100.0f;
constexpr float PASCAL_PER_DECI_HPA = 10.0f;

struct  __attribute__((packed)) timeStampEntry
{
    uint32_t seconds;
    uint8_t timeBase; // Log flag: time logged using Arduino board  or RTC module
    uint8_t timeContext; // Tag for later use 
};

struct  __attribute__((packed)) weatherEntry 
{
    uint16_t hPa; // Pressure is stored as tenth of hPa (1234.5 hPa is stored as 12345)
    int16_t tempCelsius; // Temperature is stored as hundreths of celsius (12.34 celsius is stored as 1234)
    uint8_t humidity; // Whole precent from zero to hundred
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

bool sensorStartWrap();
/*
 *  @brief Read weather data from the BME280 sensor.
 *  @returns weatherEntry object with read values.
*/
weatherEntry weatherRead();