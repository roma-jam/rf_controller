/*
 * battery.c
 *
 *  Created on: 19 но€б. 2018 г.
 *      Author: RLeonov
 */

#include "app_private.h"
#include "rexos/userspace/stm32/stm32_driver.h"
#include "rexos/userspace/stdio.h"
#include "rexos/userspace/pin.h"
#include "battery.h"
#include "lcd.h"

static inline void battery_measure(APP* app)
{
    unsigned int value = 0;
    /* get value from ADC */
    for(uint8_t i = 0; i < BATTERY_INTEGRAL_COUNT; i++)
        value += adc_get(BATTERY_CHANNEL, STM32_ADC_SMPR_239_5);

    value /= BATTERY_INTEGRAL_COUNT;

    app->battery.mV = ADC2mV(value, BATTERY_REFERENCE_MV, BATTERY_ADC_RESOLUTION_BIT);
    /* because of resistor divider */
    app->battery.mV <<= 1;
}

void battery_init(APP* app)
{
    app->battery.mV = 0;
    app->battery.timer = timer_create(APP_TIMER_BATTERY, HAL_BATTERY);
    if(app->battery.timer != INVALID_HANDLE)
        timer_start_ms(app->battery.timer, BATTERY_MEASURE_TIMEOUT_MS);

    pin_enable(BATTERY_MEASURE_PIN, STM32_GPIO_MODE_ANALOG, 0);
    adc_open();

    /* first measure */
    battery_measure(app);
    lcd_printf(app, 3, 0, "bat: %d mV  ", app->battery.mV);
}

unsigned int battery_get_value(APP* app)
{
    return app->battery.mV;
}

static inline void battery_timeout(APP* app)
{
#if (APP_DEBUG_BATTERY)
    printf("BATTERY: measuring\n");
#endif // APP_DEBUG_BATTERY
    battery_measure(app);
    timer_start_ms(app->battery.timer, BATTERY_MEASURE_TIMEOUT_MS);
    lcd_printf(app, 3, 0, "bat: %d mV", app->battery.mV);
}

void battery_request(APP* app, IPC* ipc)
{
    switch (HAL_ITEM(ipc->cmd))
    {
        case IPC_TIMEOUT:
            battery_timeout(app);
            break;

        default:
            error(ERROR_NOT_SUPPORTED);
    }
}
