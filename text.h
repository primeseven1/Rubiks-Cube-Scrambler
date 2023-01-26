#pragma once

class Scramble : public sf::Text
{
public:
	Scramble();
	void setScramble();

private:
	sf::FloatRect _m_bounds;
};