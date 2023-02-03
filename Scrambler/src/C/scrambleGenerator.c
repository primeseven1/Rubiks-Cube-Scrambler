#include "scrambleGenerator.h"
#include "threeScramble.h"

static const char moves[] = { 'U', 'R', 'F', 'D', 'L', 'B'};
static const char modifiers[] = { '\'', '2', 0 };

char** genScramble(const unsigned int puzzle, const unsigned int scrambleLength)
{
	// If there is an attempt to put some random number for the puzzle, it returns a NULL pointer, it's meant to do that
	char** scramble = NULL;

	switch (puzzle)
	{
	case TWO_BY_TWO:
		scramble = genTwoScramble(scrambleLength);
		break;

	case THREE_BY_THREE:
		scramble = genThreeScramble(scrambleLength);
		break;
	}

	return scramble;
}

void freeScramble(char** scramble, const unsigned int scrambleLength)
{
	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		free(scramble[i]);
	}

	free(scramble);
}