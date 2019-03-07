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
    lcd_init(&app);

    battery_init(&app);

    app.cc1101 = cc1101_open();
    cc1101_set_packet_size(app.cc1101, 10);
    app.active_param = APP_PARAM_CHANNEL;
    app.params.power = CC_Pwr0dBm;
    app.params.channel = 0;

    cc1101_set_channel(app.cc1101, app.params.channel);
    cc1101_set_power(app.cc1101, CC_PwrdBmValue[app.params.power]);

    lcd_set_mode(&app, LCD_MODE_OVERWRITE_INVERTED);
    lcd_printf(&app, 4, 0, "chn: %d", app.params.channel);
    lcd_set_mode(&app, LCD_MODE_OVERWRITE);
    lcd_printf(&app, 5, 0, "pwr:%s", CC_PwrdBmString[app.params.power]);

    button_init(&app);

#if (CLIENT)
    uint8_t data[100];
    int RSSI;
    app.timer = timer_create(0, HAL_APP);

    lcd_printf(&app, 5, 9, "client");
#endif // CLIENT

#if (HOST)
    lcd_printf(&app, 5, 9, "host");
#endif // HOST

    for (;;)
    {
        ipc_read(&ipc);
        switch (HAL_GROUP(ipc.cmd))
        {
#if (CLIENT)
            case HAL_APP:
                if(HAL_ITEM(ipc.cmd) == IPC_TIMEOUT)
                {
                    lcd_printf(&app, 1, 0, "PING..          ");
                    int res = cc1101_receive(app.cc1101, data, 10, CC1101_SET_TIMEOUT_MS(10000), &RSSI);
                    if(res > 0)
                        lcd_printf(&app, 1, 0, "PING.. %d dBm", RSSI);
                    else
                        lcd_printf(&app, 1, 0, "PING...ERR: %d", res);
                    timer_start_ms(app.timer, 5000);
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
