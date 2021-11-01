#include <SFML/Graphics.hpp>

#include "BaseMenu.hh"  
#include "AboutMenu.hh"
#include "Text.hh"
#include "Button.hh"
#include "LineText.hh"
#include "Global.hh"

AboutMenu::AboutMenu(sf::Texture &bgTexture, sf::Font &font)
    : BaseMenu(bgTexture, font), 
    title(this->font, sf::Vector2f(100.f, 50.f), "About", 120, sf::Color::White, false, sf::Text::Bold),
    message(this->font, sf::Vector2f(100.f, 200.f), Global::MESSAGE, 40, sf::Color::White, false, 60),
    back(sf::Vector2f(100.f, 580.f), "Back", 80, this->font, sf::Color::White, sf::Color::Cyan, false) {}

void AboutMenu::draw(sf::RenderWindow &window)
{
    window.draw(this->bgSprite);

    this->title.draw(window);
    this->message.draw(window);
    this->back.draw(window);
}

void AboutMenu::detectHover(sf::Vector2i &mousePos)
{
    this->back.checkIfHovered(mousePos);
}

unsigned int AboutMenu::buttonPressed(sf::Vector2i &mousePos, sf::Event &event)
{
    if (this->back.checkIfClicked(mousePos, event))
        return Global::back;
    return Global::none;
}
