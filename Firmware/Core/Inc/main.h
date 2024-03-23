/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "crc16.h"
#include "uart_proto.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define Ts 0.01
#define Pulseee 1320.0f // 11 xung/vong * 270 (ti so truyen 1:270) *  4 (2 canh xung A va B)
/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENC_TIM2_CH2_Pin GPIO_PIN_1
#define ENC_TIM2_CH2_GPIO_Port GPIOA
#define ENC_TIM2_CH1_Pin GPIO_PIN_5
#define ENC_TIM2_CH1_GPIO_Port GPIOA
#define PWM_TIM1_CH3_Pin GPIO_PIN_13
#define PWM_TIM1_CH3_GPIO_Port GPIOE
#define PWM_TIM1_CH4_Pin GPIO_PIN_14
#define PWM_TIM1_CH4_GPIO_Port GPIOE
#define IN1_Pin GPIO_PIN_8
#define IN1_GPIO_Port GPIOC
#define IN2_Pin GPIO_PIN_9
#define IN2_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
