

#include "stdio.h"
#include "strhead.h"

void print_str_(struct str_ * st);

int main() {
    struct str_ st1;
    st1.i = 1;
    st1.d = 2.0;

    print_str_(&st1);

    return 0;
}

void print_str_(struct str_ * st) {
    printf("Data:\ni = %d\nd = %f", st->i, st->d);
}