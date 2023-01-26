#include "scrambler.h"
#include "text.h"
#include "window.h"

static sf::Font loadFont(const char* filePath)
{
	sf::Font font;

	// If the font cannot be loaded, it tries to load a font from the windows folder
	if (!font.loadFromFile(filePath)) 
		if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) exit(EXIT_FAILURE);

	return font;
}

static const sf::Font font = loadFont("./Fonts/arial.ttf");


Scramble::Scramble()
{
	this->setFont(font);
	this->setString("Press enter to generate scrambles");
	this->setFillColor(sf::Color::White);
	this->setCharacterSize(20);
	
	_m_bounds = this->getLocalBounds();

	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
	this->setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f - 200);
}

void Scramble::setScramble()
{
	unsigned int scrambleLength = rand() % (29 - 25) + 25;
	char** tempScramble = genScramble(scrambleLength);
	if (!tempScramble) throw;

	std::string scramble;

	for (unsigned int i = 0; i < scrambleLength; i++)
	{
		for (unsigned int j = 0; j < 2 * sizeof(char); j++) // The elements inside the 2d array are always 2 elements
		{
			tempScramble[i][j] ? scramble += tempScramble[i][j] : scramble += ""; // Removes empty boxes from NULL modifiers
		}

		scramble += " ";
	}

	freeScramble(tempScramble, scrambleLength);
	tempScramble = nullptr;

	this->setString(scramble);

	_m_bounds = this->getLocalBounds();
	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
}