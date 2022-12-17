/*
 * Ex. 2.3.
 * 2. Array.
 * "malloc"
 * */

#include <malloc.h>
#include "stdio.h"

int sum_arr(int *a, int n);

int main() {
    int n;
    printf("How many numbers will you enter?\n> ");
    scanf("%d", &n);

    printf("\nEnter %d numbers, please:\n", n);
    int *a;
    a = (int*) malloc(n * sizeof(int));
    if (a == NULL) {printf("Error!"); return 1;}
    else {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 0) {
                printf("You entered '0'! Input finishes here. Read only %d numbers.\n", i);
                n = i;
                break;
            }
        }
        int sum = sum_arr(a, n);
        printf("\nSum of your numbers is %d.\n", sum);

        free(a);

        return 0;
    }
}

int sum_arr(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}