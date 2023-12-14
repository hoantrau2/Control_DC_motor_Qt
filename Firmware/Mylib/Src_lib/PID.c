/*
 * PID.c
 *
 *  Created on: Dec 2, 2023
 *      Author: lehuu
 */

#include <PID.h>

void control_PID_Position(PID_control *pid_tune, float setpoint_posi_rotation, float Kp, float Ki, float Kd)
{

  now_position = (float)instance_enc.position * 360 / Pulseee; // now_position = degree
  number_rotation = now_position / 360;
  error_posi = setpoint_posi_rotation - (now_position);
  pid_tune->P_part = error_posi;
  pid_tune->I_part += error_posi * Ts;
  pid_tune->D_part = (error_posi - pre_error_posi) / Ts;
  if(error_posi < 0.001f*setpoint_posi_rotation)
  {
	pid_tune->I_part = 0;
  }
  output_pid_posi = Kp * (pid_tune->P_part) + Ki * (pid_tune->I_part) + Kd * (pid_tune->D_part);
  if (output_pid_posi > 100.0)
  {
    output_pid_posi = 100.0;
  }
  else if (output_pid_posi < -100.0)
  {
    output_pid_posi = -100.0;
  }
  pre_error_posi = error_posi;
}

void control_PID_Velocity(PID_control *pid_tune, float setpoint_velo, float Kp, float Ki, float Kd)
{ // velocity vong/phut
  velocity_real = (float)instance_enc.speed_by_encoder * 60.0f / (Ts * Pulseee);
  error_velo = setpoint_velo - (velocity_real);
  instance_enc.velocity = velocity_real;
  pid_tune->P_part = error_velo;
  pid_tune->I_part += error_velo * Ts;
  pid_tune->D_part = (error_velo - pre_error_velo) / Ts;

  output_pid_velo = Kp * (pid_tune->P_part) + Ki * (pid_tune->I_part) + Kd * (pid_tune->D_part);
  if (output_pid_velo > 100.0)
  {
    output_pid_velo = 100.0;
  }
  else if (output_pid_velo < -100.0)
  {
    output_pid_velo = -100.0;
  }
  pre_error_velo = error_velo;
}
