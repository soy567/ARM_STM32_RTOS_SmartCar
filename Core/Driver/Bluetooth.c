#include "Bluetooth.h"


void BLE_ISR_Process(uint8_t rxData) {
	if(rxData == MANUAL || rxData == AUTO)
		EnQueue(&hQue_SmartCar, rxData);
	else if(SmartCar_GetState() == MANUAL_MODE) {
		if(rxData == STOP || rxData == FORWARD || rxData == BACKWARD
				|| rxData == LEFT || rxData == RIGHT)
			EnQueue(&hQue_Ble, rxData);
		else if((rxData >= '0' && rxData <= '9') || rxData == ';') {
			static char buff[10];
			static uint8_t tail = 0;

			if(rxData == ';') {
				buff[tail] = rxData;
				tail = 0;
				EnQueue(&hQue_CarSpeed, atoi(buff));
			} else {
				buff[tail] = rxData;
				tail++;
			}
		} else if(rxData == HORN) EnQueue(&hQue_CarHorn, rxData);
	}

}
