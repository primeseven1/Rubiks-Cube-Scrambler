#include <stdlib.h>
#include <string.h>

char** allocator(const unsigned int modifiers, const unsigned int scrambleLength)
{
	// The +1 is for NULL characters so that the nxnFreeScramble function knows when to stop
	char** scramble = (char**)malloc((scrambleLength + 1) * sizeof(char*));
	if (!scramble) return NULL;
	
	for (unsigned int i = 0; i < scrambleLength + 1; i++)
	{
		scramble[i] = (char*)malloc(modifiers + 1 * sizeof(char));

		if (!scramble[i])
		{
			for (unsigned int j = 0; j < i; j++) free(scramble[j]);
			free(scramble);
			return NULL;
		}
	}

	memset(scramble[scrambleLength], 0, modifiers + 1);
	return scramble;
}