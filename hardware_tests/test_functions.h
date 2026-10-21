#pragma once
#include <Arduino.h>
#include <Wire.h>


const uint16_t BOARD_BAUD_RATE = 9600;
const uint8_t ADDRESS_LIMIT = 0x80;
const uint8_t DS3231_ADDRESS = 0x68;
const uint8_t BMP280_ADDRESS = 0x76;

bool device_connected_check(uint8_t device_address);

bool I2C_bus_test();

bool device_ID_test();