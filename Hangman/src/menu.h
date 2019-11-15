#pragma once
#ifndef MENU_H
#define MENU_H
#include "resource.h"
#include "scoreboard.h"
#include "time.h"
#include "stats.h"
#include "play.h"
#include "input.h"
//

void init(double *time, PLAYER board[100], int* games_played);
void print_menu(void);
int navigate_menu(void);

#endif

/* * * * * * * * * * * * * * * \
*   Colors for font:           *
*                              *
*   [0;31m	Red                *
*   [1;31m	Bold Red           *
*   [0;32m	Green              *
*   [1;32m	Bold Green         *
*   [0;33m	Yellow             *
*   [01;33m	Bold Yellow        *
*   [0;34m	Blue               *
*   [1;34m	Bold Blue          *
*   [0;35m	Magenta            *
*   [1;35m	Bold Magenta       *
*   [0;36m	Cyan               *
*   [1;36m	Bold Cyan          *
*   [0m	Reset                  *
\ * * * * * * * * * * * * * * */ 