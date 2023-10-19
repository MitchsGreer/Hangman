///////////////////////////////////////////////////////////////////////////////
/// @file stats_menu_item.cpp
///
/// @brief Definition for the stats selection in the menu of Hangman.
///////////////////////////////////////////////////////////////////////////////
#ifndef STATS_MENU_ITEM_H
#define STATS_MENU_ITEM_H

#include <string>
#include "menu_item.hpp"

#define STATS_NAME_STRING "stats"
#define STATS_HELP_STRING "View stats of previous hangman games."

class StatsMenuItem : public MenuItem
{
public:
    StatsMenuItem() : MenuItem(STATS_NAME_STRING, STATS_HELP_STRING){};
    ~StatsMenuItem(){};

    bool enter();

private:
};

#endif // STATS_MENU_ITEM_H