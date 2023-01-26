#pragma once

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600

class Window : public sf::RenderWindow
{
public:
	Window(unsigned int width, unsigned int height, const char* title);

private:
	void update();
};