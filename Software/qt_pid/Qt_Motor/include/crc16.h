#ifndef CRC16_H
#define CRC16_H

#include <stdint.h>

uint16_t crc16_buff(const uint8_t *buf, int len);
uint16_t crc16_floating(uint8_t next, uint16_t seed);

#endif // CRC16_H
