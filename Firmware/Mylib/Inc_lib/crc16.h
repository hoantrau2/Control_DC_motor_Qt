/*
 * crc16.h
 *
 *  Created on: Dec 2, 2023
 *      Author: lehuu
 */

#ifndef CRC16_H_
#define CRC16_H_



#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

uint16_t crc16_buff(const uint8_t *buf, int len);
uint16_t crc16_floating(uint8_t next, uint16_t seed);

#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif /* CRC16_H_ */
