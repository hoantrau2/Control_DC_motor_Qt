#include <serial_proto.h>
#include <crc16.h>
//---
#include <QDebug>
#include <QString>
#include <QChar>
//--
/*
 * Args:
 *   src      : source raw data
 *   src_len  : length of raw data
 *   dest     : destination buffer, must be at least length of src buffer
 *   dest_len : length of data in destination buffer, unless error returned
 * Return values:
 *   -4   : False lenght data
 *   -3   : Destination buffer too small
 *   -2   : Invalid CRC
 *   -1   : No valid message found
 *   >= 0 : Message ended at src + return value
 * If  an error is returned, dest_len is set to the amount of data which can
 * be (and should be) discarded from the start of the src buffer.
 */
int8_t SerialProto::serialGetData(uint8_t *pu8Src, uint16_t u16Src_len, uint8_t *pu8Dest, uint16_t *pu16Dest_len)
{
        const uint8_t *pu8Src_start = pu8Src;
        char checkFindStart = 0;
        uint8_t checkESC = 0;
        uint8_t index = 0;
        qDebug() << "pu8Src la: " << pu8Src;
        const uint8_t *pu8Src_findStart = pu8Src + (u16Src_len);
        uint16_t crc_check = 0;
        // Advance src to start byte
        while (pu8Src < pu8Src_findStart && *pu8Src != PROTO_START_BYTE)
        {
                pu8Src++; // tim start byte
        }
        // check sau vong while
        if (*pu8Src == PROTO_START_BYTE) // neu vua vo ma nhan duoc byte start luon thi khoi vo ham while
        {
                checkFindStart = 1;
        }
        if (checkFindStart == 0)
        {
                return no_valid;
        }
        pu8Src++;
        while (index < PROTO_DATA_SIZE_RX) // do dai data ko co byte ESC
        {
                if (*pu8Src == PROTO_ESC_BYTE) // 7E
                {
                        crc_check = crc16_floating(*pu8Src, crc_check);
                        *(pu8Dest++) = (*(++pu8Src)) ^ 0x20;
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
        { // luc nay pu8Src dang o byte CRC dau tien
                return no_valid;
        }
        uint8_t byte1_crc = (crc_check >> 8) & 0xFF;
        uint8_t byte2_crc = (crc_check)&0xFF;
        if (*(pu8Src) != byte1_crc || *(++pu8Src) != byte2_crc)
        {
                return false_CRC;
        }
        *pu16Dest_len = (++pu8Src - pu8Src_start - 4 - checkESC + 1); // do dai data thu duoc, debug thay phai cong 1, vi pu8Src sau ++ dang o stop nen tru start se thieu 1 de tinh do dai
        if (*pu16Dest_len != PROTO_DATA_SIZE_RX)
        {
                return false_lenght_data;
        }
        return rightt;
}

void SerialProto::serialFrameData(uint8_t *pu8Src, uint16_t u16Src_len, uint8_t *pu8Dest, uint16_t *pu16Dest_len)
{
        uint8_t index = 0;
        uint8_t checkESC = 0;
        uint16_t crc = 0;
        *(pu8Dest++) = PROTO_START_BYTE;
        while (index < u16Src_len)
        {
                if (*pu8Src == PROTO_START_BYTE || *pu8Src == PROTO_ESC_BYTE || *pu8Src == PROTO_END_BYTE)
                {
                        *(pu8Dest++) = PROTO_ESC_BYTE;
                        crc = crc16_floating(*(pu8Dest - 1), crc);
                        *(pu8Dest++) = (*pu8Src) ^ 0x20;
                        crc = crc16_floating(*(pu8Dest - 1), crc);
                        checkESC++;
                }
                else
                {
                        crc = crc16_floating(*pu8Src, crc);
                        *(pu8Dest++) = *pu8Src;
                }
                ++pu8Src;
                index++;
        }
        *(pu8Dest) = (char)(crc >> 8);
        pu8Dest++;
        *(pu8Dest) = (char)crc;
        pu8Dest++;
        *(pu8Dest++) = PROTO_END_BYTE;
        *(pu16Dest_len) = u16Src_len + checkESC + 4; // do dai frame, 4 la start crc crc stop
}
