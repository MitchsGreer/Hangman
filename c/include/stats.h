////////////////////////////////////////////////////////////////////////////////
/// @file stats.h
///
/// @brief Functions for interacting with the stats.
////////////////////////////////////////////////////////////////////////////////
#ifndef STATS_H
#define STATS_H
#include "typedef.h"

bool_t read_in_stats(uint* games_played);
bool_t store_stats(uint games_played);
void print_stats(uint games_played);

#endif // STATS_H