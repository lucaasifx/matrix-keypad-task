#include "pico/stdlib.h"
#include "led.h"

// *********************** Lib padrao ***********************

void init_led(uint8_t LED) {
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
}

void turn_led_on(uint8_t LED) {
    gpio_put(LED, true);
}

void turn_led_off(uint8_t LED) {
    gpio_put(LED, false);
}

void blink_led(uint8_t LED, uint32_t ms, uint8_t cycles) {
    for(int i = 0; i < cycles; i++) {
        turn_led_on(LED);
        sleep_ms(ms);
        turn_led_off(LED);
        sleep_ms(ms);
    }
}

// **********************************************************


void led_action(char key) {

    if (key == '3'){
        if (gpio_get(LED_RED)){
            turn_led_off(LED_RED);
        }else{
            turn_led_on(LED_RED);
        }
    }
    if (key == '4') {
        blink_led(LED_GREEN, 1000, 3);
    }
    if (key == '6') {
        blink_led(LED_RED, 1000, 3);
    }
}
