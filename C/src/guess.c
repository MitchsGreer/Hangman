////////////////////////////////////////////////////////////////////////////////
/// @file guess.c
///
/// @brief Implementation of functions for checking guesses.
////////////////////////////////////////////////////////////////////////////////
#include <stddef.h>
#include <stdio.h>
#include "word.h"
#include "typedef.h"
#include "constants.h"


////////////////////////////////////////////////////////////////////////////////
/// @brief Checks if the players guessed letter was in the hidden word.
///
/// @param [in] word The revealed letters so far.
/// @param [in] size The size of the word.
/// @param [in] guess The players guess.
/// @param [in] answer The hidden word.
///
/// @return How many correct guesses the player has made so far.
////////////////////////////////////////////////////////////////////////////////
uint check_guess(char* word, size_t size, char guess, char* answer)
{
    uint correct_guesses = 0;

    for(size_t i = 0; i < size; i++)
    {
        if(answer[i] == guess)
        {
            word[i] = guess;
            correct_guesses++;
        }
    }
    return correct_guesses;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Checks if the players guessed letter was already guessed.
///
/// @param [in] guesses All of the players guesses so far.
/// @param [in] guess The players guess.
///
/// @return 1 if it has, 0 if not.
////////////////////////////////////////////////////////////////////////////////
bool_t check_guess_against_guesses(char* guesses, char guess)
{
    int i;
    bool_t found = FALSE;

    for(i = 0; i < ALPHABET_LENGTH; i++)
    {
        if(guesses[i] == guess)
        {
            found = 1;
        }
    }
    return found;
}
