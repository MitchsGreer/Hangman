///////////////////////////////////////////////////////////////////////////////
/// @file player.hpp
///
/// @brief Class for a player.
///////////////////////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player{
public:

    Player(
        std::string name = "",
        uint32_t games_played = 0,
        uint32_t players_stumped = 0,
        uint32_t words_guessed = 0
    ) :
        m_name(name),
        m_games_played(games_played),
        m_players_stumped(players_stumped),
        m_words_guessed(words_guessed) {};
    ~Player() {};

    // Setters
    void set_name(std::string new_name) { this->m_name = new_name; };
    void set_games_played(uint32_t new_value) { this->m_games_played = new_value; };
    void set_players_stumped(uint32_t new_value) { this->m_players_stumped = new_value; };
    void set_words_guessed(uint32_t new_value) { this->m_words_guessed = new_value; };

    // Some incremental functions.
    void increment_games_played() { this->m_players_stumped++; };
    void increment_players_stumped() { this->m_players_stumped++; };
    void increment_words_guessed() { this->m_players_stumped++; };

    // Getters
    std::string name() const { return this->m_name; };
    uint32_t games_played() const { return this->m_games_played; };
    uint32_t players_stumped() const { return this->m_players_stumped; };
    uint32_t words_guessed() const { return this->m_words_guessed; };

private:
    std::string m_name;
    uint32_t m_games_played;
    uint32_t m_players_stumped;
    uint32_t m_words_guessed;
};

std::ostream& operator<<(std::ostream& os, const Player& player) {
    return os
        << player.name()
        << " "
        << player.games_played()
        << " "
        << player.players_stumped()
        << " "
        << player.words_guessed()
        << std::endl;
}

#endif // PLAYER_H