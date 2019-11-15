#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "resource.h"
//

char * myitoa(int num, char buf[]);
int read_board_in(struct PLAYER board[100]);
int print_board(struct PLAYER board[100]);
void sort_board(struct PLAYER board[100]);
int store_board(struct PLAYER board[100]);
int add_player(struct PLAYER board[100], char * name, int index);
int find_player(struct PLAYER board[100], char * name);

#endif