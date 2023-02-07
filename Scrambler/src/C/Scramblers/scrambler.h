#pragma once

#define TWO_BY_TWO_MODIFIERS 1
#define THREE_BY_THREE_MODIFIERS TWO_BY_TWO_MODIFIERS
#define FOUR_BY_FOUR_MODIFIERS 2
#define FIVE_BY_FIVE_MODIFIERS FOUR_BY_FOUR_MODIFIERS

typedef enum Puzzles
{
	TWO_BY_TWO,
	THREE_BY_THREE,
	FOUR_BY_FOUR,
	FIVE_BY_FIVE
} Puzzle;

void nxnFreeScramble(char** scramble);
char** genScramble(const Puzzle puzzle);