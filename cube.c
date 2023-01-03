#include "cube.h"

int valid(const char* scramble, const int i, const char move)
{
	// Checks if the current move is the same as the previous one
	if (i && scramble[i - 1] == move) return 0;

	// Removes things like "D, U2, D"
	if (i > 1 && move == scramble[i - 2])
	{
		if ((move == 'U' && scramble[i - 1] == 'D') || (move == 'D' && scramble[i - 1] == 'U') ||
			(move == 'R' && scramble[i - 1] == 'L') || (move == 'L' && scramble[i - 1] == 'R') ||
			(move == 'F' && scramble[i - 1] == 'B') || (move == 'B' && scramble[i - 1] == 'F')) return 0;
	}

	return 1;
}