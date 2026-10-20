#include "test_functions.h"

void setup()
{
    Serial.begin(BOARD_BAUD_RATE);
    Wire.begin();
    digitalWrite(SDA, LOW); // Disable Arduino internal pull up on SDA
    digitalWrite(SCL, LOW); // Disable Arduino internal pull up on SDL 
}

void loop()
{
    if(!Serial.available()) return; // Waits for user input
    switch(Serial.read())
    {
        case '1': I2C_bus_test; break;
        case '2': placeholder; break;
        case '3': placeholder; break;
    }
}