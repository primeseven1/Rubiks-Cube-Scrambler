#include <stdlib.h>
#include <string.h>
#include "../../Error/errorWindow.h"
#include "allocator.h"

char** allocator(const struct PuzzleInfo* info)
{
	// The +1 is for NULL characters so that the freeScramble function knows when to stop
	char** scramble = (char**)malloc((info->scrambleLength + 1) * sizeof(char*));
	if (!scramble)
	{
		mallocFailure(__func__, "scramble");
		return NULL;
	}
	
	for (unsigned int i = 0; i < info->scrambleLength + 1; i++)
	{
		scramble[i] = (char*)malloc(info->modifiers + 1 * sizeof(char));

		if (!scramble[i])
		{
			for (unsigned int j = 0; j < i; j++) free(scramble[j]);
			free(scramble);
			return NULL;
		}
	}

	// Here is where the last element is set to null characters
	memset(scramble[info->scrambleLength], 0, info->modifiers + 1);
	return scramble;
}