/*
    I need to do some research before writing anything.

    -- SdFat is the library I will probably have to use
    
    Object: write binary data directly into the sd card.

*/

#include <SdFat.h>

const uint8_t SD_SELECTED_CS_PIN = 0; // Placeholder it should be used on PIN 10 / 4
const uint8_t SD_CARD_MHZ_SPEED = 4; // Set to 4 at the moment, board wont allow more than 16 will test with 4 and move it accordingly 

SdSpiCard memoryCard; 

bool memoryCardInit(SdSpiCard& memoryCard);