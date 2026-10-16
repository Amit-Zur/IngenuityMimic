#include "dataPacketWriting.h"

bool memoryCardInit(SdSpiCard& memoryCard)
{
    if(!memoryCard.begin(SdSpiConfig(SD_SELECTED_CS_PIN, SHARED_SPI, SD_SCK_MHZ(SD_CARD_MHZ_SPEED))))
    {
        Serial.println(F("ERROR: SD card initalization failed.")); // Placeholder I will do error handling later in the project
        return false;
    }

    uint32_t cardSectorsAmount = memoryCard.sectorCount();
    
    if(cardSectorsAmount == 0)
    {
        Serial.println(F("ERROR: SD card returns 0 sectors."));
        return false;
    }

    Serial.print(F("SD card sector count: "));
    Serial.println();

    return true;
}