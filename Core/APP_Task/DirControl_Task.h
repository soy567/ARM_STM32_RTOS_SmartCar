#ifndef APP_TASK_DIRCONTROL_TASK_H_
#define APP_TASK_DIRCONTROL_TASK_H_

#include "main.h"
#include "../APP_Task/Motor_Task.h"
#include "../Driver/UltraSonic.h"
#include "../Driver/Bluetooth.h"


void DirControl_Excute(void);
uint16_t DirControl_GetFrontDistance();
uint16_t DirControl_GetLeftDistance();
uint16_t DirControl_GetRightDistance();
// uint16_t DirControl_GetDistance(UltraSonic_HandleTypeDef *hUS_Sensor);

#endif /* APP_TASK_DIRCONTROL_TASK_H_ */
