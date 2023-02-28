#include <stdlib.h>
#include "threeScramble.h"
#include "../Valid/valid.h"

static const char moves[] = { 'U', 'R', 'F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' ' };

void genThreeScramble(char** scramble, const struct PuzzleInfo* info)
{
	// Prevents memory access violations or undefined behavior if the wrong modifiers are passed in
	// Yes... there is redundant code since the 3x3 modifiers are the same as the 2x2 modifiers, but it makes it more readable since it can generate 2x2 scrambles too
	if (!scramble) return;
	if (info->puzzle != THREE_BY_THREE && info->puzzle != TWO_BY_TWO ||
		info->modifiers != THREE_BY_THREE_MODIFIERS && info->modifiers != TWO_BY_TWO_MODIFIERS)
	{
		wrongFunctionCall(__func__);
		return;
	}

	int twoByTwo = info->puzzle == TWO_BY_TWO ? 1 : 0;

	for (unsigned int i = 0; i < info->scrambleLength; i++)
	{
		// If it's a 2x2 scramble, it only needs to generate for the first 3 moves of the moves array
		scramble[i][0] = moves[twoByTwo ? rand() % sizeof(moves) / 2 : rand() % sizeof(moves)];
		scramble[i][1] = modifiers[rand() % sizeof(modifiers)];

		if (!valid((const char**)scramble, i, 0)) i--;
	}
}