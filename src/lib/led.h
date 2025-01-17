#ifndef LED_H
#define LED_H


#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13

<<<<<<< Updated upstream
// funções padrão
void init_led(uint8_t);
void turn_led_on(uint8_t);
void turn_led_off(uint8_t);
void blink_led(uint8_t, uint32_t);

// tarefa
=======
// função de exemplo
void initialize_led(uint8_t);
void led_on(uint8_t);
void led_off(uint8_t);
>>>>>>> Stashed changes
void led_action(char);

#endif