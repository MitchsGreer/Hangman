////////////////////////////////////////////////////////////////////////////////
/// @file menu.h
///
/// @brief Utilities providing menu mechanisms.
////////////////////////////////////////////////////////////////////////////////
#ifndef MENU_H
#define MENU_H

#include "player.h"
#include "typedef.h"
#include "constants.h"

void init(double* time, PLAYER board[SCOREBOARD_SIZE], uint* games_played);
void start(void);
void print_menu(void);
void navigate_menu(void);

#endif // MENU_H

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