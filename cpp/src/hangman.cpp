///////////////////////////////////////////////////////////////////////////////
/// @file hangman.cpp
///
/// @brief Implementation for the game of Hangman.
////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "play_menu_item.hpp"
#include "util.hpp"
#include "hangman.hpp"


////////////////////////////////////////////////////////////////////////////////
/// @brief Play the game of Hangman.
///
/// @return True if the game ended without error, False otherwise.
////////////////////////////////////////////////////////////////////////////////
bool Hangman::play()
{
    std::string guesser_name = "";
    std::string provider = "";
    std::string word = "";
    char guess = '\0';
    std::string revealed_word = "";
    std::vector<char> guesses;
    uint32_t correct_guesses = 0;
    uint32_t incorrect_guesses = 0;

    guesser_name = get_input<std::string>("Who is guessing: ");
    provider = get_input<std::string>("Who is providing the word: ");
    word = get_input<std::string>("What is the word to be guessed: ");

    for(size_t i = 0; i < word.length(); i++)
    {
        revealed_word += "_";
    }

    while(revealed_word != word && incorrect_guesses < 10)
    {
        std::cout << revealed_word << std::endl;

        for( auto guess_char : guesses )
        {
            std::cout << guess_char;
        }
        std::cout << std::endl;

        do
        {
            guess = get_input<char>("What is your guess: ");
        }while(already_guessed(guesses, guess));

        guesses.push_back(guess);
        if(correct_guess(word, guess))
        {
            revealed_word = add_letter(revealed_word, word, guess);
            correct_guesses++;
        }
        else
        {
            incorrect_guesses++;
        }
    }

    if(revealed_word == word)
    {
        std::cout << guesser_name << " Won!" << std::endl;
    }
    else
    {
        std::cout << provider << " Won!" << std::endl;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Reveal the given letter in the mystery word.
///
/// @param [in] revealed_word The mystery word with all the correct guesses
///                           revealed.
/// @param [in] word The mystery word.
/// @param [in] letter The letter that has just been guessed.
///
/// @return True if the letter has been guessed, False otherwise.
////////////////////////////////////////////////////////////////////////////////
std::string Hangman::add_letter(std::string revealed_word, std::string word, char letter)
{
    size_t pos = 0;
    do
    {
        pos = word.find(letter, pos);
        if(pos != std::string::npos)
        {
            revealed_word.replace(pos, 1, 1, letter);
            pos++;
        }
    }while(pos != std::string::npos);

    return revealed_word;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Check if a letter has already been guessed.
///
/// @param [in] guesses All the letters guessed so far.
/// @param [in] guess The letter that has just been guessed.
///
/// @return True if the letter has been guessed, False otherwise.
////////////////////////////////////////////////////////////////////////////////
bool Hangman::already_guessed(std::vector<char> guesses, char guess)
{
    return std::find(guesses.begin(), guesses.end(), guess) != guesses.end();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Check if the guessed letter is in the mystery word.
///
/// @param [in] word The mystery word.
/// @param [in] guess The letter that has just been guessed.
///
/// @return True if the letter is in the mystery word, False otherwise.
////////////////////////////////////////////////////////////////////////////////
bool Hangman::correct_guess(std::string word, char guess)
{
    return word.find(guess) != std::string::npos;
}
