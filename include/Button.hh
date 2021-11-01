#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(sf::Vector2f pos, std::string label, unsigned int charSize, sf::Font &font, sf::Color defaultColour, sf::Color hoveredColour, bool centered, unsigned int styles = sf::Text::Regular);
    Button(); 

    void changeStyle(unsigned int styles);

    bool checkIfHovered(sf::Vector2i &mousePos);
    bool checkIfClicked(sf::Vector2i &mousePos, sf::Event &event);

    void draw(sf::RenderWindow &window);

private:
    sf::Vector2f pos;
    sf::Text label;
    unsigned int charSize;
    sf::Font font;
    sf::Color defaultColour;
    sf::Color hoveredColour;
    unsigned int styles;
};