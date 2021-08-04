
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define GPIO_OUTPUT_IO_0    17
#define GPIO_OUTPUT_PIN_SEL  1ULL<<GPIO_OUTPUT_IO_0



void set_pin_17(int mode)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);


    gpio_set_level(GPIO_NUM_17, mode);
    ESP_LOGI("Tey", "set gpio 17 to %d", mode);
    
}