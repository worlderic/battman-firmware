#include "ch.h"
#include "hal.h"
#include "hw_conf.h"

void gpio_init(void)
{
    // ENABLE GPIO MODULES
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

    //CHARGING CIRCUIT
    palSetPadMode(CHRG_STAT_1_GPIO, CHRG_STAT_1_PIN, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(CHRG_STAT_2_GPIO, CHRG_STAT_2_PIN, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(CHRG_ENABLE_GPIO, CHRG_ENABLE_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(CHRG_ENABLE_GPIO, CHRG_ENABLE_PIN);

    //GPIO
    palSetPadMode(PRECHRG_GPIO, PRECHRG_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(PRECHRG_GPIO, PRECHRG_PIN);
    palSetPadMode(POWER_LED_GPIO, POWER_LED_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(POWER_LED_GPIO, POWER_LED_PIN);
    palSetPadMode(PWR_BTN_NC_GPIO, PWR_BTN_NC_PIN, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(PWR_SW_GPIO, PWR_SW_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palSetPad(PWR_SW_GPIO, PWR_SW_PIN); //keep myself on
    palSetPadMode(LOAD_SW_GPIO, LOAD_SW_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(LOAD_SW_GPIO, LOAD_SW_PIN);
    palSetPadMode(CHRG_DETECT_GPIO, CHRG_DETECT_PIN, PAL_MODE_INPUT_PULLUP);



    // WS2812B
    palSetPadMode(WS2812_SW_GPIO, WS2812_SW_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);

    // USB
    palSetPadMode(USB_DM_GPIO, USB_DM_PIN, PAL_MODE_ALTERNATE(14));
    palSetPadMode(USB_DP_GPIO, USB_DP_PIN, PAL_MODE_ALTERNATE(14));
}
