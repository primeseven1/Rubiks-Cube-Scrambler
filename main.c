#include "cube.h"

int main(int argc, char* argv[])
{
	const char moves[] = { 'U', 'D', 'R', 'L', 'F', 'B' };
	const char modifiers[] = { '\'', '2', 0 };

	srand(time(NULL));

	printf("Press enter to generate scrambles\n\n");

	while (1)
	{
		// Generates random number between 25 and 28, and then dynamically allocates memory based on that size
		int scrambleLength = rand() % (29 - 25) + 25;
		char* scramble = (char*)malloc(scrambleLength * sizeof(char));

		if (!scramble)
		{
			printf("Unable to allocate memory");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < scrambleLength; i++)
		{
			char move = moves[rand() % 6];
			scramble[i] = move;

			// Getting rid of the "U U2", "U D2 U" nonsense, defined in "cube.c"
			if (!valid(scramble, i, move))
			{
				i--;
				continue;
			}

			printf("%c%c ", move, modifiers[rand() % 3]);
		}

		free(scramble);
		scramble = NULL;

		// Press enter to generate another scramble
		char enter = 0;
		while (enter != '\r' && enter != '\n') enter = getchar();
	}

	return 0;
}