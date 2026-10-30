#include "test_functions.h"

bool device_connected_check(uint8_t device_address)
{
    Wire.beginTransmission(device_address);
    return Wire.endTransmission() == 0;
} // end of device_connected_check function

/*
 *  @brief finds out which address a component is using
 *         because some components can be set to primary or secondary addresses
 *  @param current the component the function is looking for
 *  @returns the address that responded, else returns 0
*/ 
static uint8_t primary_or_secondary_address(const board_component& current)
{
    if(device_connected_check(current.primary_address)) return current.primary_address;
    if(current.secondary_address && device_connected_check(current.secondary_address)) return current.secondary_address;

    return 0;
} // end of primary_or_secondary_address function

bool I2C_bus_test()
{
    bool device_test_status = true;

    Serial.println(F("##### I2C CHECK BEGINS #####"));

    for(uint8_t device_counter = 0; device_counter < DEVICE_AMOUNT; device_counter++)
    {
        const board_component& current_device = CONNECTED_DEVICES[device_counter];
        uint8_t current_device_address = primary_or_secondary_address(current_device);

        if(current_device_address)
        {
            Serial.print(F("PASS: "));
            Serial.print(current_device.component_name);
            Serial.print(F(" found at address: 0x"));
            Serial.println(current_device_address, HEX);
        }
        else
        {
            Serial.print(F("FAILED: "));
            Serial.print(current_device.component_name);
            Serial.print(F(" not found at address: 0x"));
            Serial.print(current_device.primary_address, HEX);
            if(current_device.secondary_address)
            {
                Serial.print(F(" or at address: 0x"));
                Serial.println(current_device.secondary_address, HEX);
            }
            Serial.println();
            device_test_status = false;
        }
    }
    
    if(device_test_status == true)
    {
        Serial.println(F("##### I2C BUS TEST PASSED ######"));
    }

    return device_test_status;
} // end of I2C_bus_test function

/*
bool device_ID_test() // Redundant test will not write it for now.
                      //  Might be used later for an edge case where BMP280 is connected isntead of BME 280

}
*/

bool sensor_reading_test()
{
    Serial.println(F("##### SENSOR READING TEST BEGINS #####"));

    weatherEntry weatherObject;
    bool sensor_test_status = true;
    bool sensor_status = sensorStartWrap();
    weatherObject = weatherRead();
    
    Serial.print("hPA: ");
    Serial.println(weatherObject.hPa / PASCAL_PER_DECI_HPA);
    Serial.print("Temperature: ");
    Serial.println(weatherObject.tempCelsius / TEMP_UNITS_PER_ONE_CELSIUS);
    // Serial.print("Humidity: ");
    // Serial.println(weatherObject.humidity); PLACEHOLDER TILL I GET A BME 280 
    Serial.print("Current time: ");
    Serial.println(weatherObject.currentTime.seconds); // Wont show time till I get a battery

    if(weatherObject.hPa < MIN_HPA || weatherObject.hPa > MAX_HPA)
    {
        Serial.println(F("FAILED: hPa values are out of range."));
        sensor_test_status = false;
    }

    if(weatherObject.tempCelsius < MIN_TEMP || weatherObject.tempCelsius > MAX_TEMP)
    {
        Serial.println(F("FAILED: temperature values are out of range."));
        sensor_test_status = false;
    }

    if((sensor_test_status && sensor_status) == true)
    {
        Serial.println(F("##### SENSOR READING TEST PASSED ######"));
    }

    return (sensor_test_status && sensor_status);
}