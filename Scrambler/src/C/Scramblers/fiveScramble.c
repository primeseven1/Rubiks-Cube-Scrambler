#include <stdlib.h>
#include "allocator.h"
#include "scrambler.h"
#include "fiveScramble.h"

static const char moves[] = { 'U', 'R', ' F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' ' };

static int valid(const char** scramble, const unsigned int i, const char move)
{
	if (i && scramble[i - 1][0] == move) return 0;
	if (i < 20 && scramble[i][1] == 'w') return 0;

	if (i > 1 && move == scramble[i - 2][0])
	{
		if ((move == 'U' && scramble[i - 1][0] == 'D') || (move == 'D' && scramble[i - 1][0] == 'U') ||
			(move == 'R' && scramble[i - 1][0] == 'L') || (move == 'L' && scramble[i - 1][0] == 'R') ||
			(move == 'F' && scramble[i - 1][0] == 'B') || (move == 'B' && scramble[i - 1][0] == 'F')) return 0;
	}

	return 1;
}

void genFiveScramble(char** scramble, const unsigned int scrambleLength)
{
	int fourByFour = scrambleLength < 50 ? 1 : 0;

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		scramble[i][1] = rand() % 2 ? 'w' : ' ';
		scramble[i][0] = moves[scramble[i][1] == 'w' && fourByFour ? rand() % 3 : rand() % 6];
		scramble[i][2] = modifiers[rand() % 3];

		if (!valid(scramble, i, scramble[i][0])) i--;
	}
}