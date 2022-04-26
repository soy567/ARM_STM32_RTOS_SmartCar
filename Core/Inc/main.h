/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os.h"
#include "../Driver/Button.h"
#include "../Driver/DCMotor.h"
#include "../Driver/UltraSonic.h"
#include "../Driver/I2C_LCD.h"
#include "../Common/Queue.h"
#include "../APP_Task/Motor_Task.h"
#include "../APP_Task/DirControl_Task.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

extern osMutexId LcdMutexHandle;
extern osSemaphoreId LcdSemaphoreHandle;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define US_TrigLeft_Pin GPIO_PIN_5
#define US_TrigLeft_GPIO_Port GPIOA
#define US_TrigRight_Pin GPIO_PIN_6
#define US_TrigRight_GPIO_Port GPIOA
#define US_Echo_Pin GPIO_PIN_8
#define US_Echo_GPIO_Port GPIOC
#define US_Echo_EXTI_IRQn EXTI9_5_IRQn
#define US_Trig_Pin GPIO_PIN_9
#define US_Trig_GPIO_Port GPIOC
#define US_EchoRight_Pin GPIO_PIN_11
#define US_EchoRight_GPIO_Port GPIOA
#define US_EchoRight_EXTI_IRQn EXTI15_10_IRQn
#define US_EchoLeft_Pin GPIO_PIN_12
#define US_EchoLeft_GPIO_Port GPIOA
#define US_EchoLeft_EXTI_IRQn EXTI15_10_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
