// Implement read sensors function
// Implement constructor for the timeStampEntry & weatherEntry 
// *** Should check the delay between writing a timestampEntry and than adding it to the weatherEntry

#include <arduinoSensors.h>

bool weatherSensorStart()
{
    return weatherSensor.begin(0x76); // SDO pin connected to GND -> 0x76 / VCC -> 0x77
}

weatherEntry weatherRead()
{
    weatherEntry currObject;

    currObject.hPa = weatherSensor.readPressure();
    currObject.tempCelsius = weatherSensor.readTemperature();
    currObject.humidity = weatherSensor.readHumidity();
    // currObject.currentTime.seconds TODO
    // currObject.currentTime.timeBase TODO
    // currObject.currentTime.timeContext TODO

    return currObject;
}