/*
    I need to do some research before writing anything.

    -- SdFat is the library I will probably have to use
    
    Object: write binary data directly into the sd card.

*/
/*
#include <SdFat.h>
#include <string.h>

const uint8_t SD_SELECTED_CS_PIN = 0; // Placeholder it should be used on PIN 10 / 4
const uint8_t SD_CARD_MHZ_SPEED = 4; // Set to 4 at the moment, board wont allow more than 16 will test with 4 and move it accordingly 
const uint16_t CARD_SECTOR_SIZE = 512; 
const uint8_t DATA_PACKET_OFFSET = 0; // Placeholder value at the moment till I decide the header size

static uint8_t sectorBuffer[CARD_SECTOR_SIZE]; // Used to write data into a sector
SdSpiCard memoryCard; 

bool memoryCardInit(SdSpiCard& memoryCard);

bool encodeCardSector(uint8_t* sectorBuffer,uint32_t currSectorNum, const uint8_t* dataPacket, uint16_t dataPacketLen);

// writeCardSector
bool writeCardSector(SdSpiCard& memoryCard, )
// readCardSector
*/