////////////////////////////////////////////////////////////////////////////////
/// @file guess.h
///
/// @brief Functions for checking guesses.
////////////////////////////////////////////////////////////////////////////////
#ifndef GUESS_H
#define GUESS_H

#include <stddef.h>
#include "word.h"
#include "typedef.h"

uint check_guess(char* word, size_t size, char guess, char* answer);
bool_t check_guess_against_guesses(char* guesses, char guess);

#endif // GUESS_H