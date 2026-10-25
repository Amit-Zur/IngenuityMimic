#include "test_functions.h"

void setup()
{
    Serial.begin(BOARD_BAUD_RATE);
    Wire.begin();
    digitalWrite(SDA, LOW); // Disable Arduino internal pull up on SDA
    digitalWrite(SCL, LOW); // Disable Arduino internal pull up on SDL
    Serial.print(F(R"(
                               .-~~~~~~~~~~~~~~~~~~~~~~~~~-.
                            /   *        .         *      .     \
                         /      .          *          .          \
                        |    *          =====o=====      .        |
                        |  .                 |            *       |
                        |   *             [#####]              .  |
                        |      *          /_/ \_\                 |
                        |  *      _o_                    *        |
                        |      [=======]      _.--~~--._          |
                        |~._.~~(O)(O)(O)~._.~~._.~~._.~~._.~~._.~~|
                        |~._.~~._.~~._.~~._.~~._.~~._.~~._.~~._.~~|
                        |                                         |
                        |         INGENUITY MIMIC PROJECT         |
                         \                                       /
                           \                                   /
                               '-~~~~~~~~~~~~~~~~~~~~~~~~~-')"));


    Serial.println();
    Serial.println(F("########## BOARD IS READY FOR TESTING ##########"));
    Serial.println(F("################################################"));
    Serial.println(F("##########   I2C BUS TEST - PRESS 1   ##########"));
    Serial.println();
}

void loop()
{
    if(!Serial.available()) return; // Waits for user input
    switch(Serial.read())
    {
        case '1': I2C_bus_test(); break;
    }
}