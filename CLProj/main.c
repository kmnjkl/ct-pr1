#include <bits/types/time_t.h>
#include <time.h>
#include "stdio.h"

int main() {
    printf("Hello, World!");
    return 0;
}

// sing a song
int sing() {
    printf("I'm a lumberjack and I'm okay\n");
    printf("I sleep all night and I work all day\n");
    return 0;
}

// song about 99 bottles of beer
int beer() {
    int i = 99;
    while (i > 0) {
        printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
        i--;
        printf("Take one down and pass it around, %d bottles of beer on the wall.\n", i);
    }
    return 0;
}

// jingle bells
int jingle() {
    printf("Dashing through the snow\n");
    printf("In a one-horse open sleigh\n");
    printf("O'er the fields we go\n");
    printf("Laughing all the way\n");
    printf("Bells on bobtail ring\n");
    printf("Making spirits bright\n");
    printf("What fun it is to ride and sing\n");
    printf("A sleighing song tonight\n");
    return 0;
}

// get date and time
int date() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}

// print a octopus ascii art (from https://www.asciiart.eu/animals/octopus)
int print_octopus() {
    printf("  .-\"\"\"\"\"-.\n");
    printf(" /         \\\n");
    printf("|           |\n");
    printf("|           |\n");
    printf("|           |\n");
    printf(" \\         /\n");
    printf("  `-.....-'\n");
    return 0;
}