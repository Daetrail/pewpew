#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Button.hh"
#include "Text.hh"

class BaseMenu
{
public:
    BaseMenu(std::string bgFile, sf::Font &font);
    BaseMenu(sf::Texture &bgTexture, sf::Font &font);

    sf::Texture &getTexture();

protected:
    std::string bgFile;
    sf::Texture bgTexture;
    sf::Sprite bgSprite;

    sf::Font font;
};