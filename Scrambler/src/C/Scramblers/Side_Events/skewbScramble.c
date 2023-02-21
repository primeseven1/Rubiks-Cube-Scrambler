#include <stdlib.h>
#include "../Valid/valid.h"
#include "skewbScramble.h"

static const char moves[] = { 'U', 'R', 'L', 'B' };
static const char modifiers[] = { ' ', '\'' };

void genSkewbScramble(char** scramble, const unsigned int scrambleLength)
{
	if (!scramble) return;

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		scramble[i][0] = moves[rand() % sizeof(moves) / sizeof(char)];
		scramble[i][1] = modifiers[rand() % sizeof(modifiers) / sizeof(char)];

		if (!valid(scramble, i, 0)) i--;
	}
}