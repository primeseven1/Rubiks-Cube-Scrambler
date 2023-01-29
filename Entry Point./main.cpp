#include "../stdafx.h"
#include "../C++/window.h"

int main()
{
	srand(time(0));

	Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Scrambler", sf::Style::Close | sf::Style::Titlebar);
	return 0;
}
