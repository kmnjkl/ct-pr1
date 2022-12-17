/*
 * Ex. 3.
 * V. 1.
 *
 * Decimal to binary.
 * */

#include "stdio.h"

#define N 1000


int main() {
    int x;
    printf("\nEnter your number: ");
    scanf("%d", &x);

    int r=x%2, q=x/2;
    char ires[N];
//    48 == '0'
    ires[0] = (char) (48 + r);
    int i = 1;
    while (q >= 2) {
        r = q%2;
        q = q/2;

        ires[i] = (char) (48 + r);
        i++;
    }
    if (q == 0) {
        i--;
    } else {
        ires[i] = (char) (48 + q);
    }

    char res[i+1];
    for (int k = 0; k < i+1; k++) {
        res[k] = ires[i - k];
    }

    printf("\nBIN: ");
    for (int l = 0; l < i+1; l++) {
        printf("%c", res[l]);
    }
    printf("\n");

    return 0;
}
