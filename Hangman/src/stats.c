#include "../Resources/stats.h"
//

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

int print_stats(int games_played)
{
    printf("Games Played: %d\n", games_played);
    return 1;
}