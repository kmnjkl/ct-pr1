/*
 * ex 5
 * v 4
 *
 * p 2
 * */

#include <malloc.h>
#include "string.h"
#include "stdio.h"

int main() {
    FILE * file;
    char p[40];
    char fpath[100] = "/home/kmnjkl/YD/Computer_technologies/Prakt/ex5/1_files/";
    char c;

    scanf("%s", p);
    scanf("%s", &c);
    strcat(fpath, p);
    file = fopen(fpath, "r");
    if (file == NULL) {
        printf("\nERROR\n");
        return 1;
    } else {
        printf("FILE OPENED\n");
    }

    char * s;
    if ((s = calloc(1001, sizeof(char))) == NULL) {
        printf("calloc ERROR\n");
        return 2;
    }
    printf("MEMORY ALLOCATED\n");
//    printf("%s, %p", s, s);
    int n = 0;
    int nc = 0;
    char * ci;
    while (fgets(s, 1000, file) != NULL) {
//        printf("n");
        n++;
        while ((ci = strchr(s, c)) != NULL) {
            s = ci+1;
            nc++;
        }
    }

    fclose(file);

    printf("\nLines in file \"%s\": %d.\n", p, n);
    printf("Characters '%c' in file: %d.\n", c, nc);

    return 0;
}
