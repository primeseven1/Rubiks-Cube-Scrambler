#pragma once

#define WIDTH 850
#define HEIGHT 600

class Window : public sf::RenderWindow
{
public:
	Window(const unsigned int width, const unsigned int height, const char* title, sf::Uint32 style);

private:
	void _eventHandler();
	
	std::unordered_map<sf::Keyboard::Key, std::function<void()>> _m_keyBindings;
};