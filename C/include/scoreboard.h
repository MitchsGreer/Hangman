////////////////////////////////////////////////////////////////////////////////
/// @file scoreboard.h
///
/// @brief Functions for interacting with the scoreboard.
////////////////////////////////////////////////////////////////////////////////
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "player.h"
#include "typedef.h"
#include "constants.h"

char* myitoa(uint num, char* buf, size_t buf_size);
bool_t read_board_in(struct PLAYER board[SCOREBOARD_SIZE]);
uint print_board(struct PLAYER board[SCOREBOARD_SIZE]);
void sort_board(struct PLAYER board[SCOREBOARD_SIZE]);
bool_t store_board(struct PLAYER board[SCOREBOARD_SIZE]);
void add_player(struct PLAYER board[SCOREBOARD_SIZE], char* name, uint index);
int find_player(struct PLAYER board[SCOREBOARD_SIZE], char* name);

#endif // SCOREBOARD_H