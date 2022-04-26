#ifndef DRIVER_BLUETOOTH_H_
#define DRIVER_BLUETOOTH_H_

#include "main.h"
#include "../Common/Queue.h"

#define MANUAL		'm'
#define AUTO		'a'
#define FORWARD		'f'
#define BACKWARD	'b'
#define LEFT		'l'
#define RIGHT		'r'
#define STOP		's'
#define HORN		'h'

void BLE_ISR_Process(uint8_t rxData);


#endif /* DRIVER_BLUETOOTH_H_ */
