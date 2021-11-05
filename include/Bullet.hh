#pragma once

#include <SFML/Graphics.hpp>

#include "Player.hh"

class Bullet
{
public:
    Bullet(sf::Vector2f scale);
    Bullet();

    void update(Player &player, sf::Vector2f direction, float deltaTime);

    void fire();    

    void draw(sf::RenderWindow &window, sf::Vector2f direction);

private:
    sf::Texture bulletTex;
    sf::Texture muzzleFlashTex;
    sf::Sprite bulletSprite;
    sf::Sprite muzzleFlashSprite;

    bool posLock = false;
    bool isFired = false;

    float switchTime = 0.1f;
    float totalTime = 0.f;
    float speed = 1.f;
};