#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    char str[BUFFER_SIZE];

    printf("Введіть текст: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    int word_count = 0;
    int in_word = 0;

    // Ручний аналіз без використання бібліотеки <string.h>
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        // Перевірка на пробільні символи (пробіл, табуляція, символ нового рядка)
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            word_count++;
        }
    }

    printf("Загальна кількість слів у тексті: %d\n", word_count);

    return 0;
}