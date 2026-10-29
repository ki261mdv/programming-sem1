#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 15

int main(void) {
    int arr[SIZE];
    srand((unsigned int)time(NULL));

    printf("Вихідний масив:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50; // діапазон [-50; 50]
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // 1. Пошук мінімального за модулем елемента
    int min_abs = abs(arr[0]);
    int min_abs_val = arr[0];
    for (int i = 1; i < SIZE; i++) {
        if (abs(arr[i]) < min_abs) {
            min_abs = abs(arr[i]);
            min_abs_val = arr[i];
        }
    }

    // 2. Сума елементів після першого від'ємного
    int first_neg_index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            first_neg_index = i;
            break;
        }
    }

    int sum_after_neg = 0;
    if (first_neg_index != -1 && first_neg_index < SIZE - 1) {
        for (int i = first_neg_index + 1; i < SIZE; i++) {
            sum_after_neg += arr[i];
        }
    }

    printf("Мінімальний за модулем елемент: %d (модуль = %d)\n", min_abs_val, min_abs);
    if (first_neg_index != -1) {
        printf("Перший від'ємний елемент має індекс %d (значення %d)\n", first_neg_index, arr[first_neg_index]);
        printf("Сума елементів після першого від'ємного: %d\n", sum_after_neg);
    } else {
        printf("Від'ємних елементів у масиві не знайдено.\n");
    }

    return 0;
}