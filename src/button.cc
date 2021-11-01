#include <iostream>
#include <SFML/Graphics.hpp>

#include "Button.hh"

Button::Button(sf::Vector2f pos, std::string label, unsigned int charSize, sf::Font &font, sf::Color defaultColour, sf::Color hoveredColour, bool centered, unsigned int styles)
    : pos(pos), charSize(charSize), font(font), defaultColour(defaultColour), hoveredColour(hoveredColour), styles(styles)
{
    this->label.setFont(this->font);
    this->label.setString(label);
    this->label.setCharacterSize(this->charSize);
    if (centered)
        this->label.setOrigin(this->label.getGlobalBounds().width / 2, this->label.getGlobalBounds().height / 2);
    this->label.setPosition(this->pos);
    this->label.setFillColor(this->defaultColour);
    this->label.setStyle(this->styles);
}

Button::Button() {}

void Button::changeStyle(unsigned int styles)
{
    this->label.setStyle(styles);
}

bool Button::checkIfHovered(sf::Vector2i &mousePos)
{
    sf::FloatRect boundingBox = this->label.getGlobalBounds();

    if (boundingBox.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        this->label.setFillColor(this->hoveredColour);
        this->changeStyle(sf::Text::Bold); 
        return true;
    }
    else
    {
        this->label.setFillColor(this->defaultColour);
        this->changeStyle(this->styles);
        return false;
    }
}

bool Button::checkIfClicked(sf::Vector2i &mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left && this->checkIfHovered(mousePos))
            return true;
        else
            return false;
    }
    return false;
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(this->label);
}