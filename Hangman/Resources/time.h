#pragma once
#ifndef TIME_H
#define TIME_H
#include "resource.h"
//

int read_in_time(double * time);
int print_time(double time, int games);
int store_time(double time);
time_t start_time(void);
double end_time(time_t my_time);
#endif