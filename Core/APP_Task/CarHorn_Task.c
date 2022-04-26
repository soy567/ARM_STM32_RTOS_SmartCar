#include "CarHorn_Task.h"


void CarHorn_Excute(void) {
	if(QisEmpty(&hQue_CarHorn) == 0) {
		uint8_t carHorn = DeQueue(&hQue_CarHorn);
		CarHorn_MakeSound();
	}
}

void CarHorn_MakeSound(void) {
	for(int i = 0; i < 2; i++) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		osDelay(10);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
		osDelay(10);
	}

	osDelay(10);

	for(int i = 0; i < 2; i++) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		osDelay(70);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
		osDelay(70);
	}
}
