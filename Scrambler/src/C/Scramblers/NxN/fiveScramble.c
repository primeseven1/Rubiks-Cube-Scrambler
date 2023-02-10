#include <stdlib.h>
#include "fiveScramble.h"
#include "../Valid/valid.h"

static const char moves[] = { 'U', 'R', ' F', 'D', 'L', 'B' };
static const char modifiers[] = { '\'', '2', ' ' };

void genFiveScramble(char** scramble, const unsigned int scrambleLength)
{
	int fourByFour = scrambleLength < 50 ? 1 : 0;

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		// Whether there is a wide move or not generates first determines if there is a D, L or B move before it, this only applies to 4x4 scrambles
		scramble[i][1] = rand() % 2 ? 'w' : ' ';
		scramble[i][0] = moves[scramble[i][1] == 'w' && fourByFour ? rand() % 3 : rand() % 6];
		scramble[i][2] = modifiers[rand() % 3];

		if (!valid(scramble, i, 0)) i--;
	}
}