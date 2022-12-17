
/*
 * h = 0.1
 * y' = (y + x)^2
 * y(0) = 0
 * [0; 0.5]
 * */

#include <malloc.h>
#include "stdio.h"

double f(double u, double x);

int main() {
    double h = 0.001, s = 0, e = 0.7;
    long int n = (long int) ((e-s)/h) + 1;
    double *u = calloc(n, sizeof(double));
    if (u == NULL) return 1;
    u[0] = 0;
    double x = s;
    for (long int i = 1; i < n; i++) {
        u[i] = u[i-1] + f(u[i-1], x) * h;
        x += h;
    }

    x = s;
    int k = 100;
    for (long int i = 0; i < 7*k; i+=k) {
        printf("x = %.8f\ty = %.8f\n", x, u[i]);
        x += h*k;
    }

    free(u);

    return 0;
}

double f(double u, double x) {
    return (u + x)*(u + x);
}