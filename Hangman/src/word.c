#include "../Resources/word.h"
//

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
