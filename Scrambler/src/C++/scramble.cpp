#include "../stdafx.h"
#include "scramble.h"
#include "window.h"

extern "C" {
#include "../C/scrambleGenerator.h"
#include "../C/errorWindow.h"
}

/*****************************************************************************************************************************************
******************************************************************************************************************************************
******************************************************************************************************************************************/

static sf::Font loadFont(const char* filePath)
{
	sf::Font font;
	if (!font.loadFromFile(filePath)) loadFileError(filePath);

	return font;
}

static sf::Font font = loadFont("C:/Windows/Fonts/arial.ttf");

/*****************************************************************************************************************************************
******************************************************************************************************************************************
******************************************************************************************************************************************/

Scramble& Scramble::getInstance()
{
	static Scramble instance;
	return instance;
}

Scramble::Scramble()
	: _m_scramble("Press enter to generate scrambles")
{
	this->setFont(font);
	this->setCharacterSize(18);
	this->setString(_m_scramble);

	_m_bounds = this->getLocalBounds(); // Cannot be set in the member initializer list otherwise the text won't be in the right place
	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
	this->setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f - 100);
}

void Scramble::generateScramble()
{
	unsigned int scrambleLength = rand() % (29 - 24) + 24;
	char** tempScramble = genScramble(scrambleLength);

	_m_scramble = "";

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		for (unsigned int j = 0; j < 2 / sizeof(char); j++)
		{
			tempScramble[i][j] ? _m_scramble += tempScramble[i][j] : _m_scramble += "";
		}

		_m_scramble += " ";
	}

	freeScramble(tempScramble, scrambleLength);
	tempScramble = nullptr;

	this->setString(_m_scramble);
	_m_bounds = this->getLocalBounds();
	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
}