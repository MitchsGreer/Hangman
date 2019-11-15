#pragma once
#ifndef WORD_H
#define WORD_H
#include "resource.h"
//

int check_guess(char * word, int size, char guess, char * answer);
int check_guess_against_guesses(char * guesses, char guess);
#endif