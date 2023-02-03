#pragma once

#include <time.h>
#include <stdlib.h>

enum Puzzles {
	TWO_BY_TWO = 2,
	THREE_BY_THREE = 3
};

char** genScramble(const unsigned int puzzle, const unsigned int scrambleLength);
void freeScramble(char** scramble, const unsigned int scrambleLength);