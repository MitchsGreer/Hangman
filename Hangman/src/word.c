#include "word.h"
//


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   check_guess() Checks if the players guessed letter was    *
*                 in the hidden word.                         *
*                                                             *
*   @param word The revealed letters so far.                  *
*                                                             *
*   @param size The size of the word.                         *
*                                                             *
*   @param guess The players guess.                           *
*                                                             *
*   @param answer The hidden word.                            *
*                                                             *
*   @return How many correct guesses the player has made      *
*           so far.                                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int check_guess(char * word, int size, char guess, char * answer)
{
    int correct_guesses = 0;

    --size;
    while(size >= 0)
    {
        if(answer[size] == guess)
        {
            word[size] = guess;
            correct_guesses++;
        }
        size--;
    }
    return correct_guesses;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*   check_guess_against_guesses() Checks if the players       * 
*                 guessed letter was already guessed.         *
*                                                             *
*   @param guesses All of the players guesses so far.         *
*                                                             *
*   @param guess The players guess.                           *
*                                                             *
*   @return 1 if it has, 0 if not.                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int check_guess_against_guesses(char * guesses, char guess)
{
    int i;
    for(i = 0; i < 26; i++)
    {
        if(guesses[i] == guess)
        {
            return 1;
        }
    }
    return 0;
}
