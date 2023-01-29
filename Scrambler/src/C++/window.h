#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class Window : public sf::RenderWindow
{
public:
	Window(const unsigned int screenWidth, const unsigned int screenHeight, const char* title, sf::Uint32 style);

private:
	void eventHandler();
	void keyboardHandler(const sf::Keyboard::Key& key);
};