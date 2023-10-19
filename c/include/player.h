////////////////////////////////////////////////////////////////////////////////
/// @file player.h
///
/// @brief Definition of a player.
////////////////////////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"
#include "typedef.h"

typedef struct PLAYER
{
    char name[MAX_SIZE];
    uint words_guessed;
    uint players_stumped;
    uint games_played;
} PLAYER;

typedef enum player_t {
    GUESSER = 2,
    PROVIDER = 1
}player_t;

#endif // PLAYER_H