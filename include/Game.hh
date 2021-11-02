#pragma once

#include <SFML/Graphics.hpp>

#include "Player.hh"

class Game
{
public:
    Game(std::string bgFile, sf::RenderWindow &window);

    void update(float deltaTime, unsigned int width, unsigned int height);

    sf::Vector2f getWinPlayerPos();

    float getPlayerSpeed();

    void handlePlayerMovements();
    void handlePlayerEvent(sf::Event &event);

    void draw(sf::RenderWindow &window);

private:
    sf::Texture bgTexture;
    sf::Sprite bgSprite;

    Player player;

};