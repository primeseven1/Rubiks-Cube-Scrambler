#include "valid.h"

// indexToCheck is the index where you check the main move, like U, R, F, etc
int valid(const char** scramble, const unsigned int i, const unsigned int indexToCheck)
{
	if (i && scramble[i - 1][indexToCheck] == scramble[i][indexToCheck]) return 0;

	// This is checking if the move 2 moves ago is the same as before, and then checks to see if the move before is opposite
	if (i > 1 && scramble[i][indexToCheck] == scramble[i][0])
		if ((scramble[i][indexToCheck] == 'U' && scramble[i - 1][indexToCheck] == 'D') || (scramble[i][indexToCheck] == 'D' && scramble[i - 1][indexToCheck] == 'U') ||
			(scramble[i][indexToCheck] == 'R' && scramble[i - 1][indexToCheck] == 'L') || (scramble[i][indexToCheck] == 'L' && scramble[i - 1][indexToCheck] == 'R') ||
			(scramble[i][indexToCheck] == 'F' && scramble[i - 1][indexToCheck] == 'B') || (scramble[i][indexToCheck] == 'B' && scramble[i - 1][indexToCheck] == 'F')) return 0;

	return 1;
}