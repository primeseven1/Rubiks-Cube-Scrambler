#include <stdlib.h>
#include "fiveScramble.h"
#include "../Valid/valid.h"

static const char moves[] = { 'U', 'R', ' F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' ' };

void genFiveScramble(char** scramble, const PuzzleInfo* info)
{
	// Prevents memory access violations or undefined behavior if the wrong modifiers are passed in
	// Yes... there is redundant code since the 4x4 modifiers are the same as the 5x5 modifiers, but it makes it more readable since it can generate 4x4 scrambles too
	if (!scramble) return;	
	if (info->puzzle != FIVE_BY_FIVE && info->puzzle != FOUR_BY_FOUR ||
		info->modifiers != FIVE_BY_FIVE_MODIFIERS && info->modifiers != FOUR_BY_FOUR_MODIFIERS) 
	{
		wrongFunctionCall(__func__);
		return;
	}

	int fourByFour = info->puzzle == FOUR_BY_FOUR ? 1 : 0;

	for (unsigned int i = 0; i < info->scrambleLength; i++)
	{
		// Whether there is a wide move or not generates first determines if there is a D, L or B move before it, this only applies to 4x4 scrambles
		scramble[i][1] = rand() % 2 ? 'w' : ' ';
		scramble[i][0] = moves[scramble[i][1] == 'w' && fourByFour ? rand() % sizeof(moves) / 2 : rand() % sizeof(moves)];
		scramble[i][2] = modifiers[rand() % sizeof(modifiers)];

		if (!valid(scramble, i, 0)) i--;
	}
}