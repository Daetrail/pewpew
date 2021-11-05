#pragma once

#include <SFML/Graphics.hpp>

#include "Bullet.hh"
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

    void handleFiring();

    void draw(sf::RenderWindow &window);

private:
    sf::Texture bgTexture;
    sf::Sprite bgSprite;

    Player player;
    Bullet bullet;

};