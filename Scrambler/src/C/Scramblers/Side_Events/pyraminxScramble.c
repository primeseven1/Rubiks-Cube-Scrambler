#include <stdlib.h>
#include "../Valid/valid.h"
#include "pyraminxScramble.h"

static const char moves[] = { 'U', 'R', 'L', 'B' };
static const char modifiers[] = { ' ', '\'' };
static const char pyraminxTips[] = { 'u', 'r', 'l', 'b' };

void genPyraminxScramble(char** scramble, const unsigned int scrambleLength)
{
	unsigned int i = 0;
	while (i < scrambleLength - 4)
	{
		scramble[i][0] = moves[rand() % sizeof(moves) / sizeof(char)];
		scramble[i][1] = modifiers[rand() % sizeof(modifiers) / sizeof(char)];

		if (!valid(scramble, i)) i--;
		i++;
	}

	for (unsigned int j = i, k = 0; j < scrambleLength; j++, k++)
	{
		if (rand() % 2 == 0)
		{
			scramble[j][0] = pyraminxTips[k]; 
			scramble[j][1] = modifiers[rand() % sizeof(modifiers) / sizeof(char)];
		}
		else
		{
			scramble[j][0] = ' '; 
			scramble[j][1] = ' ';
		}
	}
}