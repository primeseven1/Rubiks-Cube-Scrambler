#include <stdlib.h>
#include "fiveScramble.h"
#include "../Valid/valid.h"

static const char moves[] = { 'U', 'R', 'F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' ' };

// 4x4 scrambles have a slightly different valid function than the others, also doesn't need an "indexToCheck" parameter like the other functions
static int fourScrambleValid(const char** scramble, const unsigned int i)
{
	// This function also knows what indexes to check as well since it's a 4x4 scramble
	if (i && scramble[i - 1][0] == scramble[i][0]) return 0;

	// It checks the first 20 moves for any wide moves, and then if there is any, it will force it to try again
	if (i < 20 && scramble[i][1] == 'w') return 0;

	// Checking if the move is the same as the previous, and if it is, it checks to see if the last move is opposite of the current move
	if (i > 1 && scramble[i][0] == scramble[i][0])
		if ((scramble[i][0] == 'U' && scramble[i - 1][0] == 'D') || (scramble[i][0] == 'D' && scramble[i - 1][0] == 'U') ||
			(scramble[i][0] == 'R' && scramble[i - 1][0] == 'L') || (scramble[i][0] == 'L' && scramble[i - 1][0] == 'R') ||
			(scramble[i][0] == 'F' && scramble[i - 1][0] == 'B') || (scramble[i][0] == 'B' && scramble[i - 1][0] == 'F')) return 0;

	return 1;
}

void genFiveScramble(char** scramble, const struct PuzzleInfo* info)
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

		// If it's 5x5, it can use the normal valid function
		if (fourByFour) { if (!fourScrambleValid((const char**)scramble, i)) i--; }
		else if (!valid((const char**)scramble, i, 0)) i--;
	}
}