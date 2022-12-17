
/*
 * zp1.2
 * point 3
 * file sort
 * */

#include <malloc.h>
#include "stdio.h"

int m_strcmp(char *, char *);

int main() {
    // Open file
    FILE * f = fopen("zp12_3.txt", "r");
    if (f == NULL) {
        printf("Error opening file!");
        return 1;
    }
    // Read lines from file
    char * lines[100];
    int n = 0;
    while (!feof(f)) {
        lines[n] = calloc(80, sizeof(char));
        if (lines[n] == NULL) {
            printf("Error allocating memory! (lines[%d])", n);
            return 2;
        }
        fgets(lines[n], 80, f);
        n++;
    }
    fclose(f);

    // Modified bubble sort
    int c = 0;
    for (int i = 0; i < n-1; i++) {
        if (m_strcmp(lines[i], lines[i+1]) > 0) {
            c++;
            char * temp = lines[i];
            lines[i] = lines[i+1];
            lines[i+1] = temp;
            if (i > 0) i -= 2;
        }
    }

    // Write sorted lines to new file
    f = fopen("zp12_3_sorted.txt", "w");
    for (int i = 0; i < n; i++) {
        fputs(lines[i], f);
    }
    fclose(f);

    printf("\nFINISHED.\nRead and wrote %d lines.\n%d transpositions have been made.\n", n, c);

    return 0;
}

// My strcmp() function
int m_strcmp(char * s1, char * s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return -1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    if (s1[i] == '\0') return 1;
    return -1;
}