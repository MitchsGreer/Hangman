#include "time.h"
//


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   read_in_time() Reads in stats saved on disk.              *
*                                                             *
*   @param time Where to store the data grabbed from disk.    *
*                                                             *
*   @return 1 if the file opened correctly, 0 otherwise.      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int read_in_time(double * time)
{
    FILE * infile;
    infile = fopen(TIME, "r");

    if(infile)
    {
        fscanf(infile, "%lf", time);
        fclose(infile);
        return 1;
    }
    else
    {
        printf("Time did not open properly to read\n");
        return 0;
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   print_time() Prints the total time played, and avg time   *
*                played per game.                             *
*                                                             *
*   @param time Total time playing the game.                  *
*                                                             *
*   @param games Total games played.                          *
*                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void print_time(double time, int games)
{
    char c;

    printf("Total time taken: %lfs\n", time);
    if(games != 0)
    {
        printf("Avg time per game: %lfs\n", time/games);
    }
    else
    {
        printf("Avg time per game: 0\n");   
    }
    
    scanf("%c", &c);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   store_time() Stores total time played on disk.            *
*                                                             *
*   @param time Total time to store on disk.                  *
*                                                             *
*   @return 1 if the file opened correctly, 0 otherwise.      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int store_time(double time)
{
    FILE * outfile;

    outfile = fopen(TIME, "w+");

    if(outfile)
    {
        fprintf(outfile, "%lf", time);
        fclose(outfile);
    }
    else
    {
        printf("Failed to open time to write\n");
        return 0;
    }
    return 1;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   store_time() Grabs the current time.                      *
*                                                             *
*   @return The current time.                                 *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
time_t start_time(void)
{
    return time(NULL);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   end_time() Calculates the difference in time from the     *
*              given time to now.                             *
*                                                             *
*   @return Te difference in time.                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double end_time(time_t my_time)
{
    time_t my_time_2;
    my_time_2 = time(NULL);
    return difftime(my_time_2, my_time);
}