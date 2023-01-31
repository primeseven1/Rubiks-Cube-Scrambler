#include "../stdafx.h"
#include "scrambleImage.h"

static std::array<sf::Texture, 6> loadColorTextures()
{
	const std::array<sf::Color, 6> colors = { sf::Color::White, sf::Color::Yellow, sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color(255, 165, 0) };
	std::array<sf::Texture, 6> textures;

	for (int i = 0; i < colors.size(); i++)
	{
		sf::Image image;
		image.create(20, 20, colors[i]);

		sf::Texture texture;
		if (!texture.loadFromImage(image)) exit(-2);
		textures[i] = texture;
	}

	return textures;
}

static const std::array<sf::Texture, 6> colorTextures = loadColorTextures();

/*****************************************************************************************************************************************
******************************************************************************************************************************************
******************************************************************************************************************************************/

ScrambleImage& ScrambleImage::getInstance()
{
	static ScrambleImage instance;
	return instance;
}

void ScrambleImage::generateImage(std::string& scramble)
{

}

ScrambleImage::ScrambleImage()
{

}