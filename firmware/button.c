/*
 * button.c
 *
 *  Created on: 21 ���. 2017 �.
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

static void button_set_encoder(APP* app, unsigned int max_counter, unsigned int current)
{
    /* max counter value * 2 in case of accuracy */
    BUTTON_ENCODER_TIM_REG->ARR    = (max_counter << 1) - 1;
    /* current value * 2 in case of accuracy */
    BUTTON_ENCODER_TIM_REG->CNT    = current << 1;
}

static unsigned int button_get_encoder_value()
{
    /* current value div 2 */
    return (BUTTON_ENCODER_TIM_REG->CNT >> 1);
}

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
//    BUTTON_ENCODER_TIM_REG->SMCR   = TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;
    BUTTON_ENCODER_TIM_REG->SMCR   = TIM_SMCR_SMS_0;
    /* Sampling filter & Prescaler */
    BUTTON_ENCODER_TIM_REG->CCMR1  = TIM_CCMR1_IC1PSC | TIM_CCMR1_IC1F | TIM_CCMR1_IC2PSC | TIM_CCMR1_IC2F;

    BUTTON_ENCODER_TIM_REG->CR1    = TIM_CR1_CEN;

//    BUTTON_ENCODER_TIM_REG->DIER   = TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_UIE;

    irq_register(TIM22_IRQn, button_encoder_irq, (void*)app);
//    NVIC_EnableIRQ(TIM22_IRQn);

    timer_start_ms(app->button.encoder_timer, BUTTON_ENCODER_TIMEOUT_MS);

    /* channel is selected by default */
    button_set_encoder(app, CC_MAX_CHANNELS, app->params.channel);
}



static inline void main_button_press(APP* app)
{
#if (APP_DEBUG_BUTTON)
    printf("BUTTON: main press\n");
#endif // APP_DEBUG_BUTTON

    lcd_printf(app, 2, 0, "1 x 0");


#if (HOST)
    uint8_t packet[10] = {0};
//    packet[0] = 0xAA;
//    packet[1] = 0xFF;
//    packet[2] = 0x01;
//    packet[3] = 0x20;
//    packet[4] = 0x80;
//    packet[5] = 0x2F;
//    packet[6] = 0xFE;
//    packet[7] = 0x11;
//    packet[8] = 0x22;
//    packet[9] = 0x33;

    packet[0] = 0xAA;
    packet[1] = 0xFF;
    packet[2] = 0xAA;
    packet[3] = 0xFF;
    packet[4] = 0xAA;
    packet[5] = 0xFF;
    packet[6] = 0xAA;
    packet[7] = 0xFF;
    packet[8] = 0xAA;
    packet[9] = 0xFF;


    lcd_printf(app, 1, 0, "Radio ping..");
    /* send packet by radio */
    if(cc1101_transmit(app->cc1101, packet, 10))
        lcd_printf(app, 1, 0, "Radio ping..SEND");
    else
        lcd_printf(app, 1, 0, "Radio ping..FAIL");
#endif // HOST

#if (CLIENT)
    timer_start_ms(app->timer, 5000);
#endif
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

    /* clear current param selection */
    lcd_set_mode(app, LCD_MODE_OVERWRITE);
    lcd_printf(app, 4, 0, "chn: %d", app->params.channel);
    lcd_printf(app, 5, 0, "pwr:%s", CC_PwrdBmString[app->params.power]);

    /* change active param */
    app->active_param++;
    if(app->active_param >= APP_PARAM_MAX)
        app->active_param = APP_PARAM_CHANNEL;

    lcd_set_mode(app, LCD_MODE_OVERWRITE_INVERTED);
    switch(app->active_param)
    {
        case APP_PARAM_CHANNEL:
            button_set_encoder(app, CC_MAX_CHANNELS, app->params.channel);
            lcd_printf(app, 4, 0, "chn: %d", app->params.channel);
            break;

        case APP_PARAM_POWER:
            button_set_encoder(app, CC_PwrMax, app->params.power);
            lcd_printf(app, 5, 0, "pwr:%s", CC_PwrdBmString[app->params.power]);
            break;

        default:
            break;
    }

    lcd_set_mode(app, LCD_MODE_OVERWRITE);
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

static inline void encoder_verify_changes(APP* app)
{
    uint8_t value = button_get_encoder_value();
//    lcd_printf(app, 2, 7, "enc: %d\n", value);
    // TODO: temporary thing
    switch(app->active_param)
    {
        case APP_PARAM_CHANNEL:
            if(app->params.channel != value)
            {
                /* clean if new value < previous */
                lcd_set_mode(app, LCD_MODE_OVERWRITE_INVERTED);
                if((value / 10))
                    lcd_printf(app, 4, 0, "chn:%d", value);
                else
                    lcd_printf(app, 4, 0, "chn: %d", value);
                /* print new value */
                lcd_set_mode(app, LCD_MODE_OVERWRITE);
                /* set new value */
                app->params.channel = value;
                cc1101_set_channel(app->cc1101, app->params.channel);
            }
            break;

        case APP_PARAM_POWER:
            if(app->params.power != value)
            {
                /* set new value */
                app->params.power = value;
                /* print new value */
                lcd_set_mode(app, LCD_MODE_OVERWRITE_INVERTED);
                lcd_printf(app, 5, 0, "pwr:%s", CC_PwrdBmString[app->params.power]);
                lcd_set_mode(app, LCD_MODE_OVERWRITE);
                /* set new value */
                cc1101_set_power(app->cc1101, CC_PwrdBmValue[app->params.power]);
            }
            break;

        default:
            break;
    }
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
            encoder_verify_changes(app);
            timer_start_ms(app->button.encoder_timer, BUTTON_ENCODER_TIMEOUT_MS);
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
