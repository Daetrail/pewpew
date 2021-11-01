#include <SFML/Graphics.hpp>

#include "BaseMenu.hh"  
#include "MainMenu.hh"
#include "Text.hh"
#include "Button.hh"
#include "Global.hh"

MainMenu::MainMenu(std::string bgFile, sf::Font &font)
    : BaseMenu(bgFile, font), 
    title(this->font, sf::Vector2f(100.f, 50.f), "Pew Pew", 120, sf::Color::White, false, sf::Text::Bold), 
    play(sf::Vector2f(100.f, 200.f), "Play", 80, this->font, sf::Color::White, sf::Color::Cyan, false),
    about(sf::Vector2f(100.f, 300.f), "About", 80, this->font, sf::Color::White, sf::Color::Cyan, false),
    exit(sf::Vector2f(100.f, 400.f), "Exit", 80, this->font, sf::Color::White, sf::Color::Cyan, false),
    version(this->font, sf::Vector2f(1150.f, 650.f), "v" + Global::VERSION, 60, sf::Color::White, true) {}

void MainMenu::draw(sf::RenderWindow &window)
{
    window.draw(this->bgSprite);

    this->title.draw(window);
    this->play.draw(window);
    this->about.draw(window);
    this->exit.draw(window);
    this->version.draw(window);
}

void MainMenu::detectHover(sf::Vector2i &mousePos)
{
    this->play.checkIfHovered(mousePos);
    this->about.checkIfHovered(mousePos);
    this->exit.checkIfHovered(mousePos);
}

unsigned int MainMenu::buttonPressed(sf::Vector2i &mousePos, sf::Event &event)
{
    if (this->play.checkIfClicked(mousePos, event))
        return Global::play;
    else if (this->about.checkIfClicked(mousePos, event))
        return Global::about;
    else if (this->exit.checkIfClicked(mousePos, event))
        return Global::exit;
    return Global::none;
}