#include "../../Precompiled_Headers/pch.h"
#include "instructions.h"
#include "../Window/window.h"
#include "font.h"

Instructions::Instructions()
	: _m_font(loadFont(".\\Fonts\\arial.ttf")), _m_instructions("\t\t\t\tNumber keys 2-7: 2x2 - 7x7\nP: Pyraminx | S: Skewb | C: Clock | M: Megaminx")
{
	this->setFont(_m_font);
	this->setFillColor(sf::Color::White);
	this->setString(_m_instructions);
	this->setCharacterSize(18);

	_m_bounds = this->getLocalBounds();
	this->setOrigin(_m_bounds.left + _m_bounds.width / 2.f, _m_bounds.top + _m_bounds.height / 2.f);
	this->setPosition(WIDTH / 2, HEIGHT / 1.5f);
}