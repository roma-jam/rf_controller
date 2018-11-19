/*
 * battery.h
 *
 *  Created on: 19 но€б. 2018 г.
 *      Author: RLeonov
 */

#ifndef BATTERY_H_
#define BATTERY_H_


#include "app.h"
#include "rexos/userspace/types.h"
#include "rexos/userspace/ipc.h"

typedef struct {
    HANDLE timer;
    unsigned int mV;
} BATTERY;

void battery_init(APP* app);
unsigned int battery_get_value(APP* app);
void battery_request(APP* app, IPC* ipc);


#endif /* BATTERY_H_ */
