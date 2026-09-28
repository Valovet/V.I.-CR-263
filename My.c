#include "stdio.h" 
#include "math.h" 
int main() {
    double a, b, c, x_start, x_end, dx, x, fx;
printf("Введите a, b, c, Xнач, Xкон, dX: ");
if (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &x_start, &x_end, &dx) != 6) {
    printf("Ошибка при вводе данных!\n");
    return 1;
}
if (dx <= 0 && x_start <= x_end) {
    printf("Ошибка: шаг dX должен быть положительным!\n");
    return 1;
}
int a_ts = (int)a;
int b_ts = (int)b;
int c_ts = (int)c;
int bitwise_expr = ~(a_ts & b_ts & c_ts);
printf("\nТаблица значений функции F(x):\n");
printf("----------------------------------------\n");
printf("|    x       |          F(x)           |\n");
printf("----------------------------------------\n");
for (x = x_start; x <= x_end + 1e-9; x += dx) {
if (x < 0 && b != 0) {
    fx = a * pow(x, 3) + b * pow(x, 2);
} 
else if (x > 0 && b == 0) {
    if (fabs(x - c) < 1e-9) {
        printf("| %10.4f | Ошибка: деление на ноль (x - c) |\n", x);
        continue;
    }
    fx = (x - a) / (x - c);
} 
else {
    if (fabs(c) < 1e-9 || fabs(x - 10) < 1e-9) {
        printf("| %10.4f | Ошибка: деление на ноль в знаменателе |\n", x);
        continue;
    }
    fx = (x + 5) / (c * (x - 10));
}

if (bitwise_expr != 0) {
    
    printf("| %10.4f | %23.4f |\n", x, fx);
} else {
    
    int fx_int = (int)fx;
    printf("| %10.4f | %23d |\n", x, fx_int);
}
}
printf("----------------------------------------\n");
return 0;
}