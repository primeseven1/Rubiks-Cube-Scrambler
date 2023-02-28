#pragma once

extern "C"
{
#include "../../C/Scramblers/scrambler.h"
}

class ScrambleText : public sf::Text
{
public:
	ScrambleText();
	void setPuzzle(Puzzle puzzle);
	void generateScramble();

private:
	void setScramble(char** scramble);

	std::string _m_scramble;
	sf::Font _m_font;
	Puzzle _m_puzzle;
	sf::FloatRect _m_bounds; // Boundaries for the text, since it's changing as you generate scrambles
};