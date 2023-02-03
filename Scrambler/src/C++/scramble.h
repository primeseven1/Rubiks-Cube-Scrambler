#pragma once

class Scramble : public sf::Text
{
public:
	static Scramble& getInstance();
	void setPuzzle(const unsigned int puzzle);
	void generateScramble();

private:
	Scramble();
	int generateScrambleLength() const;

	Scramble(const Scramble&) = delete;
	Scramble(Scramble&&) = delete;
	Scramble& operator=(const Scramble&) = delete;
	Scramble& operator=(Scramble&&) = delete;

	std::string _m_scramble;
	sf::FloatRect _m_bounds;
	unsigned int _m_puzzle;
};