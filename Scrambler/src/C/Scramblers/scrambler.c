#include <stdlib.h>
#include "./NxN/threeScramble.h"
#include "./NxN/fiveScramble.h"
#include "./NxN/sevenScramble.h"
#include "./Side_Events/skewbScramble.h"
#include "./Side_Events/pyraminxScramble.h"
#include "./Side_Events/megaminxScramble.h"
#include "./Side_Events/clockScramble.h"
#include "./Allocator/allocator.h"
#include "./Scramble_Info/scrambleInfo.h"
#include "scrambler.h"

#define FIFTY_FIFTY rand() % 2

void freeScramble(char** scramble)
{
	if (!scramble) return;

	unsigned int i = 0;
	while (scramble[i][0] != '\0')
	{
		free(scramble[i]);
		i++;
	}
	/* 
	Since the for loop can't free the last element since it stops at a NULL character, that last part of the array has to get freed to avoid memory leaks
	after that, it frees the scramble
	*/
	free(scramble[i]);
	free(scramble);
}

static struct PuzzleInfo puzzleInfo[] = {
	{.puzzle = THREE_BY_THREE, .modifiers = THREE_BY_THREE_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genThreeScramble },
	{.puzzle = TWO_BY_TWO, .modifiers = TWO_BY_TWO_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genTwoScramble },
	{.puzzle = FOUR_BY_FOUR, .modifiers = FOUR_BY_FOUR_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genFourScramble },
	{.puzzle = FIVE_BY_FIVE, .modifiers = FIVE_BY_FIVE_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genFiveScramble },
	{.puzzle = SIX_BY_SIX, .modifiers = SIX_BY_SIX_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genSixScramble },
	{.puzzle = SEVEN_BY_SEVEN, .modifiers = SEVEN_BY_SEVEN_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genSevenScramble },
	{.puzzle = SKEWB, .modifiers = SKEWB_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genSkewbScramble },
	{.puzzle = PYRAMINX, .modifiers = PYRAMINX_MODIFIERS, .scrambleLength = 0, .scrambleFunctionPtr = genPyraminxScramble },
	{.puzzle = MEGAMINX, .modifiers = MEGAMINX_MODIFIERS, .scrambleLength = MEGAMINX_LENGTH, .scrambleFunctionPtr = genMegaminxScramble },
	{.puzzle = CLOCK, .modifiers = CLOCK_MODIFIERS, .scrambleLength = CLOCK_LENGTH, .scrambleFunctionPtr = genClockScramble }
};

char** genScramble(const Puzzle puzzle)
{
	char** scramble = NULL;

	unsigned int i = 0;
	while (puzzle != puzzleInfo[i].puzzle) i++;

	genScrambleLengths(&puzzleInfo[i]);

	scramble = allocator(&puzzleInfo[i]);

	if (!scramble) return NULL;

	puzzleInfo[i].scrambleFunctionPtr(scramble, &puzzleInfo[i]);

	return scramble;
}