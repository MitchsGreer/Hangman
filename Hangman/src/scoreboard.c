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

int read_board_in(PLAYER board[100])
{
    int i = 0;
    char buf[MAX_SIZE] = {[0 ... MAX_SIZE-1] = '/0'};
    char num[3];
    char * temp;

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


int print_board(PLAYER board[100])
{
    int i;
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
    scanf("%c", &i);
}

//bubble sort taken from https://www.geeksforgeeks.org/bubble-sort/ on may 16 2019 22:50
//function was modified for the corect parameters
int sort_board(PLAYER board[100])
{
    int i, j; 
    double result_1 = 0, result_2 = 0;
    PLAYER temp;

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

int store_board(PLAYER board[100])
{
    int i = 0;
    char num[10] = {[0 ... 9] = '/0'};

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

int add_player(PLAYER board[100], char * name, int index)
{
    strcpy(board[index].name, name);
    return index;
}


int find_player(PLAYER board[100], char * name)
{
    int i;
    for(i =0; board[i].name[0]!= '\0';i++)
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
