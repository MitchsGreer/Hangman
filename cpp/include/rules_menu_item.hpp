///////////////////////////////////////////////////////////////////////////////
/// @file rules_menu_item.cpp
///
/// @brief Definition for the rules selection in the menu of Hangman.
///////////////////////////////////////////////////////////////////////////////
#ifndef RULES_MENU_ITEM_H
#define RULES_MENU_ITEM_H

#include <string>
#include "menu_item.hpp"

#define RULES_NAME_STRING "rules"
#define RULES_HELP_STRING "View rules of hangman."

class RulesMenuItem : public MenuItem
{
public:
    RulesMenuItem() : MenuItem(RULES_NAME_STRING, RULES_HELP_STRING){};
    ~RulesMenuItem(){};

    bool enter();

private:
};

#endif // RULES_MENU_ITEM_H