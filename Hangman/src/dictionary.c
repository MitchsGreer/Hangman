#include "dictionary.h"
//

void add_word_shell(DICT* dictionary, char* word, int size)
{
    if(dictionary->start_word == NULL)
    {
        dictionary->start_word = add_word(dictionary->start_word, word, size);
    }
    add_word(dictionary->start_word, word, size);
    dictionary->num_words++;
}


WORD* add_word(WORD* root, char* word, int size)
{
    //Word not in dictionary, add a new one
    if(root == NULL)
    {
        return new_word(word, size);
    }
    //word already in dictionary
    else if(root->word_size == size && strcmp(word, root->word) == 0)
    {
        return NULL;
    }
    //looking for a place to put the word
    else if(strcmp(word, root->word) < 0)
    {
        root->right_word = add_word(root->right_word, word, size);
    }
    else if(strcmp(word, root->word) > 0)
    {
        root->left_word = add_word(root->left_word, word, size);
    }
    return root;
}

WORD* new_word(char* word, int size)
{
    char* dict_word;
    WORD* temp_WORD;
    
    //create dict_word and WORD space on the stack.
    dict_word = (char*)malloc(size);
    temp_WORD = (WORD*)malloc(sizeof(WORD));

    //copy the dict_word into the WORD
    memcpy(dict_word, to_lower(word), size);

    //populate WORD fields
    temp_WORD->left_word = NULL;
    temp_WORD->right_word = NULL;
    temp_WORD->word = dict_word;
    temp_WORD->word_size = size;

    return temp_WORD;
}


int find_word_shell(DICT* dictionary, char* word, int size)
{
    WORD* result = NULL;
    result = find_word(dictionary->start_word, word, size);
    if (result == NULL)
    {
        return 0;
    }
    return 1;
}


WORD* find_word(WORD* root, char* word, int size)
{
    if(root == NULL || strcmp(to_lower(root->word), to_lower(word)) == 0)
    {
        return root;
    }
    if(strcmp(to_lower(root->word), to_lower(word)) < 0)
    {
        return find_word(root->right_word, word, size);
    }
    return find_word(root->left_word, word, size);
}


void* dict_init(void* dictionary)
{
    DICT* diction = (DICT*) dictionary;
    FILE* infile;
    char word[MAX_SIZE];

    strncpy(diction->file, DICTIONARY, 32);
    infile = fopen(diction->file, "r");   
    
    diction->start_word = NULL;
    diction->num_words = 0;


    if(infile == NULL)
    {
        printf("Dictionary file not opened correctly!\n");
    }
    if(infile != NULL)
    {
        while(!feof(infile))
        {
            fgets(word, MAX_SIZE, infile);
            word[strlen(word) - 1] = '\0';
            add_word_shell(diction, word, strlen(word));
        }
        print_dict_info(diction);
    }
    diction->loaded_in = 1;

    return NULL;
}


void print_dict_info(DICT* dictionary)
{
    printf("---------- Dictionary stats ----------\n");
    printf("From file: %s\n", dictionary->file);
    printf("Size     : %d\n", dictionary->num_words);
}

void print_in_order_shell(DICT* dictionary)
{
    print_in_order(dictionary->start_word);
}

void print_in_order(WORD* root)
{
    if(root != NULL)
    {
        printf("Word: %s\n", root->word);
        print_in_order(root->left_word);
        print_in_order(root->right_word);
    }
}


char* to_lower(char *word)
{
    char *s = word;
    while(*word != '\0')
    {
        if(*word >= 64 && *word < 91)
        {
            *word += 32;
        }
        word++;
    }
    if(s[strlen(s) - 1] == '\n')
    {
        s[strlen(s) - 1] = 0;   
    }
    return s;
}