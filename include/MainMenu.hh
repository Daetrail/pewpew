#pragma once 

#include <string>
#include <SFML/Graphics.hpp>

#include "BaseMenu.hh"
#include "Button.hh"
#include "Text.hh"

class MainMenu : public BaseMenu
{
public:
    MainMenu(std::string bgFile, sf::Font &font);

    void draw(sf::RenderWindow &window);

    void detectHover(sf::Vector2i &mousePos);

    unsigned int buttonPressed(sf::Vector2i &mousePos, sf::Event &event);

private:
    Text title;
    Button play;
    Button about;
    Button exit;
    Text version;

};