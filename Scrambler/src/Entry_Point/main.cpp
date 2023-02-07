#include "../Precompiled_Headers/stdafx.h"
#include "../C++/Window/window.h"

int main()
{
	srand(time(0));

	Window window(WIDTH, HEIGHT, "Scrambler", sf::Style::Close | sf::Style::Titlebar);
	return 0;
}