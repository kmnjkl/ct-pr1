#include "stdio.h"

int main() {

    printf("Size of 'int' -------------- %lu\n", sizeof(int));
    printf("Size of 'long int' --------- %lu\n", sizeof(long int));
    printf("\n");
    printf("Size of 'unsigned int' ----- %lu\n", sizeof(unsigned int));
    printf("Size of 'long unsigned int'  %lu\n", sizeof(long unsigned int));
    printf("\n");
    printf("Size of 'float' ------------ %lu\n", sizeof(float));
    printf("Size of 'double' ----------- %lu\n", sizeof(double));
    printf("Size of 'long double' ------ %lu\n", sizeof(long double));
    printf("\n");
    printf("Size of 'char' ------------- %lu\n", sizeof(char));

    return 0;
}