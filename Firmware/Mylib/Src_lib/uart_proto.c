#include "uart_proto.h"
#include "crc16.h"
/**
 * @brief Get data from Frame
 *
 * @param pu8Src :Data received, it's can be 1 or 2 ... frame, we don't know
 * @param u16Src_len :Lenght of data received, can be known by adding up the total number of uart interrupts until there is enough data
 * @param pu8Dest :Data cut out of frame 
 * @param pu16Dest_len :Length of data that has been trimmed from frame 
 * @return int8_t to check if frame can be trimmed correctly
 */
int8_t UART_get_data(uint8_t *pu8Src, uint16_t u16Src_len, uint8_t *pu8Dest, uint16_t *pu16Dest_len)
{   
	const uint8_t *pu8Src_start = pu8Src;
	const uint8_t *pu8Src_findStart = pu8Src + (u16Src_len);
	char checkFindStart = 0;
	uint8_t checkESC = 0;
	uint8_t index = 0;
	uint16_t crc_check = 0;
	// Advance src to start byte
	while(pu8Src < pu8Src_findStart && *pu8Src != PROTO_START_BYTE)
	{
		pu8Src++;
	}
	if(*pu8Src == PROTO_START_BYTE)   // If you just enter and receive the start byte, then you don't have to enter the while function
	{
		checkFindStart = 1;
	}
	// Set our error return val for dest_len
	if(checkFindStart == 0)
	{
	   return no_valid;
	}
	// Loop through the data
	pu8Src++;
	while(index < PROTO_DATA_SIZE_RX)
	{
		if (*pu8Src == PROTO_ESC_BYTE) // 7E
		{
			crc_check = crc16_floating(*pu8Src, crc_check);
			*(pu8Dest++)  = (*(++pu8Src)) ^ 0x20;
			crc_check = crc16_floating(*pu8Src, crc_check);
			checkESC++;
		}
		else
		{
			crc_check = crc16_floating(*pu8Src, crc_check);
			*(pu8Dest++) = *pu8Src;
		}
		pu8Src++;
		index++;
	}

	if (*(pu8Src + 2) != PROTO_END_BYTE)
		{  // pu8Src in first CRC now
			return no_valid;
		}
		uint8_t byte2_crc = (crc_check) & 0xFF;
		uint8_t byte1_crc = (crc_check >> 8) & 0xFF;
		if(*(pu8Src) != byte1_crc || *(++pu8Src) != byte2_crc)
		{
			return false_CRC;
		}
		*pu16Dest_len =(++pu8Src - pu8Src_start - 4 - checkESC + 1); // length data received
		if(*pu16Dest_len != PROTO_DATA_SIZE_RX)
		{
		   return false_lenght_data;
		}
		return right;
}
/**
 * @brief Create Frame
 * 
 * @param pu8Src :Source raw data 
 * @param u8Src_len :Lenght of source raw data, it's will be know before by programmer
 * @param pu8Dest :Create frame with source raw data, it's will be like: start mode data1 data2 (ESC byte if data is duplicate start stop or ESC).. crc1 crc2 stop
 * @param pu16Dest_len :Lenght of frame
 */
void UART_frame_data(uint8_t *pu8Src, uint8_t u8Src_len, uint8_t *pu8Dest, uint16_t *pu16Dest_len)
{
	uint8_t index = 0;
	uint8_t checkESC = 0;
	uint16_t crc = 0;
	*(pu8Dest++) = PROTO_START_BYTE;

	while(index < u8Src_len) {
			if (*pu8Src == PROTO_START_BYTE || *pu8Src == PROTO_ESC_BYTE || *pu8Src == PROTO_END_BYTE) {
					*(pu8Dest++) = PROTO_ESC_BYTE;
					crc = crc16_floating(*(pu8Dest-1), crc);
					*(pu8Dest++) = (*pu8Src) ^ 0x20;
					crc = crc16_floating(*(pu8Dest-1), crc);
					checkESC++;
			}
			else {
					crc = crc16_floating(*pu8Src, crc);
					*(pu8Dest++) = *pu8Src;
			}
			++pu8Src;
			index++;
	}

	// Set the CRC

	//Casting the CRC to lets the word be assigned to a non-word boundary in memory
	*(pu8Dest++) = (char)(crc >>8);
//	pu8Dest++;
	*(pu8Dest++) = (char)crc;
//	pu8Dest++;
	*(pu8Dest) = PROTO_END_BYTE;
//	*(pu16Dest_len) = pu8Dest - pu8Dest_start;
	*(pu16Dest_len) = u8Src_len + checkESC + 4;   // length frame, 4 equal start crc crc stop
}

