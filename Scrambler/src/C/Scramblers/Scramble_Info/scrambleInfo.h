#pragma once
#include "../scrambler.h"

typedef struct Info
{
	const Puzzle puzzle;
	const unsigned int modifiers;
	unsigned int scrambleLength;
	void (* const scrambleFunctionPtr)(char** scramblePtr, const unsigned int scrambleLen);
} PuzzleInfo;

void genScrambleLengths(PuzzleInfo* info);