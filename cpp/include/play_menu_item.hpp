///////////////////////////////////////////////////////////////////////////////
/// @file play_menu_item.hpp
///
/// @brief Definition for the play selection in the menu of Hangman.
///////////////////////////////////////////////////////////////////////////////
#ifndef PLAY_MENU_ITEM_H
#define PLAY_MENU_ITEM_H

#include <string>
#include "menu_item.hpp"

#define PLAY_NAME_STRING "play"
#define PLAY_HELP_STRING "Play the game of hangman."

class PlayMenuItem : public MenuItem
{
public:
    PlayMenuItem() : MenuItem(PLAY_NAME_STRING, PLAY_HELP_STRING){};
    ~PlayMenuItem(){};

    bool enter();

private:
};

#endif // PLAY_MENU_ITEM_H