#include "DirControl_Task.h"


void DirControl_Excute(void) {
	if(SmartCar_GetState() == MANUAL_MODE) {
		uint8_t qData;

		if(QisEmpty(&hQue_Ble) == 0) {
			qData = DeQueue(&hQue_Ble);

			if(qData == STOP) Motor_SetState(MOTOR_STOP);
			else if(qData == FORWARD) Motor_SetState(MOTOR_FORWARD);
			else if(qData == BACKWARD) Motor_SetState(MOTOR_BACKWARD);
			else if(qData == LEFT) Motor_SetState(MOTOR_LEFT);
			else if(qData == RIGHT) Motor_SetState(MOTOR_RIGHT);
		}
	}
	else if(SmartCar_GetState() == AUTO_MODE) {
		char buff[100];

		uint16_t frontDistance = DirControl_GetFrontDistance();
		uint16_t LeftDistance = DirControl_GetLeftDistance();
		uint16_t RightDistance = DirControl_GetRightDistance();

		sprintf(buff, "Front Distance: %dcm\n", frontDistance);
		HAL_UART_Transmit(&huart3, buff, strlen(buff), 1000);

		sprintf(buff, "Left Distance: %dcm\n", LeftDistance);
		HAL_UART_Transmit(&huart3, buff, strlen(buff), 1000);

		sprintf(buff, "Right Distance: %dcm\n", RightDistance);
		HAL_UART_Transmit(&huart3, buff, strlen(buff), 1000);

/*		if(LeftDistance > 1000) LeftDistance = 5;
		else if(RightDistance > 1000) RightDistance = 5;
		else if(frontDistance > 1000) frontDistance = 20;*/

		if(LeftDistance > 1000 || RightDistance > 1000 || frontDistance > 1000)
			Motor_SetState(MOTOR_STOP);

		if(frontDistance < 35 || LeftDistance < 7 || RightDistance < 7) {
			// Motor_SetState(MOTOR_STOP);
			SmartCar_SetSpeed(60);

			// if(LeftDistance <= 10 && RightDistance <= 10) Motor_SetState(MOTOR_BACKWARD);
			if(abs((LeftDistance-RightDistance)) <= 2) {
				// SmartCar_SetSpeed(40);
				// EnQueue(&hQue_CarHorn, HORN);
				// Motor_SetState(MOTOR_BACKWARD);
			}
			else if(LeftDistance > RightDistance) Motor_SetState(MOTOR_LEFT);
			else if(LeftDistance < RightDistance) Motor_SetState(MOTOR_RIGHT);
			// else Motor_SetState(MOTOR_BACKWARD);
		} else {
			SmartCar_SetSpeed(90);
			Motor_SetState(MOTOR_FORWARD);
		}

/*		if(frontDistance < 20) {
			SmartCar_SetSpeed(40);
			EnQueue(&hQue_CarHorn, HORN);
			Motor_SetState(MOTOR_BACKWARD);
		}*/
	}
	osDelay(30);
}

uint16_t DirControl_GetFrontDistance() {
	US_StartTrigger(&hUS_FrontSensor);
	while(!US_GetReadyFlag(&hUS_FrontSensor));
	// osDelay(100);
	if(US_GetReadyFlag(&hUS_FrontSensor)) {
		US_SetReadyFlag(&hUS_FrontSensor, FALSE);
		return US_GetDistance(&hUS_FrontSensor);
	}
	return 0xffff;
}

uint16_t DirControl_GetLeftDistance() {
	US_StartTrigger(&hUS_LeftSensor);
	while(!US_GetReadyFlag(&hUS_LeftSensor));
	// osDelay(100);
	if(US_GetReadyFlag(&hUS_LeftSensor)) {
		US_SetReadyFlag(&hUS_LeftSensor, FALSE);
		return US_GetDistance(&hUS_LeftSensor);
	}
	return 0xffff;
}

uint16_t DirControl_GetRightDistance() {
	US_StartTrigger(&hUS_RightSensor);
	while(!US_GetReadyFlag(&hUS_RightSensor));
	// osDelay(100);
	if(US_GetReadyFlag(&hUS_RightSensor)) {
		US_SetReadyFlag(&hUS_RightSensor, FALSE);
		return US_GetDistance(&hUS_RightSensor);
	}
	return 0xffff;
}

uint16_t DirControl_GetDistance(UltraSonic_HandleTypeDef *hUS_Sensor) {
	US_StartTrigger(hUS_Sensor);
	while(!US_GetReadyFlag(hUS_Sensor));

	if(US_GetReadyFlag(hUS_Sensor)) {
		US_SetReadyFlag(hUS_Sensor, FALSE);
		return US_GetDistance(hUS_Sensor);
	}
	return 0xffff;
}
