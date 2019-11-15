#include "input.h"
//


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   get_name() is an interface that reads in a name or word   *
*   from the player.                                          *
*                                                             *
*   @param name The charactor array holding the name or word  *
*               that inputed by the player.                   *
*   @param size The size of the charactor array holding the   *
*               name or read read in from the player.         *
*   @param message The message to accompany the read from the *
*               player.                                       *
*   @return A pointer to the start of the charactor array.    *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
char * get_name(char * name, int size, char * message)
{
    char temp[size];

    printf("%s", message);
    fgets(temp, size, stdin);
    temp[strlen(temp) - 1] = 0;
    strncpy(name, temp, size);
    return name;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   get_guess() is an interface that reads in a letter from   *
*   the player, this letter is then used as the players guess.*
*                                                             *
*   @param message The message to accompany the read from the *
*               player.                                       *
*   @return The letter the player guessed.                    *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
char get_guess(char * message)
{
    char guess = '\0';
    printf("%s", message);
    do
    {
        scanf("%c", &guess);
    }while(guess == '\n');
    
    return guess;
}