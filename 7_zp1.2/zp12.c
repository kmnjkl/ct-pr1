

#include <stdlib.h>
#include <time.h>
#include "stdio.h"

int main() {
    srand(time(NULL));
    int a[20], b[20];
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 100;
        b[i] = a[i];
    }

    int c = 0;
    for (int j = 0; j < 19; j++) {
        if (a[j] > a[j + 1]) {
            c++;
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            if (j > 0) j -= 2;
        }
    }

    printf("\nFINISHED.\n%d transpositions have been made.\n\n", c);
    printf("=-----=-----------=-----------=-----------=\n");
    printf("|  n  |  initial  |   sorted  |  delta s. |\n");
    printf("+-----+-----------+-----------+-----------+\n");
    for (int i = 0; i < 20; i++) {
        printf("|%4d |%10d |%10d |%+10d |\n", i+1, b[i], a[i], a[i] - a[(i > 0) ? i-1 : 0]);
    }
    printf("=-----=-----------=-----------=-----------=\n");

    return 0;
}
