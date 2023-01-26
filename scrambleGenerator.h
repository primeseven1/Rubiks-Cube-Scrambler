#pragma once

#include <time.h>
#include <stdlib.h>

char** genScramble(const unsigned int scrambleLength);
int valid(const char** scramble, const int i, const char move);
void freeScramble(char** scramble, const unsigned int scrambleLength);