#pragma once
#ifndef PLAY_H
#define PLAY_H
#include "resource.h"
#include "scoreboard.h"
#include "time.h"
#include "word.h"
#include "input.h"
#include "dictionary.h"
//

//Functions
int play(struct PLAYER board[100], double *time, DICT *dictionary);
int print_frame(int incorrect_guess_count, char *guesses, int round, int total_correct_guesses, char *word);
void print_guesses(char *guesses);
void print_word(char *word, int size);
void print_frame_0(void);
void print_frame_1(void);
void print_frame_2(void);
void print_frame_3(void);
void print_frame_4(void);
void print_frame_5(void);
void print_frame_6(void);
void print_frame_7(void);
void print_frame_8(void);
void print_frame_9(void);
void print_loss_frame(char *answer, char *guesser, char *word_giver);
void print_win_frame(char *answer, char *guesser, char *word_giver);

#endif