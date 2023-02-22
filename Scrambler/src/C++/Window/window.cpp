#include "../../Precompiled_Headers/stdafx.h"
#include "window.h"
#include "../ScrambleText/scrambleText.h"

Window::Window(const unsigned int width, const unsigned int height, const char* title, sf::Uint32 style)
	: _m_keyBindings {
		{ sf::Keyboard::Enter, []() { ScrambleText::getInstance().generateScramble(); } }, { sf::Keyboard::Num2, []() { ScrambleText::getInstance().setPuzzle(TWO_BY_TWO); } },
		{ sf::Keyboard::Num3, []() { ScrambleText::getInstance().setPuzzle(THREE_BY_THREE); } }, { sf::Keyboard::Num4, []() { ScrambleText::getInstance().setPuzzle(FOUR_BY_FOUR); } },
		{ sf::Keyboard::Num5, []() { ScrambleText::getInstance().setPuzzle(FIVE_BY_FIVE); } }, { sf::Keyboard::Num6, []() { ScrambleText::getInstance().setPuzzle(SIX_BY_SIX); } },
		{ sf::Keyboard::Num7, []() { ScrambleText::getInstance().setPuzzle(SEVEN_BY_SEVEN); } }, { sf::Keyboard::S, []() { ScrambleText::getInstance().setPuzzle(SKEWB); } },
		{ sf::Keyboard::P, []() { ScrambleText::getInstance().setPuzzle(PYRAMINX); } }, { sf::Keyboard::M, []() { ScrambleText::getInstance().setPuzzle(MEGAMINX); } },
		{ sf::Keyboard::C, []() { ScrambleText::getInstance().setPuzzle(CLOCK); } }
		}
{
	this->create(sf::VideoMode(width, height), title, style);
	this->setFramerateLimit(30); // Reduces CPU usage by a lot
	this->_eventHandler();
}

void Window::_eventHandler()
{
	while (this->isOpen())
	{
		sf::Event windowEvent;

		while (this->pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				this->close();
				break;

			case sf::Event::KeyPressed:
				if (_m_keyBindings.count(windowEvent.key.code) > 0) _m_keyBindings[windowEvent.key.code]();
				break;
			}
		}

		this->clear(sf::Color(53, 54, 58));
		this->draw(ScrambleText::getInstance());
		this->display();
	}
}