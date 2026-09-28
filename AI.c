#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c;
    double x_start, x_end, dx;
    double x, fx;
// Ввод исходных данных
printf("Введите a, b, c, Xнач, Xкон, dX: ");

if (scanf("%lf %lf %lf %lf %lf %lf",
          &a, &b, &c, &x_start, &x_end, &dx) != 6) {
    printf("Ошибка при вводе данных!\n");
    return 1;
}

// Проверка шага
if (dx <= 0) {
    printf("Ошибка: dX должен быть положительным!\n");
    return 1;
}

// Целые части a, b и c
int Aц = (int)a;
int Bц = (int)b;
int Cц = (int)c;

// НЕ(Ац И Вц И Сц)
int condition = ~(Aц & Bц & Cц);

printf("\nТаблица значений функции F(x):\n");
printf("--------------------------------------\n");
printf("|      x      |          F(x)        |\n");
printf("--------------------------------------\n");

// Вычисление функции на заданном интервале
for (x = x_start; x <= x_end + 1e-9; x += dx) {

    if (x < 0 && b != 0) {
        fx = a * pow(x, 3) + b * pow(x, 2);
    }
    else if (x > 0 && b == 0) {
        if (fabs(x - c) < 1e-9) {
            printf("| %10.4f | Деление на ноль       |\n", x);
            continue;
        }

        fx = (x - a) / (x - c);
    }
    else {
        if (fabs(c) < 1e-9 || fabs(x - 10) < 1e-9) {
            printf("| %10.4f | Деление на ноль       |\n", x);
            continue;
        }

        fx = (x + 5) / (c * (x - 10));
    }

    // Определение типа результата согласно условию
    if (condition != 0) {
        printf("| %10.4f | %20.4f |\n", x, fx);
    }
    else {
        printf("| %10.4f | %20d |\n", x, (int)fx);
    }
}

printf("--------------------------------------\n");

return 0;
}