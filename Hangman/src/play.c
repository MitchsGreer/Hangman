#include "../Resources/play.h"
//





/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   play() An interface used to play the game from hangman.   *
*                                                             *
*   @param board The scoreboard of all people who have played *
*                this game.                                   *
*   @param time The total time taken playing this game.       *
*                                                             *
*   @return The number of the player who won the game,        *
*           1 for the word giver and 2 for the guesser.       *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int play(struct PLAYER board[100], double * time)
{
    char word[MAX_SIZE] = {[0 ... MAX_SIZE-1] = '\0'}, guess, word_giver[MAX_SIZE], word_guesser[MAX_SIZE];
    char answer[MAX_SIZE] = {[0 ... MAX_SIZE-1] = '\0'}, guesses[26] = {[0 ... 25] = '\0'};
    int incorrect_guesses = 0, correct_guesses = 0, total_correct_guesses = 0, round_guesses = 0, round = 0;
    time_t my_time;

    //we need the names and the word first
    get_name(word_giver, MAX_SIZE, "Who is providing the word: ");
    get_name(word_guesser, MAX_SIZE, "Who is guessing: ");
    get_name(answer, MAX_SIZE, "What is the word: ");

    //now that we have those, we can start guessing
    total_correct_guesses = strlen(answer);
    my_time = start_time();
    while(incorrect_guesses < TOTAL_INCORRECT_GUESSES && correct_guesses < total_correct_guesses)
    {
        system("clear");
        ++round;
        print_frame(incorrect_guesses, guesses, round, total_correct_guesses, word);
        do
        {
            guess = get_guess("What do you guess: ");
        }while(check_guess_against_guesses(guesses, guess) != 0 || guess == '\n');
        guesses[round - 1] = guess;
        round_guesses = check_guess(word, total_correct_guesses, guess, answer);
        if(round_guesses == 0)
        {
            ++incorrect_guesses;
        }
        correct_guesses += round_guesses;
    }
    *time += end_time(my_time); 
    if(incorrect_guesses >= TOTAL_INCORRECT_GUESSES) //guesser loses
    {
        system("clear");
        print_loss_frame(answer, word_guesser, word_giver);
        board[find_player(board, word_giver)].players_stumped++;
        board[find_player(board, word_giver)].games_played++;
        board[find_player(board, word_guesser)].games_played++;
        return 1;
    }
    else                                            //guesser wins
    {
        system("clear");
        print_win_frame(answer, word_guesser, word_giver);
        board[find_player(board, word_guesser)].words_guessed++;
        board[find_player(board, word_guesser)].games_played++;
        board[find_player(board, word_giver)].games_played++;
        return 2;
    }
    
}






/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   get_name() is an interface that reads in a name or word   *
*   from the player.                                          *
*                                                             *
*   @param name The charactor array holding the name or word  *
*               that inputed by the player.                   *
*   @param size The size of the charactor array holding the   *
*               name or read read in from the player.         *
*   @param message The message to accompany the read from the *
*               player.                                       *
*   @return A pointer to the start of the charactor array.    *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
int print_frame(int incorrect_guess_count, char * guesses, int round, int total_correct_guesses, char * word)
{
    int (*fptr[])(void) = {(int (*)())print_frame_0,print_frame_1,print_frame_2,print_frame_3,
                           print_frame_4,print_frame_5,print_frame_6,print_frame_7, 
                           print_frame_8,print_frame_9};
    
    fptr[incorrect_guess_count]();
    printf("Round: %d \n", round);
    print_word(word, total_correct_guesses);
    print_guesses(guesses);
    return 1;
}

int print_guesses(char * guesses)
{
    int i = 0;
    printf("Guesses: %c", guesses[i]);
    for(i = 1; i < 26; i++)
    {
        if(guesses[i])
        {
            printf(", %c", guesses[i]);
        }
    }
    putchar('\n');
    return 1;
}

int print_word(char * word, int size)
{
    int i = 0;
    if(word[i])
    {
        printf("Word: %c", word[i]);
    }
    else
    {
        printf("Word: _");
    }
    for(i = 1; i < size; i++)
    {
        if(word[i])
        {
            printf(" %c", word[i]);
        }
        else
        {
            printf(" _");
        }
        
    }
    putchar('\n');
    return 1;
}

int print_frame_0(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_1(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O                          |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_2(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_3(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_4(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |          %c                         |\n", 92);
    printf("|                           |           %c                        |\n", 92);
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_5(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |        / %c                         |\n", 92);
    printf("|                           |       /   %c                        |\n", 92);
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_6(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O /                        |\n");
    printf("|                           |         |/                         |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |        / %c                         |\n", 92);
    printf("|                           |       /   %c                        |\n", 92);
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_7(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |       %c O /                        |\n", 92);
    printf("|                           |        %c|/                         |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |        / %c                         |\n", 92);
    printf("|                           |       /   %c                        |\n", 92);
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_8(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |       %c O /                        |\n", 92);
    printf("|                           |        %c|/                         |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |        / %c                         |\n", 92);
    printf("|                           |       /   %c_                       |\n", 92);
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_frame_9(void)
{
    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |       %c O /                        |\n", 92);
    printf("|                           |        %c|/                         |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         |                          |\n");
    printf("|                           |        / %c                         |\n", 92);
    printf("|                           |      _/   %c_                       |\n", 92);
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);
    return 1;
}

int print_loss_frame(char * answer, char * guesser, char * word_giver)
{
    char throwaway;

    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                           /---------%c                          |\n", 92);
    printf("|                           |         |                          |\n");
    printf("|                           |         O                          |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |                                    |\n");
    printf("|                           |  %c        /                        |\n", 92);
    printf("|                           |   %c      /                         |\n", 92);
    printf("|                           |    --------                        |\n");
    printf("|                           |   /      %c                         |\n", 92);
    printf("|                           |  /        %c                        |\n", 92);
    printf("|                  ---------------------                         |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);

    printf("Word: %s \n", answer);
    printf("%s beat %s \n", word_giver, guesser);
    scanf("%c", &throwaway);
    scanf("%c", &throwaway);
    return 1;
}

int print_win_frame(char * answer, char * guesser, char * word_giver)
{
    char throwaway;

    printf("/----------------------------------------------------------------%c\n", 92);
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                            %c O /                               |\n", 92);
    printf("|                             %c|/                                |\n", 92);
    printf("|                              |                                 |\n");
    printf("|                              |                                 |\n");
    printf("|                             / %c                                |\n", 92);
    printf("|                           _/   %c_                              |\n", 92);
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("|                                                                |\n");
    printf("%c----------------------------------------------------------------/\n", 92);

    printf("Word: %s \n", answer);
    printf("%s beat %s \n", guesser, word_giver);
    scanf("%c", &throwaway);
    scanf("%c", &throwaway);
    return 1;
}