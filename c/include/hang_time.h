////////////////////////////////////////////////////////////////////////////////
/// @file hang_time.h
///
/// @brief Functions for interacting with the timing.
////////////////////////////////////////////////////////////////////////////////
#ifndef HANG_TIME_H
#define HANG_TIME_H

#include <time.h>
#include "typedef.h"

bool_t read_in_time(double* time);
void print_time(double time, uint games);
bool_t store_time(double time);
time_t start_time(void);
double end_time(time_t my_time);

#endif // HANG_TIME_H