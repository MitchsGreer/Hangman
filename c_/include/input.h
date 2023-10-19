////////////////////////////////////////////////////////////////////////////////
/// @file input.h
///
/// @brief Utilities providing input mechanisms.
////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

char* get_string(char* name, size_t size, char* message);
char get_char(char* message);
char* to_lower(char *word);

#endif // INPUT_H