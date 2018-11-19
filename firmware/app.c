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
#include "config.h"
#include "button.h"
#include "lcd.h"

#include "cc1101/cc1101.h"

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
    button_init(&app);
    lcd_init(&app);
    battery_init(&app);
    app.cc1101 = cc1101_open();

    cc1101_set_packet_size(app.cc1101, 5);
    cc1101_set_channel(app.cc1101, 0);
    cc1101_set_power(app.cc1101, CC_PwrMinus10dBm);

    lcd_printf(&app, 4, 0, "chn: %d", 0);
    lcd_printf(&app, 5, 0, "pwr: 0x%X", CC_PwrMinus10dBm);

    // TODO: remove me
    sleep_ms(100);
    process_info();

#if (CLIENT)
    uint8_t data[100];
    int RSSI;
    app.timer = timer_create(0, HAL_APP);
#endif // CLIENT

    for (;;)
    {
        ipc_read(&ipc);
        switch (HAL_GROUP(ipc.cmd))
        {
#if (CLIENT)
            case HAL_APP:
                if(ipc.param1 == IPC_TIMEOUT)
                {
                    if(cc1101_receive(app.cc1101, data, 5, CC1101_FLAGS_NO_TIMEOUT, &RSSI) > 0)
                        lcd_printf(&app, 1, 0, "PING, %d dBm", RSSI);
                    else
                        lcd_printf(&app, 1, 0, "PING...FAILURE");
                }
                break;
#endif // CLIENT
            case HAL_PINBOARD:
                button_request(&app, &ipc);
                break;
            case HAL_BATTERY:
                battery_request(&app, &ipc);
                break;
            default:
#if (APP_DEBUG_ERRORS)
                printf("APP: unhandled IPC group %X, ITEM: %X\n", HAL_GROUP(ipc.cmd), HAL_ITEM(ipc.cmd));
#endif // APP_DEBUG_ERRORS
                error(ERROR_NOT_SUPPORTED);
                break;
        }
        ipc_write(&ipc);
    }
}
