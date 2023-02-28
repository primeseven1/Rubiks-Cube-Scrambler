#include "../../Precompiled_Headers/pch.h"
#include "window.h"

Window::Window(const unsigned int width, const unsigned int height, const char* title, sf::Uint32 style)
	: _m_keyBindings {
		{ sf::Keyboard::Enter, [this]() { _m_scrambleText.generateScramble(); } }, { sf::Keyboard::Num2, [this]() { _m_scrambleText.setPuzzle(TWO_BY_TWO); } },
		{ sf::Keyboard::Num3, [this]() { _m_scrambleText.setPuzzle(THREE_BY_THREE); } }, { sf::Keyboard::Num4, [this]() { _m_scrambleText.setPuzzle(FOUR_BY_FOUR); } },
		{ sf::Keyboard::Num5, [this]() { _m_scrambleText.setPuzzle(FIVE_BY_FIVE); } }, { sf::Keyboard::Num6, [this]() { _m_scrambleText.setPuzzle(SIX_BY_SIX); } },
		{ sf::Keyboard::Num7, [this]() { _m_scrambleText.setPuzzle(SEVEN_BY_SEVEN); } }, { sf::Keyboard::S, [this]() { _m_scrambleText.setPuzzle(SKEWB); } },
		{ sf::Keyboard::P, [this]() { _m_scrambleText.setPuzzle(PYRAMINX); } }, { sf::Keyboard::M, [this]() { _m_scrambleText.setPuzzle(MEGAMINX); } },
		{ sf::Keyboard::C, [this]() { _m_scrambleText.setPuzzle(CLOCK); } }
		}
{
	this->create(sf::VideoMode(width, height), title, style);
	this->setFramerateLimit(30); // Reduces CPU usage by a lot
	this->eventHandler();
}

void Window::eventHandler()
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
		this->draw(_m_scrambleText);
		this->display();
	}
}
