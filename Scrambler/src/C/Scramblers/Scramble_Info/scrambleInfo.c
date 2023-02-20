#include <stdlib.h>
#include "scrambleInfo.h"

static unsigned int scrambleLengths[][3] = {
	{ THREE_BY_THREE, THREE_BY_THREE_MIN, THREE_BY_THREE_MAX },
	{ TWO_BY_TWO, TWO_BY_TWO_MIN, TWO_BY_TWO_MAX },
	{ FOUR_BY_FOUR, FOUR_BY_FOUR_MIN, FOUR_BY_FOUR_MAX },
	{ FIVE_BY_FIVE, FIVE_BY_FIVE_MIN, FIVE_BY_FIVE_MAX },
	{ SIX_BY_SIX, SIX_BY_SIX_MIN, SIX_BY_SIX_MAX },
	{ SEVEN_BY_SEVEN, SEVEN_BY_SEVEN_MIN, SEVEN_BY_SEVEN_MAX },
	{ SKEWB, SKEWB_MIN, SKEWB_MAX },
	{ PYRAMINX, PYRAMINX_MIN, PYRAMINX_MAX },
};

void genScrambleLengths(PuzzleInfo* info)
{
	// Megaminx scramble lengths are always the same
	if (info->puzzle == MEGAMINX) return;

	int i = 0;
	while (info->puzzle != scrambleLengths[i][0]) i++;
	info->scrambleLength = rand() % (scrambleLengths[i][2] - scrambleLengths[i][1]) + scrambleLengths[i][1];
}