#pragma once
#include <Arduino.h>
#include <Wire.h>


struct board_component
{
    const char* component_name; 
    uint8_t primary_address; // Primary component address
    uint8_t secondary_address; // Secondary component address, set to 0x00 if none.
    uint8_t register_address; 
    bool check_component_ID; // Is component chip id check is necessary
    uint8_t component_chip_ID; // Component chip ID value
}

const board_component CONNECTED_DEVICES[] = // Note to self, allocate memory 
{   // name, primary address, secondary address, register address, check needed, chip ID value
    {"BME280",  0x76,   0x77,   0xD0,   true,   0x60},
    {"DS3231",  0x68,   0x00,   0x0F,   false,  0x00},
    // TBD 
};

const uint16_t BOARD_BAUD_RATE = 9600;
const uint8_t DS3231_ADDRESS = 0x68;
const uint8_t BMP280_ADDRESS = 0x76;
const uint8_t DEVICE_AMOUNT = sizeof(CONNECTED_DEVICES) / sizeof(CONNECTED_DEVICES[0]);



/*
 *  @brief Checks if a given address is actually connected to the board
 *  @returns true if it is, else false
*/
bool device_connected_check(uint8_t device_address);

/*
 *  @brief An helper function that check which address the device is using
 *         Some devices might use multiple address
 *  @returns the address that the device is using
*/
static uint8_t primary_or_secondary_address(board_component& current);

/*
 *  @brief A connectivity I2C test function that checks the components of the board
 *  @returns true if everything is connected correctly, else false
*/
bool I2C_bus_test()