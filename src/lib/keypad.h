#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include <stdbool.h>

#define BUTTON_COUNT 16

typedef struct {
    uint8_t buttons[BUTTON_COUNT];
    uint8_t gpio_column[4];
    uint8_t gpio_rows[4];
} Keypad;

void keypad_init(Keypad *keypad);
char keypad_get_key(Keypad *keypad);



#endif