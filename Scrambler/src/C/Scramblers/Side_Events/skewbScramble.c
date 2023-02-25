#include <stdlib.h>
#include "../Valid/valid.h"
#include "skewbScramble.h"

static const char moves[] = { 'U', 'R', 'L', 'B' };
static const char modifiers[] = { ' ', '\'' };

void genSkewbScramble(char** scramble, const struct PuzzleInfo* info)
{
	// Preventing memory access violations or undefined behavior
	if (!scramble) return;
	if (info->puzzle != SKEWB || info->modifiers != SKEWB_MODIFIERS)
	{
		wrongFunctionCall(__func__);
		return;
	}

	for (unsigned int i = 0; i < info->scrambleLength; i++)
	{
		scramble[i][0] = moves[rand() % sizeof(moves)];
		scramble[i][1] = modifiers[rand() % sizeof(modifiers)];

		if (!valid(scramble, i, 0)) i--;
	}
}