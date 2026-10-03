#include <stdio.h>

int main(void) {
    // 1. Визначення розмірів типів даних у байтах
    printf("=== Розміри типів даних у пам'яті ===\n");
    printf("sizeof(char)      = %zu byte(s)\n", sizeof(char));
    printf("sizeof(short)     = %zu byte(s)\n", sizeof(short));
    printf("sizeof(int)       = %zu byte(s)\n", sizeof(int));
    printf("sizeof(long)      = %zu byte(s)\n", sizeof(long));
    printf("sizeof(long long) = %zu byte(s)\n", sizeof(long long));
    printf("sizeof(float)     = %zu byte(s)\n", sizeof(float));
    printf("sizeof(double)    = %zu byte(s)\n", sizeof(double));
    printf("sizeof(void*)     = %zu byte(s)\n\n", sizeof(void*));

    // 2. Демонстрація переповнення (Integer Overflow)
    unsigned char byte_test = 255;

    printf("=== Демонстрація Integer Overflow ===\n");
    printf("Початкове значення byte_test:\n");
    printf("  Десятковий формат (%%u): %u\n", byte_test);
    printf("  Шістнадцятковий формат (0x%%02X): 0x%02X\n\n", byte_test);

    // Додаємо 1
    byte_test = byte_test + 1;

    printf("Значення після byte_test = byte_test + 1:\n");
    printf("  Десятковий формат (%%u): %u\n", byte_test);
    printf("  Шістнадцятковий формат (0x%%02X): 0x%02X\n", byte_test);

    return 0;
}