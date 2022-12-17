/*  'ZP5'
 * V. 6.
 * 1.6.
 *
 *  2*z^3 + 4*z - 1 = 0
 *
 * */

/*
The Bisectional Method
zm = 0.24283973258548090;
f(zm)=-0.00000000000000000;

The False-Position Method
Iteration j = 43; z[j] = 0.24283973258548090;
f(z[j]) = 0.00000000000000000;
BETTER PRECISION IS UNATTAINABLE: f(z[43]) == 0.


The Newton-Raphson Method
Iteration j = 7; z[j] = 0.24283973258548090;
f(z[j]) = 0.00000000000000000;
BETTER PRECISION IS UNATTAINABLE: f(z[7]) == 0.
*/

#include "math.h"
#include "stdio.h"
#include "float.h"

#define N  1000000
#define NB 1000000

#define P 0

#define OUT_DIG DECIMAL_DIG

long double a(long double, long double), b(unsigned int), c(unsigned int), f(long double), df(long double), get_z(unsigned int), get_fz(unsigned int), set_z(unsigned int, long double),
        c_get_z(unsigned int), c_get_fz(unsigned int), c_set_z(unsigned int, long double), c_get_dfz(unsigned int);

long double z[NB], fz[NB], dfz[NB];
short int zs[NB];

long double ma(long double, long double), mb(long double, long double), mc(long double, long double);

int main() {
//    Enter z1, z2
    long double z1 = 0.0, z2 = 1.0;
    scanf("%Lf %Lf", &z1, &z2);

//    === a ===
    long double m1 = ma(z1, z2);

//    === b ===
    long double m2 = mb(z1, z2);

//    === c ===
    long double m3 = mc(z1, z2);


//    Comparison
    if (m1 == m2) printf("\n\na ~ b\t - methods 'a' and 'b' gave exactly the same result.\n");
    if (m1 == m3) printf("a ~ c\t - methods 'a' and 'c' gave exactly the same result.\n");
    if (m2 == m3) printf("b ~ c\t - methods 'b' and 'c' gave exactly the same result.\n");

    return 0;
}

/*
 * A
 * */
long double ma(long double z1, long double z2) {
    printf("a\n");
    printf("The Bisectional Method\n");
    long double m1 = a(z1, z2);
    printf("\n\n");
    return m1;
}

/*
 * B
 * */
long double mb(long double z1, long double z2) {
    for (unsigned int i = 0; i < NB; i++) zs[i] = 0;
    printf("b\n");
    printf("The False-Position Method\n");
    set_z(0, z1);  // j = 0
    set_z(1, z2);   // j = 1
    unsigned int j = 2;
    while (fabsl(z1 - z2) > P && j < N && f(z2) != 0) {
        z1 = z2;
        z2 = b(j);
        j++;
    }
    printf("Iteration j = %d; z[j] = %.*Lf;\nf(z[j]) = %.*Lf;", j-1, OUT_DIG, z2, OUT_DIG, f(z2));
    if (f(z2) == 0) {
        printf("\nBETTER PRECISION IS UNATTAINABLE: f(z[%d]) == 0.\n", j-1);
    }
    printf("\n\n");
    return z2;
}

/*
 * C
 * */
long double mc(long double z1 , long double z2) {
    printf("c\n");
    printf("The Newton-Raphson Method\n");
    for (unsigned int i = 0; i < NB; i++) zs[i] = 0;
    c_set_z(0, z1);  // j = 0
    z2 = c_set_z(1, z2);   // j = 1
    int j = 2;
    while (fabsl(z1 - z2) > P && j < N && f(z2) != 0) {
        z1 = z2;
        z2 = c(j);
        j++;
    }
    printf("Iteration j = %d; z[j] = %.*Lf;\nf(z[j]) = %.*Lf;", j-1, OUT_DIG, z2, OUT_DIG, f(z2));
    if (f(z2) == 0) {
        printf("\nBETTER PRECISION IS UNATTAINABLE: f(z[%d]) == 0.\n", j-1);
    }
    printf("\n\n");
    return z2;
}



long double a(long double z1, long double z2) {
    long double zm;
    unsigned int i = 0;
    while (fabsl(z2 - z1) > P && i < N) {
        zm = (z1 + z2) / 2.0;

        if (f(zm) == 0) {
            z1 = zm;
            z2 = zm;
            i++;
            break;
        }

        if (f(zm) * f(z1) > 0) {
            z1 = zm;
        } else {
            z2 = zm;
        }
        i++;
    }
    zm = (z1+z2)/2.0;
    printf("Iteration i = %d; zm = %.*Lf;\nf(zm) = %.*Lf;", i-1, OUT_DIG, zm, OUT_DIG, f(zm));
    if (f(zm) == 0) {
        printf("\nBETTER PRECISION IS UNATTAINABLE: f(zm) == 0.");
    }
    if (i >= N) {
        printf("\nITERATION LIMIT REACHED");
    }
    return zm;
}



long double b(unsigned int jpo) {
    unsigned int j = jpo - 1;
//  Maximum precision message
    if (get_fz(j) == 0) {
        printf("BETTER PRECISION IS UNATTAINABLE: f(z[%d]) = 0.\n", j);
        return set_z(jpo, get_z(j));
    }

    unsigned int k = 0;
    while (get_fz(j) * get_fz(j-k) > 0) {
        k++;
    }
//    if (get_fz(j) > 0) {
//        while (get_fz(j - k) > 0) {
//            k++;
//        }
//    }
//    if (get_fz(j) < 0) {
//        while (get_fz(j - k) < 0) {
//            k++;
//        }
//    }
//    long double zn = get_z(j) - get_fz(j) * (get_z(j) - get_z(j-k))/(get_fz(j) - get_fz(j-k));
    long double dbg = set_z(j+1, get_z(j) - get_fz(j) * (get_z(j) - get_z(j-k))/(get_fz(j) - get_fz(j-k)));
    return dbg;
}



long double c(unsigned int jpo) {
    unsigned int j = jpo - 1;
//  Maximum precision message
    if (c_get_fz(j) == 0) {
        printf("BETTER PRECISION IS UNATTAINABLE: f(z[%d]) = 0.\n", j);
        return c_set_z(jpo, c_get_z(j));
    }
    return c_set_z(j+1, c_get_z(j) - c_get_fz(j)/c_get_dfz(j));
}



// f
long double f(long double x) {
//    return 2 * x * x * x + 4 * x - 1;
    return sinl(x);
}

long double df(long double x) {
//    return 6 * x * x + 4;
    return cosl(x);
}



// b
long double get_z(unsigned int i) {
    if (!zs[i]) {
        z[i] = b(i);
        fz[i] = f(z[i]);
        zs[i] = 1;
    }
    return z[i];
}

long double get_fz(unsigned int i) {
    if (!zs[i]) {
        z[i] = b(i);
        fz[i] = f(z[i]);
        zs[i] = 1;
    }
    return fz[i];
}

long double set_z(unsigned int i, long double zn) {
    z[i] = zn;
    fz[i] = f(zn);
    zs[i] = 1;
    return zn;
}



// c
long double c_get_dfz(unsigned int i) {
    if (!zs[i]) {
        z[i] = b(i);
        fz[i] = f(z[i]);
        dfz[i] = df(z[i]);
        zs[i] = 1;
    }
    return dfz[i];
}

long double c_get_z(unsigned int i) {
    if (!zs[i]) {
        z[i] = b(i);
        fz[i] = f(z[i]);
        dfz[i] = df(z[i]);
        zs[i] = 1;
    }
    return z[i];
}

long double c_get_fz(unsigned int i) {
    if (!zs[i]) {
        z[i] = b(i);
        fz[i] = f(z[i]);
        dfz[i] = df(z[i]);
        zs[i] = 1;
    }
    return fz[i];
}

long double c_set_z(unsigned int i, long double zn) {
    z[i] = zn;
    fz[i] = f(zn);
    dfz[i] = df(z[i]);
    zs[i] = 1;
    return zn;
}
