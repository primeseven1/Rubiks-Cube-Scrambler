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

	// The last element are scramble lengths
	unsigned int puzzleInfo[9][3] = { { THREE_BY_THREE, THREE_BY_THREE_MODIFIERS, rand() % (29 - 24) + 24 },
									{ TWO_BY_TWO, TWO_BY_TWO_MODIFIERS, rand() % (12 - 9) + 9},
									{ FOUR_BY_FOUR, FOUR_BY_FOUR_MODIFIERS, rand() % (49 - 42) + 42},
									{ FIVE_BY_FIVE, FIVE_BY_FIVE_MODIFIERS, rand() % (63 - 55) + 55},
									{ SIX_BY_SIX, SIX_BY_SIX_MODIFIERS, rand() % (85 - 78) + 78},
									{ SEVEN_BY_SEVEN, SEVEN_BY_SEVEN_MODIFIERS, rand() % (103 - 91) + 91},
									{ SKEWB, SKEWB_MODIFIERS, rand() % (10 - 7) + 7},
									{ PYRAMINX, PYRAMINX_MODIFIERS, rand() % (15 - 10) + 10},
									{ MEGAMINX, MEGAMINX_MODIFIERS, 77}
								  /*{CLOCK, CLOCK_MODIFIERS, 19}*/ };

	unsigned int i = 0;
	while (puzzle != puzzleInfo[i][0]) i++;
	scramble = allocator(puzzleInfo[i][1], puzzleInfo[i][2]);

	switch (puzzle)
	{
	case THREE_BY_THREE:
		genThreeScramble(scramble, puzzleInfo[i][2]);
		break;

	case TWO_BY_TWO:
		genTwoScramble(scramble, puzzleInfo[i][2]);
		break;

	case FOUR_BY_FOUR:
		genFourScramble(scramble, puzzleInfo[i][2]);
		break;

	case FIVE_BY_FIVE:
		genFiveScramble(scramble, puzzleInfo[i][2]);
		break;

	case SIX_BY_SIX:
		genSixScramble(scramble, puzzleInfo[i][2]);
		break;

	case SEVEN_BY_SEVEN:
		genSevenScramble(scramble, puzzleInfo[i][2]);
		break;

	case SKEWB:
		genSkewbScramble(scramble, puzzleInfo[i][2]);
		break;

	case PYRAMINX:
		genPyraminxScramble(scramble, puzzleInfo[i][2]);
		break;

	case MEGAMINX:
		genMegaminxScramble(scramble, puzzleInfo[i][2]);
		break;
	}

	return scramble;
}
