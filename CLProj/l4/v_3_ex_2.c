/*
 * Ex. 2.3.
 * 2. Recursion.
 * */

#include "stdio.h"

int sum_inputs(int n);

int main() {

    int n = 0;

    printf("How many numbers will you enter?\n> ");
    scanf("%d", &n);

    printf("\nEnter %d numbers, please:\n", n);
    int sum = sum_inputs(n);
    printf("\nSum of your numbers is %d.\n", sum);

    return 0;
}

int sum_inputs(int n) {
    if (n <= 0) return 0;
    int x=0;
    scanf("%d", &x);
    if (x == 0) {
        printf("You entered '0'! Input finishes here.\n");
        return 0;
    }
    else return x + sum_inputs(n-1);
}