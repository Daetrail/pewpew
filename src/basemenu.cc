#include <vector>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "BaseMenu.hh"
#include "Button.hh"
#include "Text.hh"

BaseMenu::BaseMenu(std::string bgFile, sf::Font &font)
    : bgFile(bgFile), font(font)
{
    this->font = font;
    if (!this->bgTexture.loadFromFile(this->bgFile))
        std::cout << "Cannot open background file: " << this->bgFile << std::endl;
    else
        this->bgSprite.setTexture(this->bgTexture);
}

BaseMenu::BaseMenu(sf::Texture &bgTexture, sf::Font &font)
    : font(font)
{
    this->bgTexture = bgTexture;
    this->bgSprite.setTexture(this->bgTexture);
}

sf::Texture& BaseMenu::getTexture()
{
    return this->bgTexture;
}
