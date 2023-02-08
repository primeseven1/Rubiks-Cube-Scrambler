#pragma once

extern "C"
{
#include "../../C/Scramblers/scrambler.h"
}

class ScrambleText : public sf::Text
{
public:
	static ScrambleText& getInstance();
	void setPuzzle(Puzzle puzzle);
	void generateScramble();

private:
	ScrambleText();
	void _setScramble(char** scramble);

	ScrambleText(const ScrambleText&) = delete;
	ScrambleText(ScrambleText&&) = delete;
	ScrambleText& operator=(const ScrambleText&) = delete;
	ScrambleText& operator=(ScrambleText&&) = delete;

	std::string _m_scramble;
	sf::Font _m_font;
	Puzzle _m_puzzle;
	sf::FloatRect _m_bounds; // Boundaries for the text, since it's changing as you generate scrambles
};