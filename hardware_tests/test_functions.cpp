#include "test_functions.h"

bool device_connected_check(uint8_t device_address)
{
    Wire.beginTransmission(device_address)
    return Wire.endTransmission() == 0;
}

bool I2C_bus_test()
{
    uint8_t device_counter = 0;
    uint8_t device_address = 0;
    bool ds3231_found = device_connected_check(DS3231_ADDRESS);
    bool bmp280_found = device_connected_check(BMP280_ADDRESS);

    Serial.println(F("--- I2C SCAN BEGINS ---"));

    for(device_address; device_address < ADDRESS_LIMIT; device_address++)
    {
        if(device_connected_check(device_address))
        {
            Serial.print(F("Found a device connected to the board at address: 0x"));
            Serial.println(device_address, HEX);
            device_counter++;
        }
    }
    
    Serial.print(device_counter);
    Serial.println(F(" devices found connected to the board."));

    Serial.println(ds3231_found ? F("PASS: DS3231 FOUND AT ADDRESS 0x68")
                                : F("FAILED: DS3231 NOT FOUND AT ADDRESS 0x68"));
    Serial.println(bmp280_found ? F("PASS: BMP280 FOUND AT ADDRESS 0x76")
                                : F("FAILED: BMP280 NOT FOUND AT ADDRESS 0x78"));

    return ds3231_found && bmp280_found;
}
