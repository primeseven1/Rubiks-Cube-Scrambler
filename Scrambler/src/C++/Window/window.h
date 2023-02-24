#pragma once

#include "../ScrambleText/scrambleText.h"

#define WIDTH 850
#define HEIGHT 600

class Window : public sf::RenderWindow
{
public:
	Window(const unsigned int width, const unsigned int height, const char* title, sf::Uint32 style);

private:
	void eventHandler();

	ScrambleText _m_scrambleText;
	std::unordered_map<sf::Keyboard::Key, std::function<void()>> _m_keyBindings;
};
