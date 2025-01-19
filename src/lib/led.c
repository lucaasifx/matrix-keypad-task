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

bool led_State=false;

void led_action(char key) {
     if (key=='3'){
        if (led_State){
            turn_led_off(LED_RED);
        }else{
            turn_led_on(LED_RED);
        }
        led_State=!led_State;
     }
        
}
