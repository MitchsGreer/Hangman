
//standered libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 256
#define TOTAL_INCORRECT_GUESSES 10
#define SCOREBOARD "/home/mitchel/Documents/Projects/Hangman/complete_game/Resources/scoreboard"
#define STATS "/home/mitchel/Documents/Projects/Hangman/complete_game/Resources/stats"
#define TIME "/home/mitchel/Documents/Projects/Hangman/complete_game/Resources/time"

typedef struct player{
    char name[MAX_SIZE];
    int words_guessed;
    int players_stumped;
    int games_played;

}PLAYER;

//files from me
#include "../src/time.c"
#include "../src/input.c"
#include "../src/word.c"
#include "../src/menu.c"
#include "../src/play.c"
#include "../src/scoreboard.c"
#include "../src/stats.c"
