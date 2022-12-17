#include <math.h>
#include "stdio.h"

#define E 18
#define M 7
#define T 16

double get_e(double e, double m, double tn);
/*
 *  1.488566e-15
 *
 *  2.220446e-16
 * */
int main() {
    double e;
    double mult;
    double tn;

    printf("\nEnter initial 'e': ");
    scanf("%lf", &e);

    printf("\nEnter 'e' multiplier: ");
    scanf("%lf", &mult);

    printf("\nEnter test number: ");
    scanf("%lf", &tn);

//        printf("\n e = %lf; mult = %lf; tn = %lf;", e, mult, tn);

    double ce = get_e(e, mult, tn);
    printf("\n\nResult: e = %e.\n", ce);

    return 0;
}

double get_e(double e, double m, double tn) {
    while (tn + e/2.0 > tn) {
        e *= m;
    }
    return e;
}

/*
Start test series?
1/0? > 1
Calculated 2016 results.

Min.: 1.500000e-23.
Max.: 5.820766e-11.
Average: 3.131236e-12.
Square of average deviation: 1.975643e-20.
 */