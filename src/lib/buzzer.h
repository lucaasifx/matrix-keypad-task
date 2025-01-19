#ifndef BUZZER_H
#define BUZZER_H


#define BUZZER01 21
#define BUZZER02 10
// Controle de frequencia do som emitido pelo buzzer
    // maior = mais agudo
    // menor = mais grave
#define FREQUENCY 500


void init_buzzer(uint8_t);
void turn_buzzer_on(uint8_t);
void turn_buzzer_off(uint8_t);
void beep(uint8_t, uint32_t);


#endif