/*
 * ex 5
 * v 4
 *
 * p 1
 * */

#include <string.h>
#include "stdio.h"

int main() {
    FILE *file;

    char letter[] = {'a','\0'};
    letter[0]--;
    for (char i = 0; i < 26; i++) {
        letter[0]++;
        char fn[100] = "/home/kmnjkl/YD/Computer_technologies/Prakt/ex5/1_files/";
        char name[5] = "";
        strcat(name, letter);
        strcat(name, ".");
        strcat(name, letter);
        strcat(fn, name);
        printf("%s %s\n", name, fn);
        file = fopen(fn, "w");
        for (int j = 0; j < 10; j++) {
            fprintf(file, "Record N %d in file %s\n", j+1, name);
        }
        fclose(file);
    }

    return 0;
}
