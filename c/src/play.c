////////////////////////////////////////////////////////////////////////////////
/// @file play.c
///
/// @brief Implementation of functions for the main play of Hangman.
////////////////////////////////////////////////////////////////////////////////
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "play.h"
#include "player.h"
#include "constants.h"
#include "typedef.h"
#include "input.h"
#include "hang_time.h"
#include "scoreboard.h"
#include "guess.h"


////////////////////////////////////////////////////////////////////////////////
/// @brief An interface used to play the game from hangman.
///
/// @todo Check out check_guess_against_guesses and check_guess further.
///
/// @param [in] board The time played sofar in Hangman the game.
/// @param [out] time The total time taken playing this game.
///
/// @returns The player who won the game.
////////////////////////////////////////////////////////////////////////////////
player_t play(struct PLAYER board[SCOREBOARD_SIZE], double *time)
{
    player_t winner = GUESSER;
    char word[MAX_SIZE] = {'\0'};
    char guess = '\0';
    char word_giver[MAX_SIZE] = {'\0'};
    char word_guesser[MAX_SIZE] = {'\0'};
    char answer[MAX_SIZE] = {'\0'};
    char guesses[ALPHABET_LENGTH] = {'\0'};
    uint incorrect_guesses = 0;
    uint correct_guesses = 0;
    uint total_correct_guesses = 0;
    uint round_guesses = 0;
    uint round = 0;
    time_t my_time = 0;
    struct timespec sleep_time = {0, 5000000};
    struct timespec rem_time = {0, 0};

    // Init all of the arrays.
    memset(word, '\0', MAX_SIZE);
    memset(word_giver, '\0', MAX_SIZE);
    memset(word_guesser, '\0', MAX_SIZE);
    memset(answer, '\0', MAX_SIZE);
    memset(guesses, '\0', ALPHABET_LENGTH);

    //we need the names and the word first
    get_string(word_giver, MAX_SIZE, PROVIDER_PROMPT);
    get_string(word_guesser, MAX_SIZE, GUESSER_PROMPT);
    get_string(answer, MAX_SIZE, WORD_PROMPT);

    //now that we have those, we can start guessing
    total_correct_guesses = strlen(answer);
    my_time = start_time();

    // Start the game loop!
    while (incorrect_guesses < TOTAL_INCORRECT_GUESSES && correct_guesses < total_correct_guesses)
    {
        system("clear");
        round++;
        print_frame(incorrect_guesses, guesses, round, total_correct_guesses, word);
        do
        {
            guess = get_char(GUESS_PROMPT);
        } while (check_guess_against_guesses(guesses, guess) != FALSE || guess == '\n');

        guesses[round - 1] = guess;
        printf("%d %d\n", round, total_correct_guesses);
        round_guesses = check_guess(word, total_correct_guesses, guess, answer);
        if (round_guesses == 0)
        {
            ++incorrect_guesses;
        }
        correct_guesses += round_guesses;
    }

    // The game is over.
    *time += end_time(my_time);
    if (incorrect_guesses >= TOTAL_INCORRECT_GUESSES) //guesser loses
    {
        system("clear");
        print_loss_frame(answer, word_guesser, word_giver);
        board[find_player(board, word_giver)].players_stumped++;
        board[find_player(board, word_giver)].games_played++;
        board[find_player(board, word_guesser)].games_played++;
        return PROVIDER;
    }
    else //guesser wins
    {
        system("clear");
        print_win_frame(answer, word_guesser, word_giver);
        board[find_player(board, word_guesser)].words_guessed++;
        board[find_player(board, word_guesser)].games_played++;
        board[find_player(board, word_giver)].games_played++;
        return GUESSER;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief An interface to print the current frame of play.
///
/// @param [in] incorrect_guess_count The time played sofar in Hangman the game.
/// @param [in] guesses The total time taken playing this game.
/// @param [in] round
/// @param [in] total_correct_guesses
/// @param [in] word
////////////////////////////////////////////////////////////////////////////////
void print_frame(uint incorrect_guess_count, char *guesses, uint round, uint total_correct_guesses, char *word)
{
    void (*fptr[])(void) = {
        print_frame_0,
        print_frame_1,
        print_frame_2,
        print_frame_3,
        print_frame_4,
        print_frame_5,
        print_frame_6,
        print_frame_7,
        print_frame_8,
        print_frame_9
    };

    fptr[incorrect_guess_count]();
    printf("Round: %d \n", round);
    print_word(word, total_correct_guesses);
    print_guesses(guesses);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints all of the players guesses to the screen.
///
/// @param [in] guesses All the current guess the player has made.
////////////////////////////////////////////////////////////////////////////////
void print_guesses(char *guesses)
{
    size_t i = 0;
    printf("Guesses: %c", guesses[i]);
    for (i = 1; i < 26; i++)
    {
        if (guesses[i])
        {
            printf(", %c", guesses[i]);
        }
    }
    putchar('\n');
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints the word so far, filling in correct guesses the screen.
///
/// @param [in] word The word filled in with correct guesses.
/// @param [in] size The length of the word.
////////////////////////////////////////////////////////////////////////////////
void print_word(char *word, size_t size)
{
    printf("Word: ");
    for (size_t i = 0; i < size; i++)
    {
        if (word[i])
        {
            printf(" %c", word[i]);
        }
        else
        {
            printf(" _");
        }
    }
    putchar('\n');
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints the starting frame of Hangman
////////////////////////////////////////////////////////////////////////////////
void print_frame_0(void)
{
    printf("/----------------------------------------------------------------%c\033[0m\n", 92);
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_1(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_2(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_3(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_4(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_5(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_6(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_7(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_8(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints a frame of Hangman.
////////////////////////////////////////////////////////////////////////////////
void print_frame_9(void)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints the final frame of Hangman is the guesser loses.
///
/// @param [in] answer Thw word that was provided.
/// @param [in] guesser The player's name who is guessing.
/// @param [in] word_giver The player's name who provided the word.
////////////////////////////////////////////////////////////////////////////////
void print_loss_frame(char *answer, char *guesser, char *word_giver)
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
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Prints the final frame of Hangman is the guesser wins.
///
/// @param [in] answer Thw word that was provided.
/// @param [in] guesser The player's name who is guessing.
/// @param [in] word_giver The player's name who provided the word.
////////////////////////////////////////////////////////////////////////////////
void print_win_frame(char *answer, char *guesser, char *word_giver)
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
}