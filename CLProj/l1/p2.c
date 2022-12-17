// 1.4.1
#include "stdio.h"
#define PI 3.1415926535897

int main() {
    float r;

    printf("Enter radius: ");
    scanf("%f", &r);

    printf("Volume: %f", 4.0/3.0 * PI * r*r*r);

    return 0;
}