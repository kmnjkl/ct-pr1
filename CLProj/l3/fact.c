#include "stdio.h"

long int fact_loop(int n);
long int fact_rec(int n);

int main() {
    int n;
    printf("Enter integer number: ");
    scanf("%d", &n);

    long int r1 = fact_loop(n), r2 = fact_rec(n);
    printf("Factorial of %d.\nLoop function: %ld.\nRecursive function: %ld.\n", n, r1, r2);
    printf("Results are ");
    if (r1 == r2) {
        printf("equal.\n");
    } else {
        printf("not equal!\n");
    }

    return 0;
}

long int fact_loop(int n) {
    if (n == 0) return 1;
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

long int fact_rec(int n) {
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return n * fact_rec(n-1);
    }
}
