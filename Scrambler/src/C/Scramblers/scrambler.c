#include <stdlib.h>
#include "./NxN/threeScramble.h"
#include "./NxN/fiveScramble.h"
#include "./NxN/sevenScramble.h"
#include "./Side_Events/skewbScramble.h"
#include "./Side_Events/pyraminxScramble.h"
#include "./Side_Events/megaminxScramble.h"
#include "./Allocator/allocator.h"
#include "scrambler.h"

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

char** genScramble(const Puzzle puzzle)
{
	char** scramble = NULL;

	// The last third element of the arrays are scramble lengths
	// The last element of the arrays are function pointers
	unsigned long long puzzleInfo[9][4] = {
		{ THREE_BY_THREE, THREE_BY_THREE_MODIFIERS, rand() % (THREE_BY_THREE_MAX - THREE_BY_THREE_MIN) + THREE_BY_THREE_MIN, genThreeScramble },
		{ TWO_BY_TWO, TWO_BY_TWO_MODIFIERS, rand() % (TWO_BY_TWO_MAX - TWO_BY_TWO_MIN) + TWO_BY_TWO_MIN, genTwoScramble },
		{ FOUR_BY_FOUR, FOUR_BY_FOUR_MODIFIERS, rand() % (FOUR_BY_FOUR_MAX - FOUR_BY_FOUR_MIN) + FOUR_BY_FOUR_MIN, genFourScramble },
		{ FIVE_BY_FIVE, FIVE_BY_FIVE_MODIFIERS, rand() % (FIVE_BY_FIVE_MAX - FIVE_BY_FIVE_MIN) + FIVE_BY_FIVE_MIN, genFiveScramble },
		{ SIX_BY_SIX, SIX_BY_SIX_MODIFIERS, rand() % (SIX_BY_SIX - SIX_BY_SIX_MIN) + SIX_BY_SIX_MIN, genSixScramble },
		{ SEVEN_BY_SEVEN, SEVEN_BY_SEVEN_MODIFIERS, rand() % (SEVEN_BY_SEVEN_MAX - SEVEN_BY_SEVEN_MIN) + SEVEN_BY_SEVEN_MIN, genSevenScramble },
		{ SKEWB, SKEWB_MODIFIERS, rand() % (SKEWB_MAX - SKEWB_MIN) + SKEWB_MIN, genSkewbScramble },
		{ PYRAMINX, PYRAMINX_MODIFIERS, rand() % (PYRAMINX_MAX - PYRAMINX_MIN) + PYRAMINX_MIN, genPyraminxScramble },
		{ MEGAMINX, MEGAMINX_MODIFIERS, MEGAMINX_LENGTH, genMegaminxScramble }
	};

	unsigned int i = 0;
	while (puzzle != puzzleInfo[i][0]) i++;
	scramble = allocator(puzzleInfo[i][1], puzzleInfo[i][2]);

	if (!scramble) return NULL;

	void(*scrambleGen)(char** scramble, unsigned int scrambleLength) = puzzleInfo[i][3];
	scrambleGen(scramble, puzzleInfo[i][2]);

	return scramble;
}