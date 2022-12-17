

#include "stdio.h"
#include "strhead.h"
#include "stdlib.h"
#include "time.h"

void print_str_(struct str_ * st, int n);

int main() {
    srand(time(NULL));
    struct str_ st1[10];
    for(int i = 0; i < 10; i++) {
        st1[i].i = i;
        st1[i].d = -1.0 + (rand()%300)/100.0;

    }

    print_str_(st1, 10);

    return 0;
}

void print_str_(struct str_ * st, int n) {
    for (int i = 0; i < n; i++) {
        printf("i = %d\td = %f\n", st[i].i, st[i].d);
    }
}