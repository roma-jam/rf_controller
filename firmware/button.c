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
#include "rexos/userspace/pin.h"
#include "rexos/userspace/irq.h"
#include "rexos/midware/pinboard.h"
#include "config.h"
#include "device.h"
#include "lcd.h"
#include "cc1101/cc1101.h"

void button_encoder_irq(int vector, void* param)
{
//    APP* app = (APP*)param;
    printk("irq\n");
}

void button_init(APP* app)
{
#if (APP_DEBUG_BUTTON)
#endif // APP_DEBUG_BUTTON
    /* PINBOARD */
    app->button.pinboard = process_create(&__PINBOARD);
    app->button.pressed = false;
    app->button.timer_double = timer_create(APP_TIMER_BUTTON_DOUBLE_PRESS, HAL_PINBOARD);
    app->button.timer_long = timer_create(APP_TIMER_BUTTON_LONG_PRESS, HAL_PINBOARD);
    app->button.encoder_timer = timer_create(APP_TIMER_ENCODER, HAL_PINBOARD);
    /* BITTONS */
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON0, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON1, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON2, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);
    ack(app->button.pinboard, HAL_REQ(HAL_PINBOARD, IPC_OPEN), BUTTON3, PINBOARD_FLAG_DOWN_EVENT | PINBOARD_FLAG_UP_EVENT | PINBOARD_FLAG_PULL | PINBOARD_FLAG_INVERTED, 0);

    /* ENCODER */
    pin_enable(BUTTON_ENCODER_CH1_PIN, STM32_GPIO_MODE_AF, AF4);
    pin_enable(BUTTON_ENCODER_CH2_PIN, STM32_GPIO_MODE_AF, AF4);
    // enable rcc on TIM3
    RCC->APB2ENR |= RCC_APB2ENR_TIM22EN;
    //
    BUTTON_ENCODER_TIM_REG->CCER   = TIM_CCER_CC1P | TIM_CCER_CC2P;
    BUTTON_ENCODER_TIM_REG->CCMR1  = TIM_CCMR1_CC2S_0 | TIM_CCMR1_CC1S_0;
    /* count both edges */
    BUTTON_ENCODER_TIM_REG->SMCR   = TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;
    /* Sampling filter & Prescaler */
    BUTTON_ENCODER_TIM_REG->CCMR1  = TIM_CCMR1_IC1PSC | TIM_CCMR1_IC1F | TIM_CCMR1_IC2PSC | TIM_CCMR1_IC2F;

    BUTTON_ENCODER_TIM_REG->ARR    = 100;
    BUTTON_ENCODER_TIM_REG->CNT    = 50;
    BUTTON_ENCODER_TIM_REG->CR1    = TIM_CR1_CEN;
    BUTTON_ENCODER_TIM_REG->DIER   = TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_UIE;

    irq_register(TIM22_IRQn, button_encoder_irq, (void*)app);
    NVIC_EnableIRQ(TIM22_IRQn);

    timer_start_ms(app->button.encoder_timer, 1000);

}

static inline void main_button_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main press\n");
#endif // APP_DEBUG_BUTTON

    lcd_printf(app, 2, 0, "1 x 0");
}

static inline void main_button_double_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main double press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "2 x 0");
}

static inline void main_button_long_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main long press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "L x 0");
}

static inline void button_left_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: left press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "1 x 1");

#if (HOST)
    uint8_t packet[5] = {0};
    lcd_printf(app, 1, 0, "Radio ping..");
    /* send packet by radio */
    if(cc1101_transmit(app->cc1101, packet, 5))
        lcd_printf(app, 1, 0, "Radio ping..SEND");
    else
        lcd_printf(app, 1, 0, "Radio ping..FAIL");
#endif // HOST

#if (CLIENT)
    timer_start_ms(app->timer, 1000);
    lcd_printf(app, 1, 0, "PING..          ");
#endif
}

static inline void button_center_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: center press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "1 x 2");
}

static inline void button_right_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: right press\n");
#endif // APP_DEBUG_BUTTON
    lcd_printf(app, 2, 0, "1 x 3");
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

        case APP_TIMER_ENCODER:
            lcd_printf(app, 2, 7, "enc: %d\n", BUTTON_ENCODER_TIM_REG->CNT);
            printf("BUTTON: encoder value %d\n", BUTTON_ENCODER_TIM_REG->CNT);
            timer_start_ms(app->button.encoder_timer, 1000);
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
