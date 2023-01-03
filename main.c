#include "cube.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	printf("Press enter to generate another scramble\n");

	while (1)
	{
		// Generates a random number between 22 and 28
		int scrambleLength = rand() % (29 - 22) + 22;

		char moves[] = { 'U', 'D', 'R', 'L', 'F', 'B' };
		char modifiers[] = { '\'', '2', 0 };

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

		char enter = 0;
		while (enter != '\r' && enter != '\n') enter = getchar();
	}

	return 0;
}
