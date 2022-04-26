#include "DCMotor.h"


void Motor_LeftSpeed(uint16_t speed) {
	if(speed == 0)
		// HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	else {
		// HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);
	}
}

void Motor_RightSpeed(uint16_t speed) {
	if(speed == 0)
		// HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	else {
		// HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed);
	}
}

void Motor_LeftForward() {
	// Motor_LeftSpeed(100);
	HAL_GPIO_WritePin(MOTOR_LEFT_A_PORT, MOTOR_LEFT_A_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR_LEFT_B_PORT, MOTOR_LEFT_B_PIN, GPIO_PIN_RESET);
}

void Motor_RightForward() {
	// Motor_RightSpeed(100);
	HAL_GPIO_WritePin(MOTOR_RIGHT_A_PORT, MOTOR_RIGHT_A_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR_RIGHT_B_PORT, MOTOR_RIGHT_B_PIN, GPIO_PIN_RESET);
}

void Motor_LeftBackward() {
	// Motor_LeftSpeed(100);
	HAL_GPIO_WritePin(MOTOR_LEFT_A_PORT, MOTOR_LEFT_A_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_LEFT_B_PORT, MOTOR_LEFT_B_PIN, GPIO_PIN_SET);
}

void Motor_RightBackward() {
	// Motor_RightSpeed(100);
	HAL_GPIO_WritePin(MOTOR_RIGHT_A_PORT, MOTOR_RIGHT_A_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_RIGHT_B_PORT, MOTOR_RIGHT_B_PIN, GPIO_PIN_SET);
}

void Motor_AllForward() {
	Motor_LeftForward();
	Motor_RightForward();
}

void Motor_AllBackward() {
	Motor_LeftBackward();
	Motor_RightBackward();
}

void Motor_LeftStop() {
	Motor_LeftSpeed(0);
}

void Motor_RightStop() {
	Motor_RightSpeed(0);
}

void Motor_AllStop() {
	Motor_LeftStop();
	Motor_RightStop();
}

