

int print_menu(void)
{
    printf("----------Welcome to Hangman----------\n");
    printf("----------       Play       ----------\n");
    printf("----------    Score Board   ----------\n");
    printf("----------       Stats      ----------\n");
    printf("----------       Exit       ----------\n");
    return 1;
}

int navigate_menu(void)
{
    char option[MAX_SIZE] = {[0 ... MAX_SIZE-1] = '/0'};
    PLAYER board[100] = {[0 ... 99] = {"", 0,0,0}};
    int games_played = 0;
    double time = 0;

    read_in_time(&time);
    read_board_in(board); 
    read_in_stats(&games_played);
    sort_board(board);
    store_board(board);
    store_time(time);
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