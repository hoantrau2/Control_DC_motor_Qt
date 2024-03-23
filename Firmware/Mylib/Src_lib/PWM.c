/*
 * PWM.c
 *
 *  Created on: Dec 2, 2023
 *      Author: lehuu
 */

#include "PWM.h"
void PWM_control_velocity(TIM_HandleTypeDef *htim, float duty)
{
  if (duty > 0)
  {
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_RESET);
    htim1.Instance->CCR3 = (duty) * (htim1.Instance->ARR) / 100;
  }
  else if (duty < 0)
  {
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
    htim1.Instance->CCR3 = (-duty) * (htim1.Instance->ARR) / 100;
  }
  else
  {
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
  }
}

void PWM_control_position(TIM_HandleTypeDef *htim, float duty)
{
  if (duty > 0)
  {
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_RESET);
    htim1.Instance->CCR3 = (duty) * (htim1.Instance->ARR) / 100;
  }
  else if (duty < 0)
  {
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
    htim1.Instance->CCR3 = (-duty) * (htim1.Instance->ARR) / 100;
  }
  else
  {
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
  }
}
