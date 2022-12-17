#include "stdio.h"

int main() {
    int a = 1, b = 2;

    int nc = a/b;
    float ic = a/b;
    float ec = (float) a/b;
    float ec2 = 1.0f*a/b;

    printf("Implicit type juggling: '1/2' = %d (int); '1/2' = %f (float).\nExplicit type casting: '(float) 1/2' = %f (float); '1.0*1/2' = %f (float)\n", nc, ic, ec, ec2);

    return 0;
}