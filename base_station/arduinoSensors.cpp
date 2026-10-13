// Implement read sensors function
// Implement constructor for the timeStampEntry & weatherEntry 
// *** Should check the delay between writing a timestampEntry and than adding it to the weatherEntry

#include <arduinoSensors.h>

bool weatherSensorStart()
{
    return weatherSensor.begin(BME280_I2C_ADDRESS); // SDO pin connected to GND -> 0x76 / VCC -> 0x77
}

bool timeClockStart();
{
    Wire.begin(); // Initalize I2C communication with the board 

    Wire.beginTransmission(RTC_I2C_ADDRESS); 
    if(Wire.endTransmission() != 0) return false; // Checks if the communication was successfully established 
}

weatherEntry weatherRead()
{
    weatherEntry currWeatherObject;
    timeStampEntry currTimeObject;

    currWeatherObject.hPa = weatherSensor.readPressure();
    currWeatherObject.tempCelsius = weatherSensor.readTemperature();
    currWeatherObject.humidity = weatherSensor.readHumidity();
    // currTimeObject.currentTime.seconds = 
    // currTimeObject.currentTime.timeBase 
    // currTimeObject.currentTime.timeContext 

    return currObject;
}