#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "LineText.hh"

LineText::LineText(sf::Font &font, sf::Vector2f pos, std::vector<std::string> lines, unsigned int charSize, sf::Color colour, bool centered, unsigned int spacing, unsigned int styles)
    : font(font), pos(pos), charSize(charSize), colour(colour), spacing(spacing), styles(styles)
{   
    for (std::string line : lines)
    {
        sf::Text text;
        text.setFont(this->font);
        text.setString(line);
        text.setCharacterSize(this->charSize);
        if (centered)
            text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
        text.setPosition(this->pos);
        text.setFillColor(this->colour);
        text.setStyle(this->styles);

        this->lines.push_back(text);

        this->pos += sf::Vector2f(0.f, this->spacing);
    }
}

LineText::LineText() {}

void LineText::draw(sf::RenderWindow &window)
{
    for (auto text : this->lines)
        window.draw(text);
}