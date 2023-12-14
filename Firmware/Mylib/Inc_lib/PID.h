/*
 * PID.h
 *
 *  Created on: Dec 2, 2023
 *      Author: lehuu
 */

#ifndef PID_H_
#define PID_H_

#include "encoder.h"
typedef struct
{
  float P_part;
  float I_part;
  float D_part;
} PID_control;
extern PID_control PID_contr;
extern float output_pid, output_pid_velo, output_pid_posi;
extern float error_posi, pre_error_posi;
extern float error_velo, pre_error_velo;
extern float now_position, velocity_real, number_rotation;
extern float Kp_true, Ki_true, Kd_true;
extern uint8_t count_PID;
extern uint8_t countUpdate;

void control_PID_Position(PID_control *pid_tune, float setpoint_posi_rotation, float Kp, float Ki, float Kd);
void control_PID_Velocity(PID_control *pid_tune, float setpoint_velo, float Kp, float Ki, float Kd);
#endif /* PID_H_ */
