#include "keypad.h"
#include "pico/stdlib.h"
#include <stdio.h>


void keypad_init(Keypad *keypad) {

    const char key_map[] = {
        '1', '2', '3', 'A',
        '4', '5', '6', 'B',
        '7', '8', '9', 'C',
        '*', '0', '#', 'D'
    };
    const uint8_t columns[] = {17, 18, 19, 20};
    const uint8_t rows[] = {4, 8, 9, 16};

    for (int i = 0; i < 4; i++) {
        gpio_init(keypad->gpio_column[i] = columns[i]);
        gpio_set_dir(keypad->gpio_column[i], GPIO_OUT);
        gpio_put(keypad->gpio_column[i], 1);

        gpio_init(keypad->gpio_rows[i] = rows[i]);
        gpio_set_dir(keypad->gpio_rows[i], GPIO_IN);
        gpio_pull_up(keypad->gpio_rows[i]);
    }

    for (int i = 0; i < BUTTON_COUNT; i++)
        keypad->buttons[i] = key_map[i];
}

char keypad_get_key(Keypad *keypad) {
    static bool is_released = true;

    for (int col = 0; col < 4; col++) {
        gpio_put(keypad->gpio_column[col], 0);

        sleep_us(50);

        for (int row = 0; row < 4; row++) {
            int button_index = row * 4 + col;

            if (!gpio_get(keypad->gpio_rows[row])) { 
                if (is_released) { 
                    is_released = false;
                    gpio_put(keypad->gpio_column[col], 1);
                    return keypad->buttons[button_index];
                }
                gpio_put(keypad->gpio_column[col], 1);
                return '\0';
            }
        }

        gpio_put(keypad->gpio_column[col], 1);
    }

    if (!is_released)
        is_released = true;

    return '\0';
}

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
