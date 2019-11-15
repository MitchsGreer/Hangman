#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

//standered libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

//Deinfed constants
#define MAX_SIZE 256
#define TOTAL_INCORRECT_GUESSES 10
#define SCOREBOARD "../resources/scoreboard"
#define STATS "../resources/stats"
#define TIME "../resources/time"

//How players are stored
typedef struct PLAYER{
    char name[MAX_SIZE];
    int words_guessed;
    int players_stumped;
    int games_played;
}PLAYER;

#endif