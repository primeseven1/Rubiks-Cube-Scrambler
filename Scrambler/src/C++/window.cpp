#include "../stdafx.h"
#include "window.h"
#include "scramble.h"

extern "C" {
#include "../C/scrambleGenerator.h"
}

Window::Window(const unsigned int screenWidth, const unsigned int screenHeight, const char* title, sf::Uint32 style = sf::Style::Default)
{
	this->create(sf::VideoMode(screenWidth, screenHeight), title, style);
	this->setFramerateLimit(30); // This reduces CPU usage by a lot
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
				this->_keyboardEventHandler(windowEvent.key.code);
				break;
			}
		}

		this->clear();
		this->draw(Scramble::getInstance());
		this->display();
	}
}

void Window::_keyboardEventHandler(const sf::Keyboard::Key& key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Enter:
		Scramble::getInstance().generateScramble();
		break;

	case sf::Keyboard::Key::Num2:
		Scramble::getInstance().setPuzzle(2);
		break;

	case sf::Keyboard::Key::Num3:
		Scramble::getInstance().setPuzzle(3);
		break;
	}
}