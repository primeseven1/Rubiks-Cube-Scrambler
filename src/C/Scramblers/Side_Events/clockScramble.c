#include <stdlib.h>
#include <string.h>
#include "clockScramble.h"
#include "../scrambler.h"

static const char pins[][2] = { { 'U', 'R' }, { 'D', 'R' }, { 'D', 'L' }, { 'U', 'L' } };
static const char doublePinOrder[] = { 'U', 'R', 'D', 'L' };
static const char numOfTurns[] = { '0', '1', '2', '3', '4', '5', '6' };
static const char clockwiseOrCounter[] = { '+', '-' };

// This just simply makes sure that if there is a 6-, it will just switch it to a + since that's how they are normally generated
static void clockValid(const char numOfTurns, char* clockwiseOrCounter) 
{ 
	// Making sure this is not a NULL pointer
	if (!clockwiseOrCounter) return;

	if (numOfTurns == '6' && *clockwiseOrCounter == '-') *clockwiseOrCounter = '+'; 
}

// Normally this is ALL, but I just shortened it to A
static void genAllMove(char** scramble, const int i)
{
	scramble[i][0] = 'A';
	scramble[i][1] = numOfTurns[rand() % sizeof(numOfTurns)];
	scramble[i][2] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
	scramble[i][3] = ' ';
	clockValid(scramble[i][1], &scramble[i][2]);
}

// I don't know what else to call this function
static void genTwoPinDownMoves(char** scramble, const int i, const int j)
{
	scramble[i][0] = doublePinOrder[j];
	scramble[i][1] = numOfTurns[rand() % sizeof(numOfTurns)];
	scramble[i][2] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
	clockValid(scramble[i][1], &scramble[i][2]);
	scramble[i][3] = ' ';
}

void genClockScramble(char** scramble, const struct PuzzleInfo* info)
{
	// Preventing memory access violations or undefined behavior
	if (!scramble) return;
	if (info->puzzle != CLOCK || info->modifiers != CLOCK_MODIFIERS) wrongFunctionCall(__func__);;

	// Setting the first 4 moves according to the pin order
	// i needs to still exist after the for loop
	unsigned int i = 0;
	for ( ; i < 4; i++)
	{
		for (int j = 0; j < 2; j++) scramble[i][j] = pins[i][j];
		scramble[i][2] = numOfTurns[rand() % sizeof(numOfTurns)];
		scramble[i][3] = clockwiseOrCounter[rand() % sizeof(clockwiseOrCounter)];
		clockValid(scramble[i][2], &scramble[i][3]);
	}

	// Generating next 4 moves
	for (int j = 0; j < 4; j++, i++) genTwoPinDownMoves(scramble, i, j);

	genAllMove(scramble, i);
	i++;

	// This is for the flip in the middle of the scramble
	scramble[i][0] = 'y';
	scramble[i][1] = '2';
	scramble[i][2] = ' ';
	scramble[i][3] = scramble[i][2];
	i++;

	// Generating next 4 moves
	for (int j = 0; j < 4; j++, i++) genTwoPinDownMoves(scramble, i, j);

	genAllMove(scramble, i);
	i++;

	// Generating what pins should be up or down for the last 4 moves
	for (int j = 0; j < 4; j++, i++)
	{
		memset(scramble[i], ' ', 4);
		scramble[i][0] = rand() % 2 == 0 ? pins[j][0] : ' ';
		scramble[i][1] = scramble[i][0] != ' ' ? pins[j][1] : ' ';
	}
}