/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "crc16.h"
#include "encoder.h"
#include "PID.h"
#include "PWM.h"
#include "uart_proto.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

/* USER CODE BEGIN PV */

float output_pid, output_pid_velo, output_pid_posi;
float error_posi = 0, pre_error_posi = 0;
float error_velo = 0, pre_error_velo = 0;
float now_position, velocity_real, number_rotation;
float Kp_true, Ki_true, Kd_true;
float setpointQt = 0;

uint8_t transmittedData[10];
uint8_t lastTransmittedData;
float now_position1 = 1;
uint8_t checkModeFromQt = 0;
uint8_t count_PID = 0;
uint8_t countUpdate = 0;
uint8_t check_status;
uint8_t data_rx = 0;
uint8_t data_uart[50] = {0};
uint8_t data_after_cut[PROTO_DATA_SIZE_RX];
uint8_t uart_count = 0;
uint16_t frame_tx_lenght;
uint16_t get_data_lenght;

bool count_PID_position_first_time = true;
bool data_check = true;
bool flag_motor= false;   //enable motor if flag is true
bool uart_flag = false;

typedef enum
{
  Select_Velo,
  Select_Posi,
} Select_Tune;
typedef enum
{
  Select_PID1 = 2,
  Select_PID2,
} Select_PID;
Select_PID choose_PID;
typedef enum
{
	MODE_POSI = 1,
	MODE_VELO,
} Select_mode_Qt;
typedef enum
{
	PARA_K = 0x11,
	SET_POSI = 0x22,
	SET_VELO = 0x33,
	RESETT = 0x44,
	ENABLEE = 0x55,
	CHOOSE = 0x88,
} Para_from_Qt;

uart_proto_handle_t uart_handle;
instance_encoder instance_enc;
PID_control PID_contr;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void tune_PID_after1(Select_Tune select);
void tune_PID_after2(Select_Tune select);
void send_data_to_Qt();
void condition_of_flag();

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_UART_Receive_IT(&huart2, &data_rx, 1);   // 57600!
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  data_check = true;
	  if (uart_flag == true)
	      {
	        memset(data_after_cut, 0, sizeof(data_after_cut));
	        memcpy(uart_handle.au8RxBuffer, (uint8_t *)data_uart, uart_count);
	        check_status = UART_get_data(uart_handle.au8RxBuffer, uart_count, data_after_cut, &get_data_lenght); // After this function data_after_cut will contain the data bytes of Kp Ki Kd                                                                                                           //     char message[] = {0};
	        if (check_status == no_valid || check_status == false_CRC ||
	        	check_status == buffer_small || check_status == false_lenght_data)
	        {
	          data_check = false;
	        }
	        if (data_check == true)
	        {
	        	condition_of_flag();
	        }
	        memset(data_uart, 0, uart_count);
	        uart_flag = false;
	        uart_count = 0;
	      }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1679;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 999;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1679;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 57600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, IN1_Pin|IN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : IN1_Pin IN2_Pin */
  GPIO_InitStruct.Pin = IN1_Pin|IN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void tune_PID_after1(Select_Tune select)
{
  switch (select)
  {
  case Select_Posi:
    control_PID_Position(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);
    output_pid = output_pid_posi;
    PWM_control_position(&htim1, output_pid);
    break;
  case Select_Velo:
    control_PID_Velocity(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);
    output_pid = output_pid_velo;
    PWM_control_velocity(&htim1, output_pid);
    break;
  default:
    break;
  }
}

void tune_PID_after2(Select_Tune select)
{
  switch (select)
  {
  case Select_Posi:
    if (count_PID_position_first_time == true)
    {
      control_PID_Position(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);      // in degrees, calculated at the first time the engine has been run only once
      control_PID_Velocity(&PID_contr, output_pid_posi, Kp_true, Ki_true, Kd_true); // setpoint speed equal output position
      output_pid = output_pid_velo;
      PWM_control_position(&htim1, output_pid);
      count_PID_position_first_time = false;
      break;
    }
    if (count_PID == 3) // 3 times speed PID -> 1 time position PID
    {
      control_PID_Position(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);      // recalculate new output_pid_posi
      control_PID_Velocity(&PID_contr, output_pid_posi, Kp_true, Ki_true, Kd_true); // setpoint speed equal output position
      output_pid = output_pid_velo;
      PWM_control_position(&htim1, output_pid);
      count_PID = 0;
      break;
    }
    else if (count_PID != 3)
    {
      control_PID_Velocity(&PID_contr, output_pid_posi, Kp_true, Ki_true, Kd_true); // setpoint speed equal output position
      output_pid = output_pid_velo;
      PWM_control_position(&htim1, output_pid);
      break;
    }
  case Select_Velo:
    control_PID_Velocity(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);
    output_pid = output_pid_velo; // uniformity to output_pid for easy control
    PWM_control_velocity(&htim1, output_pid);
    break;
  default:
    break;
  }
}

void send_data_to_Qt()
{
  if (checkModeFromQt == MODE_POSI && flag_motor == true)
  {
    char float_to_char[sizeof(float)];
    char mode = 0x66;
    memcpy(float_to_char, &now_position, sizeof(float));
    uint8_t *array_data;
    array_data = (uint8_t *)malloc(5);
    uint8_t index = 0;
    memcpy(array_data + index, &mode, 1); // Mode 0x66, if 0x66 ->position
    index += 1;
    memcpy(array_data + index, float_to_char, 4);

    UART_frame_data(array_data, PROTO_DATA_SIZE_TX, uart_handle.au8TxBuffer, &frame_tx_lenght);
    HAL_UART_Transmit_DMA(&huart2, uart_handle.au8TxBuffer, frame_tx_lenght);
    free(array_data);
  }
  else if (checkModeFromQt == MODE_VELO && flag_motor == true)
  {
    char float_to_char[sizeof(float)];
    char mode = 0x77;
    memcpy(float_to_char, &velocity_real, sizeof(float));
    uint8_t *array_data;
    array_data = (uint8_t *)malloc(5);
    uint8_t index = 0;
    memcpy(array_data + index, &mode, 1); // Mode 0x77, if 0x77 ->velocity
    index += 1;
    memcpy(array_data + index, float_to_char, 4);
    UART_frame_data(array_data, PROTO_DATA_SIZE_TX, uart_handle.au8TxBuffer, &frame_tx_lenght);
    HAL_UART_Transmit_DMA(&huart2, uart_handle.au8TxBuffer, frame_tx_lenght);
    free(array_data);
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM3)
  {
    encoder();
  }
  if (checkModeFromQt == MODE_POSI && flag_motor == true && choose_PID == Select_PID1)
  {
    tune_PID_after1(Select_Posi);
  }
  else if (checkModeFromQt == MODE_VELO && flag_motor == true && choose_PID == Select_PID1)
  {
    tune_PID_after1(Select_Velo);
  }

  else if (checkModeFromQt == MODE_POSI && flag_motor == true && choose_PID == Select_PID2)
  {
        count_PID++;
    tune_PID_after2(Select_Posi);
  }
  else if (checkModeFromQt == MODE_VELO && flag_motor == true && choose_PID == Select_PID2)
  {
    tune_PID_after2(Select_Velo);
  }
  send_data_to_Qt();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART2)
  {
    if (data_rx == PROTO_END_BYTE)
    {
      data_uart[uart_count++] = data_rx;
      uart_flag = true; // complete
    }
    else
    {
      data_uart[uart_count] = data_rx;
      uart_count++;
    }
    HAL_UART_Receive_IT(&huart2, (uint8_t *)&data_rx, 1);
  }
}

void condition_of_flag()
{
	while (1) // if in here <=> receive right data
	  {
		if (data_after_cut[0] == SET_POSI) //
		{
		  setpointQt = *((float *)(data_after_cut + 1));
		  checkModeFromQt = MODE_POSI; // position
		  break;
		}
		else if (data_after_cut[0] == SET_VELO) //
		{
		  setpointQt = *((float *)(data_after_cut + 1));
		  checkModeFromQt = MODE_VELO; // velocity
		  break;
		}
		else if (data_after_cut[0] == ENABLEE)
		{
		  flag_motor = true;
		  break;
		}
		else if (data_after_cut[0] == PARA_K)
		{
		  Kp_true = *((float *)(data_after_cut + 1));
		  Ki_true = *((float *)(data_after_cut + 5));
		  Kd_true = *((float *)(data_after_cut + 9));
		  break;
		}
		else if (data_after_cut[0] == CHOOSE) // choose mode PID1 or PID2
		{
		  float floatData;
		  memcpy(&floatData, data_after_cut + 1, sizeof(float));
		  if (floatData == 1.0f)
		  {
			choose_PID = Select_PID1;
			break;
		  }
		  else if (floatData == 2.0f)
		  {
			choose_PID = Select_PID2;
			break;
		  }
		  else
		  {
			break;
		  }
		}
		else if (data_after_cut[0] == RESETT)
		{
		  Kp_true = Ki_true = Kd_true = 0; // Reset
		  htim2.Instance->CNT = 0;
		  instance_enc.position = 0;
		  instance_enc.speed_by_encoder = 0;
		  setpointQt = 0;
		  if (checkModeFromQt == MODE_POSI)
		  {
			control_PID_Position(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);
		  }
		  else if (checkModeFromQt == MODE_VELO)
		  {
			control_PID_Velocity(&PID_contr, setpointQt, Kp_true, Ki_true, Kd_true);
		  }
		  output_pid = 0;
		  HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET); // force silence motor and stop motor
		  HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
		  checkModeFromQt = 0;
		  flag_motor = false;
		  break;
		}
	  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
