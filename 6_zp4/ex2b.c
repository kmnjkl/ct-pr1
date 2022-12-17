
#include <malloc.h>
#include "stdio.h"

double f(double T);

int main() {
    double h = 0.1, s = 0, e = 10;
    int n = (int) ((e-s)/h) + 1;
    double *T = calloc(n, sizeof(double));
    if (T == NULL) return 1;
    T[0] = 80;

    for (int i = 1; i < n; i++) {
        double Tp = T[i-1] + f(T[i-1]) * h;
        T[i] = T[i-1] + 0.5 * (f(T[i-1]) + f(Tp)) * h;
    }

    printf("T(10) = %f", T[n-1]);

    return 0;
}

double f(double T) {
    return -0.03 * (T - 20);
}