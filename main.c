

#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <string.h>
#include "fileLoading.h"

static char instruction[] = "Rules of this game: \nPlayers create a multi digit number. Each player must enter a number. First number cannot be a zero. For example in decimal numeral system: after number 9 you can enter any number. After a number smaller than 9, you should enter any bigger. Numbers can't repeat more than a certain value of repetition. You enter this value and a base of numeral system in config.txt. A player who can't enter any more number loses the game.";

static struct argp argp = {0, 0, 0, instruction};


int checkInput(int x);
int max_fig;
int score = 0;
char input;
int prev_input = 0;
int repeat_fig[36];

int main(int argc, char** argv) {

    argp_parse(&argp, argc, argv, 0, 0, 0);


    char name1[30];
    char name2[30];
    printf("Welcome. Before we start, enter your names. Player 1: \n");
    scanf(" %s", name1);
    printf("Player 2: \n");
    scanf(" %s", name2);
    printf("%s begins the game. \n", name1);

    c = getconfig(); //getting configuration from config.txt via fileLoading

    char figures[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int convert[26];
    int m;
    for (m = 0; m <= 35; m++) {
        repeat_fig[m] = 0; //filling array of repetitions with zeros
        if (m >= 10 && m <= 35) { //filling conversion array with numbers from 10 to 35
            convert[m - 10] = m;
        }

    }
    int input2;
    max_fig = c.base - 1;
    int end = 0;
    int n = 0;
    char *game = malloc(200 * sizeof (char)); //for saving created number
    while (end == 0) {
        for (m = 0; m < n; m++) {
            printf("%c", game[m]);
        }
        scanf(" %c", &input);
        input = tolower(input);
        for (m = 0; m <= 25; m++) { //converting letters to decimal numbers
            if (input == figures[m]) {
                input2 = convert[m];
                break;
            } else {
                int x = input - '0'; //changing char to integer
                input2 = x;
                break;
            }
        }

        if (checkInput(input2) == 1) {
            printf("You entered wrong number.\n");
            for (m = input2; m <= 35; m++) { //checking if a player can enter any more numbers
                if (repeat_fig[m] == c.repeat) {
                    end = 1;
                    printf("End\n");
                    free(game);
                    break;
                }
                else {
                    end = 0;
                    break;
                }
            }
        } else {
            game[n] = input;
            n++;
            repeat_fig[input2] = repeat_fig[input2] + 1;
            score++;
            prev_input = input2;
        }

    }
    if (score % 2 == 0) printf("The winner is %s.\n", name2);
    else printf("The winner is %s.\n", name1);
}


// checkInput checks if numbers entered by player are following the rules.

int checkInput(int x) {
    int passed = 0;
    if (x < 0) passed = 1;
    if (score == 0 && x == 0) passed = 1;
    if (x > max_fig) passed = 1;
    if (prev_input != max_fig && x <= prev_input) passed = 1;
    if (repeat_fig[x] == c.repeat) passed = 1;

    return passed;
}