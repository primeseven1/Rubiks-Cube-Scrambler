#pragma once
#include "../scrambler.h"

typedef struct Info
{
	Puzzle puzzle;
	unsigned int modifiers;
	unsigned int scrambleLength;
	void (*scrambleFunctionPtr)(char** scramble, unsigned int scramble_length);
} PuzzleInfo;

void genScrambleLengths(PuzzleInfo* info);