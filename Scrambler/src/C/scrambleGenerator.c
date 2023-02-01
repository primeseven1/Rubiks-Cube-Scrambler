#include <time.h>
#include <stdlib.h>
#include "scrambleGenerator.h"

static const char moves[] = { 'U', 'D', 'R', 'L', 'F', 'B' };
static const char modifiers[] = { '\'', '2', 0 };

static int valid(const char** scramble, const unsigned int i, const char move)
{
	// Checks if the current move is the same as the previous one
	if (i && scramble[i - 1][0] == move) return 0;

	// Removes things like "D U2 D"
	if (i > 1 && move == scramble[i - 2][0])
	{
		if ((move == 'U' && scramble[i - 1][0] == 'D') || (move == 'D' && scramble[i - 1][0] == 'U') ||
			(move == 'R' && scramble[i - 1][0] == 'L') || (move == 'L' && scramble[i - 1][0] == 'R') ||
			(move == 'F' && scramble[i - 1][0] == 'B') || (move == 'B' && scramble[i - 1][0] == 'F')) return 0;
	}

	return 1;
}

char** genScramble(const unsigned int scrambleLength)
{
	char** scramble = (char**)malloc(scrambleLength * sizeof(char*));

	if (!scramble)
	{
		return NULL;
	}

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		scramble[i] = (char*)malloc(2 * sizeof(char));

		// If allocating fails at any point, it frees the scramble
		if (!scramble[i])
		{
			for (unsigned int j = 0; j < i; j++)
			{
				free(scramble[j]);
			}

			free(scramble);
			return NULL;
		}
	}

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		scramble[i][0] = moves[rand() % 6];
		scramble[i][1] = modifiers[rand() % 3];

		if (!valid(scramble, i, scramble[i][0]))
		{
			i--;
			continue;
		}
	}

	// Memory is freed by using the freeScramble() function
	return scramble;
}

void freeScramble(char** scramble, const unsigned int scrambleLength)
{
	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		free(scramble[i]);
	}

	free(scramble);
}