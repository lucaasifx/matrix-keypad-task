#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

// libs
#include "lib/led.h"
#include "lib/keypad.h"

#define DEBOUNCE_TIME 200 // tempo de debounce em ms

int main() {
    stdio_init_all();
    init_led(LED_GREEN);
    init_keypad();

    while (true) {
        char key = NO_KEY; // Inicializando a variável key
        key = get_key();
        if (key != NO_KEY) {
            led_action(key);
            sleep_ms(DEBOUNCE_TIME);
        }
        sleep_ms(10); // para evitar alto uso de CPU
    }
}
