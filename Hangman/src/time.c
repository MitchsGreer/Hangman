#include "../Resources/time.h"
//

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

int print_time(double time, int games)
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

    return 1;
}

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

time_t start_time(void)
{
    return time(NULL);
}

double end_time(time_t my_time)
{
    time_t my_time_2;
    my_time_2 = time(NULL);
    return difftime(my_time_2, my_time);
}