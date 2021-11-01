#include <SFML/Graphics.hpp>

#include "Text.hh"

Text::Text(sf::Font &font, sf::Vector2f pos, std::string text, unsigned int charSize, sf::Color colour, bool centered, unsigned int styles)
    : font(font), pos(pos), charSize(charSize), colour(colour), styles(styles)
{
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(this->charSize);
    if (centered)
        this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
    this->text.setPosition(this->pos);
    this->text.setFillColor(this->colour);
    this->text.setStyle(this->styles);
}

Text::Text() {}

void Text::changeText(std::string text)
{
    this->text.setString(text);
}

void Text::changeCharSize(unsigned int charSize)
{
    this->charSize = charSize;
    this->text.setCharacterSize(this->charSize);
}

void Text::changeColour(sf::Color colour)
{
    this->colour = colour;
    this->text.setFillColor(this->colour);
}

void Text::changeStyles(unsigned int styles)
{
    this->styles = styles;
    this->text.setStyle(this->styles);
}

void Text::draw(sf::RenderWindow &window)
{
   window.draw(this->text);
}