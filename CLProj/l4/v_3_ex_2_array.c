/*
 * Ex. 2.3.
 * 2. Array.
 * */

#include "stdio.h"

#define N 1000

int sum_arr(int* a, int n);

int main() {

    int n = N + 1;

    while (n > N) {
        printf("How many numbers will you enter (less then %d)?\n> ", N);
        scanf("%d", &n);
    }

    printf("\nEnter %d numbers, please:\n", n);
    int a[N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            printf("You entered '0'! Input finishes here.\n");
            break;
        }
    }
    int sum = sum_arr(a, n);
    printf("\nSum of your numbers is %d.\n", sum);

    return 0;
}

int sum_arr(int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] == 0) {
            break;
        }
    }
    return sum;
}