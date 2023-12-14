/*
 * encoder.h
 *
 *  Created on: Dec 2, 2023
 *      Author: lehuu
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "stdint.h"
#include "main.h"
typedef struct
{
  int32_t position;
  int16_t speed_by_encoder; // xung/(time interrupt timer)
  int16_t pre_speed_by_encoder;
  short pre_counter;
  int32_t velocity; // vong/phut
} instance_encoder;
extern instance_encoder instance_enc;
extern uint8_t data_after_cut[PROTO_DATA_SIZE_RX];
extern TIM_HandleTypeDef htim2;
void encoder();



#endif /* ENCODER_H_ */
