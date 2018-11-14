/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#include "rexos/userspace/stdio.h"
#include "rexos/userspace/stdlib.h"
#include "rexos/userspace/process.h"
#include "rexos/userspace/sys.h"
#include "rexos/userspace/stm32/stm32_driver.h"
#include "rexos/userspace/ipc.h"
#include "rexos/userspace/uart.h"
#include "rexos/userspace/process.h"
#include "rexos/userspace/pin.h"
#include "rexos/userspace/gpio.h"
#include "app_private.h"
#include "checksum.h"
#include "app_usb.h"
#include "app_hid.h"
#include "device.h"
#include "config.h"
#include "led.h"
#include "lcd.h"

void app();

const REX __APP = {
    //name
    "App main",
    //size
    2048,
    //priority
    200,
    //flags
    PROCESS_FLAGS_ACTIVE | REX_FLAG_PERSISTENT_NAME,
    //function
    app
};


static inline void app_setup_dbg()
{
    BAUD baudrate;
    pin_enable(DBG_CONSOLE_TX_PIN, STM32_GPIO_MODE_AF, AF4);
    uart_open(DBG_CONSOLE, UART_MODE_STREAM | UART_TX_STREAM);
    baudrate.baud = DBG_CONSOLE_BAUD;
    baudrate.data_bits = 8;
    baudrate.parity = 'N';
    baudrate.stop_bits= 1;
    uart_set_baudrate(DBG_CONSOLE, &baudrate);
    uart_setup_printk(DBG_CONSOLE);
    uart_setup_stdout(DBG_CONSOLE);
    open_stdout();
}

static inline void app_init(APP* app)
{
#if (APP_DEBUG)
    app_setup_dbg();
    printf("RF Controller, CPU %d MHz\n", power_get_core_clock()/1000000);
    printf("%s\n", __BUILD_TIME);
#endif
}

void app()
{
    APP app;
    IPC ipc;

    app_init(&app);
    checksum_init(&app);
//    device_init(&app);
//    led_init(&app);
//    app_usb_init(&app);
//    app_hid_init(&app);

    lcd_init(&app);

//    app.timer = timer_create(0, HAL_APP);
//    if(app.device.standalone_flag)
//    {
//        /* switch device on */
//        device_set_state(&app, DEVICE_STATE_ON);
//        timer_start_ms(app.timer, app.device.timeout_ms);
//    }

    for (;;)
    {
        ipc_read(&ipc);
        switch (HAL_GROUP(ipc.cmd))
        {
        case HAL_APP:
//            if(HAL_ITEM(ipc.cmd) == IPC_TIMEOUT)
//            {
//                /* toggle twice */
//                device_set_state(&app, (app.device.state == DEVICE_STATE_OFF)? DEVICE_STATE_ON : DEVICE_STATE_OFF);
//                sleep_ms(app.device.delay_ms);
//                device_set_state(&app, (app.device.state == DEVICE_STATE_OFF)? DEVICE_STATE_ON : DEVICE_STATE_OFF);
//                if(app.device.standalone_flag)
//                    timer_start_ms(app.timer, app.device.timeout_ms);
//            }
            break;
        case HAL_USBD:
//            app_usb_request(&app, &ipc);
            break;
        case HAL_USBD_IFACE:
//            app_hid_request(&app, &ipc);
            break;
        default:
#if (APP_DEBUG_ERRORS)
            printf("APP: unhandled IPC group %X\n", HAL_GROUP(ipc.cmd));
#endif // APP_DEBUG_ERRORS
            error(ERROR_NOT_SUPPORTED);
            break;
        }
        ipc_write(&ipc);
    }
}
