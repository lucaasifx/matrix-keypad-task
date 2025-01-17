#include "pico/stdlib.h"
#include "led.h"

<<<<<<< Updated upstream
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

}


=======
// função de exemplo
void initialize_led(uint8_t led) {
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
}

void led_on(uint8_t led){
    gpio_put(led,true);
}

void led_off(uint8_t led){
    gpio_put(led,false);
}

void led_action(char key){
    if (key=='1')
    {
        led_on(LED_GREEN);
    }else
    {
        led_off(LED_GREEN);
    }
}

>>>>>>> Stashed changes
