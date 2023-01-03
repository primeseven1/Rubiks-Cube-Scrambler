#include "cube.h"

int valid(const char* scramble, const int i, const char move)
{
	if (i && scramble[i - 1] == move)
	{
		return 0;
	}

	if (i > 1 && move == scramble[i - 2])
	{
		if (move == 'U' && scramble[-1] == 'D' || move == 'D' && scramble[-1] == 'U' ||
			move == 'R' && scramble[-1] == 'L' || move == 'L' && scramble[-1] == 'R' ||
			move == 'F' && scramble[-1] == 'B' || move == 'B' && scramble[-1] == 'F') return 0;
	}

	return 1;
}
