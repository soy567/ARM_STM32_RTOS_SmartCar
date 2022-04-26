#include "Button.h"


BUTTON_HandleTypeDef hButton_RunStop = {GPIOC, GPIO_PIN_13, RELEASED};


uint8_t Button_GetState(BUTTON_HandleTypeDef *hButton) {
	uint8_t curState = HAL_GPIO_ReadPin(hButton->GPIO, hButton->GPIO_Pin);

	if ((curState == PUSHED) && (hButton->prevState != PUSHED)) {
		hButton->prevState = PUSHED;
		return FALSE;
	}
	else if ((curState != PUSHED) && (hButton->prevState == PUSHED)) {
		hButton->prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}
