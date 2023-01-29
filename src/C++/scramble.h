#pragma once

class Scramble : public sf::Text
{
public:
	static Scramble& getInstance();
	void generateScramble();

private:
	Scramble();

	// Prevents the class from being copied, and you also can't move this class to a new variable
	Scramble(const Scramble&) = delete;
	Scramble(Scramble&&) = delete;
	Scramble& operator=(const Scramble&) = delete;
	Scramble& operator=(Scramble&&) = delete;

private:
	std::string _m_scramble;
	sf::FloatRect _m_bounds;
};