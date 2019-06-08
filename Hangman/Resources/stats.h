#pragma once
#ifndef STATS_H
#define STATS_H
#include "scoreboard.h"
//

int read_in_stats(int * games_played);
int store_stats(int games_played);
int print_stats(int games_played);
#endif