#include "menu.h"
//


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   init() is an interface that initializes the game.         *
*                                                             *
*   @param time The time played sofar in Hangman the game.    *
*                                                             *
*   @param board The scoreboard of all people who have played *
*                this game.                                   *
*                                                             *
*   @param games_played Total games of Hangman played.        *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void init(double *time, PLAYER board[100], int* games_played)
{
    read_in_time(time);
    read_board_in(board); 
    read_in_stats(games_played);
    sort_board(board);
    store_board(board);
    store_time(*time);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   print_menu() Displays the menu options for Hangman.       *
*                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void print_menu(void)
{
    printf("\033[0;32m----------Welcome to Hangman----------\033[0m\n");
    printf("----------       Play       ----------\n");
    printf("----------    Score Board   ----------\n");
    printf("----------       Stats      ----------\n");
    printf("----------       Exit       ----------\n");
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   navigate_menu() Allows the user to select a menu option.  *
*                                                             *
*   @return An integer, returns 1 if the user does not exit.  *
*           the game.                                         *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int navigate_menu(void)
{
    char option[MAX_SIZE] = {[0 ... MAX_SIZE-1] = 0};
    struct PLAYER board[100] = {[0 ... 99] = {"", 0,0,0}};
    int games_played = 0;
    double time = 0;

    init(&time, board, &games_played);
    print_menu();
    get_name(option, MAX_SIZE, "Please provide your option: ");

    if(strcmp(option, "play") == 0 || strcmp(option, "Play") == 0)
    {
        play(board, &time);
        games_played++;
        store_board(board);
        store_stats(games_played);
        store_time(time);
    }
    else if(strcmp(option, "score board") == 0 || strcmp(option, "Score board") == 0 || strcmp(option, "score Board") == 0 || strcmp(option, "Score Board") == 0)
    {  
        print_board(board); 
    }
    else if(strcmp(option, "stats") == 0 || strcmp(option, "Stats") == 0)
    {
        print_stats(games_played);
        print_time(time, games_played);
    }
    else if(strcmp(option, "exit") == 0 || strcmp(option, "Exit") == 0)
    {
        exit(0);
    }
    return 1;
}