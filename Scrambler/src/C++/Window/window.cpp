#include "../../Precompiled_Headers/stdafx.h"
#include "window.h"
#include "../ScrambleText/scrambleText.h"

Window::Window(const unsigned int width, const unsigned int height, const char* title, sf::Uint32 style)
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
				this->_keyboardHandler(windowEvent.key.code);
				break;
			}
		}

		this->clear(sf::Color(53, 54, 58));
		this->draw(ScrambleText::getInstance());
		this->display();
	}
}

void Window::_keyboardHandler(sf::Keyboard::Key& key)
{
	switch (key)
	{
	case sf::Keyboard::Enter:
		ScrambleText::getInstance().generateScramble();
		break;

	case sf::Keyboard::Num2:
		ScrambleText::getInstance().setPuzzle(TWO_BY_TWO);
		break;

	case sf::Keyboard::Num3:
		ScrambleText::getInstance().setPuzzle(THREE_BY_THREE);
		break;

	case sf::Keyboard::Num4:
		ScrambleText::getInstance().setPuzzle(FOUR_BY_FOUR);
		break;

	case sf::Keyboard::Num5:
		ScrambleText::getInstance().setPuzzle(FIVE_BY_FIVE);
		break;

	case sf::Keyboard::Escape:
		this->close();
		break;
	}
}