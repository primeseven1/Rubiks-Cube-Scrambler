#include "../../Precompiled_Headers/stdafx.h"
#include "scrambleText.h"
#include "../Window/window.h"

extern "C"
{
#include "../../C/Scramblers/scrambler.h"
#include "../../C/Error/errorWindow.h"
}

static sf::Font loadFont(const char* filePath)
{
	sf::Font font;
	if (!font.loadFromFile(filePath)) loadFileError(filePath);
	return font;
}

ScrambleText& ScrambleText::getInstance()
{
	// This class is a singleton, so I have to access it statically
	static ScrambleText instance;
	return instance;
}

void ScrambleText::setPuzzle(Puzzle puzzle)
{
	_m_puzzle = puzzle;
}

void ScrambleText::generateScramble()
{
	char** scramble = genScramble(_m_puzzle);
	this->_setScramble(scramble);
}

ScrambleText::ScrambleText()
	: _m_scramble("Press enter to generate scrambles..."), _m_font(loadFont(".\\Fonts\\arial.ttf")), _m_puzzle(THREE_BY_THREE)
{
	this->setFont(_m_font);
	this->setFillColor(sf::Color::White);
	this->setString(_m_scramble);
	this->setCharacterSize(20);

	// Cannot be set in the member initializer list since the string has to be set before the boundaries are set
	_m_bounds = this->getLocalBounds();
	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
	this->setPosition(WIDTH / 2, HEIGHT / 3);
}

void ScrambleText::_setScramble(char** scramble)
{
	// The +1 includes the move that's not a modifer, since that needs to be displayed too
	unsigned int modifiers = _m_puzzle < FOUR_BY_FOUR ? 1 + 1 : _m_puzzle < SIX_BY_SIX ? 2 + 1 : 3 + 1;
	_m_scramble.clear();
	unsigned int i = 0;
	while (scramble[i][0] != '\0')
	{
		for (unsigned int j = 0; j < modifiers; j++) scramble[i][j] != ' ' ? _m_scramble += scramble[i][j] : _m_scramble += "";

		// For some reason, there is a weird thing that happens only with the pyraminx tips
		if (_m_puzzle == PYRAMINX && scramble[i][0] == ' ') _m_scramble += "";
		else _m_scramble += " ";
		i++;

		// This makes sure that the scramble stays on the screen, this only needs to happen if it's bigger than 3x3
		if (_m_puzzle > THREE_BY_THREE && i % 20 == 0) _m_scramble += "\n";
	}

	freeScramble(scramble);
	scramble = nullptr;

	this->setString(_m_scramble);

	// Since the scramble changed, this has to be called to make it center again
	this->_m_bounds = this->getLocalBounds();
	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
}