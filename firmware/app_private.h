/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#ifndef APP_PRIVATE_H
#define APP_PRIVATE_H

#include "app.h"
#include "rexos/userspace/types.h"
#include "rexos/userspace/ipc.h"
#include "device.h"
#include "app_hid.h"
#include "button.h"
#include "battery.h"
#include "cc1101/cc1101.h"

typedef enum {
    APP_PARAM_CHANNEL = 0,
    APP_PARAM_POWER,
    APP_PARAM_MAX
} APP_PARAM;

typedef enum {
    HAL_CC1101 = HAL_APP,
    HAL_BATTERY,
} HAL_APP_GROUPS;

typedef enum {
    APP_TIMER_BUTTON_DOUBLE_PRESS = 0x00,
    APP_TIMER_BUTTON_LONG_PRESS,
    APP_TIMER_ENCODER,
    APP_TIMER_BATTERY,
} APP_TIMER;

typedef struct {
    uint8_t channel;
    CC_POWER_DBM power;
} SYSTEM_PARAMS;

typedef struct _APP {
    HANDLE timer;
    HANDLE lcd;
    HANDLE cc1101;
    BUTTON button;
    BATTERY battery;
    APP_PARAM active_param;
    //
    SYSTEM_PARAMS params;
} APP;

#endif // APP_PRIVATE_H
