#include <stdlib.h>
#include "../Valid/valid.h"
#include "sevenScramble.h"

static const char moves[] = { 'U', 'R', 'F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' '};

void genSevenScramble(char** scramble, const struct PuzzleInfo* info)
{
	// Prevents memory access violations or undefined behavior if the wrong modifiers are passed in
	// Yes... there is redundant code since the 7x7 modifiers are the same as the 6x6 modifiers, but it makes it more readable since it can generate 6x6 scrambles too
	if (!scramble) return;
	if (info->puzzle != SEVEN_BY_SEVEN && info->puzzle != SIX_BY_SIX ||
		info->modifiers != SEVEN_BY_SEVEN_MODIFIERS && info->modifiers != SIX_BY_SIX_MODIFIERS)
	{
		wrongFunctionCall(__func__);
		return;
	}

	int sixBySix = info->puzzle == SIX_BY_SIX ? 1 : 0;

	for (unsigned int i = 0; i < info->scrambleLength; i++)
	{
		scramble[i][0] = rand() % 3 == 0 ? '3' : ' ';
		scramble[i][2] = scramble[i][0] == '3' ? 'w' : rand() % 2 == 0 ? 'w' : ' ';
		scramble[i][1] = sixBySix ? moves[rand() % sizeof(moves) / 2] : moves[rand() % sizeof(moves)];
		scramble[i][3] = rand() % 2 == 0 ? '\'' : ' ';

		if (!valid((const char**)scramble, i, 1)) i--;
	}
}