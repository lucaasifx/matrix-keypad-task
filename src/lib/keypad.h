#ifndef KEYPAD_H
#define KEYPAD_H

#include "pico/stdlib.h"

#define NO_KEY '\0'

void init_keypad();
char get_key();

#endif
