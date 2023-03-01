#include "../../Precompiled_Headers/pch.h"
#include "font.h"

extern "C"
{
#include "../../C/Error/errorWindow.h"
}

sf::Font loadFont(const char* filePath)
{
	sf::Font font;
	if (!font.loadFromFile(filePath)) loadFileError(filePath);
	return font;
}