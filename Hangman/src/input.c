//can use this to retrive the guessers name, the word, and the word suppliers name
//does not need anything to happen before we start
//outputs a string that is read in
//
//can also use this for navagating the menu
char * get_name(char * name, int size, char * message)
{
    char temp[size];

    printf("%s", message);
    fgets(temp, size, stdin);
    temp[strlen(temp) - 1] = 0;
    strncpy(name, temp, size);
    return name;
}

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