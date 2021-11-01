#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class LineText
{
public:
    LineText(sf::Font &font, sf::Vector2f pos, std::vector<std::string> lines, unsigned int charSize, sf::Color colour, bool centered, unsigned int spacing, unsigned int styles = sf::Text::Regular);
    LineText();

    void draw(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Vector2f pos;
    std::vector<sf::Text> lines;
    unsigned int charSize;
    sf::Color colour;
    unsigned int spacing;
    unsigned int styles;
};