#pragma once

#include <SFML/Graphics.hpp>

#include "BaseMenu.hh"
#include "Button.hh"
#include "Text.hh"
#include "LineText.hh"

class AboutMenu : public BaseMenu
{
public:
    AboutMenu(sf::Texture &bgTexture, sf::Font &font);

    void draw(sf::RenderWindow &window);

    void detectHover(sf::Vector2i &mousePos);

    unsigned int buttonPressed(sf::Vector2i &mousePos, sf::Event &event);

private:
    Text title;
    LineText message;
    Button back;
};
