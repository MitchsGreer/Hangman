///////////////////////////////////////////////////////////////////////////////
/// @file main.cpp
///
/// @brief This is the main entrypoint for this application.
///////////////////////////////////////////////////////////////////////////////
#include "menu.hpp"
#include "menu_item.hpp"
#include "play_menu_item.hpp"
#include "stats_menu_item.hpp"
#include "rules_menu_item.hpp"
#include "score_board_menu_item.hpp"

int main(int argc, char* argv[])
{
    Menu main_menu("Hangman");
    std::unique_ptr<MenuItem> play_menu_item(new PlayMenuItem());
    std::unique_ptr<MenuItem> stats_menu_item(new StatsMenuItem());
    std::unique_ptr<MenuItem> rules_menu_item(new RulesMenuItem());
    std::unique_ptr<MenuItem> board_menu_item(new ScoreBoardMenuItem());

    main_menu.add_menu_item(play_menu_item);
    main_menu.add_menu_item(stats_menu_item);
    main_menu.add_menu_item(rules_menu_item);
    main_menu.add_menu_item(board_menu_item);

    return !main_menu.enter();
}