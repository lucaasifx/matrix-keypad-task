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

void blink_led(uint8_t LED, uint32_t ms) {
    turn_led_on(LED);
    sleep_ms(ms);
    turn_led_off(LED);
} 

// **********************************************************

void led_action(char key) {
    static bool is_blinking = false;

    if (key == '6') {
        if (is_blinking) {
            is_blinking = false;
            turn_led_off(LED_RED);
        } else {
            is_blinking = true;
            while (is_blinking) {
                blink_led(LED_RED, 500);
                sleep_ms(500);

                char pressed_key = pico_keypad_get_key();
                if (pressed_key == '6') {
                    is_blinking = false;
                    turn_led_off(LED_RED);
                    break;
                }
            }
        }
    }
}


