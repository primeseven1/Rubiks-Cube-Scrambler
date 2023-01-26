#include "scrambler.h"
#include "window.h"
#include "text.h"

Window::Window(unsigned int width, unsigned int height, const char* title)
{
	this->create(sf::VideoMode(width, height), title, sf::Style::Close);
	this->setFramerateLimit(30); // Reduces CPU usage by a lot
	this->update();
}

void Window::update()
{
	Scramble scramble;

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
				if (windowEvent.key.code == sf::Keyboard::Key::Enter) scramble.setScramble();
				break;
			}
		}

		this->clear();
		this->draw(scramble);
		this->display();
	}
}

