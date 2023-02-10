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
	unsigned int scrambleLength;

	switch (puzzle)
	{
	case THREE_BY_THREE:
		scrambleLength = rand() % (29 - 24) + 24;
		scramble = allocator(THREE_BY_THREE_MODIFIERS, scrambleLength);
		genThreeScramble(scramble, scrambleLength);
		break;
	
	case TWO_BY_TWO:
		scrambleLength = rand() % (12 - 9) + 9;
		scramble = allocator(TWO_BY_TWO_MODIFIERS, scrambleLength);
		genTwoScramble(scramble, scrambleLength);
		break;

	case FOUR_BY_FOUR:
		scrambleLength = rand() % (49 - 42) + 42;
		scramble = allocator(FOUR_BY_FOUR_MODIFIERS, scrambleLength);
		genFourScramble(scramble, scrambleLength);
		break;

	case FIVE_BY_FIVE:
		scrambleLength = rand() % (63 - 55) + 55;
		scramble = allocator(FIVE_BY_FIVE_MODIFIERS, scrambleLength);
		genFiveScramble(scramble, scrambleLength);
		break;

	case SIX_BY_SIX:
		scrambleLength = rand() % (85 - 78) + 78;
		scramble = allocator(SIX_BY_SIX_MODIFIERS, scrambleLength);
		genSixScramble(scramble, scrambleLength);
		break;

	case SEVEN_BY_SEVEN:
		scrambleLength = rand() % (103 - 91) + 91;
		scramble = allocator(SEVEN_BY_SEVEN_MODIFIERS, scrambleLength);
		genSevenScramble(scramble, scrambleLength);
		break;

	case SKEWB:
		scrambleLength = rand() % (10 - 7) + 7;
		scramble = allocator(SKEWB_MODIFIERS, scrambleLength);
		genSkewbScramble(scramble, scrambleLength);
		break;

	case PYRAMINX:
		scrambleLength = rand() % (15 - 10) + 10;
		scramble = allocator(PYRAMINX_MODIFIERS, scrambleLength);
		genPyraminxScramble(scramble, scrambleLength);
		break;

	case MEGAMINX:
		scrambleLength = 77;
		scramble = allocator(MEGAMINX_MODIFIERS, scrambleLength);
		genMegaminxScramble(scramble, scrambleLength);
		break;
	}

	return scramble;
}