#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.hh"
#include "Global.hh"

Game::Game(std::string bgFile, sf::RenderWindow &window)
    : player(Global::jumpFile, Global::idleFile, Global::runFile, Global::deathFile, Global::crouchFile, 0.2f)
{
    if (!this->bgTexture.loadFromFile(bgFile))
        std::cout << "Unable to load " << bgFile << std::endl;
    else
    {
        this->bgSprite.setTexture(this->bgTexture);
    }

    player.setSpeed(3.f);
}

void Game::update(float deltaTime, unsigned int width, unsigned int height)
{
    this->player.update(deltaTime, width, height);
}

sf::Vector2f Game::getWinPlayerPos()
{
    return this->player.getPos();
}

float Game::getPlayerSpeed()
{
    return this->player.getSpeed();
}

void Game::handlePlayerMovements()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player.move(sf::Vector2f(-1.f, 0.f));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player.move(sf::Vector2f(1.f, 0.f));
    else
        this->player.notMoving();
}

void Game::handlePlayerEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            this->player.jump(); 
        }
    }
}

void Game::draw(sf::RenderWindow &window)
{
    window.draw(this->bgSprite);

    this->player.draw(window);
}