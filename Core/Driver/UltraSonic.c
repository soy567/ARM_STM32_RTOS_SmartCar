#include "UltraSonic.h"


UltraSonic_HandleTypeDef hUS_FrontSensor = {&htim3, GPIOC, GPIO_PIN_9, 0, 0};
UltraSonic_HandleTypeDef hUS_LeftSensor = {&htim3, GPIOA, GPIO_PIN_5, 0, 0};
UltraSonic_HandleTypeDef hUS_RightSensor = {&htim3, GPIOA, GPIO_PIN_6, 0, 0};


uint8_t US_GetReadyFlag(UltraSonic_HandleTypeDef *hUS_Sensor) {
	return hUS_Sensor->distReadyFlag;
}

void US_SetReadyFlag(UltraSonic_HandleTypeDef *hUS_Sensor, uint8_t flag) {
	hUS_Sensor->distReadyFlag = flag;
}

void US_StartCount(UltraSonic_HandleTypeDef *hUS_Sensor) {
	// timer = 0
	__HAL_TIM_SET_COUNTER(hUS_Sensor->htim, 0);
	HAL_TIM_Base_Start(hUS_Sensor->htim);
}

void US_ReadCount(UltraSonic_HandleTypeDef *hUS_Sensor) {
	// Read timer
	// htim3->Instance->CNT	(Direct approaching)
	hUS_Sensor->counterValue = __HAL_TIM_GET_COUNTER(hUS_Sensor->htim);
	US_SetReadyFlag(hUS_Sensor, TRUE);
}

void US_StartTrigger(UltraSonic_HandleTypeDef *hUS_Sensor) {
	// Start Trigger
	HAL_GPIO_WritePin(hUS_Sensor->Trigger_GPIO_Port, hUS_Sensor->Trigger_GPIO_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(hUS_Sensor->Trigger_GPIO_Port, hUS_Sensor->Trigger_GPIO_Pin, GPIO_PIN_RESET);
}

uint16_t US_GetDistance(UltraSonic_HandleTypeDef *hUS_Sensor) {
	return (hUS_Sensor->counterValue * 0.17);
}
