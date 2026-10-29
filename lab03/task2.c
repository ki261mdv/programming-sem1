#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main(void) {
    int matrix[ROWS][COLS];
    srand((unsigned int)time(NULL));

    // Заповнення та вивід початкової матриці (Row-Major Order)
    printf("Початкова матриця:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 101 - 50; // діапазон [-50; 50]
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // 1. Пошук мінімального елемента в кожній колонці
    printf("\nМінімальні елементи за колонками:\n");
    for (int j = 0; j < COLS; j++) {
        int min_col = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] < min_col) {
                min_col = matrix[i][j];
            }
        }
        printf("%6d", min_col);
    }
    printf("\n\n");

    // 2. Обмін першого та останнього рядків місцями
    for (int j = 0; j < COLS; j++) {
        int temp = matrix[0][j];
        matrix[0][j] = matrix[ROWS - 1][j];
        matrix[ROWS - 1][j] = temp;
    }

    // Вивід перетвореної матриці (Row-Major Order)
    printf("Перетворена матриця (перший та останній рядки поміняні місцями):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}