/*
 * button.c
 *
 *  Created on: 21 дек. 2017 г.
 *      Author: RLeonov
 */

#include "button.h"
#include "app_private.h"
#include "rexos/userspace/stm32/stm32_driver.h"
#include "rexos/userspace/gpio.h"
#include "rexos/userspace/stdio.h"
#include "rexos/userspace/conv.h"
#include "rexos/midware/pinboard.h"
#include "config.h"
#include "device.h"
#include "lcd.h"

void button_init(APP* app)
{
#if (APP_DEBUG_BUTTON)
#endif // APP_DEBUG_BUTTON
    app->button.pinboard = process_create(&__PINBOARD);
    app->button.pressed = false;
    app->button.timer_double = timer_create(APP_TIMER_BUTTON_DOUBLE_PRESS, HAL_PINBOARD);
    app->button.timer_long = timer_create(APP_TIMER_BUTTON_LONG_PRESS, HAL_PINBOARD);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON0, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON1, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON2, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON3, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
}

static inline void main_button_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main press\n");
#endif // APP_DEBUG_BUTTON

    lcd_printf(app, 2, 0, "BUTTON 0 PRESS ");
}

static inline void main_button_double_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main double press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "BUTTON 0 DOUBLE");
}

static inline void main_button_long_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main long press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "BUTTON 0 LONG  ");
}

static inline void button_left_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: left press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "BUTTON 1 PRESS ");
}

static inline void button_center_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: center press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "BUTTON 2 PRESS ");
}

static inline void button_right_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: right press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "BUTTON 3 PRESS ");
}

static inline void button_down(APP *app, uint8_t button)
{
    switch(button)
    {
        case BUTTON0:
            if(!app->button.pressed)
            {
                timer_start_ms(app->button.timer_long, B_PRESS_LONG_MS);
                app->button.pressed = true;
                return;
            }

            timer_stop(app->button.timer_double, APP_TIMER_BUTTON_DOUBLE_PRESS, HAL_PINBOARD);
            timer_stop(app->button.timer_long, APP_TIMER_BUTTON_LONG_PRESS, HAL_PINBOARD);
            app->button.pressed = false;
            main_button_double_press(app);
            break;
        case BUTTON1:
            button_left_press(app);
            break;
        case BUTTON2:
            button_center_press(app);
            break;
        case BUTTON3:
            button_right_press(app);
            break;
    }
}

static inline void button_up(APP *app, uint8_t button)
{
    if(app->button.pressed)
        timer_start_ms(app->button.timer_double, B_PRESS_MS); // TODO:

    timer_stop(app->button.timer_long, APP_TIMER_BUTTON_LONG_PRESS, HAL_PINBOARD);
}


static inline void button_timeout(APP* app, IPC* ipc)
{
    switch (ipc->param1)
    {
        case APP_TIMER_BUTTON_LONG_PRESS:
            timer_stop(app->button.timer_double, APP_TIMER_BUTTON_DOUBLE_PRESS, HAL_PINBOARD);
            app->button.pressed = false;
            main_button_long_press(app);
            return;

        case APP_TIMER_BUTTON_DOUBLE_PRESS:
            app->button.pressed = false;
            main_button_press(app);
            return;
    }
    error(ERROR_NOT_SUPPORTED);
}

void button_request(APP* app, IPC* ipc)
{
    switch (HAL_ITEM(ipc->cmd))
    {
        case PINBOARD_KEY_DOWN:
            button_down(app, ipc->param1);
            break;

        case PINBOARD_KEY_UP:
            button_up(app, ipc->param1);
            break;

        case IPC_TIMEOUT:
            button_timeout(app, ipc);
            break;

        default:
            error(ERROR_NOT_SUPPORTED);
    }
}
