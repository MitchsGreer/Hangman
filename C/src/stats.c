////////////////////////////////////////////////////////////////////////////////
/// @file stats.c
///
/// @brief Implementation of functions for the stats handling of the game.
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#include "typedef.h"
#include "constants.h"
#include "scoreboard.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief Reads in stats saved on disk.
///
/// @param [out] games_played Where to store the data grabbed from disk.
///
/// @returns 1 if the file was able to be loaded, 0 otherwise.
////////////////////////////////////////////////////////////////////////////////
bool_t read_in_stats(uint* games_played)
{
    FILE * input = NULL;
    char buf[MAX_SIZE];
    bool_t success = FALSE;

    input = fopen(STATS_FILE, "r");

    if(input)
    {
        fgets(buf, MAX_SIZE, input);
        *games_played = atoi(buf);
        fclose(input);
        success = TRUE;
    }
    else
    {
        printf(STATS_FILE_OPEN_READ_ERROR);
    }
    return success;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Stores stats to disk.
///
/// @todo Add error macros and strings here.
///
/// @param [in] games_played Stats to store to disk.
///
/// @returns 1 if the file was able to be loaded, 0 otherwise.
////////////////////////////////////////////////////////////////////////////////
bool_t store_stats(uint games_played)
{
    FILE * output = NULL;
    char buf[MAX_SIZE];
    bool_t success = FALSE;

    output = fopen(STATS_FILE, "w");

    if(output)
    {
        myitoa(games_played, buf, MAX_SIZE);
        fputs(buf, output);
        fclose(output);
        success = TRUE;
    }
    else
    {
        printf(STATS_FILE_OPEN_WRITE_ERROR);
    }
    return success;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints stats to screen.
///
/// @param [in] games_played Stats to store to disk.
////////////////////////////////////////////////////////////////////////////////
void print_stats(uint games_played)
{
    printf("Games Played: %d\n", games_played);
}