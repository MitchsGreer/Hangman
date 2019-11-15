#include "stats.h"
//


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   read_in_stats() Reads in stats saved on disk.             *
*                                                             *
*   @param games_played Where to store the data grabbed       *
*                       from disk                             *
*                                                             *
*   @return 1 if the file opened correctly, 0 otherwise.      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int read_in_stats(int * games_played)
{
    FILE * input = NULL;
    char buf[MAX_SIZE];

    input = fopen(STATS, "r");

    if(input)
    {
        fgets(buf, MAX_SIZE, input);
        *games_played = atoi(buf);
        fclose(input);
        return 1;
    }
    else
    {
        printf("Stats not opened correctly\n");
    }
    return 0;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   store_stats() Stores stats to disk.                       *
*                                                             *
*   @param games_played Stats to store to disk.               *
*                                                             *
*   @return 1 if the file opened correctly, 0 otherwise.      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int store_stats(int games_played)
{
    FILE * output = NULL;
    char buf[MAX_SIZE];

    output = fopen(STATS, "w");

    if(output)
    {
        myitoa(games_played, buf);
        fputs(buf, output);
        fclose(output);
        return 1;
    }
    else
    {
        printf("Stats not opened correctly");
    }
    return 0;   
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   print_stats() Prints stats to screen.                     *
*                                                             *
*   @param games_played Stats to print to screen.             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void print_stats(int games_played)
{
    printf("Games Played: %d\n", games_played);
}