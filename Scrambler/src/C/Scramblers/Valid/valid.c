#include "valid.h"

int valid(const char** scramble, const unsigned int i, const unsigned int indexToCheck)
{
	if (i && scramble[i - 1][indexToCheck] == scramble[i][indexToCheck]) return 0;

	// Checking if the move is the same as the previous, and if it is, it checks to see if the last move is opposite of the current move
	if (i > 1 && scramble[i][indexToCheck] == scramble[i][0])
		if ((scramble[i][indexToCheck] == 'U' && scramble[i - 1][indexToCheck] == 'D') || (scramble[i][indexToCheck] == 'D' && scramble[i - 1][indexToCheck] == 'U') ||
			(scramble[i][indexToCheck] == 'R' && scramble[i - 1][indexToCheck] == 'L') || (scramble[i][indexToCheck] == 'L' && scramble[i - 1][indexToCheck] == 'R') ||
			(scramble[i][indexToCheck] == 'F' && scramble[i - 1][indexToCheck] == 'B') || (scramble[i][indexToCheck] == 'B' && scramble[i - 1][indexToCheck] == 'F')) return 0;

	return 1;
}