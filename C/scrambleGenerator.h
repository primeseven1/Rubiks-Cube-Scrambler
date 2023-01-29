#pragma once

char** genScramble(const unsigned int scrambleLength);
int valid(const char** scramble, const unsigned int i, const char move);
void freeScramble(char** scramble, const unsigned int scrambleLength);