#include "scoreboard.h"
//

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   myitoa() Converts a number to a string.                   *
*                                                             *
*   @param num Given number to transform to a string.         *
*                                                             *
*   @param buf Where the string will be stored.               *
*                                                             *
*   @return Address of the start of the string.               *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
char * myitoa(int num, char buf[])
{  
    int k = 0;
    char c;
    while(num && k < 10)
    {
        buf[k] = (num % 10) + 48;
        num -= buf[k] - 48;
        num /= 10;
        k++;
    }
    buf[k] = 0;
    for(k = 0; k < strlen(buf)/2; k++)
    {
        c = buf[k];
        buf[k] = buf[strlen(buf) - 1 - k];
        buf[strlen(buf) - 1 - k] = c;
    }
    return buf;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   read_board_in() Reads the scoreboard from disk.           *
*                                                             *
*   @param board Scoreboard storing all players and           *
*                their scores.                                *
*                                                             *
*   @return 1 if the file opened correctly, 0 otherwise.      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int read_board_in(struct PLAYER board[100])
{
    int i = 0;
    char buf[MAX_SIZE] = {[0 ... MAX_SIZE-1] = 0};
    char num[3];

    FILE * infile = NULL;

    infile = fopen(SCOREBOARD, "r");

    if(infile)
    {

        while(!feof(infile))
        {
            fgets(buf, MAX_SIZE, infile);
            if(buf[0] != '0')
            {
                strcpy(board[i].name, strtok(buf, ","));
                strcpy(num, strtok(NULL, ","));
                board[i].players_stumped = atoi(num);
                strcpy(num, strtok(NULL, ","));
                board[i].words_guessed = atoi(num);
                strcpy(num, strtok(NULL, ","));
                board[i].games_played = atoi(num);
                i++;
            }
        } 
        fclose(infile);  
    }
    else
    {
        printf("board not opened properly\n");
        return 0;
    }
    
    return 1;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   print_board() Prints the scoreboard to the screen.        *
*                                                             *
*   @param board Scoreboard storing all players and           *
*                their scores.                                *
*                                                             *
*   @return Number of players that have played before.        *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int print_board(struct PLAYER board[100])
{
    int i;
    char c;
    printf("\n\n-----------------------  Score Board  ------------------------\n");
    printf("Name\t    | Stumped Players | Words Guessed | Games Played\n");
    printf("--------------------------------------------------------------\n");

    for(i = 0; i < 100; i++)
    {
        if(strcmp(board[i].name, ""))
        {
            printf("%s\t    |\t     %d        |       %d       |       %d\n", board[i].name, board[i].players_stumped, board[i].words_guessed, board[i].games_played);
        }
    }
    scanf("%c", &c);
    return i;
}


//bubble sort taken from https://www.geeksforgeeks.org/bubble-sort/ on may 16 2019 22:50
//function was modified for the correct parameters
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   sort_board() Sorts the score board.                       *
*                                                             *
*   @param board Scoreboard storing all players and           *
*                their scores.                                *
*                                                             *
*   @return Number of players that have played before.        *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void sort_board(struct PLAYER board[100])
{
    int i, j; 
    double result_1 = 0, result_2 = 0;
    struct PLAYER temp;

    for (i = 0; i < 100 - 1; i++)       
    {
        for (j = 0; j < 100-i-1; j++)  
        {
            if(board[j].games_played && board[j+1].games_played)
            {
                result_1 = ((board[j].players_stumped + board[j].words_guessed)/board[j].games_played);
                result_2 = ((board[j+1].players_stumped + board[j+1].words_guessed)/board[j+1].games_played);
                if (result_1 < result_2) 
                {
                    temp = board[j];
                    board[j] = board[j+1];
                    board[j+1] = temp;
                }
            }
        }
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   store_board() Writes the scoreboard to disk.              *
*                                                             *
*   @param board Scoreboard storing all players and           *
*                their scores.                                *
*                                                             *
*   @return 1 if the file opened correctly, 0 otherwise.      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int store_board(struct PLAYER board[100])
{
    int i = 0;
    char num[10] = {[0 ... 9] = 0};

    FILE * infile = NULL;

    infile = fopen(SCOREBOARD, "w");


    if(infile)
    {
        while(board[i].name[0] != '\0')
        {
            fputs(board[i].name, infile);
            fputs(",", infile);
            myitoa(board[i].players_stumped, num);
            if(num[0] == '\0')
            {
                num[0] = '0';
                num[1] = '\0';
            }
            fputs(num, infile);
            fputs(",", infile);
            myitoa(board[i].words_guessed, num);
            if(num[0] == '\0')
            {
                num[0] = '0';
                num[1] = '\0';
            }
            fputs(num, infile);
            fputs(",", infile);
            myitoa(board[i].games_played, num);
            if(num[0] == '\0')
            {
                num[0] = '0';
                num[1] = '\0';
            }
            fputs(num, infile);
            if(board[i + 1].name[0] != '\0' && i < 100)
            {
                fputc('\n', infile);
            }
            i++;
        }
        fclose(infile);
    }
    else
    {
        printf("file not opened properly\n");
        return 0;
    }

    return i;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \
*   add_player() Adds a new player entry to the scoreboard.      *
*                                                                *
*   @param board Scoreboard storing all players and              *
*                their scores.                                   *
*                                                                *
*   @param name Players name to be added to the scoreboard.      *
*                                                                *
*   @param index Index of the player on the board.               *
*                                                                *
*   @return Number of players that have played before.           *
\ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int add_player(struct PLAYER board[100], char * name, int index)
{
    strcpy(board[index].name, name);
    return index;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   find_player() Finds the index of a player by their name in   *
*                 the scoreboard.                                *
*                                                                *
*   @param board Scoreboard storing all players and              *
*                their scores.                                   *
*                                                                *
*   @param name Players name to be added to the scoreboard.      *
*                                                                *
*   @return Index of the player on the scoreboard, -1 if         *
*           not found.                                           *
\ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int find_player(struct PLAYER board[100], char * name)
{
    int i;
    for(i = 0; board[i].name[0] != '\0'; i++)
    {
        if(strcmp(board[i].name, name) == 0)
        {
            return i;
        }
    }
    if(i < 100)
    {
        add_player(board, name, i);
        return i;
    }
    return -1;
}