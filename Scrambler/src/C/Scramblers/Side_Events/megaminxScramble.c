#include <stdlib.h>
#include "megaminxScramble.h"

static const char modifiers[] = { '+', '-' };

void genMegaminxScramble(char** scramble, const unsigned int scrambleLength)
{
	if (!scramble) return;

	// No need for a valid function
	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		if (i % 11 == 0 && i)
		{
			scramble[i][0] = 'U';
			scramble[i][1] = rand() % 2 == 0 ? '\'' : ' ';
			scramble[i][2] = ' ';
			continue;
		}

		scramble[i][0] = i % 2 == 0 ? 'R' : 'D';
		scramble[i][1] = modifiers[rand() % sizeof(modifiers)];
		scramble[i][2] = scramble[i][1];
	}
}