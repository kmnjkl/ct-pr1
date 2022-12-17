#include <math.h>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define E 10
#define T 10

double get_e( double e,  double m,  double tn);

int main() {
    srand(time(NULL));
    unsigned int EMT = E*T;
    double res[EMT];
    double e[E];
    double mult = 0.999999;
    double tn[T];

    e[0] = 1;
    int u=1;
    for (u = 0; u < E/2; u++) {
        e[u] = 0.000001 + (rand()%10000)/1000.0;
//            printf("e = %e\n", e[i]);
    }
    for (u = E/2; u < E; u++) {
        e[u] = 0.000001 + (rand()%1000)/1000.0;
    }
//        printf("\n");
    for (int i = 0; i < T; i++) {
        tn[i] = 0.000001 + (rand()%1000000)/1000.0;
//            printf("tn = %e\n", tn[i]);
    }

    unsigned int ri = 0;
    for (int i = 0; i < E; i++) {
        for (int k = 0; k < T; k++) {
            res[ri] = get_e(e[i], mult, tn[k]);
            ri++;
        }
    }

    double minr = res[0], maxr = res[0], avg=0, avg_err=0;
    for(unsigned int i = 0; i < EMT; i++) {
        avg += res[i];
        if (res[i] < minr) {
            minr = res[i];
        }
        if (res[i] > maxr) {
            maxr = res[i];
        }
    }
    for (unsigned int i = 0; i < EMT; i++) {
        avg_err += (res[i] - avg)*(res[i] - avg);
    }
    avg /= EMT;
    avg_err = avg_err / (EMT * (EMT-1));
//    avg_err = sqrt(avg_err / (EMT * (EMT-1)));
    printf("\nCalculated %u results.\n", EMT);
    printf("\nMin.: %e.\nMax.: %e.\nAverage: %e.\nSquare of average deviation: %e.\n", minr, maxr, avg, avg_err);
//        printf("res[0] = %e", res[0]);

    return 0;
}

double get_e( double e,  double m,  double tn) {
    while (tn + e > tn) {
        e *= m;
    }
    return e;
}

/*
Calculated 100 results.

Min.: 8.881776e-16.
Max.: 5.684342e-14.
Average: 3.490539e-14.
Square of average deviation: 1.206255e-25.
 */