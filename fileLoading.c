//Reading specific lines from a configuration file, returning base of numeral system and repetitions

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fileLoading.h"

struct configuration getconfig() {
    FILE *file;
    file = fopen("config.txt", "r");

    if (file != NULL) {
        char numeral [100];
        char repetition [100];
        int linenumeral = 2;
        int linerepeat = 4;
        int countline = 1;
        while (fgets(numeral, 100, file) != NULL) {
            if (countline == linenumeral) {
                break;
            } else countline++;
        }
        while (fgets(repetition, sizeof repetition, file) != NULL) {
            if (countline == linerepeat) {
                break;
            } else countline++;
        }

        a.base = atoi(numeral); //string to integer
        a.repeat = atoi(repetition);
        assert(a.repeat != 0); //checking if base and repetition are in config.txt
        assert(a.base != 0);
        if (a.base < 4 || a.base > 35) { //checking if base is correct
            printf("Error in config.txt - base");
            exit(1);
        }

    }
    fclose(file);
    return a;
}

