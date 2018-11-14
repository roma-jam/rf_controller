/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#ifndef CONFIG_H
#define CONFIG_H

#define VERSION                                     "0.1b"

// ============================= BUTTONS ======================================
#define BUTTON0                                     A0
#define BUTTON1                                     A10
#define BUTTON2                                     A11
#define BUTTON3                                     A12

#define B_PRESS_MS                                  350
#define B_PRESS_LONG_MS                             1000

// =============================== PINs =======================================
#define DEVICE_POWER_PIN1                           A0
#define DEVICE_POWER_PIN2                           A1
#define DEVICE_DATA_PIN1                            B7
#define DEVICE_DATA_PIN2                            B8

#define DEVICE_DEAFULT_DELAY_MS                     200
#define DEVICE_TEST_TIMEOUT_MS                      300

// =============================== LEDS ========================================
#define LED_COUNT                                   4
#define LED_RED_PIN                                 A1
#define LED_BLUE_PIN                                A2
#define LED_ORANGE_PIN                              A15

#define LED_MAX_BRIGHT                              0xFF
#define LED_BLINK_FREQ_HZ                           25
#define LED_BLINK_TIMES                             3

#define LED_TIM_REG                                 TIM2
#define LED_TIM                                     TIM_2
#define LED_RED_CHANNEL                             TIM_CHANNEL2
#define LED_BLUE_CHANNEL                            TIM_CHANNEL3
#define LED_ORANGE_CHANNEL                          TIM_CHANNEL4

#define LED_BLINK_TIM_REG                           TIM3
#define LED_BLINK_TIM                               TIM_3
#define LED_BLINK_TIM_CHANNEL                       TIM_CHANNEL1
#define LED_BLINK_IRQ_VECTOR                        TIM3_IRQn

// ================================ LCD ========================================
#define LCD_DOT_FULL                                0x07
#define LCD_DOT_EMPTY                               0x09
#define LCD_BITBYTE                                 1
#define LCD_SPI                                     0

#define LCD_UPDATE_MS                               200
#define LCD_WIDTH                                   84
#define LCD_HEIGHT                                  48

#define LCD_STR_HEIGHT                              8
#define LCD_STR_WIDTH                               16

/* PINS */
#define LCD_BCKLT_PIN                               B0
#define LCD_RESET_PIN                               B1
#define LCD_CE_PIN                                  B2
#define LCD_SCLK_PIN                                B3
#define LCD_DC_PIN                                  B6
#define LCD_DIN_PIN                                 B7

// =============================== USB =========================================
#define USB_PORT_NUM                                USB_0
#define USBD_PROCESS_SIZE                           1200
#define USBD_PROCESS_PRIORITY                       150

// ============================== CCID  ========================================
#define USB_CCID_INTERFACE                          0
#define USB_HID_INTERFACE                           0

// =============================== COMM ========================================
#define COMM_COMMAND_END                            0x0D

// ================================= DEBUG =====================================

#define DBG_CONSOLE                                 UART_1
#define DBG_CONSOLE_TX_PIN                          A9
#define DBG_CONSOLE_BAUD                            115200

#define TEST_ROUNDS                                 10000

#define APP_DEBUG                                   1
#define APP_DEBUG_ERRORS                            1

#define APP_DEBUG_USB                               0
#define APP_DEBUG_HID                               0
#define APP_DEBUG_DEVICE                            1
#define APP_DEBUG_LCD                               1
#define APP_DEBUG_BUTTON                            1

#endif // CONFIG_H
