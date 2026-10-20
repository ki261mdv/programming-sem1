#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100000

int main(void) {
    double x, eps;

    printf("Введіть аргумент X та точність eps: ");
    if (scanf("%lf %lf", &x, &eps) != 2) {
        fprintf(stderr, "Помилка: Некоректне введення даних.\n");
        return 1;
    }

    if (eps <= 0.0) {
        fprintf(stderr, "Помилка: Точність eps повинна бути більшою за 0.\n");
        return 1;
    }

    double sum = 1.0;  // Перший член a_0 = 1
    double term = 1.0; // Поточний доданок a_0
    int n = 1;
    int iter = 0;

    while (fabs(term) >= eps && iter < MAX_ITER) {
        term = term * (x / n); // Рекурентне обчислення без pow() та факторіалу
        sum += term;
        n++;
        iter++;
    }

    if (iter >= MAX_ITER) {
        printf("Попередження: Досягнуто ліміт ітерацій (%d).\n", MAX_ITER);
    }

    double exact = exp(x);
    double abs_error = fabs(sum - exact);

    printf("\n=== Результати обчислень ===\n");
    printf("Аргумент X:              %.6lf\n", x);
    printf("Точність eps:            %.1e\n", eps);
    printf("Обчислена сума ряду:     %.10lf\n", sum);
    printf("Еталонне значення exp(X):%.10lf\n", exact);
    printf("Абсолютна похибка:       %.10e\n", abs_error);
    printf("Кількість ітерацій:      %d\n", iter);

    return 0;
}