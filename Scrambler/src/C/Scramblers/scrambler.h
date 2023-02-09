#pragma once

typedef enum Puzzles
{
	SKEWB,
	PYRAMINX,
	TWO_BY_TWO,
	THREE_BY_THREE,
	FOUR_BY_FOUR,
	FIVE_BY_FIVE,
	MEGAMINX
} Puzzle;

enum PuzzleModifers
{
	SKEWB_MODIFIERS = 1,
	PYRAMINX_MODIFIERS = 1,
	TWO_BY_TWO_MODIFIERS = 1,
	THREE_BY_THREE_MODIFIERS = 1,
	FOUR_BY_FOUR_MODIFIERS = 2,
	FIVE_BY_FIVE_MODIFIERS = 2,
	MEGAMINX_MODIFIERS = 2
};

void nxnFreeScramble(char** scramble);
char** genScramble(const Puzzle puzzle);