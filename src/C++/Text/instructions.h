#pragma once

class Instructions : public sf::Text
{
public:
    Instructions();

private:
    sf::Font _m_font;
    std::string _m_instructions;
    sf::FloatRect _m_bounds;
};