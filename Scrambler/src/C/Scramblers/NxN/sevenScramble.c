#include <stdlib.h>
#include "../Valid/valid.h"
#include "sevenScramble.h"

static const char moves[] = { 'U', 'R', 'F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' '};

void genSevenScramble(char** scramble, const PuzzleInfo* info)
{
	if (!scramble || info->puzzle != SEVEN_BY_SEVEN && info->puzzle != SIX_BY_SIX) return;

	int sixBySix = info->scrambleLength < 90 ? 1 : 0;

	for (unsigned int i = 0; i < info->scrambleLength; i++)
	{
		scramble[i][0] = rand() % 3 == 0 ? '3' : ' ';
		scramble[i][2] = scramble[i][0] == '3' ? 'w' : rand() % 2 == 0 ? 'w' : ' ';
		scramble[i][1] = sixBySix ? moves[rand() % sizeof(moves) / 2] : moves[rand() % sizeof(moves)];
		scramble[i][3] = rand() % 2 == 0 ? '\'' : ' ';

		if (!valid(scramble, i, 1)) i--;
	}
}