#pragma once

class ScrambleImage
{
public:
	static ScrambleImage& getInstance();
	void generateImage(std::string& scramble);

private:
	ScrambleImage();

	ScrambleImage(const ScrambleImage&) = delete;
	ScrambleImage(ScrambleImage&&) = delete;
	ScrambleImage& operator=(const ScrambleImage&) = delete;
	ScrambleImage& operator=(ScrambleImage&&) = delete;

	std::array<std::array<sf::Sprite, 9>, 6> _m_scrambleImage;

	// Made for the order of the array of textures in the scramble.cpp file
	enum Colors {
		white,
		yellow,
		green,
		blue,
		red,
		orange
	};
};