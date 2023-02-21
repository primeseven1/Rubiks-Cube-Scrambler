#include <stdlib.h>
#include "threeScramble.h"
#include "../Valid/valid.h"

static const char moves[] = { 'U', 'R', 'F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' ' };

void genThreeScramble(char** scramble, const unsigned int scrambleLength)
{
	if (!scramble) return;

	int twoByTwo = scrambleLength < 15 ? 1 : 0;

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		// If it's a 2x2 scramble, it only needs to generate for the first 3 moves of the moves array
		scramble[i][0] = moves[twoByTwo ? rand() % ((sizeof(moves) / 2) / sizeof(char)) : rand() % (sizeof(moves) / sizeof(char))];
		scramble[i][1] = modifiers[rand() % (sizeof(modifiers) / sizeof(char))];

		if (!valid(scramble, i, 0)) i--;
	}
}