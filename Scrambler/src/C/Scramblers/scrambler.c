#include <stdlib.h>
#include "threeScramble.h"
#include "fiveScramble.h"
#include "allocator.h"
#include "scrambler.h"

void nxnFreeScramble(char** scramble)
{
	unsigned int i = 0;
	while (scramble[i][0] != '\0')
	{
		free(scramble[i]);
		i++;
	}
	/* Since the for loop can't free the last element since it stops at a NULL character, that last part of the array has to get freed to avoid memory leaks
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
		scramble = nxnAllocator(THREE_BY_THREE_MODIFIERS, scrambleLength);
		genThreeScramble(scramble, scrambleLength);
		break;
	
	case TWO_BY_TWO:
		scrambleLength = rand() % rand() % (12 - 9) + 9;
		scramble = nxnAllocator(TWO_BY_TWO_MODIFIERS, scrambleLength);
		genTwoScramble(scramble, scrambleLength);
		break;

	case FOUR_BY_FOUR:
		scrambleLength = rand() % rand() % (49 - 42) + 42;
		scramble = nxnAllocator(FOUR_BY_FOUR_MODIFIERS, scrambleLength);
		genFourScramble(scramble, scrambleLength);
		break;

	case FIVE_BY_FIVE:
		scrambleLength = rand() % rand() % (63 - 55) + 55;
		scramble = nxnAllocator(FIVE_BY_FIVE_MODIFIERS, scrambleLength);
		genFiveScramble(scramble, scrambleLength);
		break;
	}

	return scramble;
}