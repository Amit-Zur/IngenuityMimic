/*
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

bool encodeCardSector(uint8_t* sectorBuffer,uint32_t currSectorNum, const uint8_t* dataPacket, uint16_t dataPacketLen)
{
    std::memset(sectorBuffer, 0xFF, CARD_SECTOR_SIZE); // Cleans the sector buffer

    // Decide which header files I want to use in order to catgeroize the data that will be written in the sector

    std::memcpy(&sectorBuffer[DATA_PACKET_OFFSET], dataPacket, dataPacketLen); // Copy data into the sector buffer 

    // Read about Cyclic Redundancy Check and hopefully implement it correctly here.

    return true;
}
    */