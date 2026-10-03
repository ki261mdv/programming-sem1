#include <stdio.h>

int main(void) {
    double mass = 0.0;      // Mass m (kg)
    double radius = 0.0;    // Radius r (m)
    double velocity = 0.0;  // Velocity v (m/s)

    printf("=== Centripetal Acceleration and Force (Variant 16) ===\n");
    printf("Enter mass m (kg), radius r (m), and velocity v (m/s) separated by spaces: ");

    // Перевірка коректності введення числових даних
    if (scanf("%lf %lf %lf", &mass, &radius, &velocity) != 3) {
        printf("Error: Invalid input! Please enter numbers only.\n");
        return 1;
    }

    // Перевірка фізичних обмежень та запобігання діленню на нуль
    if (radius <= 0.0) {
        printf("Error: Radius must be strictly greater than zero (r > 0)!\n");
        return 1;
    }

    if (mass < 0.0) {
        printf("Error: Mass cannot be negative!\n");
        return 1;
    }

    // Обчислення за формулами: a = v^2 / r, F = m * a
    double acceleration = (velocity * velocity) / radius;
    double force = mass * acceleration;

    // Виведення результатів
    printf("\n--- Calculation Results ---\n");
    printf("Centripetal Acceleration (a): %.3f m/s^2\n", acceleration);
    printf("Centripetal Force (F):        %.2f N\n", force);

    return 0;
}