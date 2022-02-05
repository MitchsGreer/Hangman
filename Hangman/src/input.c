#include "input.h"
//

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   get_string() is an interface that reads in a name or word *
*   from the player.                                          *
*                                                             *
*   @param buff Buffer in which to store the input string.    *
*                                                             *
*   @param size The size of buff                              *
*                                                             *
*   @param message The message to accompany the read from the *
*               player.                                       *
*   @return A pointer to the start of the charactor array.    *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
char *get_string(char *buff, int size, char *message)
{
    printf("%s", message);
    fgets(buff, size, stdin);
    buff[strlen(buff) - 1] = 0;
    return buff;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   get_char() is an interface that reads in a letter from    *
*   the player.                                               *
*                                                             *
*   @param message The message to accompany the read from the *
*               player.                                       *
*   @return The letter the inputted.                          *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   to_lower() Lower all of the letters in the given string.  *
*                                                             *
*   @param word The word to convert to all lower case.        *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
char *to_lower(char *word)
{
    while (*word != '\0')
    {
        *word = tolower(*word);
        word++;
    }

    return word;
}