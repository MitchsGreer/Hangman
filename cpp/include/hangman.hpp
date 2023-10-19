///////////////////////////////////////////////////////////////////////////////
/// @file hangman.hpp
///
/// @brief Class for the game of Hangman.
///
/// @todo Add a scoreboard class, stats, and player list to this class. These
///       should be initialized during the constructor.
////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>


class Hangman
{
public:
    Hangman() {};
    ~Hangman() {};

    bool play();

private:
    bool correct_guess(std::string word, char guess);
    bool already_guessed(std::vector<char> guesses, char guess);
    std::string add_letter(std::string revealed_word, std::string word, char letter);

    // Place for stats and the like.
};