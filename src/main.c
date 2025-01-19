#include "pico/stdlib.h"
#include"hardware/pwm.h"
#include <stdio.h>

// libs
#include "lib/led.h"
#include "lib/buzzer.h"
#include "lib/keypad.h"

void turn_off_all_leds() {
    turn_led_off(LED_GREEN);
    turn_led_off(LED_BLUE);
    turn_led_off(LED_RED);
}

int main() {
    stdio_init_all();

    //inicializa o keypad
    Keypad keypad;
    init_keypad(&keypad);
    
    // inicializa os leds
    init_led(LED_GREEN);
    init_led(LED_BLUE);
    init_led(LED_RED);

    //inicializa o buzzer
    init_buzzer(BUZZER01);

    while(true) {
        char pressed_key = keypad_get_key(&keypad);
        if(pressed_key)
            printf("Tecla pressionada: %c\n", pressed_key);
        
        if(pressed_key >= '1' && pressed_key <= '6') {
            turn_off_all_leds();
            led_action(pressed_key);
        } else if(pressed_key == 'B') {
            beep(BUZZER01, 1000);
        }
    }

}
