#include "valid.h"

int valid(const char** scramble, const unsigned int i)
{
	if (i && scramble[i - 1][0] == scramble[i][0]) return 0;

	// 2x2, 3x3, 4x4, and 5x5 can both use the same function since for 3x3 and 2x2, this will always evaluate to false
	if (i < 20 && scramble[i][1] == 'w') return 0;

	// Checking if the move is the same as the previous, and if it is, it checks to see if the last move is opposite of the current move
	if (i > 1 && scramble[i][0] == scramble[i - 2][0])
	{
		if ((scramble[i][0] == 'U' && scramble[i - 1][0] == 'D') || (scramble[i][0] == 'D' && scramble[i - 1][0] == 'U') ||
			(scramble[i][0] == 'R' && scramble[i - 1][0] == 'L') || (scramble[i][0] == 'L' && scramble[i - 1][0] == 'R') ||
			(scramble[i][0] == 'F' && scramble[i - 1][0] == 'B') || (scramble[i][0] == 'B' && scramble[i - 1][0] == 'F')) return 0;
	}

	return 1;
}