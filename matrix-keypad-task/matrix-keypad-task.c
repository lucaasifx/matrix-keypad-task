#include <stdio.h>
#include "pico/stdlib.h"

#define LED_GREEN_PIN 12    // Pino de conexão com o led verde é o 12

// Define os pinos do teclado com as portas GPIO
uint columns[4] = {17, 18, 19, 20}; 
uint rows[4] = {4, 8, 9, 16};

// Mapa de teclas
char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

// Variáveis internas
uint _columns[4];
uint _rows[4];
char _matrix_values[16];
uint all_columns_mask = 0x0;
uint column_mask[4];

// Função para imprimir valor binário
void imprimir_binario(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
}

// Inicializa o keypad
void pico_keypad_init(uint columns[4], uint rows[4], char matrix_values[16]) {
    for (int i = 0; i < 16; i++) {
        _matrix_values[i] = matrix_values[i];
    }

    for (int i = 0; i < 4; i++) {
        _columns[i] = columns[i];
        _rows[i] = rows[i];

        gpio_init(_columns[i]);
        gpio_init(_rows[i]);

        gpio_set_dir(_columns[i], GPIO_IN);
        gpio_set_dir(_rows[i], GPIO_OUT);

        gpio_put(_rows[i], 1);

        all_columns_mask = all_columns_mask + (1 << _columns[i]);
        column_mask[i] = 1 << _columns[i];
    }
}

// Coleta o caractere pressionado
char pico_keypad_get_key(void) {
    int row;
    uint32_t cols;
    bool pressed = false;

    cols = gpio_get_all();
    cols = cols & all_columns_mask;
    imprimir_binario(cols);
    
    if (cols == 0x0) {
        return 0;
    }

    for (int j = 0; j < 4; j++) {
        gpio_put(_rows[j], 0);
    }

    for (row = 0; row < 4; row++) {
        gpio_put(_rows[row], 1);
        busy_wait_us(10000);

        cols = gpio_get_all();
        gpio_put(_rows[row], 0);
        cols = cols & all_columns_mask;
        if (cols != 0x0) {
            break;
        }   
    }

    for (int i = 0; i < 4; i++) {
        gpio_put(_rows[i], 1);
    }

    if (cols == column_mask[0]) {
        return (char)_matrix_values[row * 4 + 0];
    }
    else if (cols == column_mask[1]) {
        return (char)_matrix_values[row * 4 + 1];
    }
    if (cols == column_mask[2]) {
        return (char)_matrix_values[row * 4 + 2];
    }
    else if (cols == column_mask[3]) {
        return (char)_matrix_values[row * 4 + 3];
    }
    else {
        return 0;
    }
}

// Função para acender ou apagar o LED
void led_action(char key) {
    // Desliga o LED caso qualquer outra tecla seja pressionada ou não tenha tecla pressionada
    gpio_put(LED_GREEN_PIN, false);

    // Se a tecla '1' for pressionada, acende o LED GREEN
    if (key == '1') {
        gpio_put(LED_GREEN_PIN, true);  // Acende o LED no pino 12
    }
}

// Função principal
int main() {
    stdio_init_all();
    pico_keypad_init(columns, rows, KEY_MAP);

    // Inicializa o LED_GREEN na GPIO 12
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    char caracter_press;

    while (true) {
        caracter_press = pico_keypad_get_key();
        printf("\nTecla pressionada: %c\n", caracter_press);

        // Aciona o LED baseado na tecla pressionada
        led_action(caracter_press);

        busy_wait_us(500000);  // Delay para evitar leituras excessivas
    }
}
