////////////////////////////////////////////////////////////////////////////////
/// @file constants.h
///
/// @brief Constants used in this implementation.
////////////////////////////////////////////////////////////////////////////////
#ifndef CONSTANTS_H
#define CONSTANTS_H

// -----------------------------------------------------------------------------
// Magic Numbers
// -----------------------------------------------------------------------------
#define MAX_SIZE 256
#define SCOREBOARD_SIZE 100
#define TOTAL_INCORRECT_GUESSES 10
#define ALPHABET_LENGTH 26
#define NUM_BUFFER_LENGTH 10

// -----------------------------------------------------------------------------
// Resource File Names
// -----------------------------------------------------------------------------
#define SCOREBOARD_FILE "scoreboard.txt"
#define STATS_FILE "stats.txt"
#define TIME_FILE "time.txt"

// -----------------------------------------------------------------------------
// Menu Options
// -----------------------------------------------------------------------------
#define PLAY_OPTION "play"
#define SCOREBOARD_OPTION "score board"
#define STATS_OPTIONS "stats"
#define EXIT_OPTION "exit"

// -----------------------------------------------------------------------------
// Prompts
// -----------------------------------------------------------------------------
#define MAIN_MENU_PROMPT "Please provide your option: "
#define PROVIDER_PROMPT "Who is providing the word: "
#define GUESSER_PROMPT "Who is guessing: "
#define WORD_PROMPT "What is the word: "
#define GUESS_PROMPT "What do you guess: "

// -----------------------------------------------------------------------------
// Error Strings
// -----------------------------------------------------------------------------
#define SCOREBOARD_FILE_OPEN_READ_ERROR "Failed to open scoreboard to read!\n"
#define SCOREBOARD_FILE_OPEN_WRITE_ERROR "Failed to open scoreboard to write!\n"
#define STATS_FILE_OPEN_READ_ERROR "Failed to open stats to read!\n"
#define STATS_FILE_OPEN_WRITE_ERROR "Failed to open stats to write!\n"
#define TIME_FILE_OPEN_READ_ERROR "Failed to open time to read!\n"
#define TIME_FILE_OPEN_WRITE_ERROR "Failed to open time to write!\n"

#endif // CONSTANTS_H