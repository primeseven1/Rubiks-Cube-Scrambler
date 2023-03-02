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
	{ GEAR_CUBE, GEAR_CUBE_MIN, GEAR_CUBE_MAX },
};

void genScrambleLengths(struct PuzzleInfo* info)
{
	if (!info) return;

	// Megaminx and clock scrambles will always have the same length
	if (info->puzzle == MEGAMINX || info->puzzle == CLOCK) return;

	/* This essentially just loops through the scrambleLengths array until it finds the correct one to use, 
	   and generates a new scramble length for it */
	int i = 0;
	while (info->puzzle != scrambleLengths[i][0]) 
	{
		if (i > sizeof(scrambleLengths) / sizeof(unsigned int) / 3) return;
		i++;
	}
	
	info->scrambleLength = rand() % (scrambleLengths[i][2] - scrambleLengths[i][1]) + scrambleLengths[i][1];
}