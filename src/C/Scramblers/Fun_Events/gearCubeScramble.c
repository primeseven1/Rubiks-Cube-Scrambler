#include "../scrambler.h"
#include "gearCubeScramble.h"

static const char moves[] = { 'U', 'R', 'F' };
static const char modifiers[] = { '1', '2', '3', '4', '5', '6' };
static const char modifiers2[] = { '\'', ' ' };

static int gearCubeScrambleValid(char** scramble, const unsigned int i)
{
    if (i && scramble[i][0] == scramble[i - 1][0]) return 0;
    if (scramble[i][1] == '6' && scramble[i][2] == '\'')
    {
        scramble[i][2] = ' ';
        return 1;
    }
    
    return 1;
}

void genGearCubeScramble(char** scramble, const struct PuzzleInfo* info)
{
    if (!scramble) return;
    if (info->puzzle != GEAR_CUBE)
	{
		wrongFunctionCall(__func__);
		return;
	}

    for (unsigned int i = 0; i < info->scrambleLength; i++)
    {
        scramble[i][0] = moves[rand() % sizeof(moves)];
        scramble[i][1] = modifiers[rand() % sizeof(modifiers)];
        scramble[i][2] = modifiers2[rand() % sizeof(modifiers2)];

        if (!gearCubeScrambleValid(scramble, i)) i--;
    }
}