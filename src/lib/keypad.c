#include "keypad.h"
#include "pico/stdlib.h"

#define ROWS 4
#define COLS 4

static const uint8_t row_pins[ROWS] = {8, 7, 6, 5};
static const uint8_t col_pins[COLS] = {4, 3, 2, 1};

static const char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void init_keypad() {
    for (int row = 0; row < ROWS; row++) {
        gpio_init(row_pins[row]);
        gpio_set_dir(row_pins[row], GPIO_OUT);
        gpio_put(row_pins[row], 0);
    }

    for (int col = 0; col < COLS; col++) {
        gpio_init(col_pins[col]);
        gpio_set_dir(col_pins[col], GPIO_IN);
        gpio_pull_up(col_pins[col]);
    }
}

char get_key() {
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 1);
        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col]) == 0) {
                gpio_put(row_pins[row], 0);
                return keys[row][col];
            }
        }
        gpio_put(row_pins[row], 0);
    }
    return NO_KEY;
}
