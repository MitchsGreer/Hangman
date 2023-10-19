////////////////////////////////////////////////////////////////////////////////
/// @file play.c
///
/// @brief Implementation of functions for the main play of Hangman.
////////////////////////////////////////////////////////////////////////////////
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scoreboard.h"
#include "constants.h"
#include "typedef.h"


////////////////////////////////////////////////////////////////////////////////
/// @brief Converts a number to a string.
///
/// @param [in] num Given number to transform to a string.
/// @param [out] buf Where the string will be stored.
/// @param [in] buf_size The size of the string buffer.
///
/// @returns  Address of the start of the string.
////////////////////////////////////////////////////////////////////////////////
char* myitoa(uint num, char* buf, size_t buf_size)
{
    size_t k = 0;
    char c = '\0';

    // Convert the number to a string.
    while (num && k < buf_size)
    {
        buf[k] = (num % 10) + 48;
        num -= buf[k] - 48;
        num /= 10;
        k++;
    }
    buf[k] = '\0';

    // Flip the string representation.
    for (k = 0; k < strlen(buf) / 2; k++)
    {
        c = buf[k];
        buf[k] = buf[strlen(buf) - 1 - k];
        buf[strlen(buf) - 1 - k] = c;
    }
    return buf;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Reads the scoreboard from disk.
///
/// @param [in,out] board Scoreboard storing all players and their scores.
///
/// @returns 1 if the file was able to be loaded, 0 otherwise.
////////////////////////////////////////////////////////////////////////////////
bool_t read_board_in(struct PLAYER board[SCOREBOARD_SIZE])
{
    int i = 0;
    char buf[MAX_SIZE];
    char num[3];
    FILE *infile = NULL;
    bool_t success = FALSE;

    infile = fopen(SCOREBOARD_FILE, "r");

    for(size_t i = 0; i < SCOREBOARD_SIZE; i++)
    {
        memset(board[i].name, '\0', MAX_SIZE);
        board[i].players_stumped = 0;
        board[i].words_guessed = 0;
        board[i].games_played = 0;
    }

    if (infile)
    {
        while (!feof(infile))
        {
            if (fgets(buf, MAX_SIZE, infile) != NULL)
            {
                sscanf(
                    buf,
                    "%s %d %d %d",
                    board[i].name,
                    &(board[i].players_stumped),
                    &(board[i].words_guessed),
                    &(board[i].games_played)
                );
                i++;
            }
        }
        fclose(infile);
        success = TRUE;
    }
    else
    {
        printf(SCOREBOARD_FILE_OPEN_READ_ERROR);
    }

    return success;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints the scoreboard to the screen.
///
/// @param [in] board board Scoreboard storing all players and their scores.
///
/// @returns Number of players that have played before.
////////////////////////////////////////////////////////////////////////////////
uint print_board(struct PLAYER board[SCOREBOARD_SIZE])
{
    uint i = 0;
    printf("\n\n-----------------------  Score Board  ------------------------\n");
    printf("Name\t    | Stumped Players | Words Guessed | Games Played\n");
    printf("--------------------------------------------------------------\n");

    for (uint i = 0; i < SCOREBOARD_SIZE; i++)
    {
        if (strcmp(board[i].name, ""))
        {
            printf("%s\t    |\t     %d        |       %d       |       %d\n", board[i].name, board[i].players_stumped, board[i].words_guessed, board[i].games_played);
        }
    }
    getchar();

    return i;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Sorts the score board. (Slowly)
///
/// @details Bubble sort taken from:
///             https://www.geeksforgeeks.org/bubble-sort/ on may 16 2019 22:50
///          function was modified for the correct parameters.
///
/// @param [in] board Scoreboard storing all players and their scores.
////////////////////////////////////////////////////////////////////////////////
void sort_board(struct PLAYER board[SCOREBOARD_SIZE])
{
    int i, j;
    double result_1 = 0, result_2 = 0;
    struct PLAYER temp;

    for (i = 0; i < SCOREBOARD_SIZE - 1; i++)
    {
        for (j = 0; j < SCOREBOARD_SIZE - i - 1; j++)
        {
            if (board[j].games_played && board[j + 1].games_played)
            {
                result_1 = ((board[j].players_stumped + board[j].words_guessed) / board[j].games_played);
                result_2 = ((board[j + 1].players_stumped + board[j + 1].words_guessed) / board[j + 1].games_played);
                if (result_1 < result_2)
                {
                    temp = board[j];
                    board[j] = board[j + 1];
                    board[j + 1] = temp;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Writes the scoreboard to disk.
///
/// @todo Add helper function to write each part of the line.
///
/// @details Bubble sort taken from:
///             https://www.geeksforgeeks.org/bubble-sort/ on may 16 2019 22:50
///          function was modified for the correct parameters.
///
/// @param [in] board Scoreboard storing all players and their scores.
///
/// @return 1 if the file opened correctly, 0 otherwise.
////////////////////////////////////////////////////////////////////////////////
bool_t store_board(struct PLAYER board[SCOREBOARD_SIZE])
{
    int i = 0;
    char num[NUM_BUFFER_LENGTH];
    FILE *infile = NULL;
    bool_t success = FALSE;

    infile = fopen(SCOREBOARD_FILE, "w+");

    if (infile)
    {
        while (board[i].name[0] != '\0')
        {
            fprintf(
                infile,
                "%s %d %d %d\n",
                board[i].name,
                board[i].players_stumped,
                board[i].words_guessed,
                board[i].games_played
            );
            i++;
        }
        fclose(infile);
        success = TRUE;
    }
    else
    {
        printf(SCOREBOARD_FILE_OPEN_WRITE_ERROR);
    }

    return success;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Adds a new player entry to the scoreboard.
///
/// @todo Add error macros and strings here.
///
/// @param [in] board Scoreboard storing all players and their scores.
/// @param [in] name Players name to be added to the scoreboard.
/// @param [in] index Index of the player on the board.
////////////////////////////////////////////////////////////////////////////////
void add_player(struct PLAYER board[SCOREBOARD_SIZE], char *name, uint index)
{
    strcpy(board[index].name, name);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Finds the index of a player by their name in the scoreboard.
///
/// @param [in] board Scoreboard storing all players and their scores.
/// @param [in] name Players name to be added to the scoreboard.
///
/// @returns Index of the player on the scoreboard, -1 if not found.
////////////////////////////////////////////////////////////////////////////////
int find_player(struct PLAYER board[SCOREBOARD_SIZE], char *name)
{
    int i;
    for (i = 0; board[i].name[0] != '\0'; i++)
    {
        if (strcmp(board[i].name, name) == 0)
        {
            return i;
        }
    }

    if (i < SCOREBOARD_SIZE)
    {
        add_player(board, name, i);
        return i;
    }
    return -1;
}