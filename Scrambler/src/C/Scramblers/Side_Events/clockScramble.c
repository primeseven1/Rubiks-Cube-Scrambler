#include <stdlib.h>
#include "clockScramble.h"
#include "../scrambler.h"

static const char pinOrder[] = { 'L', 'R', 'R', 'L'};
static const char pinOrder2[] = { 'U', 'R', 'D', 'L' };
static const char numOfTurns[] = {'0', '1', '2', '3', '4', '5', '6'};
static const char clockwiseOrCounter[] = { '+', '-' };
static const char pins[][2] = { { 'U', 'R' }, { 'D', 'R' }, { 'D', 'L' }, { 'U', 'L' } };

void genClockScramble(char** scramble, const unsigned int scrambleLength)
{
	if (!scramble) return;

	// Generate first four moves
	unsigned int i = 0;
	for (; i < 4; i++)
	{
		scramble[i][0] = i < 2 ? 'U' : 'D';
		scramble[i][1] = pinOrder[i];
		scramble[i][2] = numOfTurns[rand() % sizeof(numOfTurns)];
		scramble[i][3] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
	}
	
	// J is used for array indexes now since the variable "i" can't do that anymore
	// Generating next four moves
	for (unsigned int j = 0; j < 4; j++)
	{
		scramble[i][0] = pinOrder2[j];
		scramble[i][1] = numOfTurns[rand() % sizeof(numOfTurns)];
		scramble[i][2] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
		scramble[i][3] = ' ';
		i++;
	}

	// A means all, and it just generates that for that move
	scramble[i][0] = 'A';
	scramble[i][1] = numOfTurns[rand() % sizeof(numOfTurns)];
	scramble[i][2] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
	scramble[i][3] = ' ';
	i++;

	memset(scramble[i], ' ', 2 * sizeof(char)); // Setting the first 2 bytes of that part of the array to spaces
	scramble[i][2] = 'y';
	scramble[i][3] = '2';
	i++;

	for (unsigned int j = 0; j < 4; j++)
	{
		scramble[i][0] = scramble[i - 6][0];
		scramble[i][1] = numOfTurns[rand() % sizeof(numOfTurns)];
		scramble[i][2] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
		scramble[i][3] = scramble[i - 6][3];
		i++;
	}

	scramble[i][0] = 'A';
	scramble[i][1] = numOfTurns[rand() % sizeof(numOfTurns)];
	scramble[i][2] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
	scramble[i][3] = ' ';
	i++;

	for (int j = 0; j < 4; j++)
	{
		memset(scramble[i], ' ', 2);
		scramble[i][2] = rand() % 2 == 0 ? pins[j][0] : ' ';
		scramble[i][3] = scramble[i][2] != ' ' ? pins[j][1] : ' ';
		i++;
	}
}