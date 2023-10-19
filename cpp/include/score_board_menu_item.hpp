///////////////////////////////////////////////////////////////////////////////
/// @file stats_menu_item.cpp
///
/// @brief Definition for the stats selection in the menu of Hangman.
///////////////////////////////////////////////////////////////////////////////
#ifndef SCORE_BOARD_MENU_ITEM_H
#define SCORE_BOARD_MENU_ITEM_H

#include <string>
#include "menu_item.hpp"

#define SCORE_BOARD_NAME_STRING "board"
#define SCORE_BOARD_HELP_STRING "View the scoreboard of previous hangman players."

class ScoreBoardMenuItem : public MenuItem
{
public:
    ScoreBoardMenuItem() : MenuItem(SCORE_BOARD_NAME_STRING, SCORE_BOARD_HELP_STRING){};
    ~ScoreBoardMenuItem(){};

    bool enter();

private:
};

#endif // SCORE_BOARD_MENU_ITEM_H