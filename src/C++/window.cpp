#include "../stdafx.h"
#include "window.h"
#include "scramble.h"

extern "C" {
#include "../C/scrambleGenerator.h"
}

Window::Window(const unsigned int screenWidth, const unsigned int screenHeight, const char* title, sf::Uint32 style = sf::Style::Default)
{
	this->create(sf::VideoMode(screenWidth, screenHeight), title, style);
	this->setFramerateLimit(30);
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
				this->keyboardHandler(windowEvent.key.code);
				break;
			}
		}

		this->clear();
		this->draw(Scramble::getInstance());
		this->display();
	}
}

void Window::keyboardHandler(const sf::Keyboard::Key& key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Enter:
		Scramble::getInstance().generateScramble();
		break;
	}
}