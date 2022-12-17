/*  ZP5
 * V. 6.
 * 2.6
 *
 * I(0,1) e^(2x) * sin(2*x^2 + 1) * dx
 *
 * */

#include <math.h>
#include <stdio.h>
#include <float.h>

#define P 0.0000000001

#define OUT_DIG DECIMAL_DIG

long double f(long double), ab(long double, long double, int), c(long double, long double, int);

int main() {
    // a, b
    long double l = 0, r = 1;
    int n = 1000;
    long double i1, i2;

    i1 = ab(l, r, n);
    n *= 2;
    i2 = ab(l, r, n);
    long double p = fabsl(i1 - i2);

    while (p >= P) {
        n *= 2;
        i1 = i2;
        i2 = ab(l, r, n);
        p = fabsl(i1 - i2);
    }
    printf("I = %.*Lf; n = %8d, p = %.*Lf;\n", OUT_DIG, i2, n, OUT_DIG, p);

    // c
    n = 1000;
    i1 = c(l, r, n);
    n *= 2;
    i2 = c(l, r, n);
    p = fabsl(i1 - i2);

    while (p >= P) {
        n *= 2;
        i1 = i2;
        i2 = c(l, r, n);
        p = fabsl(i1 - i2);
    }
    printf("I = %.*Lf; n = %8d, p = %.*Lf;\n", OUT_DIG, i2, n, OUT_DIG, p);

    return 0;
}

long double f(long double x) {
    return expl(2*x) * sinl(2*x*x + 1.0);
}

// Integral of f(x) from l to r
// trapeze method (a,b)
long double ab(long double l, long double r, int n) {
    long double h = (r - l) / n;
    long double f0 = f(l);
    long double fn = f(r);
    long double I = 0;
    I += (f0 + fn) / 2;
    for (int i = 1; i < n; i++) {
        I += f(l + i*h);
    }
    I *= h;
    return I;
}

// Integral of f(x) from l to r
// Simpson's method (c)
long double c(long double l, long double r, int n) {
    long double h = (r - l) / n;
    long double f0 = f(l);
    long double fn = f(r);
    long double I = 0;
    I += f0/3 + fn/3;
    for (int i = 1; i < n; i++) {
        I += f(l + i*h) * (i % 2 == 0 ? 2 : 4) / 3;
    }
    I *= h;
    return I;
}