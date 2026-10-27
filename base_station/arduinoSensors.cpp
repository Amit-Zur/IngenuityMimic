// Implement read sensors function
// Implement constructor for the timeStampEntry & weatherEntry 
// *** Should check the delay between writing a timestampEntry and than adding it to the weatherEntry

#include "arduinoSensors.h"

static Adafruit_BME280 weatherSensor; 
static DS3231 realTimeClock; 
static bool realTimeClockFlag = false;

bool weatherSensorStart()
{
    if(!weatherSensor.begin(BME280_I2C_ADDRESS)) return false; 
    // Future error handling of sensor not working?

    weatherSensor.setSampling(Adafruit_BME280::MODE_FORCED, // Takes temperature reading only when called
                              Adafruit_BME280::SAMPLING_X1, // Temperature reading
                              Adafruit_BME280::SAMPLING_X1, // Pressure reading
                              Adafruit_BME280::SAMPLING_X1, // Humidity reading
                              Adafruit_BME280::FILTER_OFF); // Turns filter off, because it's not relevant in this type of reading
    return true;
}

bool timeClockStart()
{
    Wire.beginTransmission(RTC_I2C_ADDRESS); 
    // Checks if the communication was successfully established 
    if(Wire.endTransmission() != 0) return false; 
    // Checks if the oscillator is running, else time stamp is unreliable
    if(realTimeClock.oscillatorCheck() == false) return false; 

    realTimeClockFlag = true;
    return true;
}

bool sensorStartWrap()
{
    Wire.begin();
    bool bme280_sensor = weatherSensorStart();
    bool ds3231_rtc = timeClockStart();

    return bme280_sensor && ds3231_rtc;
}

weatherEntry weatherRead()
{
    weatherEntry currWeatherObject;

    if(realTimeClockFlag == true)
    {
        currWeatherObject.currentTime.seconds = RTClib::now().unixtime();
    }
    else
    {
        currWeatherObject.currentTime.seconds = millis() / MILLI_SECOND_PER_SECOND;
    }

    weatherSensor.takeForcedMeasurement();

    currWeatherObject.hPa = weatherSensor.readPressure() / PASCAL_PER_DECI_HPA;
    currWeatherObject.tempCelsius = weatherSensor.readTemperature() * TEMP_UNITS_PER_ONE_CELSIUS;
    currWeatherObject.humidity = weatherSensor.readHumidity();

    currWeatherObject.currentTime.timeBase = realTimeClockFlag;
    currWeatherObject.currentTime.timeContext = 0; // PLACEHOLDER 

    return currWeatherObject;
}