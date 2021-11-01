#pragma once

#include <SFML/Graphics.hpp>

class Text
{
public:
    Text(sf::Font &font, sf::Vector2f pos, std::string text, unsigned int charSize, sf::Color colour, bool centered, unsigned int styles = sf::Text::Regular);
    Text();

    void changeText(std::string text);
    void changeCharSize(unsigned int charSize);
    void changeColour(sf::Color colour);
    void changeStyles(unsigned int styles);

    void draw(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Vector2f pos;
    sf::Text text;
    unsigned int charSize;
    sf::Color colour;
    unsigned int styles;
};