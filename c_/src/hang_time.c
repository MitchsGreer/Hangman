////////////////////////////////////////////////////////////////////////////////
/// @file hang_time.c
///
/// @brief Implementation of time utilities.
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "hang_time.h"
#include "typedef.h"
#include "constants.h"


////////////////////////////////////////////////////////////////////////////////
/// @brief Reads the time played Hangman from disk.
///
/// @param [out] time The time spent playing Hangman.
///
/// @returns TRUE if the file was able to be loaded, FALSE otherwise.
////////////////////////////////////////////////////////////////////////////////
bool_t read_in_time(double * time)
{
    FILE * infile;
    infile = fopen(TIME_FILE, "r");
    bool_t success = FALSE;

    if(infile)
    {
        fscanf(infile, "%lf", time);
        fclose(infile);
        success = TRUE;
    }
    else
    {
        printf(TIME_FILE_OPEN_READ_ERROR);
    }

    return success;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints the total time played, and avg time played per game.
///
/// @param [in] time The time spent playing Hangman.
/// @param [in] games The number of games a player has played.
////////////////////////////////////////////////////////////////////////////////
void print_time(double time, uint games)
{
    printf("Total time taken: %lfs\n", time);
    if(games != 0)
    {
        printf("Avg time per game: %lfs\n", time/games);
    }
    else
    {
        printf("Avg time per game: 0\n");
    }

    getchar();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Stores total time played on disk.
///
/// @param [out] time Total time to store on disk.
///
/// @returns TRUE if the file was able to be loaded, FALSE otherwise.
////////////////////////////////////////////////////////////////////////////////
bool_t store_time(double time)
{
    FILE * outfile;
    bool_t success = FALSE;

    outfile = fopen(TIME_FILE, "w+");

    if(outfile)
    {
        fprintf(outfile, "%lf", time);
        fclose(outfile);
        success = TRUE;
    }
    else
    {
        printf(TIME_FILE_OPEN_WRITE_ERROR);
    }

    return success;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Grabs the current time.
///
/// @returns The current time.
////////////////////////////////////////////////////////////////////////////////
time_t start_time(void)
{
    return time(NULL);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Calculates the difference in time from the given time to now.
///
/// @param [in] my_time The start time.
///
/// @returns The difference in time.
////////////////////////////////////////////////////////////////////////////////
double end_time(time_t my_time)
{
    time_t my_time_2;
    my_time_2 = time(NULL);
    return difftime(my_time_2, my_time);
}