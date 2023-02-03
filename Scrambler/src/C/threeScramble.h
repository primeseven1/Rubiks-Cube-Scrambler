#pragma once

// The genThreeScramble function is also able to generate 2x2 scrambles, the scramble length determines what it generates
#define genTwoScramble genThreeScramble

char** genThreeScramble(unsigned int scrambleLength);