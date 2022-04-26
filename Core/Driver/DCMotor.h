#ifndef DRIVER_DCMOTOR_H_
#define DRIVER_DCMOTOR_H_

#include "main.h"

#define MOTOR_LEFT_A_PORT	GPIOC
#define MOTOR_LEFT_B_PORT	GPIOC
#define MOTOR_LEFT_A_PIN	GPIO_PIN_0
#define MOTOR_LEFT_B_PIN	GPIO_PIN_1

#define MOTOR_RIGHT_A_PORT	GPIOC
#define MOTOR_RIGHT_B_PORT	GPIOC
#define MOTOR_RIGHT_A_PIN	GPIO_PIN_2
#define MOTOR_RIGHT_B_PIN	GPIO_PIN_3

void Motor_LeftSpeed(uint16_t speed);
void Motor_RightSpeed(uint16_t speed);
void Motor_LeftForward();
void Motor_RightForward();
void Motor_LeftBackward();
void Motor_RightBackward();
void Motor_AllForward();
void Motor_AllBackward();
void Motor_LeftStop();
void Motor_RightStop();
void Motor_AllStop();


#endif /* DRIVER_DCMOTOR_H_ */
