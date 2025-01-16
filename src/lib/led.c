#include "pico/stdlib.h"
#include "led.h"

// função de exemplo
void initialize_led(uint8_t led) {
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
}