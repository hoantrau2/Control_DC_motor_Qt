#ifndef SERIAL_PROTO_H
#define SERIAL_PROTO_H

#include "stdint.h"
#include "stdlib.h"
#define PROTO_DATA_SIZE_TX 13
#define PROTO_DATA_SIZE_RX 5

#define PROTO_BUFF_SIZE_TX PROTO_DATA_SIZE_TX*2 + 4
#define PROTO_BUFF_SIZE_RX PROTO_DATA_SIZE_RX*2 + 4

#define PROTO_START_BYTE 0x02 // STX
#define PROTO_ESC_BYTE 0x7E
#define PROTO_END_BYTE 0x03 // ETX

typedef enum
{
    false_lenght_data = -4,
    buffer_small,
    false_CRC,
    no_valid = -1,
    rightt = 2
}check;

class SerialProto
{
public:
    SerialProto()
    {
    }
    void call_create_frameQt();
    int8_t call_get_dataFromSTM(); // use with serialGetData
    int8_t serialGetData(uint8_t *pu8Src, uint16_t u16Src_len, uint8_t *pu8Dest, uint16_t *pu16Dest_len);
    void serialFrameData(uint8_t *pu8Src, uint16_t u16Src_len, uint8_t *pu8Dest, uint16_t *pu16Dest_len);
    uint8_t au8TxBuffer[PROTO_BUFF_SIZE_TX];
    uint8_t au8RxBuffer[PROTO_BUFF_SIZE_RX];
};

#endif // SERIAL_PROTO_H
