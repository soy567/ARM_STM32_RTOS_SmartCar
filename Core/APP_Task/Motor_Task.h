#ifndef APP_TASK_MOTOR_TASK_H_
#define APP_TASK_MOTOR_TASK_H_

#include "main.h"

typedef enum {MANUAL_MODE, AUTO_MODE} smartCarEnum;
typedef enum {MOTOR_STOP, MOTOR_FORWARD, MOTOR_BACKWARD, MOTOR_LEFT, MOTOR_RIGHT} motorEnum;

void SmartCar_SetState(smartCarEnum state);
smartCarEnum SmartCar_GetState(void);
void Motor_SetState(motorEnum state);
motorEnum Motor_GetState(void);
void SmartCar_Excute(void);
void Motor_Excute(void);
void SmartCar_Stop(void);
void SmartCar_SetSpeed(uint8_t speed);
void SmartCar_Forward(void);
void SmartCar_Backward(void);
void SmartCar_Left(void);
void SmartCar_Right(void);


#endif /* APP_TASK_MOTOR_TASK_H_ */
