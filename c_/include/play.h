////////////////////////////////////////////////////////////////////////////////
/// @file play.h
///
/// @brief Functions containing the main play of the game.
////////////////////////////////////////////////////////////////////////////////
#ifndef PLAY_H
#define PLAY_H

#include "player.h"
#include "typedef.h"
#include "constants.h"

player_t play(struct PLAYER board[SCOREBOARD_SIZE], double* time);
void print_frame(uint incorrect_guess_count, char* guesses, uint round, uint total_correct_guesses, char* word);
void print_guesses(char* guesses);
void print_word(char* word, size_t size);
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
void print_loss_frame(char* answer, char* guesser, char* word_giver);
void print_win_frame(char* answer, char* guesser, char* word_giver);

#endif // PLAY_H