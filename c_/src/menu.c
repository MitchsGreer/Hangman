////////////////////////////////////////////////////////////////////////////////
/// @file menu.c
///
/// @brief Implementation of menu functions.
////////////////////////////////////////////////////////////////////////////////
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "menu.h"
#include "constants.h"
#include "typedef.h"
#include "hang_time.h"
#include "scoreboard.h"
#include "stats.h"
#include "input.h"
#include "play.h"


////////////////////////////////////////////////////////////////////////////////
/// @brief An interface that initializes the game.
///
/// @param [in] time The time played sofar in Hangman the game.
/// @param [in] board The scoreboard of all people who have played this game.
/// @param [in] games_played Total games of Hangman played.
////////////////////////////////////////////////////////////////////////////////
void init(double *time, PLAYER board[SCOREBOARD_SIZE], uint* games_played)
{
    bool_t time_success = FALSE;
    bool_t stats_success = FALSE;
    bool_t scoreboard_success = FALSE;

    time_success = read_in_time(time);
    stats_success = read_board_in(board);
    scoreboard_success = read_in_stats(games_played);

    if (time_success == TRUE)
    {
        store_time(*time);
    }

    if (scoreboard_success == TRUE)
    {
        sort_board(board);
        store_board(board);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief An interface that starts the threads for the game.
////////////////////////////////////////////////////////////////////////////////
void start(void)
{
    navigate_menu();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Displays the menu options for Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_menu(void)
{
    printf("\033[0;32m----------Welcome to Hangman----------\033[0m\n");
    printf("----------       Play       ----------\n");
    printf("----------    Score Board   ----------\n");
    printf("----------       Stats      ----------\n");
    printf("----------       Exit       ----------\n");
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Allows the user to select a menu option.
////////////////////////////////////////////////////////////////////////////////
void navigate_menu(void)
{
    char option[MAX_SIZE] = {'\0'};
    struct PLAYER board[SCOREBOARD_SIZE];
    uint games_played = 0;
    double time = 0;

    while (1)
    {
        system("clear");
        print_menu();
        init(&time, board, &games_played);
        get_string(option, MAX_SIZE, MAIN_MENU_PROMPT);
        to_lower(option);

        if (strcmp(option, PLAY_OPTION) == 0)
        {
            play(board, &time);
            games_played++;
            store_board(board);
            store_stats(games_played);
            store_time(time);
        }
        else if (strcmp(option, SCOREBOARD_OPTION) == 0)
        {
            print_board(board);
        }
        else if (strcmp(option, STATS_OPTIONS) == 0)
        {
            print_stats(games_played);
            print_time(time, games_played);
        }
        else if (strcmp(option, EXIT_OPTION) == 0)
        {
            exit(0);
        }
    }
}