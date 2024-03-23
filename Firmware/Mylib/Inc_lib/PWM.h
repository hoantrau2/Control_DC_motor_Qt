/*
 * PWM.h
 *
 *  Created on: Dec 2, 2023
 *      Author: lehuu
 */

#ifndef PWM_H_
#define PWM_H_

#include "PID.h"
extern TIM_HandleTypeDef htim1;

void PWM_control_position(TIM_HandleTypeDef *htim, float duty);
void PWM_control_velocity(TIM_HandleTypeDef *htim, float duty);

#endif /* PWM_H_ */
