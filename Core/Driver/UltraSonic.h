#ifndef DRIVER_ULTRASONIC_H_
#define DRIVER_ULTRASONIC_H_

#include "main.h"

#define TRUE	1
#define FALSE	0

typedef struct {
	TIM_HandleTypeDef *htim;
	GPIO_TypeDef *Trigger_GPIO_Port;
	uint16_t Trigger_GPIO_Pin;
	uint16_t counterValue;
	uint8_t distReadyFlag;
} UltraSonic_HandleTypeDef;


extern UltraSonic_HandleTypeDef hUS_FrontSensor;
extern UltraSonic_HandleTypeDef hUS_LeftSensor;
extern UltraSonic_HandleTypeDef hUS_RightSensor;


uint8_t US_GetReadyFlag(UltraSonic_HandleTypeDef *hUS_Sensor);
void US_SetReadyFlag(UltraSonic_HandleTypeDef *hUS_Sensor, uint8_t flag);
void US_StartCount(UltraSonic_HandleTypeDef *hUS_Sensor);
void US_ReadCount(UltraSonic_HandleTypeDef *hUS_Sensor);
void US_StartTrigger(UltraSonic_HandleTypeDef *hUS_Sensor);
uint16_t US_GetDistance(UltraSonic_HandleTypeDef *hUS_Sensor);


#endif /* DRIVER_ULTRASONIC_H_ */
