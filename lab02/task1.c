#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double x_start, x_end, dx;

    printf("Введіть X_start, X_end та dX: ");
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        fprintf(stderr, "Помилка: Некоректне введення даних.\n");
        return 1;
    }

    // Перевірка коректності вхідних параметрів
    if (x_start >= x_end || dx <= 0.0) {
        fprintf(stderr, "Помилка валідації: Очікується X_start < X_end та dX > 0.\n");
        return 1;
    }

    // Вивід текстової таблиці
    printf("+------------+--------------+\n");
    printf("|     X      |     Y(X)     |\n");
    printf("+------------+--------------+\n");

    for (double x = x_start; x <= x_end + dx / 2.0; x += dx) {
        double y;

        if (x <= 0.0) {
            y = -x;
        } else if (x <= 2.0) {
            y = x * x;
        } else {
            y = 4.0;
        }

        printf("| %10.2lf | %12.4lf |\n", x, y);
    }

    printf("+------------+--------------+\n");

    return 0;
}