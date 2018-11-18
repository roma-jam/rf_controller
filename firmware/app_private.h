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

typedef enum {
    HAL_CC1101 = HAL_APP,
} HAL_APP_GROUPS;

typedef enum {
    APP_TIMER_BUTTON_DOUBLE_PRESS = 0x00,
    APP_TIMER_BUTTON_LONG_PRESS,
} APP_TIMER;

typedef struct _APP {
    HANDLE lcd;
    HANDLE cc1101;
    BUTTON button;
} APP;

#endif // APP_PRIVATE_H
