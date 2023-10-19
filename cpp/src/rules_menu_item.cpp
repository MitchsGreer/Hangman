///////////////////////////////////////////////////////////////////////////////
/// @file rules_menu_item.cpp
///
/// @brief Implementation for the rules selection in the menu of Hangman.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "rules_menu_item.hpp"

///////////////////////////////////////////////////////////////////////////////
/// @brief Main entry action for the rules option, this will print the rules
///        for hangman.
///
/// @returns Always returns true.
///////////////////////////////////////////////////////////////////////////////
bool RulesMenuItem::enter()
{
    std::cout << "Hangman Rules:" << std::endl;
    std::cout << "One individual comes up with a word and the other guesses letters, or words, until the word is guessed or the hangman is complete." << std::endl;

    return true;
}