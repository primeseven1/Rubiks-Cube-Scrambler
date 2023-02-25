#pragma once

#include "../scrambler.h"
#include "../../Error/Debugging/debugErrorWindow.h"


struct PuzzleInfo
{
	const Puzzle puzzle;
	const unsigned int modifiers;
	unsigned int scrambleLength;
	void (* const scrambleFunctionPtr)(char** scramblePtr, struct Info* info);
};

void genScrambleLengths(struct PuzzleInfo* info);