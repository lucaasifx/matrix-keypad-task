#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "buzzer.h"



void init_buzzer(uint8_t buzzer) {
    gpio_init(buzzer);
    gpio_set_dir(buzzer, GPIO_OUT);
}

void turn_buzzer_on(uint8_t buzzer) {
    gpio_put(buzzer, true);
} 

void turn_buzzer_off(uint8_t buzzer) {
    gpio_put(buzzer, false);
}

void beep(uint8_t buzzer, uint32_t ms) {
    // Calcula o período (em microssegundos) da frequência
    uint32_t period_us = 1000000 / FREQUENCY;  // Tempo de um ciclo completo
    uint32_t half_period_us = period_us / 2;   // Metade do período

    // Calcula o número de ciclos com base na duração
    uint32_t cycles = (ms * 1000) / period_us;

    // Gera o sinal para o número de ciclos
    for (uint32_t i = 0; i < cycles; i++) {
        turn_buzzer_on(buzzer);
        sleep_us(half_period_us);
        turn_buzzer_off(buzzer);
        sleep_us(half_period_us);
    }
}
