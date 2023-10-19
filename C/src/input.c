////////////////////////////////////////////////////////////////////////////////
/// @file input.c
///
/// @brief Implementation of input utilities.
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "input.h"


///////////////////////////////////////////////////////////////////////////////
/// @brief An interface that reads in a name or word from the player.
///
/// @param [in] buff Buffer in which to store the input string.
/// @param [in] size The size of buffer.
/// @param [in] message The message to accompany the read from the player.
///
/// @returns A pointer to the start of the character array.
///////////////////////////////////////////////////////////////////////////////
char* get_string(char *buff, size_t size, char *message)
{
    printf("%s", message);
    fgets(buff, size, stdin);
    buff[strlen(buff) - 1] = '\0';
    return buff;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief An interface that reads in a letter from the player.
///
/// @param [in] message The message to accompany the read from the player.
///
/// @returns The inputted letter.
///////////////////////////////////////////////////////////////////////////////
char get_char(char *message)
{
    char c = '\0';
    printf("%s", message);
    do
    {
        scanf("%c", &c);
    } while (c == '\n');

    return c;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Lower all of the letters in the given string.
///
/// @param [in] message The word to convert to all lower case.
///
/// @returns Pointer to the start of the changed word.
///////////////////////////////////////////////////////////////////////////////
char* to_lower(char *word)
{
    while (*word != '\0')
    {
        *word = tolower(*word);
        word++;
    }

    return word;
}