#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n == 0 || n == 1) return 1.0;
    double fact = 1.0;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double series_fixed_n(double x, int N) {
    double S = 0.0;
    for (int n = 0; n <= N; n++) {
        S += cos(n * x) / factorial(n);
    }
    return S;
}

double series_fixed_epsilon(double x, double epsilon) {
    double S = 0.0;
    double term = 1.0;
    int n = 0;

    while (fabs(term) > epsilon) {
        term = cos(n * x) / factorial(n);
        S += term;
        n++;
    }
    return S;
}

int main() {
    double a = 0.0, b = 1.0; 
    int k = 10; 
    int N = 10; 
    double epsilon = 0.0001; 

    double h = (b - a) / (k - 1); 

    printf("x\tРяд (N=%d)\tРяд (epsilon=%.5f)\tТочне значення\n", N, epsilon);
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < k; i++) {
        double x = a + i * h;
        double exact_value = exp(cos(x)) * cos(sin(x));
        double series_n = series_fixed_n(x, N);
        double series_epsilon = series_fixed_epsilon(x, epsilon);

        printf("%.5f\t%.5f\t\t%.5f\t\t%.5f\n", x, series_n, series_epsilon, exact_value);
    }

    return 0;
}