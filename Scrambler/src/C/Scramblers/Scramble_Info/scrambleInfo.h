#pragma once

#include "../scrambler.h"
#include "../../Error/Debugging/debugErrorWindow.h"

typedef struct Info PuzzleInfo;

struct Info
{
	const Puzzle puzzle;
	const unsigned int modifiers;
	unsigned int scrambleLength;
	void (* const scrambleFunctionPtr)(char** scramblePtr, PuzzleInfo* info);
};

void genScrambleLengths(PuzzleInfo* info);