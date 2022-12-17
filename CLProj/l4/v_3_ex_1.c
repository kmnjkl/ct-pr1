/*
 * Ex. 2.3.
 * 1.
 * */

#include "stdio.h"
#define N 10

int main() {
    int arr[N] = {23, -4, 47, -14287, 236, 236, 8, -23, 432879, 34};

    int sum = arr[0];

    printf("\n/-----+-----------+-----------\\\n");
    printf("|  i  |  element  |   delta   |\n");
    printf("|-----+-----------+-----------|\n");
    printf("|   0 | %9d | %9d |\n", arr[0], arr[0]);
    for (int i = 1; i < N; i++) {
        sum += arr[i];
        printf("| %3d | %9d | %9d |\n", i, arr[i], arr[i] - arr[i-1]);
    }
    printf("\\-----+-----------+-----------/\n\n");
    printf("SUM: %d\n", sum);

    return 0;
}