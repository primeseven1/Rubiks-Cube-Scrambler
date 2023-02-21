#pragma once

typedef enum Puzzles
{
	SKEWB,
	PYRAMINX,
	TWO_BY_TWO,
	THREE_BY_THREE,
	FOUR_BY_FOUR,
	FIVE_BY_FIVE,
	MEGAMINX,
	SIX_BY_SIX,
	SEVEN_BY_SEVEN,
	CLOCK
} Puzzle;

enum PuzzleModifers
{
	SKEWB_MODIFIERS = 1,
	PYRAMINX_MODIFIERS = 1,
	TWO_BY_TWO_MODIFIERS = 1,
	THREE_BY_THREE_MODIFIERS = 1,
	FOUR_BY_FOUR_MODIFIERS = 2,
	FIVE_BY_FIVE_MODIFIERS = 2,
	MEGAMINX_MODIFIERS = 2,
	SIX_BY_SIX_MODIFIERS = 3,
	SEVEN_BY_SEVEN_MODIFIERS = 3,
	CLOCK_MODIFIERS = 4
};

enum MinMaxLengths
{
	THREE_BY_THREE_MIN = 24,
	THREE_BY_THREE_MAX = 29,
	TWO_BY_TWO_MIN = 9,
	TWO_BY_TWO_MAX = 12,
	FOUR_BY_FOUR_MIN = 42,
	FOUR_BY_FOUR_MAX = 49,
	FIVE_BY_FIVE_MIN = 55,
	FIVE_BY_FIVE_MAX = 63,
	SIX_BY_SIX_MIN = 78,
	SIX_BY_SIX_MAX = 85,
	SEVEN_BY_SEVEN_MIN = 91,
	SEVEN_BY_SEVEN_MAX = 103,
	SKEWB_MIN = 7,
	SKEWB_MAX = 10,
	PYRAMINX_MIN = 10,
	PYRAMINX_MAX = 15,
	CLOCK_LENGTH = 19,
	MEGAMINX_LENGTH = 77
};

void freeScramble(char** scramble);
char** genScramble(const Puzzle puzzle);