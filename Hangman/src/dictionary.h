#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

//Dictionary words downloaded from https://github.com/dwyl/english-words on 11/15/2019
#include "resource.h"

//Globals
DICT dictionary;

//Functions
void add_word_shell(DICT* dictionary, char* word, int size);
WORD* add_word(WORD* root, char* word, int size);
WORD* new_word(char* word, int size);
int find_word_shell(DICT* dictionary, char* word, int size);
WORD* find_word(WORD* root, char* word, int size);
void* dict_init(void* dictionary);
void print_dict_info(DICT* dictionary);
void print_in_order_shell(DICT* dictionary);
void print_in_order(WORD* root);
char* to_lower(char *word);

#endif