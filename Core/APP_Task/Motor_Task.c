#include "Motor_Task.h"


smartCarEnum smartCarState = MANUAL_MODE;
motorEnum motorState = MOTOR_STOP;

uint8_t speedState = 0;

void SmartCar_SetState(smartCarEnum state) {
	smartCarState = state;
}

smartCarEnum SmartCar_GetState() {
	return smartCarState;
}

void Motor_SetState(motorEnum state) {
	motorState = state;
}

motorEnum Motor_GetState(void) {
	return motorState;
}

void SmartCar_Excute(void) {
	uint8_t qData;

	if(QisEmpty(&hQue_SmartCar) == 0) {
		qData = DeQueue(&hQue_SmartCar);

		if(qData == MANUAL) {
			smartCarState = MANUAL_MODE;
			motorState = MOTOR_STOP;
			LCD_WriteStringXY(0, 0, "Manual Mode!");
		} else if(qData == AUTO) {
			smartCarState = AUTO_MODE;
			LCD_WriteStringXY(0, 0, "Auto Mode!");
		}
	}
}

void Motor_Excute(void) {
	if(QisEmpty(&hQue_CarSpeed) == 0)
		speedState = DeQueue(&hQue_CarSpeed);

	switch(motorState) {
		case MOTOR_STOP:
			SmartCar_Stop();
			break;
		case MOTOR_FORWARD:
			SmartCar_Forward();
			break;
		case MOTOR_BACKWARD:
			SmartCar_Backward();
			break;
		case MOTOR_LEFT:
			SmartCar_Left();
			break;
		case MOTOR_RIGHT:
			SmartCar_Right();
			break;
		default :
			SmartCar_Stop();
			break;
	}
}

void SmartCar_Stop(void) {
	Motor_AllStop();

	if(Button_GetState(&hButton_RunStop))
		motorState = MOTOR_FORWARD;
}

void SmartCar_SetSpeed(uint8_t speed) {
	speedState = speed;
}

void SmartCar_Forward(void) {
	Motor_LeftSpeed(speedState);
	Motor_RightSpeed(speedState);
	Motor_AllForward();

	if(Button_GetState(&hButton_RunStop))
		motorState = MOTOR_STOP;
}

void SmartCar_Backward(void) {
	Motor_LeftSpeed(speedState);
	Motor_RightSpeed(speedState);
	Motor_AllBackward();

	if(Button_GetState(&hButton_RunStop))
		motorState = MOTOR_STOP;
}

void SmartCar_Left(void) {
	Motor_LeftSpeed(speedState);
	Motor_RightSpeed(speedState);
	Motor_LeftBackward();
	Motor_RightForward();

	if(Button_GetState(&hButton_RunStop))
		motorState = MOTOR_STOP;
}

void SmartCar_Right(void) {
	Motor_LeftSpeed(speedState);
	Motor_RightSpeed(speedState);
	Motor_RightBackward();
	Motor_LeftForward();

	if(Button_GetState(&hButton_RunStop))
		motorState = MOTOR_STOP;
}
