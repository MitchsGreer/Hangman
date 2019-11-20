#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

//standered libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

//Deinfed constants
#define MAX_SIZE 256
#define TOTAL_INCORRECT_GUESSES 10
#define SCOREBOARD "../resources/scoreboard.txt"
#define STATS "../resources/stats.txt"
#define TIME "../resources/time.txt"
#define DICTIONARY "../resources/words.txt"

//How players are stored
typedef struct PLAYER{
    char name[MAX_SIZE];
    int words_guessed;
    int players_stumped;
    int games_played;
}PLAYER;

//How words will be stored in the dictionary
typedef struct WORD{
    struct WORD* right_word;
    struct WORD* left_word;
    char* word;
    int word_size;
}WORD;

//The dictionary
typedef struct DICT{
    struct WORD* start_word;
    char file[32];
    int num_words;
    int loaded_in;
}DICT;

#endif