// 1.4.1

#include "stdio.h"

int sum_for(int Nstart, int Nend, int Step);
int sum_while(int Nstart, int Nend, int Step);

int main() {
    int Nstart, Nend, Step;
    printf("Enter Nstart, Nend, Step: ");
    scanf("%d %d %d", &Nstart, &Nend, &Step);
    printf("\n");
    sum_for(Nstart, Nend, Step);
    printf("\n");
    sum_while(Nstart, Nend, Step);

    int n = (Nend - Nstart)/Step + 1;
    int sum = (Nstart + (n-1)*Step/2.0)*n;
    printf("\nArithmetic progression formula: %d", sum);
    return 0;
}

int sum_for(int Nstart, int Nend, int Step) {
    printf("FOR:\n");
    printf("|  num  |  sum  |\n");
    printf("--------|--------\n");
    int sum=0;
    for (; Nstart <= Nend; Nstart+=Step) {
        sum += Nstart;
        printf("| %5d | %5d |\n", Nstart, sum);
    }
    printf("-----------------\n");
    return sum;
}

int sum_while(int Nstart, int Nend, int Step) {
    printf("WHILE:\n");
    printf("|  num  |  sum  |\n");
    printf("--------|--------\n");
    int sum=0;
    while (Nstart <= Nend) {
        sum += Nstart;
        printf("| %5d | %5d |\n", Nstart, sum);
        Nstart+=Step;
    }
    printf("-----------------\n");
    return sum;
}